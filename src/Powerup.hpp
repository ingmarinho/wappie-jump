#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.hpp"

#include "DEFINITIONS.hpp"

namespace WappieJump
{
	class Powerup
	{
	public:
		Powerup(GameDataRef data);
		
		float CalculateRandomWidth();
		void SpawnPowerup();
        void Draw();

	private:
		GameDataRef _data;

		sf::Sprite _powerup;
		float _powerupWidth;
		float _powerupHeight;
	};
}