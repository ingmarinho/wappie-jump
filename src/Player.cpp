#include "Player.hpp"

namespace Sonar
{
	Player::Player(GameDataRef data) : _data(data)
	{
		_player.setTexture(_data->assets.GetTexture("Player"));
	}

	void Player::setPlayerTexture(const sf::Texture &texture)
	{
		_player.setTexture(texture);
	}

	void Player::Draw()
	{
		_data->window.draw(_player);
	}

	void Player::Animate(float dt)
	{
	}

	void Player::Update(float dt)
	{
		switch (playerMovement)
		{
		case MOVING:

			break;

		case STANDING:

			break;

		case JUMPING:

			break;

		case FALLING:

			break;
		}
	}
}