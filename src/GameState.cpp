#include "GameState.hpp"

namespace WappieJump
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

	void GameState::Update()
	{
		player->Update();
		platform->SpawnPlatform();
		score->UpdateScore(platform->GetDeletedPlatforms() * 10);

		if (_player.getPosition().x > _data->window.getSize().x) player->SetPlayerPosition(-_player.getGlobalBounds().width, _player.getPosition().y);
		else if (_player.getPosition().x + _player.getGlobalBounds().width < 0)player->SetPlayerPosition(_data->window.getSize().x, _player.getPosition().y);

		_platforms = platform->GetPlatformsVector();
		_player = player->GetPlayerSprite();

		float heightLimit = _data->window.getSize().y * 0.4f;
		// float playerDistanceToHeightLimit = heightLimit -( _player.getPosition().y + _player.getGlobalBounds().height);

		if (_player.getPosition().y < heightLimit && player->GetPlayerMovement() == Player::RISING)
		{
			if (!_hasProgressed)_hasProgressed = true;

			_platformVelocityY = player->GetPlayerVelocityY();
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
				if (platform.platformCategory == Platform::INVISIBLE) continue;

				if (collision->CheckPlatformBounceCollision(platform.platformSprite, _player))
				{
					switch (platform.platformCategory)
					{
					case Platform::DEFAULT:
						player->SetPlayerMovement(Player::JUMPING);
						break;

					case Platform::BOOSTER:
						player->SetPlayerMovement(Player::BOOSTJUMPING);
						break;

					case Platform::INVISIBLE: // case is unecessary but required by c++
						break;
					}
					break;
				}
			}
		}

		// calculate distance to height limit (for player), jump to limit, extend remainder of jump by moving platforms down and making player float 
		// if the distance to height limit would become negative by jumping, float instead and simulate jump by moving platforms down
		// calculate velocity needed to get to specific point

		// float velocity = std::sqrt(2.0f * (GRAVITY * playerDistanceToHeightLimit));

		// float distance = heightLimit - (_player.getPosition().y + _player.getGlobalBounds().height);
		// std::cout << heightLimit << '\n';
		// std::cout << distance << '\n';

		// bottom window jumping
		if (!_hasProgressed && collision->CheckWindowBottomBounceCollision(_player)) player->SetPlayerMovement(Player::JUMPING);

		// check out of screen death (should change state to gameover state, game close is temporary)
		if (_player.getPosition().y - _player.getGlobalBounds().height > _data->window.getSize().y) _data->isRunning = false;
	}

	void GameState::Draw()
	{
		_data->window.clear(sf::Color::Black);

		_data->window.draw(_background);

		platform->DrawPlatforms();

		player->Draw();

		score->Draw();

		_data->window.display();
	}
}