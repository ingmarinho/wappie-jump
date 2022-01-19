#pragma once

#include <SFML/Graphics.hpp>

namespace Sonar
{
	class Collision
	{
	public:
		bool CheckPlayerBounceCollision(sf::Sprite platform, sf::Sprite player);
	};
}