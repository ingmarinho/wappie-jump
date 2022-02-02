#include "GameState.hpp"

namespace WappieJump
{
    GameState::GameState(GameDataRef data) : _data(data),
    _jumpSound(_data->assets.GetSound("Jump")),
    _gameOverSound(_data->assets.GetSound("Game Over")),
    _boosterSound(_data->assets.GetSound("Vaccine")),
    _monsterSound(_data->assets.GetSound("Monster Hit")),
    _breakingBedSound(_data->assets.GetSound("Breaking Bed"))
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

		_data->assets.LoadTexture("Speedometer", SPEEDOMETER_FILEPATH);
		_data->assets.LoadTexture("Vaccine Platform", VACCINE_POWERUP_FILEPATH);

		_data->assets.LoadTexture("Corona", CORONA_FILEPATH);


		_data->assets.LoadTexture("Pause Button", PAUSE_BUTTON_FILEPATH); 

		_data->assets.LoadTexture("Platform", PLATFORM_FILEPATH);
		_data->assets.LoadTexture("Booster Platform", BOOSTER_PLATFORM_FILEPATH);
		_data->assets.LoadTexture("Moving Platform", MOVING_PLATFORM_FILEPATH);
		_data->assets.LoadTexture("Breaking Platform", BREAKING_PLATFORM_FILEPATH);

		_data->assets.LoadFont("Font", FONT_FILEPATH);

		accelerometer = new Accelerometer(_data);
		collision = new Collision(_data);
		platform = new Platform(_data);
		player = new Player(_data);
		score = new Score(_data);
		monster = new Monster(_data);

		_background.setTexture(_data->assets.GetTexture("Game Background"));
		_pauseButton.setTexture(_data->assets.GetTexture("Pause Button"));
		_pauseButton.setScale(0.05f, 0.05f);
		_pauseButton.setPosition(SCREEN_WIDTH * 0.88f, SCREEN_HEIGHT * 0.02f);
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
			if (_data->input.IsSpriteClicked(_pauseButton, sf::Mouse::Left, _data->window) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
                _data->machine.AddState(StateRef(new PauseState(_data)), false);
				
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			player->SetPlayerAngle(Player::LEFT);
			player->MoveLeft();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			player->SetPlayerAngle(Player::RIGHT);
			player->MoveRight();
		}
		else player->Decelleration();

	
	}

	void GameState::Update()
	{
		player->Update();

		accelerometer->SetSpeed(player->GetPlayerVelocity().x, player->GetPlayerVelocity().y - _platformVelocityY);
		platform->SpawnPlatform();
		platform->MoveOtherPlatforms();
		monster->MoveMonsterX();
		player->ChangePoisonValue();

		_data->score = platform->GetDeletedPlatforms() * 10;
		score->UpdateScore(_data->score);

		_platforms = platform->GetPlatformsVector();
		_player = player->GetPlayerSprite();
        
		// spawn enemy
		if (_platforms->back().platformCategory == Platform::INVISIBLE) monster->SpawnMonster(_platforms->back().platformSprite.getGlobalBounds().top);
		if (monster->Exists() && collision->CheckMonsterCollision(monster->GetMonsterSprite(), *_player))
		{
            _monsterSound.play();
            player->SetPlayerMovement(Player::DEATHFALL);
			_correctedJump = false;
        }

		if (_player->getPosition().x - _player->getGlobalBounds().width > SCREEN_WIDTH) player->SetPlayerPosition(-_player->getGlobalBounds().width, _player->getPosition().y);
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
			monster->MoveMonsterY(_platformVelocityY);
			_platformVelocityY -= GRAVITY;
		}
		else if (player->GetPlayerMovement() == Player::FALLING)
		{
			for (auto &platform : *_platforms)
			{
				if (platform.platformCategory == Platform::INVISIBLE
				||
				platform.platformCategory == Platform::SHADOW
				||
				platform.collided) continue;

				if (collision->CheckPlatformBounceCollision(platform.platformSprite, *_player))
				{
					playerDistanceToHeightLimit = _player->getPosition().y - _data->window.getSize().y * 0.3f;

					switch (platform.platformCategory)
					{
					case Platform::DEFAULT:
                        _jumpSound.play();

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
							remainingVelocity = remainingDistance > 0.0f ? std::sqrt(2.0f * (GRAVITY * remainingDistance)) : 0.0f;
							_correctedJump = true;
							_platformVelocityY = remainingVelocity;
							player->SetJumpVelocity(-velocityToReachHeightLimit);
							player->SetPlayerMovement(Player::JUMPING);
						}
						break;
					case Platform::MOVING:
                        _jumpSound.play();

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
                        _boosterSound.play();

						velocityToReachHeightLimit = playerDistanceToHeightLimit > 0 ? std::sqrt(2.0f * (GRAVITY * playerDistanceToHeightLimit)) : 0.0f;
						remainingDistance = potentialTravelDistanceBoost - playerDistanceToHeightLimit;
						remainingVelocity = remainingDistance > 0 ? std::sqrt(2.0f * (GRAVITY * remainingDistance)) : 0.0f;
						
						_correctedJump = true;
						_platformVelocityY = remainingVelocity;
						player->SetJumpVelocity(-velocityToReachHeightLimit);
						player->SetPlayerMovement(Player::JUMPING);
						player->SetPoisonValue();
						break;
					case Platform::BREAKING:
						_breakingBedSound.play();
						platform.collided = true;
						break;

					default:
						break;
					}
					break;
				}
			}
		}
		// bottom window jumping
		if (!_hasProgressed && player->GetPlayerMovement() != Player::DEATHFALL && collision->CheckWindowBottomBounceCollision(*_player)) player->SetPlayerMovement(Player::JUMPING);

		// check out of screen death
		if (_player->getPosition().y - _player->getGlobalBounds().height > _data->window.getSize().y) 
		{
			_gameOverSound.play();
			_data->machine.AddState(StateRef(new GameOverState(_data)), true);
		}
	}

	void GameState::Draw()
	{
		_data->window.clear(sf::Color::Black);

		_data->window.draw(_background);

		platform->DrawPlatforms();

		monster->DrawMonster();

		player->Draw();
		
		_data->window.draw(_pauseButton);

		score->Draw();

		accelerometer->Draw();
	
		_data->window.display();
	}
}