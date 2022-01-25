#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

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
			const category platformCategory;
			const direction platformDirection;
			direction currentPlatformDirection;
			const float originalXPos;

			platform(sf::Sprite platformSprite, category platformCategory, direction platformDirection = NONE, direction currentPlatformDirection = NONE)
				: platformSprite(platformSprite), platformCategory(platformCategory), platformDirection(platformDirection), currentPlatformDirection(currentPlatformDirection)
			{}
		};
	public:
		Platform(GameDataRef data);

		int GetDeletedPlatforms();
		std::vector<platform>& GetPlatformsVector();
		float CalculateRandomWidth(float x);
		direction DetermineDirection(float randomWidth);
		void SpawnPlatform();
		void SpawnFirstPlatform();
		void AddInvisiblePlatform(float randomWidth, float prevTop);
		void AddBoosterPlatform(float randomWidth, float prevTop);
		void AddMovingPlatform(float randomWidth, float prevTop);
		void AddDefaultPlatform(float randomWidth, float prevTop);
		void MovePlatforms(float velocity);
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