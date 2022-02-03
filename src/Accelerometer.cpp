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
        
        _indicator.setSize(sf::Vector2f(30.0f, 3.0f));
        _indicatorY = _speedometer.getPosition().y + _speedometer.getGlobalBounds().height - 3.0f;
        _indicatorX = _speedometer.getPosition().x;
	}


    
    void Accelerometer::SetSpeed(float x, float y) 
    {
        _indicator.setPosition(_indicatorX, _indicatorY - (std::abs(static_cast<int>(x)) + std::abs(static_cast<int>(y))) * 2.8f);
    }

    
    void Accelerometer::Draw()
    {
        _data->window.draw(_speedometer);
        _data->window.draw(_indicator);
    }

}