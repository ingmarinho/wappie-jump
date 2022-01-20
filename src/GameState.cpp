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
		_data->assets.LoadFont("Font", FONT_FILEPATH);

		collision = new Collision(_data);
		platform = new Platform(_data);
		player = new Player(_data);
		score = new Score(_data);

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
		platform->SpawnPlatform();
		score->UpdateScore(platform->GetDeletedPlatforms() * 10);

		if (_player.getPosition().x > _data->window.getSize().x) player->SetPlayerPosition(-_player.getGlobalBounds().width, _player.getPosition().y);
		else if (_player.getPosition().x + _player.getGlobalBounds().width < 0) player->SetPlayerPosition(_data->window.getSize().x, _player.getPosition().y);

		_platforms = platform->GetPlatformsVector();
		_player = player->GetPlayerSprite();

		if (_player.getPosition().y < SCREEN_HEIGHT * 0.4f && (player->GetPlayerMovement() == Player::RISING))
		{
			if (!_hasProgressed) _hasProgressed = true;
			
			_platformVelocityY = player->GetPlayerVelocityY();
			player->SetPlayerVelocityY(2.0f);
			player->SetPlayerMovement(Player::FLOATING);
		}

		if (_platformVelocityY > 0) player->SetPlayerMovement(Player::FALLING);

		if (player->GetPlayerMovement() == Player::FLOATING)
		{
			_platformVelocityY += GRAVITY;
			platform->MovePlatforms(-_platformVelocityY);
		}
		else if (player->GetPlayerMovement() == Player::FALLING)
		{
			for (auto &platform : _platforms)
			{
				if (platform.platformCategory != Platform::INVISIBLE && collision->CheckPlatformBounceCollision(platform.platformSprite, _player))
				{
					player->SetPlayerMovement(Player::JUMPING);
					break;
				}
			}
		}

		// bottom window jumping
		if (!_hasProgressed && collision->CheckWindowBottomBounceCollision(_player)) player->SetPlayerMovement(Player::JUMPING);
	}

	void GameState::Draw(float dt)
	{
		_data->window.clear(sf::Color::Black);

		_data->window.draw(_background);

		platform->DrawPlatforms();

		player->Draw();

		score->Draw();

		_data->window.display();
	}
}