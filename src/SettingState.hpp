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

	private:
		GameDataRef _data;
		sf::Sprite _background;
		sf::Text _title;
        sf::Text _soundSettings;
        sf::Text _lowSound;
        sf::Text _mediumSound;
        sf::Text _highSound;
        sf::Text _difficultySettings;
        sf::Text _easy;
        sf::Text _medium;
        sf::Text _hard;

        std::map<sf::Text*, std::array<> > _sounds;
		_sounds[&_lowSound] = 25;
		_sounds[&_mediumSound] = 45;
		_sounds[&_highSound] = 75;
     
        std::map<sf::Text*, int> _difficulties
        _difficulties[&_easy] = 100;
        _difficulties[&_medium] = 50;
        _difficulties[&_hard]   = 25;    
	};
}