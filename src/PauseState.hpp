#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>

#include "State.hpp"
#include "Game.hpp"
#include "PauseState.hpp"
#include "CharacterSelectionState.hpp"
#include "SettingState.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "Alignment.hpp"

#include "DEFINITIONS.hpp"

///@file 

namespace WappieJump
{
	/// Pause State
	///	
	/// When the pause button is pressed in the game state you can access the
	/// pause menu where you can either resume the game or go back to the main menu.
	class PauseState : public State
	{
	public:
		/// Construct by providing GameDataRef
		PauseState(GameDataRef data);
		/// Loads all screen objects and sets their positions
		void Init();									 
		///	Manages hardware input 
		void HandleInput();
		void Update();
		/// Draws the screen objects
		void Draw();									

	private:
		GameDataRef _data;

		Alignment *alignment;
		
		sf::Sprite _background;
		sf::Sprite _resumeButton;
		sf::Sprite _homeButton;

        sf::Text _pauseTitle;
		sf::Sound _buttonPressSound;
	};
}