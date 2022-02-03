#include "Alignment.hpp"

namespace WappieJump
{
    Alignment::Alignment(GameDataRef data) : _data(data)
	{
	}

    int Alignment::AlignObjectCenterX(sf::Sprite object) 
    {
        return SCREEN_WIDTH / 2 - object.getGlobalBounds().width / 2;
    }

    int Alignment::AlignObjectCenterY(sf::Sprite object) 
    {
        return SCREEN_HEIGHT / 2 - object.getGlobalBounds().height / 2;
    }
}