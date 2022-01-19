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

		collision = new Collision();
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
		// platform->SpawnStaticPlatform();
		player->Update(dt);
		
		_platforms = platform->GetPlatformsVector();
		_player = player->getPlayerSprite();

		for (auto &platform : _platforms)
		{
			if (collision->CheckPlayerBounceCollision(platform.platformSprite, _player))
			{
				player->SetPlayerMovement(Player::JUMPING);
				break;
			}

		}

		// platform->SpawnPlatform();
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