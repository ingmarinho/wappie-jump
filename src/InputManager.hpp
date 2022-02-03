#pragma once

#include "SFML\Graphics.hpp"
///@file

namespace WappieJump
{
	/// Input Manager
	///
	///	Contains functions that return a boolean on
	/// whether or not a screen object has been interacted with through hardware.

	class InputManager
	{
	public:
		/// Returns a boolean on whether or not a sf::Sprite object has been clicked
		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
		/// Returns a boolean on whether or not a sf::Text object has been clicked
		bool IsTextClicked(sf::Text object, sf::Mouse::Button button, sf::RenderWindow &window);
		/// Returns a vector containing the current mouse coordinates (x, y)
		sf::Vector2i GetMousePosition(sf::RenderWindow &window);
	};
}