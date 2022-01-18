#include "GameState.hpp"

namespace Sonar
{
	GameState::GameState(GameDataRef data) : _data(data)
	{

	}

	void GameState::Init()
	{
		_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Platform", PLATFORM_FILEPATH);
		_data->assets.LoadTexture("Player", CHAR6_FILEPATH);
		_data->assets.LoadTexture("Player Mirrored", CHAR6MIR_FILEPATH);

		platform = new Platform(_data);
		player = new Player(_data);

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
				// platform->SpawnPlatform();
				// for (unsigned int i = 0; i < 1000; i++)
				// {
				// 	platform->SpawnPlatform();
				// }
			}

		}
	}

	void GameState::Update(float dt)
	{
		if (platform->GetPlatformAmount() < 18) platform->SpawnPlatform();

		platform->MovePlatforms(dt);
	}

	void GameState::Draw(float dt)
	{
		_data->window.clear(sf::Color::Red);

		_data->window.draw(_background);

		platform->DrawPlatforms();

		_data->window.display();
	}
}