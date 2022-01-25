#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Score.hpp"
#include "MainMenuState.hpp"

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
		sf::Text _highScoreText;
		sf::Text _scoreText;
		sf::Text _gameOverText;
		Score *score;
		
	};
}