#include "Game.hpp"
#include "SplashState.hpp"
#include "GameState.hpp"
#include "GameOverState.hpp"
#include "CharacterSelectionState.hpp"

namespace WappieJump
{
	Game::Game(int width, int height, std::string title)
	{
		sf::err().rdbuf(NULL);
		srand(time(NULL));
		
		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		_data->window.setFramerateLimit(60);
		// _data->machine.AddState(StateRef(new SplashState(_data)));
		// _data->machine.AddState(StateRef(new GameState(_data)));
		_data->machine.AddState(StateRef(new CharacterSelectionState(_data)));
		// _data->machine.AddState(StateRef(new SettingState(_data)));
		// _data->machine.AddState(StateRef(new GameOverState(_data)));

		Run();
	}

	void Game::Run()
	{
		while (_data->window.isOpen() && _data->isRunning)
		{
			_data->machine.ProcessStateChanges();
			_data->machine.GetActiveState()->HandleInput();
			_data->machine.GetActiveState()->Update();
			_data->machine.GetActiveState()->Draw();
		}
	}
}