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

	// void GameState::Update()
	// {
	// 	player->Update();
	// 	platform->SpawnPlatform();
	// 	score->UpdateScore(platform->GetDeletedPlatforms() * 10);

	// 	if (_player.getPosition().x > _data->window.getSize().x) player->SetPlayerPosition(-_player.getGlobalBounds().width, _player.getPosition().y);
	// 	else if (_player.getPosition().x + _player.getGlobalBounds().width < 0)player->SetPlayerPosition(_data->window.getSize().x, _player.getPosition().y);

	// 	_platforms = platform->GetPlatformsVector();
	// 	_player = player->GetPlayerSprite();

	// 	float heightLimit = _data->window.getSize().y * 0.4f;
	// 	// float playerDistanceToHeightLimit = heightLimit -( _player.getPosition().y + _player.getGlobalBounds().height);

	// 	if (_player.getPosition().y < heightLimit && player->GetPlayerMovement() == Player::RISING)
	// 	{
	// 		if (!_hasProgressed)_hasProgressed = true;

	// 		_platformVelocityY = player->GetPlayerVelocityY();
	// 		player->SetPlayerMovement(Player::FLOATING);
	// 	}

	// 	if (_platformVelocityY > 0) player->SetPlayerMovement(Player::FALLING);

	// 	if (player->GetPlayerMovement() == Player::FLOATING)
	// 	{
	// 		_platformVelocityY += GRAVITY;
	// 		platform->MovePlatforms(-_platformVelocityY);
	// 	}
	// 	else if (player->GetPlayerMovement() == Player::FALLING)
	// 	{
	// 		for (auto &platform : _platforms)
	// 		{
	// 			if (platform.platformCategory == Platform::INVISIBLE) continue;

	// 			if (collision->CheckPlatformBounceCollision(platform.platformSprite, _player))
	// 			{
	// 				switch (platform.platformCategory)
	// 				{
	// 				case Platform::DEFAULT:
	// 					player->SetPlayerMovement(Player::JUMPING);
	// 					break;

	// 				case Platform::BOOSTER:
	// 					player->SetPlayerMovement(Player::BOOSTJUMPING);
	// 					break;

	// 				case Platform::INVISIBLE: // case is unecessary but required by c++
	// 					break;
	// 				}
	// 				break;
	// 			}
	// 		}
	// 	}

	// 	// calculate distance to height limit (for player), jump to limit, extend remainder of jump by moving platforms down and making player float 
	// 	// if the distance to height limit would become negative by jumping, float instead and simulate jump by moving platforms down
	// 	// calculate velocity needed to get to specific point

	// 	// float velocity = std::sqrt(2.0f * (GRAVITY * playerDistanceToHeightLimit));
	// 	// float distance = (0.5 * GRAVITY) * std::pow(VELOCITY, 2)

	// 	// float distance = heightLimit - (_player.getPosition().y + _player.getGlobalBounds().height);
	// 	// std::cout << heightLimit << '\n';
	// 	// std::cout << distance << '\n';

	// 	// bottom window jumping
	// 	if (!_hasProgressed && collision->CheckWindowBottomBounceCollision(_player)) player->SetPlayerMovement(Player::JUMPING);

	// 	// check out of screen death (should change state to gameover state, game close is temporary)
	// 	if (_player.getPosition().y - _player.getGlobalBounds().height > _data->window.getSize().y) _data->isRunning = false;
	// }

	void GameState::Update()
	{
		player->Update();
		platform->SpawnPlatform();
		score->UpdateScore(platform->GetDeletedPlatforms() * 10);

		if (_player.getPosition().x > _data->window.getSize().x) player->SetPlayerPosition(-_player.getGlobalBounds().width, _player.getPosition().y);
		else if (_player.getPosition().x + _player.getGlobalBounds().width < 0)player->SetPlayerPosition(_data->window.getSize().x, _player.getPosition().y);

		_platforms = platform->GetPlatformsVector();
		_player = player->GetPlayerSprite();

		// float heightLimit = _data->window.getSize().y * 0.4f;
		// float possibleTravelDistance = (0.5f * GRAVITY) * (float)std::pow(player->GetPlayerVelocityY(), 2);

		// if (playerDistanceToHeightLimit < 0)
		// {
		// 	std::cout << "Possible travel distance with current velocity: " << possibleTravelDistance << '\n';
		// 	std::cout << "Player distance to height limit: " << playerDistanceToHeightLimit << '\n';
		// }


		// if (playerDistanceToHeightLimit < 0 && player->GetPlayerMovement() == Player::RISING)

		// std::cout << std::boolalpha << _playerWillExceedLimit << '\n';
		// std::cout << std::boolalpha << player->hasReachedMaxDistance() << '\n';

		if (_playerWillExceedLimit && player->hasReachedMaxDistance())
		{
			_playerWillExceedLimit = false;
			// std::cout << "Player distance to height limit: " << playerDistanceToHeightLimit << '\n';
			if (!_hasProgressed)_hasProgressed = true;

			// _platformVelocityY = player->GetPlayerVelocityY();
			player->SetPlayerMovement(Player::FLOATING);
		}

		if (_platformVelocityY <= 0) 
		{
			
			// std::cout << "making player fall\n";
			_platformVelocityY = 0;
			player->SetPlayerMovement(Player::FALLING);
		}

		if (_platformVelocityY > 0)
		{
			// std::cout << "platform velocity: " << _platformVelocityY << '\n';
			// if (_platformVelocityY < GRAVITY) _platformVelocityY = 0;
			// else
			// {
				platform->MovePlatforms(_platformVelocityY);
				_platformVelocityY -= GRAVITY;
			// }
		}
		else if (player->GetPlayerMovement() == Player::FALLING)
		{
			for (auto &platform : _platforms)
			{
				if (platform.platformCategory == Platform::INVISIBLE) continue;

				if (collision->CheckPlatformBounceCollision(platform.platformSprite, _player))
				{
					float playerDistanceToHeightLimit = _player.getPosition().y - _data->window.getSize().y * 0.3f;

					float potentialTravelDistance = 0.5f * (1.0f / GRAVITY) * (float) std::pow(PLAYER_VELOCITY_Y, 2);

					float velocityToReachHeightLimit = playerDistanceToHeightLimit > 0 ? std::sqrt(2.0f * (GRAVITY * playerDistanceToHeightLimit)) : 0.0f;
					
					float remainingDistance = potentialTravelDistance - playerDistanceToHeightLimit;
					float remainingVelocity = remainingDistance > 0 ? std::sqrt(2.0f * (GRAVITY * remainingDistance)) : 0.0f;


					
					// float remainderVelocity = PLAYER_VELOCITY_Y - velocityToReachHeightLimit;

					// std::cout << "Player distance to height limit in pixels: " << playerDistanceToHeightLimit << '\n';
					// std::cout << "Possible travel distance in pixels: " << possibleTravelDistance << '\n';
					// std::cout << "Needed velocity to reach height limit: " << velocityToReachHeightLimit << '\n';
					std::cout << "Remainder velocity (for platforms): " << remainingVelocity << '\n';

					switch (platform.platformCategory)
					{
					case Platform::DEFAULT:
						if (potentialTravelDistance <= playerDistanceToHeightLimit)
						{
							std::cout << "regular jump\n";
							_playerWillExceedLimit = false;
							player->SetJumpVelocity(-PLAYER_VELOCITY_Y);
							player->SetPlayerMovement(Player::JUMPING);
						}
						else if (remainingVelocity > 8)
						{
							std::cout << "weird jump\n";
							_playerWillExceedLimit = true;
							_platformVelocityY = remainingVelocity;
							player->SetJumpVelocity(-velocityToReachHeightLimit);
							player->SetPlayerMovement(Player::JUMPING);
						}
						break;

					case Platform::BOOSTER:
						_playerWillExceedLimit = true;
						_platformVelocityY = remainingVelocity;
						player->SetBoostJumpVelocity(-velocityToReachHeightLimit);
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
		// float distance = (0.5 * GRAVITY) * std::pow(VELOCITY, 2)

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