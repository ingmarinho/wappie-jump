#include <sstream>
#include "SplashState.hpp"
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"

#include <iostream>

namespace WappieJump
{
	SplashState::SplashState(GameDataRef data) : _data(data)
	{

	}

	void SplashState::Init()
	{
		_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);

		_background.setTexture(_data->assets.GetTexture("Splash State Background"));
		_background.setPosition((SCREEN_WIDTH / 2) - (_background.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_background.getGlobalBounds().height / 2));

		_data->assets.LoadSound("Hit", HIT_SOUND_FILEPATH);
		_data->assets.LoadSound("Jump", JUMP_SOUND_FILEPATH);
		_data->assets.LoadSound("Vaccine", BOOSTER_SOUND_FILEPATH );
        _data->assets.LoadSound("Monster Hit", MONSTER_SOUND_FILEPATH );
		_data->assets.LoadSound("Game Over", GAME_OVER_SOUND_FILEPATH);
		_data->assets.LoadSound("Button Press", BUTTON_PRESS_FILEPATH);
		_data->assets.LoadSound("Breaking Bed", BREAKING_BED_FILEPATH);
	}

	void SplashState::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}
		}
	}

	void SplashState::Update()
	{
		if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			// Switch To Main Menu
			_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
	}

	void SplashState::Draw()
	{
		_data->window.clear(sf::Color::White);

		_data->window.draw( _background );

		_data->window.display();
	}
}