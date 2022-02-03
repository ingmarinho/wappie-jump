#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Game.hpp"

/// @file

namespace WappieJump
{
	/// A platform
	///
	/// A platform is a screen object that can either go back and forth on the screen or stay stationary.
	/// Colliding with a platform causes different effects based on the platform category.
	class Platform
	{
	public:
		/// Platform categories
		enum category
		{
			DEFAULT,
			BOOSTER,
			MOVING,
			BREAKING,
			SHADOW,
			INVISIBLE
		};
		/// Platform directions
		enum direction
		{
			RIGHT,
			LEFT,
			NONE
		};
		/// Saves all the data about the platforms current state
		struct platform
		{
			sf::Sprite platformSprite;
			category platformCategory;
			direction platformDirection;
			bool collided = false;
			int fadeValue = 255;

			platform(sf::Sprite platformSprite, category platformCategory, direction platformDirection = NONE)
				: platformSprite(platformSprite), platformCategory(platformCategory), platformDirection(platformDirection)
			{}
		};
	public:
		/// Construct by providing GameDataRef
		Platform(GameDataRef data);
		/// Returns the number of consecutive deleted platforms
		int GetDeletedPlatforms();
		/// Returns a reference to platforms in a vector
		std::vector<platform>* GetPlatformsVector();
		/// Returns a certain type of platform (invisible, breaking or bounceable) based on
		/// algorithms stated in the technical documentation
		category GeneratePlatformCategory();
		/// Returns a certain type of bounceable platform (default, moving, or booster) based on
		/// algorithms not stated in the technical documentation but very similar to the one that is.
		category GenerateBounceablePlatformCategory();
		/// Returns a random X position
		float CalculateRandomWidth(float x);
		/// Spawns the generated platforms
		void SpawnPlatform();
		/// Generates the first platform on which the next platforms will be dependent on.
		void SpawnFirstPlatform();
		/// Sets the position and adds it to the vector
		void AddInvisiblePlatform(float randomWidth, float prevTop);
		/// Sets the position and adds it to the vector
		void AddShadowPlatform(float randomWidth, float prevTop);
		/// Sets the position and adds it to the vector
		void AddBreakingPlatform(float randomWidth, float prevTop);
		/// Sets the position and adds it to the vector
		void AddBoosterPlatform(float randomWidth, float prevTop);
		/// Sets the position and adds it to the vector
		void AddMovingPlatform(float randomWidth, float prevTop);
		/// Sets the position and adds it to the vector
		void AddDefaultPlatform(float randomWidth, float prevTop);
		/// Moves the moving and breakable platforms on the X and Y axis respectively and when appropriate
		void MoveOtherPlatforms();
		/// Moves the platforms on the Y axis and deletes the last platform when off-screen
		void MovePlatformsY(float velocity);
		/// Draws the platforms on the screen
		void DrawPlatforms();

	private:
		GameDataRef _data;
		std::vector<platform> platforms;
		
		bool _invisiblePlatform = false;
		float _platformWidth;
		float _platformHeight;
		long long int _deletedPlatforms = 0;
		int _consecutiveInvisiblePlatforms = 0;
	};
}