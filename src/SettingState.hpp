#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include "State.hpp"
#include "Game.hpp"
#include "Score.hpp"
#include "MainMenuState.hpp"
#include "Alignment.hpp"
///@file 

namespace WappieJump
{
	/// Setting State
	/// 
	/// Contains the settings menu which is accessible by a single sprite object in multiple states.
	/// This menu allows you to set the sound volume and difficulty of the game. 
	class SettingState : public State
	{
		/// Game volume options
		enum volume
		{
			MUTED,
			LOW,
			MEDIUM,
			HIGH
		};
		/// Game difficulty options
		enum difficulty
		{
			EASY,
			NORMAL,
			HARD
		};


	public:
		/// Construct by providing GameDataRef
		SettingState(GameDataRef data);
	
		~SettingState();
		/// Loads all screen object and sets their positions 
		void Init();	
		/// Sets the the correct volume for all sound objects							
		void setVolume(SettingState::volume volume);
		void HandleInput();
		void Update();
		/// Draws the screen objects
		void Draw();									

	private:
		GameDataRef _data;

		Alignment *alignment;

		sf::Sprite _background;
		sf::Sprite _mainMenuButton; 
		sf::Sprite _soundButton;
		sf::Sprite _soundButtonMute;
		sf::Sprite _difficultyButton;

		sf::Text _title;
		sf::Text _soundSettings;
		sf::Text _lowSound;
		sf::Text _mediumSound;
		sf::Text _highSound;
		sf::Text _difficultySettings;
		sf::Text _easy;
		sf::Text _medium;
		sf::Text _hard;

		sf::Sound _buttonPressSound; 

		std::map<std::string, sf::Sound> &_sounds;

		sf::Text *_previouslyClickedDifficulty = nullptr;		
		sf::Text *_previouslyClickedVolume = nullptr;

		std::map<sf::Text *, volume> _volumeOptions;
		std::map<sf::Text *, difficulty> _difficultyOptions;

		volume _currentVolume = MEDIUM;

		bool mutedTexture = false;
		
	};
}