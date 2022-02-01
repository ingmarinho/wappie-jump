#include "PauseState.hpp"
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"

namespace WappieJump
{
	PauseState::PauseState(GameDataRef data) : _data(data)
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
        _data->assets.LoadTexture("Pause Background", PAUSE_BACKGROUND_FILEPATH); 
        _data->assets.LoadTexture("Resume Button", RESUME_BUTTON_FILEPATH); 
        _data->assets.LoadTexture("Home Button", HOME_BUTTON_FILEPATH); 

        _background.setTexture(_data->assets.GetTexture("Pause Background"));
        _homeButton.setTexture(_data->assets.GetTexture("Home Button"));
        _resumeButton.setTexture(_data->assets.GetTexture("Resume Button"));


        _resumeButton.setPosition(SCREEN_WIDTH * 0.87, SCREEN_HEIGHT * 0.9);
        _resumeButton.setScale(0.2f, 0.2f);

        _homeButton.setPosition(SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.5);
        _homeButton.setScale(0.2f, 0.2f);
        
	

	
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
                _data->machine.RemoveState();
				
			}

			if (_data->input.IsSpriteClicked(_homeButton, sf::Mouse::Left, _data->window) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
			
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
	

		_data->window.display();
	}
}