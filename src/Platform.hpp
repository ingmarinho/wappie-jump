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
			INVISIBLE
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

		int GetDeletedPlatforms();
		std::vector<platform>& GetPlatformsVector();
		float CalculateRandomWidth(float x);
		void SpawnPlatform();
		void SpawnFirstPlatform();
		void SpawnMovingPlatform();
		void SpawnInvisiblePlatform();
		void AddInvisiblePlatform(sf::Sprite &platformSprite);
		void AddDefaultPlatform(sf::Sprite &platformSprite);
		void MovePlatforms(float dt);
		void DrawPlatforms();

		sf::Sprite getStaticPlatform();
		void SpawnStaticPlatform(); 

	private:
		GameDataRef _data;
		std::vector<platform> platforms;
		
		long long int _deletedPlatforms = 0;
		int _consecutiveInvisiblePlatforms = 0;
	};
}