#include "Platform.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace Sonar
{
	Platform::Platform(GameDataRef data) : _data(data)
	{
		SpawnFirstPlatform();
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
		if (platforms.size() > 17) return;

		sf::Sprite platformSprite(_data->assets.GetTexture("Platform"));

		float randomWidth = CalculateRandomWidth(platformSprite.getGlobalBounds().width);

		platform previousPlatform = platforms.back();
		int previousPlatformTop = previousPlatform.platformSprite.getGlobalBounds().top;

		platformSprite.setPosition(randomWidth, previousPlatformTop - platformSprite.getGlobalBounds().height * 1.2); // random hoogtes

		platforms.push_back(platform(platformSprite, DEFAULT));
	}

	// void Platform::SpawnMovingPlatform()
	// {
	// 	sf::Sprite sprite(_data->assets.GetTexture("Platform"));

	// 	sprite.setPosition(_data->window.getSize().x, -_platformSpawnXOffset);

	// 	platformSprites.push_back(sprite);
	// }

	// void Platform::SpawnInvisiblePlatform()
	// {
	// 	sf::Sprite sprite(_data->assets.GetTexture("Platform"));

	// 	sprite.setPosition(_data->window.getSize().x, -_platformSpawnXOffset);
	// 	sprite.setColor(sf::Color(0, 0, 0, 0));

	// 	platformSprites.push_back(sprite);
	// }

	void Platform::MovePlatforms(float dt)
	{
		for ( unsigned int i = 0; i < platforms.size(); i++)
		{
			if (platforms.at(i).platformSprite.getPosition().y > _data->window.getSize().y + platforms.at(i).platformSprite.getGlobalBounds().height)
			{
				platforms.erase( platforms.begin( ) + i );
			}
			else
			{
				float movement = 200.0f * dt;
				platforms.at(i).platformSprite.move(0, movement);
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

	void Platform::RandomisePipeOffset()
	{
		// _platformSpawnYOffset = rand() % (_landHeight + 1);
	}
}