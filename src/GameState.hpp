#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

#include "State.hpp"
#include "Game.hpp"
#include "Collision.hpp"
#include "Platform.hpp"
#include "Player.hpp"

#include "DEFINITIONS.hpp"


namespace Sonar
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;

		Collision *collision;
		Platform *platform;
		Player *player; 

		sf::Clock clock;
	};
}