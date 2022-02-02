#include "Powerup.hpp"

namespace WappieJump
{
    Powerup::Powerup(GameDataRef data) : _data(data)
	{
        _powerup.setTexture(_data->assets.GetTexture("Vaccine Powerup"));
        _powerupWidth = _powerup.getGlobalBounds().width;
        _powerupHeight = _powerup.getGlobalBounds().height;
	}


    float Powerup::CalculateRandomWidth()
	{
		int maxWidth = SCREEN_WIDTH * 0.99f - _powerupWidth;
		return rand() % maxWidth + SCREEN_HEIGHT * 0.005f;
	}

    
    void Powerup::SpawnPowerup()
    {
        // float randomWidth = CalculateRandomWidth();

    }


    void Powerup::Draw()
    {
        _data->window.draw(_powerup);
    }

}