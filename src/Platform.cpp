#include "Platform.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>
#include <cmath>

namespace WappieJump
{
	Platform::Platform(GameDataRef data) : _data(data)
	{
		SpawnFirstPlatform();
	}

	int Platform::GetDeletedPlatforms()
	{
		return _deletedPlatforms;
	}

	std::vector<Platform::platform>* Platform::GetPlatformsVector()
	{
		return &platforms;
	}

	float Platform::CalculateRandomWidth(float platformWidth)
	{
		int maxWidth = _data->window.getSize().x * 0.99f - platformWidth;
		return rand() % maxWidth + _data->window.getSize().x * 0.005f;
	}

	void Platform::SpawnFirstPlatform()
	{
		sf::Sprite platformSprite(_data->assets.GetTexture("Platform"));

		float randomWidth = CalculateRandomWidth(platformSprite.getGlobalBounds().width);

		_platformWidth = platformSprite.getGlobalBounds().width;
		_platformHeight = platformSprite.getGlobalBounds().height;

		platformSprite.setPosition(randomWidth, _data->window.getSize().y - platformSprite.getGlobalBounds().height);
		platforms.push_back(platform(platformSprite, DEFAULT));
	}

	Platform::category Platform::GenerateBounceablePlatformCategory()
	{
		_consecutiveInvisiblePlatforms = 0;
		//Moeilijkheidsgraad mag niet onder de 10 komen bij deze oplossing

		int randomNumber = rand() % 1001 + 1;
		int defaultPlatformProbability = 3000000 / (_deletedPlatforms/ 0.1f * DIFFICULTY_LEVEL+ 10000) + 500;
		int boosterPlatformProbability = defaultPlatformProbability + 3000000 / (_deletedPlatforms / 0.1f * DIFFICULTY_LEVEL + 16000) + 10;

		if (randomNumber < defaultPlatformProbability) return Platform::DEFAULT;
		if (randomNumber < boosterPlatformProbability) return Platform::BOOSTER;
		return Platform::MOVING;
	}

	Platform::category Platform::GeneratePlatformCategory()
	{
		if (_consecutiveInvisiblePlatforms < 3)
		{
			int randomNumber = rand() % 101 + 1;
			int invisiblePlatformProbability = (90 - log2(1 + _deletedPlatforms / DIFFICULTY_LEVEL) * 10);

			if (randomNumber > invisiblePlatformProbability && randomNumber % 2 == 0)
			{
				_consecutiveInvisiblePlatforms++;
				return Platform::INVISIBLE;
			}
			else if (randomNumber > invisiblePlatformProbability)
			{
				_consecutiveInvisiblePlatforms++;
				return Platform::BREAKING;
			}
			else return GenerateBounceablePlatformCategory();
		}
		else return GenerateBounceablePlatformCategory();

	}

	void Platform::SpawnPlatform()
	{
		if (platforms.size() > MAX_PLATFORMS) return;

		float randomWidth = CalculateRandomWidth(_platformWidth);

		platform previousPlatform = platforms.back();
		
		category platformCategory = GeneratePlatformCategory();

		switch(platformCategory)
		{
			case Platform::DEFAULT:
				AddDefaultPlatform(randomWidth, previousPlatform.platformSprite.getGlobalBounds().top);
				break;

			case Platform::BOOSTER:
				AddBoosterPlatform(randomWidth, previousPlatform.platformSprite.getGlobalBounds().top);
				break;

			case Platform::MOVING:
				AddMovingPlatform(randomWidth, previousPlatform.platformSprite.getGlobalBounds().top);
				break;

			case Platform::BREAKING:
				AddBreakingPlatform(randomWidth, previousPlatform.platformSprite.getGlobalBounds().top);
				break;
			
			case Platform::INVISIBLE:
				AddInvisiblePlatform(randomWidth, previousPlatform.platformSprite.getGlobalBounds().top);
				break;
			
			default:
				break;
		}
	}

	void Platform::AddDefaultPlatform(float randomWidth, float prevTop)
	{
		sf::Sprite platformSprite(_data->assets.GetTexture("Platform"));

		platformSprite.setPosition(randomWidth, prevTop - _platformHeight * 1.2);
		platforms.push_back(platform(platformSprite, Platform::DEFAULT));
	}

	void Platform::AddBoosterPlatform(float randomWidth, float prevTop)
	{
		sf::Sprite platformSprite(_data->assets.GetTexture("Booster Platform"));

		platformSprite.setPosition(randomWidth, prevTop - _platformHeight * 1.2);	
		platforms.push_back(platform(platformSprite, Platform::BOOSTER));
	}

	void Platform::AddMovingPlatform(float randomWidth, float prevTop)
	{
		sf::Sprite platformSprite(_data->assets.GetTexture("Moving Platform"));

		platformSprite.setPosition(randomWidth, prevTop - _platformHeight * 1.2);
		platforms.push_back(platform(platformSprite, Platform::MOVING, Platform::LEFT));
	}

	void Platform::AddBreakingPlatform(float randomWidth, float prevTop)
	{
		sf::Sprite platformSprite(_data->assets.GetTexture("Breaking Platform"));

		platformSprite.setPosition(randomWidth, prevTop - _platformHeight * 1.2);
		platforms.push_back(platform(platformSprite, Platform::BREAKING));
	}

	void Platform::AddInvisiblePlatform(float randomWidth, float prevTop)
	{
		sf::Sprite platformSprite(_data->assets.GetTexture("Platform"));

		platformSprite.setPosition(randomWidth, prevTop - _platformHeight * 1.2);
		platformSprite.setColor(sf::Color(0, 0, 0, 0));
		platforms.push_back(platform(platformSprite, Platform::INVISIBLE));
	}

	void Platform::MovePlatformsX()
	{
		for (auto &platform : platforms)
		{
			if (platform.platformCategory == Platform::MOVING)
			{
				switch(platform.platformDirection)
				{
					case Platform::LEFT:
						if (platform.platformSprite.getPosition().x <= 0.0f)
						{
							platform.platformDirection = Platform::RIGHT;
							break;
						}
						else platform.platformSprite.move(-PLATFORM_MOVEMENT_SPEED, 0);
						break;

					case Platform::RIGHT:
						if (platform.platformSprite.getPosition().x + _platformWidth >= _data->window.getSize().x)
						{
							platform.platformDirection = Platform::LEFT;
							break;
						}
						else platform.platformSprite.move(PLATFORM_MOVEMENT_SPEED, 0);
						break;

					default:
						break;
				}
			}
		}
	}


	void Platform::MovePlatformsY(float velocity)
	{
		if (platforms.at(0).platformSprite.getPosition().y > _data->window.getSize().y + platforms.at(0).platformSprite.getGlobalBounds().height)
		{
			platforms.erase(platforms.begin());
			_deletedPlatforms++;
		}
		for (auto &platform : platforms)
		{
			platform.platformSprite.move(0, velocity);
		}
	}

	void Platform::DrawPlatforms()
	{
		for (auto &platform : platforms)
		{
			_data->window.draw(platform.platformSprite);
		}
	}
}