#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

namespace WappieJump
{
	struct GameData
	{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
		bool isRunning = true;
		long long int score = 0;
		sf::Sprite characterSprite;
		int difficultyLevel = 100; 
		int soundVolume = 50; 

	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game
	{
	public:
		Game(int width, int height, std::string title);

	private:
		GameDataRef _data = std::make_shared<GameData>();

		void Run();
	};
}