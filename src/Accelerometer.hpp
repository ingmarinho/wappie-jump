#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

#include "Game.hpp"

#include "DEFINITIONS.hpp"

namespace WappieJump
{
	class Accelerometer
	{
	public:
		Accelerometer(GameDataRef data);

        int AlignObjectCenterX(sf::Sprite object);
        int AlignObjectCenterY(sf::Sprite object);
        void SetSpeed(sf::Vector2f velocity);
        void Draw();
		
	private:
		GameDataRef _data;
        sf::Text _speedText;
	};
}