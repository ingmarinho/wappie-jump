#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Game.hpp"

namespace WappieJump
{
	class Platform
	{
	public:
		enum category
		{
			DEFAULT,
			BOOSTER,
			MOVING,
			BREAKING,
			INVISIBLE
		};
		enum direction
		{
			RIGHT,
			LEFT,
			NONE
		};

		struct platform
		{
			sf::Sprite platformSprite;
			category platformCategory;
			direction platformDirection;

			platform(sf::Sprite platformSprite, category platformCategory, direction platformDirection = NONE)
				: platformSprite(platformSprite), platformCategory(platformCategory), platformDirection(platformDirection)
			{}
		};
	public:
		Platform(GameDataRef data);

		int GetDeletedPlatforms();
		std::vector<platform>* GetPlatformsVector();
		category GeneratePlatformCategory();
		category GenerateBounceablePlatformCategory();
		float CalculateRandomWidth(float x);
		void SpawnPlatform();
		void SpawnFirstPlatform();
		void AddInvisiblePlatform(float randomWidth, float prevTop);
		void AddBreakingPlatform(float randomWidth, float prevTop);
		void AddBoosterPlatform(float randomWidth, float prevTop);
		void AddMovingPlatform(float randomWidth, float prevTop);
		void AddDefaultPlatform(float randomWidth, float prevTop);
		void MovePlatformsX();
		void MovePlatformsY(float velocity);
		void DrawPlatforms();

	private:
		GameDataRef _data;
		std::vector<platform> platforms;
		
		float _platformWidth;
		float _platformHeight;
		long long int _deletedPlatforms = 0;
		int _consecutiveInvisiblePlatforms = 0;
	};
}