#include <sstream>
#include "DEFINITIONS.hpp"
#include "SettingState.hpp"

#include <iostream>

namespace WappieJump
{
    SettingState::SettingState(GameDataRef data) : _data(data), _sounds(_data->assets.GetSoundMap())
    {
        _volumeOptions[&_lowSound] = SettingState::LOW;
        _volumeOptions[&_mediumSound] = SettingState::MEDIUM;
        _volumeOptions[&_highSound] = SettingState::HIGH;

        _difficultyOptions[&_easy] = SettingState::EASY;
        _difficultyOptions[&_medium] = SettingState::NORMAL;
        _difficultyOptions[&_hard] = SettingState::HARD;
    }

    SettingState::~SettingState()
    {
    }

    int SettingState::AlignObjectCenterX(sf::Sprite object)
    {
        return SCREEN_WIDTH / 2 - object.getGlobalBounds().width / 2;
    }

    int SettingState::AlignObjectCenterY(sf::Sprite object)
    {
        return SCREEN_HEIGHT / 2 - object.getGlobalBounds().height / 2;
    }

    // dat gaat niet werken denk ik, we kunnen beter sound volume en difficulty level bij game data toevoegen

    void SettingState::Init()
    {

        _data->assets.LoadFont("Font", FONT_FILEPATH);
        _data->assets.LoadTexture("Setting Background", CHARACTER_SELECTION_BACKGROUND_FILEPATH);
        _data->assets.LoadTexture("Main menu Button", MAIN_MENU_BUTTON_FILEPATH);
        _data->assets.LoadTexture("Sound Button", SOUND_BUTTON_FILEPATH);
        _data->assets.LoadTexture("Mute Sound Button", MUTE_SOUND_BUTTON_FILEPATH);
        _data->assets.LoadTexture("Difficulty button", DIFFICULTY_BUTTON_FILEPATH);

        _background.setTexture(_data->assets.GetTexture("Setting Background"));

        _mainMenuButton.setTexture(_data->assets.GetTexture("Main menu Button"));

        _soundButton.setTexture(_data->assets.GetTexture("Sound Button"));
        _difficultyButton.setTexture(_data->assets.GetTexture("Difficulty button"));

        _title.setFont(_data->assets.GetFont("Font"));

        _lowSound.setFont(_data->assets.GetFont("Font"));
        _mediumSound.setFont(_data->assets.GetFont("Font"));
        _highSound.setFont(_data->assets.GetFont("Font"));

        _easy.setFont(_data->assets.GetFont("Font"));
        _medium.setFont(_data->assets.GetFont("Font"));
        _hard.setFont(_data->assets.GetFont("Font"));

        _mainMenuButton.setScale(0.5f, 0.5f);
        _mainMenuButton.setPosition(AlignObjectCenterX(_mainMenuButton), AlignObjectCenterY(_mainMenuButton) + 400);

        _soundButton.setScale(0.5f, 0.5f);
        _soundButton.setPosition(SCREEN_WIDTH * 0.01, SCREEN_HEIGHT * 0.4);

        _difficultyButton.setScale(1.0f, 1.0f);
        _difficultyButton.setPosition(SCREEN_WIDTH * 0.01, SCREEN_HEIGHT * 0.6);

        _title.setString(SETTINGS_TEXT);
        _title.setCharacterSize(100);
        _title.setFillColor(sf::Color::Green);
        // _title.setOrigin(sf::Vector2f(_title.getGlobalBounds().width / 2, _soundSettings.getGlobalBounds().height / 2));
        _title.setPosition(SCREEN_WIDTH * 0.2, SCREEN_HEIGHT * 0.1);

        _lowSound.setString(LOW_SOUND_TEXT);
        _lowSound.setCharacterSize(40);
        _lowSound.setFillColor(sf::Color::Green);
        // _lowSound.setOrigin(sf::Vector2f(_lowSound.getGlobalBounds().width / 2, _lowSound.getGlobalBounds().height / 2));
        _lowSound.setPosition(SCREEN_WIDTH * 0.25, SCREEN_HEIGHT * 0.4);

        _mediumSound.setString(MEDIUM_SOUND_TEXT);
        _mediumSound.setCharacterSize(40);
        _mediumSound.setFillColor(sf::Color::Green);
        // _mediumSound.setOrigin(sf::Vector2f(_mediumSound.getGlobalBounds().width / 2, _mediumSound.getGlobalBounds().height / 2));
        _mediumSound.setPosition(SCREEN_WIDTH * 0.4, SCREEN_HEIGHT * 0.4);

        _highSound.setString(HARD_SOUND_TEXT);
        _highSound.setCharacterSize(40);
        _highSound.setFillColor(sf::Color::Green);
        // _highSound.setOrigin(sf::Vector2f(_highSound.getGlobalBounds().width / 2, _highSound.getGlobalBounds().height / 2));
        _highSound.setPosition(SCREEN_WIDTH * 0.63, SCREEN_HEIGHT * 0.4);

        /////////////////////////////////////////////////////////

        _easy.setString(DIFFICULTY_EASY_TEXT);
        _easy.setCharacterSize(40);
        _easy.setFillColor(sf::Color::Green);
        // _easy.setOrigin(sf::Vector2f(_highSound.getGlobalBounds().width / 2, _highSound.getGlobalBounds().height / 2));
        _easy.setPosition(SCREEN_WIDTH * 0.25, SCREEN_HEIGHT * 0.6);

        _medium.setString(DIFFICULTY_MEDIUM_TEXT);
        _medium.setCharacterSize(40);
        _medium.setFillColor(sf::Color::Green);
        // _medium.setOrigin(sf::Vector2f(_highSound.getGlobalBounds().width / 2, _highSound.getGlobalBounds().height / 2));
        _medium.setPosition(SCREEN_WIDTH * 0.4, SCREEN_HEIGHT * 0.6);

        _hard.setString(DIFFICULTY_HARD_TEXT);
        _hard.setCharacterSize(40);
        _hard.setFillColor(sf::Color::Green);
        // _hard.setOrigin(sf::Vector2f(_highSound.getGlobalBounds().width / 2, _highSound.getGlobalBounds().height / 2));
        _hard.setPosition(SCREEN_WIDTH * 0.63, SCREEN_HEIGHT * 0.6);
    }

    void SettingState::setVolume(SettingState::volume volume)
    {
        switch (volume)
        {
        case SettingState::LOW:
            for (auto &sound : _sounds)
            {
                sound.second.setVolume(20.0f);
            }
            break;
        case SettingState::MEDIUM:
            for (auto &sound : _sounds)
            {
                sound.second.setVolume(50.0f);
            }
            break;
        case SettingState::HIGH:
            for (auto &sound : _sounds)
            {
                sound.second.setVolume(80.0f);
            }
            break;
        case SettingState::MUTED:
            for (auto &sound : _sounds)
            {
                sound.second.setVolume(0.0f);
            }
            break;
        }
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

            if (_data->input.IsSpriteClicked(_mainMenuButton, sf::Mouse::Left, _data->window) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                _data->machine.AddState(StateRef(new MainMenuState(_data)), true);
            }

            if (_data->input.IsSpriteClicked(_soundButton, sf::Mouse::Left, _data->window) || sf::Keyboard::isKeyPressed(sf::Keyboard::M))
            {
                if (mutedTexture)
                {
                    _soundButton.setTexture(_data->assets.GetTexture("Sound Button"));
                    mutedTexture = false;
                }
                else
                {
                    _soundButton.setTexture(_data->assets.GetTexture("Mute Sound Button"));
                    mutedTexture = true;
                }
            }

            // NB: we moeten niet allen de geclicked text groen maken
            // maar ook de vorige geclicked text zwart maken
            // we kunnen dat doen door een extra variable toe te voegen

            if (!mutedTexture)
            {
                for (const auto &item : _volumeOptions)
                {
                    _data->soundVolume = item.second;

                    if (_data->input.IsTextClicked(*item.first, sf::Mouse::Left, _data->window))
                    {
                        if (item.first != _previouslyClickedVolume)
                        {
                            item.first->setFillColor(sf::Color::Red);
                            if (_previouslyClickedVolume != nullptr)
                                _previouslyClickedVolume->setFillColor(sf::Color::Green);
                            setVolume(item.second);
                            _previouslyClickedVolume = item.first;
                        }
                    }
                }
            }
            else if (_previouslyClickedVolume != nullptr)
            {
                _previouslyClickedVolume->setFillColor(sf::Color::Green);
                _previouslyClickedVolume = nullptr;
            }

            for (const auto &item : _difficultyOptions)
            {
                _data->difficultyLevel = item.second;

                if (_data->input.IsTextClicked(*item.first, sf::Mouse::Left, _data->window))
                {
                    if (item.first != _previouslyClickedDifficulty)
                    {
                        item.first->setFillColor(sf::Color::Red);

                        if (_previouslyClickedDifficulty != nullptr)
                            _previouslyClickedDifficulty->setFillColor(sf::Color::Green);
                        _previouslyClickedDifficulty = item.first;
                    }
                }
            }
        }
    }

    void SettingState::Update()
    {

        // switch ()
    }

    void SettingState::Draw()
    {
        _data->window.clear(sf::Color::Red);

        _data->window.draw(_background);
        _data->window.draw(_mainMenuButton);
        _data->window.draw(_soundButton);
        _data->window.draw(_difficultyButton);

        _data->window.draw(_title);
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