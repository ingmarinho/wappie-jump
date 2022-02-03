#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.hpp"

#include "DEFINITIONS.hpp"

/// @file

namespace WappieJump
{
	///	Alignment
	///
	/// The alignment class is used for aligning screen objects. 
	class Alignment
	{
	public:
		/// Construct by providing GameDataRef
		Alignment(GameDataRef data);
		/// Returns the X position to center an object on the X-axis
        int AlignObjectCenterX(sf::Sprite object); 
		/// Returns the Y position to center an object on the Y-axis
        int AlignObjectCenterY(sf::Sprite object); 

	private:
		GameDataRef _data;
	};
}