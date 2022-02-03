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
#include "Monster.hpp"

#include "DEFINITIONS.hpp"

/// @file

namespace WappieJump
{
	/// Game State
	///
	/// This is the state where the game runs
	/// all user input is handled in this state.
	/// it also handles all game logic including spawning platformns,
	/// checking collisions and spawning monsters
	class GameState : public State
	{
	public:

		/// Construct by providing GameDataRef
		GameState(GameDataRef data);
		~GameState();
		
		/// Loads all screen objects and sets their positions 
		void Init();
		/// Handles user input and makes actions
		void HandleInput();
		/// Update the game state,
		/// calls the update function of other objects
		void Update();
		/// Draws the screen objects
		void Draw();

	private:
	
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _pauseButton;

        sf::Sound &_jumpSound;
        sf::Sound &_gameOverSound;
        sf::Sound &_boosterSound;
        sf::Sound &_monsterSound;
        sf::Sound &_breakingBedSound;

		Accelerometer *accelerometer;
		Collision *collision;
		Platform *platform;
		Player *player;
		Score *score;
		Monster *monster;
		
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