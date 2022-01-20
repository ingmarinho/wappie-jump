#include "GameState.hpp"

namespace Sonar
{
	GameState::GameState(GameDataRef data) : _data(data)
	{
	}

	void GameState::Init()
	{
		_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Platform", PLATFORM_FILEPATH);
		_data->assets.LoadTexture("Player", CHAR6_FILEPATH);
		_data->assets.LoadTexture("Player Mirrored", CHAR6MIR_FILEPATH);

		collision = new Collision(_data);
		platform = new Platform(_data);
		player = new Player(_data);

		_background.setTexture(_data->assets.GetTexture("Game Background"));
	}

	void GameState::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			player->SetPlayerAngle(Player::LEFT);
			player->MoveLeft();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			player->SetPlayerAngle(Player::RIGHT);
			player->MoveRight();
		}
	}

	void GameState::Update(float dt)
	{
		player->Update(dt);
		
		_platforms = platform->GetPlatformsVector();
		_player = player->GetPlayerSprite();

		if (player->GetPlayerMovement() == Player::FALLING)
		{
			for (auto &platform : _platforms)
			{
				if (collision->CheckPlatformBounceCollision(platform.platformSprite, _player))
				{
					player->SetPlayerMovement(Player::JUMPING);
					break;
				}
			}
		}

		if (_player.getPosition().y < SCREEN_HEIGHT * 0.8 && (player->GetPlayerMovement() == Player::RISING))
		{
			platform->MovePlatforms(-player->GetPlayerVelocityY() * 1.1);
		}

		// bottom window jumping
		if (collision->CheckWindowBottomBounceCollision(_player)) player->SetPlayerMovement(Player::JUMPING);

		platform->SpawnPlatform();
		// platform->MovePlatforms(dt);
	}

	void GameState::Draw(float dt)
	{
		_data->window.clear(sf::Color::Black);

		_data->window.draw(_background);

		player->Draw();

		platform->DrawPlatforms();

		_data->window.display();
	}
}