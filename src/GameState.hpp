#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <math.h>

#include "State.hpp"
#include "Game.hpp"
#include "PauseState.hpp"
#include "Collision.hpp"
#include "Platform.hpp"
#include "Player.hpp"
#include "Score.hpp"
#include "GameOverState.hpp"
#include "Accelerometer.hpp"
#include "Powerup.hpp"

#include "DEFINITIONS.hpp"


namespace WappieJump
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);
		~GameState();
		void Init();

		void HandleInput();
		void Update();
		void Draw();

	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _pauseButton;
	
		sf::Sound &_jumpSound;

		Accelerometer *accelerometer;
		Collision *collision;
		Platform *platform;
		Player *player;
		Score *score;
		Powerup *powerup;
		
		std::vector<Platform::platform> *_platforms;
		sf::Sprite *_player;

		const float potentialTravelDistance = 0.5f * (1.0f / GRAVITY) * (float) std::pow(PLAYER_VELOCITY_Y, 2);
		const float potentialTravelDistanceBoost = 0.5f * (1.0f / GRAVITY) * (float) std::pow(BOOSTER_VELOCITY_Y, 2);
		float playerDistanceToHeightLimit;
		float velocityToReachHeightLimit;
		float remainingDistance;
		float remainingVelocity;

		float _platformVelocityY = 0.0f;
		bool _hasProgressed = false;
		bool _correctedJump = false;

		sf::Clock clock;
	};
}