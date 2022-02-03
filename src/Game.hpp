#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

/// @file

namespace WappieJump
{
	/// saves all the data about the game's current state,
	/// and contains important information for the game to be able to run
	struct GameData
	{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
		bool isRunning = true;
		long long int score = 0;
		long long int highScore = 0; 
		sf::Sprite characterSprite;
		int difficultyLevel = 100; 
		int soundVolume = 50;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game
	{
	public:
		/// Declares the window (width/height) and sets the window title
		Game(int width, int height, std::string title);

	private:
		GameDataRef _data = std::make_shared<GameData>();

		/// Start the main game loop
		void Run();
	};
}