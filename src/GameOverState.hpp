#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"
#include "Score.hpp"
#include "MainMenuState.hpp"
#include "Alignment.hpp"

/// @file

namespace WappieJump
{
	/// Game Over State
	///
	/// This is the screen that appears after your character dies,
	/// from here u can either go back to the main menu or restart the game instantly.
	class GameOverState : public State
	{
	public:
		/// Construct by providing GameDataRef
		GameOverState(GameDataRef data);
		~GameOverState();

		/// Loads all screen objects and sets their positions 
		void Init();				
		/// Reads the highscore file
		void ReadHighScoreFile(); 
		/// Writes the highscore to the highscore file	
		void WriteHighScoreFile(); 	
		///	Manages hardware input 
		void HandleInput();			
		void Update();
		/// Draws the screen objects
		void Draw();				

	private:
		GameDataRef _data;
		sf::Sprite _playAgainButton;
		sf::Sprite _mainMenuButton;
		sf::Sprite _background;
		sf::Sprite _highScoreSprite;
		sf::Sprite _scoreSprite;
		sf::Text _highScoreText;
		sf::Text _scoreText;
		sf::Text _gameOverText;
		sf::Text _highScore; 
		sf::Text _score;
		
		sf::Sound &_buttonPressSound; 

		Alignment *alignment;

		long long int highScore = _data->highScore;
		long long int score = _data->score;

	};
}