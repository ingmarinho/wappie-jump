#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.hpp"

#include "DEFINITIONS.hpp"

namespace Sonar
{
	class Collision
	{
	public:
		Collision(GameDataRef data);
		bool CheckPlatformBounceCollision(sf::Sprite platform, sf::Sprite player);
		bool CheckWindowBottomBounceCollision(sf::Sprite player);
	private:
		GameDataRef _data;
	};
}