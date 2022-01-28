#include "MainMenuState.hpp"


namespace WappieJump
{
	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{
	}

    int MainMenuState::AlignObjectCenterX(sf::Sprite object)
    {
        return SCREEN_WIDTH / 2 - object.getGlobalBounds().width / 2;
    }

    int MainMenuState::AlignObjectCenterY(sf::Sprite object)
    {
        return SCREEN_HEIGHT / 2 - object.getGlobalBounds().height / 2;
    }

	void MainMenuState::Init()
	{
		_data->assets.LoadFont("Font", FONT_FILEPATH);
		_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
		_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);
		_data->assets.LoadTexture("Play Button Down", PLAY_BUTTON_DOWN_FILEPATH);
		_data->assets.LoadTexture("Settings Button", SETTINGS_BUTTON_FILEPATH);

		_gameQuote.setFont(_data->assets.GetFont("Font"));
		_background.setTexture(_data->assets.GetTexture("Main Menu Background"));
		_title.setTexture(_data->assets.GetTexture("Game Title"));
		_playButton.setTexture(_data->assets.GetTexture("Play Button"));

		_settingsButton.setTexture(_data->assets.GetTexture("Settings Button"));

		_gameQuote.setString(GAME_QUOTE_TEXT);
		_gameQuote.setCharacterSize(30);
		_gameQuote.setFillColor(sf::Color::White);
		_gameQuote.setPosition(sf::Vector2f(SCREEN_WIDTH / 2 - _gameQuote.getGlobalBounds().width / 2, 100));

		_title.setPosition(AlignObjectCenterX(_title), 200);
		_playButton.setPosition(AlignObjectCenterX(_playButton), AlignObjectCenterY(_playButton));

		_settingsButton.setScale(0.2f, 0.2f);
		_settingsButton.setPosition(SCREEN_WIDTH * 0.87, SCREEN_HEIGHT * 0.9);
	}

	void MainMenuState::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}

			if (_data->input.IsSpriteClicked(_playButton, sf::Mouse::Left, _data->window) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				_playButton.setTexture(_data->assets.GetTexture("Play Button Down"));

				// Switch To Main Menu
				_data->machine.AddState(StateRef(new CharacterSelectionState(_data)), true);
			}

			if (_data->input.IsSpriteClicked(_settingsButton, sf::Mouse::Left, _data->window) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				_playButton.setTexture(_data->assets.GetTexture("Play Button Down"));

				// Switch To Main Menu
				_data->machine.AddState(StateRef(new SettingState(_data)), true);
			}
		}
	}

	void MainMenuState::Update()
	{
	}

	void MainMenuState::Draw()
	{
		_data->window.clear(sf::Color::White);

		_data->window.draw(_background);
		_data->window.draw(_title);
		_data->window.draw(_playButton);
		_data->window.draw(_gameQuote);
		_data->window.draw(_settingsButton);

		_data->window.display();
	}
}