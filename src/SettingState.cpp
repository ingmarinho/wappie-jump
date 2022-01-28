#include <sstream>
#include "DEFINITIONS.hpp"
#include "SettingState.hpp"

#include <iostream>

namespace WappieJump
{
    SettingState::SettingState(GameDataRef data) : _data(data)
    {
        _sounds[&_lowSound] = 25;
		_sounds[&_mediumSound] = 45;
		_sounds[&_highSound] = 75;

        _difficulties[&_easy] = 100;
        _difficulties[&_medium] = 50;
        _difficulties[&_hard]   = 25;
    }

    SettingState::~SettingState()
    {
    }

    void SettingState::SetSoundVolume(int x)
    {
        #undef SOUND_VOLUME
        #define SOUND_VOLUME    x
    }

    void SettingState::SetDifficultyLevel(int x)
    {
        #undef DIFFICULTY_LEVEL
        #define DIFFICULTY_LEVEL    x
    }

    // dat gaat niet werken denk ik, we kunnen beter sound volume en difficulty level bij game data toevoegen

    void SettingState::Init()
    {

        _data->assets.LoadFont("Font", FONT_FILEPATH);
        _data->assets.LoadTexture("Setting Background", MAIN_MENU_BACKGROUND_FILEPATH);

        _background.setTexture(_data->assets.GetTexture("Setting Background"));

        _title.setFont(_data->assets.GetFont("Font"));

        _soundSettings.setFont(_data->assets.GetFont("Font"));
        _lowSound.setFont(_data->assets.GetFont("Font"));
        _mediumSound.setFont(_data->assets.GetFont("Font"));
        _highSound.setFont(_data->assets.GetFont("Font"));

        _difficultySettings.setFont(_data->assets.GetFont("Font"));
        _easy.setFont(_data->assets.GetFont("Font"));
        _medium.setFont(_data->assets.GetFont("Font"));
        _hard.setFont(_data->assets.GetFont("Font"));

        _title.setString(SETTINGS_TEXT);
        _title.setCharacterSize(100);
        _title.setFillColor(sf::Color::Red);
        _title.setOrigin(sf::Vector2f(_title.getGlobalBounds().width / 2, _soundSettings.getGlobalBounds().height / 2));
        _title.setPosition(_data->window.getSize().x * 0.5, _data->window.getSize().y * 0.2);

        _soundSettings.setString(SOUND_TEXT);
        _soundSettings.setCharacterSize(100);
        _soundSettings.setFillColor(sf::Color::Black);
        _soundSettings.setOrigin(sf::Vector2f(_soundSettings.getGlobalBounds().width / 2, _soundSettings.getGlobalBounds().height / 2));
        _soundSettings.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y * 0.1);

        _lowSound.setString(LOW_SOUND_TEXT);
        _lowSound.setCharacterSize(100);
        _lowSound.setFillColor(sf::Color::Black);
        _lowSound.setOrigin(sf::Vector2f(_lowSound.getGlobalBounds().width / 2, _lowSound.getGlobalBounds().height / 2));
        _lowSound.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y * 0.1);

        _mediumSound.setString(MEDIUM_SOUND_TEXT);
        _mediumSound.setCharacterSize(100);
        _mediumSound.setFillColor(sf::Color::Black);
        _mediumSound.setOrigin(sf::Vector2f(_mediumSound.getGlobalBounds().width / 2, _mediumSound.getGlobalBounds().height / 2));
        _mediumSound.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y * 0.1);

        _highSound.setString(HARD_SOUND_TEXT);
        _highSound.setCharacterSize(100);
        _highSound.setFillColor(sf::Color::Black);
        _highSound.setOrigin(sf::Vector2f(_highSound.getGlobalBounds().width / 2, _highSound.getGlobalBounds().height / 2));
        _highSound.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y * 0.1);

        /////////////////////////////////////////////////////////
        _difficultySettings.setString(DIFFICULTY_TEXT);
        _difficultySettings.setCharacterSize(100);
        _difficultySettings.setFillColor(sf::Color::Black);
        _difficultySettings.setOrigin(sf::Vector2f(_difficultySettings.getGlobalBounds().width / 2, _difficultySettings.getGlobalBounds().height / 2));
        _difficultySettings.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y * 0.1);

        _easy.setString(DIFFICULTY_EASY_TEXT);
        _easy.setCharacterSize(100);
        _easy.setFillColor(sf::Color::Black);
        _easy.setOrigin(sf::Vector2f(_highSound.getGlobalBounds().width / 2, _highSound.getGlobalBounds().height / 2));
        _easy.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y * 0.1);

        _medium.setString(DIFFICULTY_MEDIUM_TEXT);
        _medium.setCharacterSize(100);
        _medium.setFillColor(sf::Color::Black);
        _medium.setOrigin(sf::Vector2f(_highSound.getGlobalBounds().width / 2, _highSound.getGlobalBounds().height / 2));
        _medium.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y * 0.1);

        _hard.setString(DIFFICULTY_HARD_TEXT);
        _hard.setCharacterSize(100);
        _hard.setFillColor(sf::Color::Black);
        _hard.setOrigin(sf::Vector2f(_highSound.getGlobalBounds().width / 2, _highSound.getGlobalBounds().height / 2));
        _hard.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y * 0.1);
    }

    void SettingState::HandleInput()
    {
        sf::Event event;

        while (_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                _data->window.close();
            }

            if (_data->input.IsTextClicked(_lowSound, sf::Mouse::Left, _data->window))
            {
            	_lowSound.setFillColor(sf::Color::Green);
            }

            // NB: we moeten niet allen de geclicked text groen maken
            // maar ook de vorige geclicked text zwart maken
            // we kunnen dat doen door een extra variable toe te voegen
            
            for (const auto &item : _sounds)
            {
                if (_data->input.IsTextClicked(*item.first, sf::Mouse::Left, _data->window))
                {
            	    item.first->setFillColor(sf::Color::Green);
                    if (_previouslyClicked != nullptr) _previouslyClicked->setFillColor(sf::Color::Black);
                    _previouslyClicked = item.first;
                }
            }
            // love you Ian
        }
    }

    void SettingState::Update()
    {
    }

    void SettingState::Draw()
    {
        _data->window.clear(sf::Color::Red);

        _data->window.draw(_background);

        _data->window.draw(_soundSettings);
        _data->window.draw(_lowSound);
        _data->window.draw(_mediumSound);
        _data->window.draw(_highSound);
        _data->window.draw(_difficultySettings);
        _data->window.draw(_easy);
        _data->window.draw(_medium);
        _data->window.draw(_hard);

        _data->window.display();
    }
}