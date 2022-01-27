#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameOverState.hpp"

#include <iostream>

namespace WappieJump
{
	GameOverState::GameOverState(GameDataRef data) : _data(data)
	{
	}

	GameOverState::~GameOverState()
	{
	}

	void GameOverState::Init()
	{	
		_data->assets.LoadFont("Font", FONT_FILEPATH);
		_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Play again Button", PLAY_AGAIN_BUTTON_FILEPATH);
		_data->assets.LoadTexture("Main menu Button", MAIN_MENU_BUTTON_FILEPATH);
		_data->assets.LoadTexture("Score", SCORE_FILEPATH);
		_data->assets.LoadTexture("Highscore", HIGH_SCORE_FILEPATH);



		_background.setTexture(_data->assets.GetTexture("Game Over Background"));

		_playAgainButton.setTexture(_data->assets.GetTexture("Play again Button"));
        _mainMenuButton.setTexture(_data->assets.GetTexture("Main menu Button"));

		
        _scoreSprite.setTexture(_data->assets.GetTexture("Score"));
        _highScoreSprite.setTexture(_data->assets.GetTexture("Highscore"));
		


		_gameOverText.setFont(_data->assets.GetFont("Font"));
		_scoreText.setFont(_data->assets.GetFont("Font"));
		_highScoreText.setFont(_data->assets.GetFont("Font"));
		_score.setFont(_data->assets.GetFont("Font"));

		_gameOverText.setString(GAME_OVER_TEXT);
		_gameOverText.setCharacterSize(100);
		_gameOverText.setFillColor(sf::Color::Black);
		_gameOverText.setOrigin(sf::Vector2f(_gameOverText.getGlobalBounds().width / 2, _gameOverText.getGlobalBounds().height / 2));
		_gameOverText.setPosition(_data->window.getSize().x / 2 , _data->window.getSize().y * 0.1);

		_scoreText.setString(SCORE_TEXT);
		_scoreText.setCharacterSize(50);
		_scoreText.setFillColor(sf::Color::Black);
		_scoreText.setOrigin(sf::Vector2f(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2));
		_scoreText.setPosition((_data->window.getSize().x * 0.4), _data->window.getSize().y * 0.3);

		_highScoreText.setString(HIGHSCORE_TEXT);
		_highScoreText.setCharacterSize(50);
		_highScoreText.setFillColor(sf::Color::Black);
		_highScoreText.setOrigin(sf::Vector2f(_highScoreText.getGlobalBounds().width / 2, _highScoreText.getGlobalBounds().height / 2));
		_highScoreText.setPosition(_data->window.getSize().x * 0.48f, _data->window.getSize().y * 0.4);

		_score.setString(std::to_string(_data->score));
		_score.setCharacterSize(50);
		_score.setFillColor(sf::Color::White);
		_score.setOrigin(sf::Vector2f(_score.getGlobalBounds().width / 2, _score.getGlobalBounds().height / 2));
		_score.setPosition(_data->window.getSize().x * 0.7f, _data->window.getSize().y * 0.3);
		
		_playAgainButton.setScale(0.5f, 0.5f);
		_playAgainButton.setPosition((SCREEN_WIDTH / 2) - (_playAgainButton.getGlobalBounds().width / 2 ), (SCREEN_HEIGHT * 0.85f) - (_playAgainButton.getGlobalBounds().height));
		
		_mainMenuButton.setScale(0.5f, 0.5f);
		_mainMenuButton.setPosition((SCREEN_WIDTH / 2) - (_mainMenuButton.getGlobalBounds().width / 2) , _playAgainButton.getPosition().y + _playAgainButton.getGlobalBounds().height * 0.7);
		
		_scoreSprite.setScale(0.5f, 0.5f);
		_scoreSprite.setPosition(_data->window.getSize().x * 0.05f, _data->window.getSize().y * 0.2);

		_highScoreSprite.setScale(0.5f, 0.5f);
		_highScoreSprite.setPosition(_data->window.getSize().x * 0.05f, _data->window.getSize().y * 0.3);
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
			if (_data->input.IsSpriteClicked(_playAgainButton, sf::Mouse::Left, _data->window) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				_data->machine.AddState(StateRef(new GameState(_data)), true);
			}
			if (_data->input.IsSpriteClicked(_mainMenuButton, sf::Mouse::Left, _data->window))
			{
				_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			}
		}
	}

	void GameOverState::Update()
	{
	}

	void GameOverState::Draw()
	{
		_data->window.clear(sf::Color::Red);

		_data->window.draw(_background);

		_data->window.draw(_scoreText);
		_data->window.draw(_score);
		_data->window.draw(_highScoreText);
		_data->window.draw(_gameOverText);
		
		_data->window.draw(_playAgainButton);
		_data->window.draw(_mainMenuButton);

		// _data->window.draw(_highScoreSprite);
		// _data->window.draw(_scoreSprite);


		_data->window.display();
	
	}
}