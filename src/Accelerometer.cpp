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
        _speedometer.setTexture(_data->assets.GetTexture("Speedometer"));

        _speedometer.setScale(2.0f, 2.0f);
        _speedometer.setPosition(SCREEN_WIDTH - _speedometer.getGlobalBounds().width, SCREEN_HEIGHT * 0.2);
        
        _indicator.setSize(sf::Vector2f(30.0f, 1.0f));
        // _indicator.setPosition(_speedometer.getPosition().x, _speedometer.getPosition().y + _speedometer.getGlobalBounds().height - 5.0f);

        // _data->assets.LoadFont("Font", FONT_FILEPATH);
        
        // _speedText.setFont(_data->assets.GetFont("Font"));
        // _speedText.setString("0");
		// _speedText.setCharacterSize(100);
		// _speedText.setFillColor(sf::Color::White);
		// _speedText.setPosition(SCREEN_WIDTH / 4, SCREEN_HEIGHT * 0.1);
	}



    // void Accelerometer::SetSpeed(float x, float y)
    // {
    //     _speedText.setString(std::to_string(static_cast<int>(sqrt(pow(x, 2) + pow(y, 2)))));
    // }
    void Accelerometer::SetSpeed(float x, float y)
    {
        _indicator.setPosition(_speedometer.getPosition().x, _speedometer.getPosition().y + _speedometer.getGlobalBounds().height - (x + y));
    }

    void Accelerometer::Draw()
    {
        _data->window.draw(_speedometer);
        _data->window.draw(_indicator);
    }

}