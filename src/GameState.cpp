#include "GameState.hpp"

namespace WappieJump
{
	GameState::GameState(GameDataRef data) : _data(data)
	{
	}
	
	GameState::~GameState()
	{
		delete collision;
		delete score;
		delete platform;
		delete player;
	}

	void GameState::Init()
	{
		_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);

		_data->assets.LoadTexture("Platform", PLATFORM_FILEPATH);
		_data->assets.LoadTexture("Booster Platform", BOOSTER_PLATFORM_FILEPATH);
		_data->assets.LoadTexture("Moving Platform", MOVING_PLATFORM_FILEPATH);
		_data->assets.LoadTexture("Breaking Platform", BREAKING_PLATFORM_FILEPATH);
		_data->assets.LoadTexture("Breaking Broke Platform", BREAKING_BROKE_PLATFORM_FILEPATH);

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
		platform->MovePlatformsX();

		_data->score = platform->GetDeletedPlatforms() * 10;
		score->UpdateScore(_data->score);

		_platforms = platform->GetPlatformsVector();
		_player = player->GetPlayerSprite();

		if (_player->getPosition().x > _data->window.getSize().x) player->SetPlayerPosition(-_player->getGlobalBounds().width, _player->getPosition().y);
		else if (_player->getPosition().x + _player->getGlobalBounds().width < 0) player->SetPlayerPosition(_data->window.getSize().x, _player->getPosition().y);


		if (_correctedJump && player->hasReachedMaxDistance())
		{
			_correctedJump = false;

			if (!_hasProgressed)_hasProgressed = true;
			player->SetPlayerMovement(Player::FLOATING);
		}

		if (_platformVelocityY <= 0) 
		{
			_platformVelocityY = 0;
			player->SetPlayerMovement(Player::FALLING);
		}

		if (_platformVelocityY > 0)
		{
			platform->MovePlatformsY(_platformVelocityY);
			_platformVelocityY -= GRAVITY;
		}
		else if (player->GetPlayerMovement() == Player::FALLING)
		{
			for (auto &platform : *_platforms)
			{
				if (platform.platformCategory == Platform::INVISIBLE) continue;

				if (collision->CheckPlatformBounceCollision(platform.platformSprite, *_player))
				{
					playerDistanceToHeightLimit = _player->getPosition().y - _data->window.getSize().y * 0.3f;

					switch (platform.platformCategory)
					{
					case Platform::DEFAULT:
						if (potentialTravelDistance <= playerDistanceToHeightLimit)
						{
							player->SetJumpVelocity(-PLAYER_VELOCITY_Y);
							player->SetPlayerMovement(Player::JUMPING);
						}
						// else if (remainingVelocity > 8)
						else
						{
							velocityToReachHeightLimit = playerDistanceToHeightLimit > 0 ? std::sqrt(2.0f * (GRAVITY * playerDistanceToHeightLimit)) : 0.0f;
							remainingDistance = potentialTravelDistance - playerDistanceToHeightLimit;
							remainingVelocity = remainingDistance > 0 ? std::sqrt(2.0f * (GRAVITY * remainingDistance)) : 0.0f;

							_correctedJump = true;
							_platformVelocityY = remainingVelocity;
							player->SetJumpVelocity(-velocityToReachHeightLimit);
							player->SetPlayerMovement(Player::JUMPING);
						}
						break;
					case Platform::MOVING:
						if (potentialTravelDistance <= playerDistanceToHeightLimit)
						{
							player->SetJumpVelocity(-PLAYER_VELOCITY_Y);
							player->SetPlayerMovement(Player::JUMPING);
						}
						// else if (remainingVelocity > 8)
						else
						{
							velocityToReachHeightLimit = playerDistanceToHeightLimit > 0 ? std::sqrt(2.0f * (GRAVITY * playerDistanceToHeightLimit)) : 0.0f;
							remainingDistance = potentialTravelDistance - playerDistanceToHeightLimit;
							remainingVelocity = remainingDistance > 0 ? std::sqrt(2.0f * (GRAVITY * remainingDistance)) : 0.0f;

							_correctedJump = true;
							_platformVelocityY = remainingVelocity;
							player->SetJumpVelocity(-velocityToReachHeightLimit);
							player->SetPlayerMovement(Player::JUMPING);
						}
						break;

					case Platform::BOOSTER:
						velocityToReachHeightLimit = playerDistanceToHeightLimit > 0 ? std::sqrt(2.0f * (GRAVITY * playerDistanceToHeightLimit)) : 0.0f;
						remainingDistance = potentialTravelDistanceBoost - playerDistanceToHeightLimit;
						remainingVelocity = remainingDistance > 0 ? std::sqrt(2.0f * (GRAVITY * remainingDistance)) : 0.0f;

						_correctedJump = true;
						_platformVelocityY = remainingVelocity;
						player->SetJumpVelocity(-velocityToReachHeightLimit);
						player->SetPlayerMovement(Player::JUMPING);
						break;
					case Platform::BREAKING:
						platform.platformSprite.setTexture(_data->assets.GetTexture("Breaking Broke Platform"));
						break;

					default:
						break;
					}
					break;
				}
			}
		}

		// bottom window jumping
		if (!_hasProgressed && collision->CheckWindowBottomBounceCollision(*_player)) player->SetPlayerMovement(Player::JUMPING);

		// check out of screen death (should change state to gameover state, game close is temporary)
		if (_player->getPosition().y - _player->getGlobalBounds().height > _data->window.getSize().y) _data->isRunning = false;
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