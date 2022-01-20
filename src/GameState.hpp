#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

#include "State.hpp"
#include "Game.hpp"
#include "Collision.hpp"
#include "Platform.hpp"
#include "Player.hpp"
#include "Score.hpp"

#include "DEFINITIONS.hpp"


namespace WappieJump
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update();
		void Draw();

	private:
		GameDataRef _data;

		sf::Sprite _background;

		Collision *collision;
		Platform *platform;
		Player *player;
		Score *score;
		
		std::vector<Platform::platform> _platforms;
		sf::Sprite _player;

		float _platformVelocityY = 0.0;
		bool _hasProgressed = false;

		sf::Clock clock;
	};
}