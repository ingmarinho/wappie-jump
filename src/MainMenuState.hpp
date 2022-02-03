#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>

#include "State.hpp"
#include "Game.hpp"
#include "MainMenuState.hpp"
#include "CharacterSelectionState.hpp"
#include "SettingState.hpp"
#include "DEFINITIONS.hpp"

///@file

namespace WappieJump
{
	///	Main Menu State
 	///
	/// This state is the first interactable state of the game
	/// from here on you can press the play button
	/// to start the game or the settings button to go to the settings state.

	class MainMenuState : public State
	{
	public:
		/// construct by providing GameDataRef
		MainMenuState(GameDataRef data);
		/// Returns the X position to center an object on the X-axis
        int AlignObjectCenterX(sf::Sprite object);
		/// Returns the Y position to center an object on the Y-axis
        int AlignObjectCenterY(sf::Sprite object);
		/// Loads all screen object images and sets their positions 
		void Init();									
		///	Manages hardware input 
		void HandleInput();
		void Update();
		/// Draws the screen objects
		void Draw();									

	private:
		GameDataRef _data;

		sf::Text _gameQuote;
		sf::Sprite _background;
		sf::Sprite _title;
		sf::Sprite _playButton;
		sf::Sprite _playButtonDown;
		sf::Sprite _settingsButton;

		sf::Sound &_buttonPressSound; 
	};
}