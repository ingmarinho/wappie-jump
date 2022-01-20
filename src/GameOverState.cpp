#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameOverState.hpp"

#include <iostream>

namespace WappieJump
{
	GameOverState::GameOverState(GameDataRef data) : _data(data)
	{
	}

	void GameOverState::Init()
	{
		_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);

		_background.setTexture(_data->assets.GetTexture("Game Over Background"));
	}

	void GameOverState::HandleInput()
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

	void GameOverState::Update(float dt)
	{
		
	}

	void GameOverState::Draw(float dt)
	{
		_data->window.clear(sf::Color::Red);

		_data->window.draw(_background);

		_data->window.display();
	}
}