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

        void Draw();

	private:
		GameDataRef _data;
	};
}