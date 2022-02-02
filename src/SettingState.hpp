#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Score.hpp"
#include "MainMenuState.hpp"
#include <map>

namespace WappieJump
{
	class SettingState : public State
	{
		enum volume
		{
			MUTED,
			LOW,
			MEDIUM,
			HIGH
		};
		enum difficulty
		{
			EASY,
			NORMAL,
			HARD
		};


	public:
		SettingState(GameDataRef data);
		~SettingState();

		void Init();
		void setVolume(SettingState::volume volume);
		void HandleInput();
		void Update();
		void Draw();
		void SetSoundVolume(int x);
		void SetDifficultyLevel(int x);

		int AlignObjectCenterX(sf::Sprite object);
		int AlignObjectCenterY(sf::Sprite object);

	private:
		GameDataRef _data;
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