#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.hpp"

#include "DEFINITIONS.hpp"

namespace WappieJump
{
	class Alignment
	{
	public:
		Alignment(GameDataRef data);

        int AlignObjectCenterX(sf::Sprite object);
        int AlignObjectCenterY(sf::Sprite object);

	private:
		GameDataRef _data;
	};
}