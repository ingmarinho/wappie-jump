#include "Accelerometer.hpp"

namespace WappieJump
{
    Accelerometer::Accelerometer(GameDataRef data) : _data(data)
	{
        _data->assets.LoadFont("Font", FONT_FILEPATH);
        _speedText.setFont(_data->assets.GetFont("Font"));
        _speedText.setString("0");
		_speedText.setCharacterSize(100);
		_speedText.setFillColor(sf::Color::White);
		// _speedText.setOrigin(sf::Vector2f(_speedText.getGlobalBounds().width / 2, _speedText.getGlobalBounds().height / 2));
		_speedText.setPosition(SCREEN_WIDTH / 4, SCREEN_HEIGHT * 0.1);
	}



    Accelerometer::SetSpeed() : 

    
}