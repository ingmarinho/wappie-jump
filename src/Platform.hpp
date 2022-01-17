#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace Sonar
{
	class Platform
	{
	public:
		Platform(GameDataRef data);

		void SpawnPlatform();
		void SpawnMovingPlatform();
		void SpawnInvisiblePlatform();
		void MovePlatforms(float dt);
		void DrawPlatforms();
		void RandomisePipeOffset();

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> platformSprites;
		std::vector<sf::Sprite > platformsToDelete;

		int _landHeight;
		int _platformSpawnXOffset;

	};
}