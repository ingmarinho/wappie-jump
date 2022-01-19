#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace Sonar
{
	class Platform
	{
	public:
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
	public:
		Platform(GameDataRef data);

		std::vector<platform>& GetPlatformsVector();
		float CalculateRandomWidth(float x);
		void SpawnPlatform();
		void SpawnFirstPlatform();
		void SpawnMovingPlatform();
		void SpawnInvisiblePlatform();
		void MovePlatforms(float dt);
		void DrawPlatforms();

		sf::Sprite getStaticPlatform();
		void SpawnStaticPlatform(); 

	private:
		GameDataRef _data;
		std::vector<platform> platforms;
		std::vector<platform> platformsToDelete;
		
		int _platformWidth;
		int _maxWidth;
	};
}