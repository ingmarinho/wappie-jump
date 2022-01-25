#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>

#include "State.hpp"
#include "Game.hpp"
#include "MainMenuState.hpp"
#include "CharacterSelectionState.hpp"

#include "DEFINITIONS.hpp"


namespace WappieJump
{
	class MainMenuState : public State
	{
	public:
		MainMenuState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update();
		void Draw();

	private:
		GameDataRef _data;

		sf::Text _gameQuote;
		sf::Sprite _background;
		sf::Sprite _title;
		sf::Sprite _playButton;
		sf::Sprite _playButtonDown;
	};
}