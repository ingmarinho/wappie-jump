#include "PauseState.hpp"
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"

namespace WappieJump
{
	PauseState::PauseState(GameDataRef data) : _data(data), _buttonPressSound(_data->assets.GetSound("Button Press"))
	{
	}

    int PauseState::AlignObjectCenterX(sf::Sprite object)
    {
        return SCREEN_WIDTH / 2 - object.getGlobalBounds().width / 2;
    }

    int PauseState::AlignObjectCenterY(sf::Sprite object)
    {
        return SCREEN_HEIGHT / 2 - object.getGlobalBounds().height / 2;
    }

	void PauseState::Init()
	{
        _data->assets.LoadFont("Font", FONT_FILEPATH);
        _data->assets.LoadTexture("Pause Background", PAUSE_BACKGROUND_FILEPATH); 
        _data->assets.LoadTexture("Resume Button", RESUME_BUTTON_FILEPATH); 
        _data->assets.LoadTexture("Home Button", HOME_BUTTON_FILEPATH); 

        _background.setTexture(_data->assets.GetTexture("Pause Background"));
        _homeButton.setTexture(_data->assets.GetTexture("Home Button"));
        _resumeButton.setTexture(_data->assets.GetTexture("Resume Button"));

        _pauseTitle.setFont(_data->assets.GetFont("Font"));

        _pauseTitle.setString(PAUSE_TITLE_TEXT);
		_pauseTitle.setCharacterSize(100);
		_pauseTitle.setFillColor(sf::Color::Green);
		_pauseTitle.setPosition(sf::Vector2f(SCREEN_WIDTH / 2 - _pauseTitle.getGlobalBounds().width / 2, 100));



        _resumeButton.setScale(0.5f, 0.5f);
        _resumeButton.setPosition(AlignObjectCenterX(_resumeButton), AlignObjectCenterY(_resumeButton));

        _homeButton.setScale(0.5f, 0.5f);
        _homeButton.setPosition(AlignObjectCenterX(_homeButton), AlignObjectCenterY(_homeButton) + 150);
	}

	void PauseState::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}

			if (_data->input.IsSpriteClicked(_resumeButton, sf::Mouse::Left, _data->window) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				_buttonPressSound.play();
                _data->machine.RemoveState();
				
			}

			if (_data->input.IsSpriteClicked(_homeButton, sf::Mouse::Left, _data->window) || sf::Keyboard::isKeyPressed(sf::Keyboard::H))
			{
				_buttonPressSound.play();
				_data->machine.RemoveState();
                _data->machine.AddState(StateRef (new MainMenuState(_data)), true);
			}
		}
	}

	void PauseState::Update()
	{
	}

	void PauseState::Draw()
	{
		_data->window.clear(sf::Color::White);

		_data->window.draw(_background);
		_data->window.draw(_resumeButton);
		_data->window.draw(_homeButton);

        _data->window.draw(_pauseTitle);

	

		_data->window.display();
	}
}