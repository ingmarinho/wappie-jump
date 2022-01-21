#include "Player.hpp"

namespace WappieJump
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

	void Player::SetJumpVelocity(float newVelocity)
	{
		_jumpVelocity = newVelocity;
	}
	
	void Player::SetBoostJumpVelocity(float newVelocity)
	{
		_jumpVelocity = newVelocity;
	}
	
	void Player::SetPlayerPosition(float x, float y)
	{
		_player.setPosition(x, y);
	}

	float Player::GetPlayerVelocityY()
	{
		return _velocity.y;
	}

	void Player::SetPlayerVelocityY(float velocity)
	{
		_velocity.y = velocity;
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

			case BOOSTJUMPING:
				_playerMovement = BOOSTJUMPING;
				break;

			case RISING:
				_playerMovement = RISING;
				break;

			case FLOATING:
				_playerMovement = FLOATING;
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

	void Player::Update()
	{
		switch (_playerMovement)
		{
		case JUMPING:
			_distance = _player.getPosition().y;

			_velocity.y = _jumpVelocity;

			_player.move(0, _velocity.y);

			_playerMovement = RISING;

			break;

		case BOOSTJUMPING:
			_velocity.y = _boosterJumpVelocity;

			_player.move(0, _velocity.y);

			_playerMovement = RISING;

			break;

		case RISING:
			_velocity.y += GRAVITY;

			_player.move(0, _velocity.y);

			if (_velocity.y >= 0) _playerMovement = FALLING;
		
			break;

		case FLOATING:
			_velocity.y = 0.0f;
			break;

		case FALLING:
			_velocity.y += GRAVITY;

			_player.move(0, _velocity.y);

			break;
		}
	}
}