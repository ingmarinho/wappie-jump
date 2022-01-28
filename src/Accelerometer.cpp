#include "Accelerometer.hpp"

namespace WappieJump
{
    int Accelerometer::AlignObjectCenterX(sf::Sprite object)
    {
        return SCREEN_WIDTH / 2 - object.getGlobalBounds().width / 2;
    }

    int Accelerometer::AlignObjectCenterY(sf::Sprite object)
    {
        return SCREEN_HEIGHT / 2 - object.getGlobalBounds().height / 2;
    }


    Accelerometer::Accelerometer(GameDataRef data) : _data(data)
	{
        _data->assets.LoadFont("Font", FONT_FILEPATH);
        
        _speedText.setFont(_data->assets.GetFont("Font"));
        _speedText.setString("0");
		_speedText.setCharacterSize(100);
		_speedText.setFillColor(sf::Color::White);
		_speedText.setPosition(SCREEN_WIDTH / 4, SCREEN_HEIGHT * 0.1);
	}



    void Accelerometer::SetSpeed(sf::Vector2f velocity)
    {
        _speedText.setString(std::to_string(sqrt(pow(velocity.x) + pow(velocity.y))));
    }

    void Accelerometer::Draw()
    {
        _data->window.draw(_speedText);
    }

}