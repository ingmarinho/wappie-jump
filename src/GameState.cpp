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
		collision = new Collision();
		player = new Player(_data, platform, collision);

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
		platform->SpawnStaticPlatform();
		player->Update(dt);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			player->setPlayerTexture(_data->assets.GetTexture("Player"));
			player->MoveLeft();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			player->setPlayerTexture(_data->assets.GetTexture("Player Mirrored"));
			player->MoveRight();
		}
		platform->SpawnPlatform();
		// platform->MovePlatforms(dt);
	}

	void GameState::Draw(float dt)
	{
		_data->window.clear(sf::Color::Black);

		_data->window.draw(_background);

		player->Draw();

		platform->DrawPlatforms();

		_data->window.display();
	}
}