#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.hpp"

#include "DEFINITIONS.hpp"

/// @file

namespace WappieJump
{
	/// Collision
	///
	/// Collision is responsible for checking colliding objects. 
	class Collision
	{
	public:
		/// construct by providing GameDataRef
		Collision(GameDataRef data);
		/// checks if the player is colliding with a platform
		bool CheckPlatformBounceCollision(sf::Sprite platform, sf::Sprite player);
		/// checks if the player is fallen out the screen
		bool CheckWindowBottomBounceCollision(sf::Sprite player);
		/// checks if the player is colliding with a monster
		bool CheckMonsterCollision(sf::Sprite monster, sf::Sprite player);
	private:
		GameDataRef _data;
	};
}