#include "Platform.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace Sonar
{
	Platform::Platform(GameDataRef data) : _data(data)
	{
		SpawnFirstPlatform();
	}

	int Platform::getPlatformAmount()
	{
		return platforms.size();
	}

	void Platform::SpawnFirstPlatform()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Platform"));

		int width = _data->window.getSize().x * 0.99f - sprite.getGlobalBounds().width;
		int maxWidth = rand() % width + _data->window.getSize().x * 0.005f;

		sprite.setPosition(maxWidth, _data->window.getSize().y - sprite.getGlobalBounds().height);
		platforms.push_back(platform(sprite, DEFAULT));
	}

	void Platform::SpawnPlatform()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Platform"));

		int width = _data->window.getSize().x * 0.99f - sprite.getGlobalBounds().width;
		int maxWidth = rand() % width + _data->window.getSize().x * 0.005f;

		platform previousPlatform = platforms.back();
		int previousPlatformTop = previousPlatform.platformSprite.getGlobalBounds().top;

		sprite.setPosition(maxWidth, previousPlatformTop - sprite.getGlobalBounds().height * 1.2);

		platforms.push_back(platform(sprite, DEFAULT));
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

	// void Platform::MovePlatforms(float dt)
	// {
	// 	for ( int i = 0; i < platformSprites.size(); i++)
	// 	{
	// 		if (platformSprites.at(i).getPosition().y < 0 - platformSprites.at(i).getLocalBounds().height)
	// 		{
	// 			platformSprites.erase( platformSprites.begin( ) + i );
	// 		}
	// 		else
	// 		{
	// 			sf::Vector2f position = platformSprites.at(i).getPosition();
	// 			float movement = PIPE_MOVEMENT_SPEED * dt;

	// 			platformSprites.at(i).move(-movement, 0);
	// 		}
	// 	}
	// }

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