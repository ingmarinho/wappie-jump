#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameState.hpp"

#include <iostream>

namespace Sonar
{
	GameState::GameState(GameDataRef data) : _data(data)
	{

	}

	void GameState::Init()
	{
		_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Platform", PLATFORM_FILEPATH);

		_background.setTexture(_data->assets.GetTexture("Game Background"));
	}

	void GameState::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}

			if (_data->input.IsSpriteClicked(_background, sf::Mouse::Left, _data->window))
			{
				
			}
		}
	}

	void GameState::Update(float dt)
	{
		
	}

	void GameState::Draw(float dt)
	{
		_data->window.clear(sf::Color::Red);

		_data->window.draw(_background);

		_data->window.display();
	}
}