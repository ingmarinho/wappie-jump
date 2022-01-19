#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace Sonar
{
	enum category
	{
		DEFAULT,
		BOOSTER,
		INVISBLE
	};

	struct platform
	{
		sf::Sprite platformSprite;
		category platformCategory;

		platform(sf::Sprite platformSprite, category platformCategory)
			: platformSprite(platformSprite), platformCategory(platformCategory)
		{}
	};

	class Platform
	{
	public:
		Platform(GameDataRef data);

		float CalculateRandomWidth(float x);
		void SpawnPlatform();
		void SpawnFirstPlatform();
		void SpawnMovingPlatform();
		void SpawnInvisiblePlatform();
		void MovePlatforms(float dt);
		void DrawPlatforms();
		void RandomisePipeOffset();

	private:
		GameDataRef _data;
		std::vector<platform> platforms;
		std::vector<platform> platformsToDelete;

		int _platformWidth;
		int _maxWidth;
	};
}