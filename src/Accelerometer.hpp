/// @file

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

#include "Game.hpp"

#include "DEFINITIONS.hpp"

/// @file

namespace WappieJump
{
	/// Accelerometer
	///
	/// The Accelerometer is a little tool that visualizes the players speed (Y Velocity).
	class Accelerometer
	{
	public:
		/// Construct by providing GameDataRef
		Accelerometer(GameDataRef data);
		/// Returns the X position to center an object on the X-axis
        int AlignObjectCenterX(sf::Sprite object); 
		 /// Returns the Y position to center an object on the Y-axis
        int AlignObjectCenterY(sf::Sprite object);
		/// Sets the position for the accelerometers indicator with an absolute value
        void SetSpeed(float x, float y); 
		/// Draws the sprites
        void Draw(); 
		
	private:
		GameDataRef _data;
		sf::Sprite _speedometer;
		sf::RectangleShape _indicator;
		float _indicatorY;
		float _indicatorX;
        
	};
}