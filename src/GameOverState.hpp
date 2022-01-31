#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"
#include "Score.hpp"
#include "MainMenuState.hpp"
#include "Alignment.hpp"


namespace WappieJump
{
	class GameOverState : public State
	{
	public:
		GameOverState(GameDataRef data);
		~GameOverState();

		void Init();

		void HandleInput();
		void Update();
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
		sf::Text _score;
		
		sf::Sound &_hitSound; 

		Alignment *alignment;

	};
}