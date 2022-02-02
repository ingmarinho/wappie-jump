#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>

#include "State.hpp"
#include "Game.hpp"
#include "PauseState.hpp"
#include "CharacterSelectionState.hpp"
#include "SettingState.hpp"
#include "DEFINITIONS.hpp"



namespace WappieJump
{
	class PauseState : public State
	{
	public:
		PauseState(GameDataRef data);

        int AlignObjectCenterX(sf::Sprite object);
        int AlignObjectCenterY(sf::Sprite object);
		void Init();

		void HandleInput();
		void Update();
		void Draw();

	private:
		GameDataRef _data;

		
		sf::Sprite _background;
		sf::Sprite _resumeButton;
		sf::Sprite _homeButton;

        sf::Text _pauseTitle;
		sf::Sound _buttonPressSound;
	};
}