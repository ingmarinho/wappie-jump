#pragma once

#include "SFML\Graphics.hpp"

namespace WappieJump
{
	class InputManager
	{
	public:
		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);

		sf::Vector2i GetMousePosition(sf::RenderWindow &window);
	};
}