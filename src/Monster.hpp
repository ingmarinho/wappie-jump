#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Game.hpp"

/// @file

namespace WappieJump
{
	/// Monster
	///
	/// A monster is a screen object that goes back and forth
	/// on the screen, colliding with a monster will cause the player to die.
	class Monster
	{
		/// Monster directions
		enum direction
		{
			RIGHT,
			LEFT,
			NONE
		};
		/// Saves all the data about the monsters current state
		struct monster
		{
			sf::Sprite monsterSprite;
			bool collided = false;
			int fadeValue = 255;
			direction monsterDirection = LEFT;
		};

	public:
		/// Construct by providing GameDataRef
		Monster(GameDataRef data);
		/// Sets the new position of the monster
		void AddCoronaMonster(float randomWidth, float invisiblePlatY);
		/// Returns true if the monster is currently on the screen
		bool Exists();
		/// Returns the monster Sprite
		sf::Sprite GetMonsterSprite();
		/// Draws the monster on the screen
		void DrawMonster();
		/// Returns a random X position
		float CalculateRandomWidth(float monsterWidth);
		/// Moves the monster on the Y-axis
		void MoveMonsterY(float velocity);
		/// Calculates the probability of spwaning a monster
		void SpawnMonster(float invisiblePlatY);
		/// Moves the monster on the X-axis
		void MoveMonsterX();

	private:
		GameDataRef _data;
		monster corona;
		sf::Sprite monsterSprite;
		float _monsterWidth;
		float _monsterHeight;
		bool exist = false;
	};

}
