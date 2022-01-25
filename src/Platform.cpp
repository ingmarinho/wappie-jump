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

	std::vector<Platform::platform> &Platform::GetPlatformsVector()
	{
		return platforms;
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

	void Platform::SpawnPlatform()
	{
		if (platforms.size() > MAX_PLATFORMS) return;

		float randomWidth = CalculateRandomWidth(_platformWidth);

		platform previousPlatform = platforms.back();
		
		category platformCategory;


		if (_consecutiveInvisiblePlatforms < 3) platformCategory = Platform::INVISIBLE;
		else 
		{
			platformCategory = Platform::DEFAULT;
			_consecutiveInvisiblePlatforms = 0;
			
			// hier moet algoritme om te kiezen tussen default/booster/moving
			// platformCategory = 
		}

		platformCategory = Platform::DEFAULT;


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
			
			case Platform::INVISIBLE:
			{
				int randomNumber = rand() % 101 + 1;
				int invisiblePlatformProbability = (90 - log2(1 + _deletedPlatforms / DIFFICULTY_LEVEL) * 10);

				if (randomNumber > invisiblePlatformProbability)
				{
					_consecutiveInvisiblePlatforms++;
					AddInvisiblePlatform(randomWidth, previousPlatform.platformSprite.getGlobalBounds().top);
				}
				// else SpawnPlatform();
				break;
			}
			default:
				break;
		}
	}

	Platform::direction Platform::DetermineDirection(float randomWidth)
	{
		if (randomWidth + MOVING_PLATFORM_DISTANCE > _data->window.getSize().x) return Platform::LEFT;
		return Platform::RIGHT;
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
		sf::Sprite platformSprite(_data->assets.GetTexture("Platform"));

		platformSprite.setPosition(randomWidth, prevTop - _platformHeight * 1.2);
		platforms.push_back(platform(platformSprite, Platform::MOVING, DetermineDirection(randomWidth)));
	}

	void Platform::AddInvisiblePlatform(float randomWidth, float prevTop)
	{
		sf::Sprite platformSprite(_data->assets.GetTexture("Platform"));
		platformSprite.setPosition(randomWidth, prevTop - _platformHeight * 1.2);
		platformSprite.setColor(sf::Color(0, 0, 0, 0));
		platforms.push_back(platform(platformSprite, Platform::INVISIBLE));
	}


	void Platform::MovePlatforms(float velocity)
	{
		if (platforms.at(0).platformSprite.getPosition().y > _data->window.getSize().y + platforms.at(0).platformSprite.getGlobalBounds().height)
		{
			platforms.erase(platforms.begin());
			_deletedPlatforms++;
		}
		for (unsigned int i = 0; i < platforms.size(); i++)
		{
			platform *currentPlatform = &platforms.at(i);
			currentPlatform->platformSprite.move(0, velocity);
			if (currentPlatform->platformCategory == Platform::MOVING)
			{
				switch(currentPlatform->platformDirection)
				{
					case Platform::LEFT:
						if (currentPlatform->platformSprite.getPosition().x <= currentPlatform->originalXPos && currentPlatform->originalXPos - MOVING_PLATFORM_DISTANCE >= currentPlatform->platformSprite.getPosition().x)
						{
							currentPlatform->platformSprite.move(PLATFORM_MOVEMENT_SPEED, 0);
						}
						else
						{
							
						}
						break;

					case Platform::RIGHT:
						break;

					default:
						break;
				}
			}
		}
	}

	void Platform::DrawPlatforms()
	{
		for (unsigned short int i = 0; i < platforms.size(); i++)
		{
			_data->window.draw(platforms.at(i).platformSprite);
		}
	}
}