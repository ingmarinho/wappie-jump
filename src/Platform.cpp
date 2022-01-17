#include "Platform.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace Sonar
{
	Platform::Platform(GameDataRef data) : _data(data)
	{
		_landHeight = _data->assets.GetTexture("Land").getSize().y;
		_platformSpawnXOffset = 0;
	}

	void Platform::SpawnPlatform()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Platform"));

		sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getLocalBounds().height - _platformSpawnXOffset);

		platformSprites.push_back(sprite);
	}

	void Platform::SpawnMovingPlatform()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Platform"));

		sprite.setPosition(_data->window.getSize().x, -_platformSpawnXOffset);

		platformSprites.push_back(sprite);
	}

	void Platform::SpawnInvisiblePlatform()
	{
		sf::Sprite sprite(_data->assets.GetTexture("Platform"));

		sprite.setPosition(_data->window.getSize().x, -_platformSpawnXOffset);
		sprite.setColor(sf::Color(0, 0, 0, 0));

		platformSprites.push_back(sprite);
	}

	void Platform::MovePlatforms(float dt)
	{
		for ( int i = 0; i < platformSprites.size(); i++)
		{
			if (platformSprites.at(i).getPosition().y < 0 - platformSprites.at(i).getLocalBounds().height)
			{
				platformSprites.erase( platformSprites.begin( ) + i );
			}
			else
			{
				sf::Vector2f position = platformSprites.at(i).getPosition();
				float movement = PIPE_MOVEMENT_SPEED * dt;

				platformSprites.at(i).move(-movement, 0);
			}
		}
	}

	void Platform::DrawPlatforms()
	{
		for (unsigned short int i = 0; i < platformSprites.size(); i++)
		{
			_data->window.draw(platformSprites.at(i));
		}
	}

	void Platform::RandomisePipeOffset()
	{
		_platformSpawnXOffset = rand() % (_landHeight + 1);
	}
}