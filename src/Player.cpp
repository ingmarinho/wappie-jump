#include "Player.hpp"

namespace Sonar
{
    Player::Player(GameDataRef data) : _data(data)
    {
        sf::Sprite _playerSprite(_data->assets.GetTexture("Player"));
		sf::Sprite _playerSpriteMirrored(_data->assets.GetTexture("Player Mirrored"));
    }

    void Player::Draw()
	{
		_data->window.draw(_playerSprite);
        _data->window.draw(_playerSpriteMirrored);
	}

    void Player::Animate(float dt)
    {
        
    }

    void Player::Update(float dt)
    {

    }
}