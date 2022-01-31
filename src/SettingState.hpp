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
	public:
		SettingState(GameDataRef data);
		~SettingState();

		void Init();
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


		sf::Text *_previouslyClicked1 = nullptr;		sf::Text *_previouslyClicked = nullptr;

		std::map<sf::Text *, int> _sounds;
		std::map<sf::Text *, int> _difficulties;

		bool mutedTexture = false;
		
	};
}