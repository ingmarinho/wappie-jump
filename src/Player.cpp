#include "Player.hpp"

namespace Sonar
{
    Player::Player(GameDataRef data) : _data(data)
    {
        
    }

    void Player::Draw()
	{
		_data->window.draw(_playerSprite);
        _data->window.draw(_playerSpriteMirrored);
	}

    void Player::Animate(float dt)
    {
        _playerCurrent = _playerSpriteMirrored;
    }

    void Player::Update(float dt)
    {

    }
}