#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#include "Game.hpp"

#include "DEFINITIONS.hpp"

namespace WappieJump
{
	class Accelerometer
	{
	public:
		Accelerometer(GameDataRef data);
		
	private:
		GameDataRef _data;
        sf::Text _speedText;
	};
}