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
        void SetSpeed(float x, float y);
        void Draw();
		
	private:
		GameDataRef _data;
		sf::Sprite _speedometer;
		sf::RectangleShape _indicator;
		float _indicatorY;
		float _indicatorX;
        // sf::Text _speedText;
	};
}