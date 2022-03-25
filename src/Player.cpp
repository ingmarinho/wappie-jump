#include "Player.hpp"

namespace WappieJump
{
	Player::Player(GameDataRef data) : _data(data)
	{
		_player = _data->characterSprite;
		_player.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 100.0f);
	}

	bool Player::hasReachedMaxDistance()
	{
		return _reachedMaxDistance;
	}

	sf::Sprite* Player::GetPlayerSprite()
	{
		return &_player;
	}

	Player::Movement Player::GetPlayerMovement()
	{
		return _playerMovement;
	}

	void Player::SetJumpVelocity(float newVelocity)
	{
		_jumpVelocity = newVelocity;
	}
	
	void Player::SetPlayerPosition(float x, float y)
	{
		_player.setPosition(x, y);
	}

	sf::Vector2f Player::GetPlayerVelocity()
	{
		return _velocity;
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
				if (_playerAngle != Player::LEFT)
				{
					_player.setScale(1, 1);
					_player.move(-_player.getGlobalBounds().width, 0);
					_playerAngle = Player::LEFT;
				}
				break;

			case RIGHT:
				if (_playerAngle != Player::RIGHT)
				{
					_player.setScale(-1, 1);
					_player.move(_player.getGlobalBounds().width, 0);
					_playerAngle = Player::RIGHT;
				}
				break;
		}
	}

	void Player::SetPlayerMovement(Movement newPlayerMovement)
	{
		if (_playerMovement == DEATHFALL) return;

		switch (newPlayerMovement)
		{
			case JUMPING:
				_playerMovement = JUMPING;
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

			case DEATHFALL:
				_playerMovement = DEATHFALL;
				break;
		}
	}

	void Player::ChangePoisonColor()
	{
		if (_poisonFadeValue == 155) return;
		
		_poisonFadeValue += 2.5f;
		_player.setColor(sf::Color(100 + _poisonFadeValue, 255, 100 + _poisonFadeValue, 255));
	}
	
	void Player::SetPoisonColor()
	{	
		_player.setColor(sf::Color(100, 255, 100, 255));
		_poisonFadeValue = 0;
	}

	void Player::SetPlayerDeathColor()
	{	
		_player.setColor(sf::Color(255, 100, 100, 255));
	}

	void Player::Draw()
	{
		_data->window.draw(_player);
	}

	void Player::MoveRight()
	{
		if (_velocity.x < PLAYER_VELOCITY_X_MAX) _velocity.x += PLAYER_ACCELERATION_X;
		_player.move(_velocity.x, 0);
	}

	void Player::MoveLeft()
	{
		if (_velocity.x > -PLAYER_VELOCITY_X_MAX) _velocity.x -= PLAYER_ACCELERATION_X;
		_player.move(_velocity.x, 0);
	}

	void Player::Decelleration()
	{
		if (_velocity.x > 0.0f) 
		{
			_velocity.x -= PLAYER_ACCELERATION_X;
			// if (_velocity.x < 0.0f) _velocity.x = 0.0f;
		}
		else if (_velocity.x < 0.0f) 
		{
			_velocity.x += PLAYER_ACCELERATION_X;
			// if (_velocity.x > 0.0f) _velocity.x = 0.0f;
		}
		
		if (_velocity.x != 0.0f) _player.move(_velocity.x, 0);
	}

	void Player::Update()
	{
		switch (_playerMovement)
		{
		case JUMPING:
			_velocity.y = _jumpVelocity;

			_player.move(0, _velocity.y);

			_playerMovement = RISING;

			break;

		case RISING:
			if (_velocity.y + GRAVITY > 0) _velocity.y -= GRAVITY;
			else _velocity.y += GRAVITY;

			_player.move(0, _velocity.y);

			if (_velocity.y == 0.0f)
			{
				_reachedMaxDistance = true;
				_playerMovement = FALLING;
			}
		
			break;

		case FLOATING:
			break;

		case FALLING:
			_reachedMaxDistance = false;
			_velocity.y += GRAVITY;

			_player.move(0, _velocity.y);

			break;
		case DEATHFALL:
			if (_velocity.y < -10.0f) _velocity.y = -10.0f;

			_velocity.y += GRAVITY;

			_player.move(0, _velocity.y);

			break;
		}
	}
}