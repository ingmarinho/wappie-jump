#include "Player.hpp"

namespace Sonar
{
	Player::Player(GameDataRef data, Platform* platform, Collision* collision) : _data(data), platform(platform), collision(collision)
	{
		_player.setTexture(_data->assets.GetTexture("Player"));
		_player.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2.2);
	}

	void Player::setPlayerTexture(const sf::Texture &texture)
	{
		_player.setTexture(texture);
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
		switch (playerMovement)
		{
		case JUMPING:
			_velocity.y = -20;
			_player.move(0, _velocity.y);

			playerMovement = FALLING;
			break;
			

		case FALLING:
			_velocity.y += _gravity;
			_player.move(0, _velocity.y);
			if (collision->CheckPlayerBounceCollision(platform->getStaticPlatform(), _player)) playerMovement = JUMPING;

			break;
		}
	}
}