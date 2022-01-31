#include "Powerup.hpp"

namespace WappieJump
{
    Powerup::Powerup(GameDataRef data) : _data(data)
	{
        _powerup.setTexture(_data->assets.GetTexture("Vaccine Powerup"));
	}

    

    void Draw()
    {

    }

}