#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace WappieJump
{
	class SplashState : public State
	{
	public:
		SplashState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update();
		void Draw();

	private:
		GameDataRef _data;

		sf::Clock _clock;

		sf::Sprite _background;
	};
}