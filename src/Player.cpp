#include "Player.hpp"

namespace Sonar
{
	Player::Player(GameDataRef data) : _data(data)
	{
		_player.setTexture(_data->assets.GetTexture("Player"));
		_player.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2.2);
	}

	sf::Sprite& Player::GetPlayerSprite()
	{
		return _player;
	}

	Player::Movement Player::GetPlayerMovement()
	{
		return _playerMovement;
	}
	
	float Player::GetPlayerVelocityY()
	{
		return _velocity.y;
	}

	void Player::SetPlayerAngle(Angle newPlayerAngle)
	{
		switch (newPlayerAngle)
		{
			case LEFT:
				_player.setTexture(_data->assets.GetTexture("Player"));
				break;

			case RIGHT:
				_player.setTexture(_data->assets.GetTexture("Player Mirrored"));
				break;
		}
	}

	void Player::SetPlayerMovement(Movement newPlayerMovement)
	{
		switch (newPlayerMovement)
		{
			case JUMPING:
				_playerMovement = JUMPING;
				break;

			case RISING:
				_playerMovement = RISING;
				break;

			case FALLING:
				_playerMovement = FALLING;
				break;
		}
	}

	void Player::Draw()
	{
		_data->window.draw(_player);
	}

	void Player::MoveRight()
	{
		_player.move(_velocity.x, 0);
	}

	void Player::MoveLeft()
	{
		_player.move(-_velocity.x, 0);
	}

	void Player::Update(float dt)
	{
		switch (_playerMovement)
		{
		case JUMPING:
			_velocity.y = -20;

			_player.move(0, _velocity.y);

			// std::cout << "JUMPING" << '\n';

			_playerMovement = RISING;

			break;

		case RISING:
			_velocity.y += GRAVITY;

			_player.move(0, _velocity.y);

			// std::cout << "RISING\n";

			if (_velocity.y > 0) _playerMovement = FALLING;

			break;

		case FALLING:
			_velocity.y += GRAVITY;

			_player.move(0, _velocity.y);

			// std::cout << "FALLING\n";

			break;
		}
	}
}