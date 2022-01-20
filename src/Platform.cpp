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

		platformSprite.setPosition(randomWidth, _data->window.getSize().y - platformSprite.getGlobalBounds().height);
		platforms.push_back(platform(platformSprite, DEFAULT));
	}

	void Platform::SpawnPlatform()
	{
		if (platforms.size() > MAX_PLATFORMS) return;

		sf::Sprite platformSprite(_data->assets.GetTexture("Platform"));

		float randomWidth = CalculateRandomWidth(platformSprite.getGlobalBounds().width);

		platform previousPlatform = platforms.back();
		int previousPlatformTop = previousPlatform.platformSprite.getGlobalBounds().top;

		platformSprite.setPosition(randomWidth, previousPlatformTop - platformSprite.getGlobalBounds().height * 1.2); // random hoogtes

		// this is the algorithm for spawning random invisible beds
		if (_consecutiveInvisiblePlatforms < 3)
		{
			int randomNumber = rand() % 101 + 1;
			int invisiblePlatformProbability = (_consecutiveInvisiblePlatforms * 10) + (90 - log2(1 + _deletedPlatforms / DIFFICULTY_LEVEL) * 10);

			if (randomNumber > invisiblePlatformProbability)
			{
				AddInvisiblePlatform(platformSprite);
				_consecutiveInvisiblePlatforms++;
			}
			else AddDefaultPlatform(platformSprite);
		}
		else
		{
			AddDefaultPlatform(platformSprite);
			_consecutiveInvisiblePlatforms = 0;
		}
	}

	void Platform::AddDefaultPlatform(sf::Sprite &platformSprite)
	{
		platforms.push_back(platform(platformSprite, Platform::DEFAULT));
	}

	void Platform::AddBoosterPlatform(sf::Sprite &platformSprite)
	{
		platforms.push_back(platform(platformSprite, Platform::BOOSTER));
	}

	void Platform::AddInvisiblePlatform(sf::Sprite &platformSprite)
	{
		platformSprite.setColor(sf::Color(0, 0, 0, 0));
		platforms.push_back(platform(platformSprite, Platform::INVISIBLE));
	}

	// void Platform::AddMovingPlatform()
	// {
	// 	sf::Sprite sprite(_data->assets.GetTexture("Platform"));

	// 	sprite.setPosition(_data->window.getSize().x, -_platformSpawnXOffset);

	// 	platformSprites.push_back(sprite);
	// }


	void Platform::MovePlatforms(float velocity)
	{
		if (platforms.at(0).platformSprite.getPosition().y > _data->window.getSize().y + platforms.at(0).platformSprite.getGlobalBounds().height)
		{
			platforms.erase(platforms.begin());
			_deletedPlatforms++;
		}
		for (unsigned int i = 0; i < platforms.size(); i++)
		{
			platforms.at(i).platformSprite.move(0, velocity);
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