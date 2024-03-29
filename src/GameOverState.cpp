#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameOverState.hpp"

#include <iostream>
#include <fstream>

namespace WappieJump
{
	GameOverState::GameOverState(GameDataRef data) : _data(data), _buttonPressSound(_data->assets.GetSound("Button Press"))
	{
		alignment = new Alignment(_data);
	}

	GameOverState::~GameOverState()
	{
		delete alignment;
		
	}

	void GameOverState::Init()
	{	
		ReadHighScoreFile();
		WriteHighScoreFile();

		_data->assets.LoadFont("Font", FONT_FILEPATH);
		_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
		_data->assets.LoadTexture("Play again Button", PLAY_AGAIN_BUTTON_FILEPATH);
		_data->assets.LoadTexture("Main menu Button", MAIN_MENU_BUTTON_FILEPATH);
	
		
		_background.setTexture(_data->assets.GetTexture("Game Over Background"));

		_playAgainButton.setTexture(_data->assets.GetTexture("Play again Button"));
        _mainMenuButton.setTexture(_data->assets.GetTexture("Main menu Button"));


		_gameOverText.setFont(_data->assets.GetFont("Font"));
		_scoreText.setFont(_data->assets.GetFont("Font"));
		_highScoreText.setFont(_data->assets.GetFont("Font"));
		_score.setFont(_data->assets.GetFont("Font"));
		_highScore.setFont(_data->assets.GetFont("Font"));

		_gameOverText.setString(GAME_OVER_TEXT);
		_gameOverText.setCharacterSize(100);
		_gameOverText.setFillColor(sf::Color::Black);
		_gameOverText.setPosition(SCREEN_WIDTH / 4, SCREEN_HEIGHT * 0.1);

		_scoreText.setString(SCORE_TEXT);
		_scoreText.setCharacterSize(50);
		_scoreText.setFillColor(sf::Color::Black);
		_scoreText.setPosition(SCREEN_WIDTH / 4, SCREEN_HEIGHT * 0.3);

		_highScoreText.setString(HIGHSCORE_TEXT);
		_highScoreText.setCharacterSize(50);
		_highScoreText.setFillColor(sf::Color::Black);
		_highScoreText.setPosition(SCREEN_WIDTH / 4, SCREEN_HEIGHT * 0.4);

		_score.setString(std::to_string(score));
		_score.setCharacterSize(50);
		_score.setFillColor(sf::Color::White);
		
		_score.setPosition(SCREEN_WIDTH * 0.65f, SCREEN_HEIGHT * 0.3f);

		_highScore.setString(std::to_string(highScore));
		_highScore.setCharacterSize(50);
		_highScore.setFillColor(sf::Color::White);
		
		_highScore.setPosition(SCREEN_WIDTH * 0.65f, SCREEN_HEIGHT * 0.4f);


        _playAgainButton.setScale(0.5f, 0.5f);
        _playAgainButton.setPosition(alignment->AlignObjectCenterX(_playAgainButton), alignment->AlignObjectCenterY(_playAgainButton) + 200);

        _mainMenuButton.setScale(0.5f, 0.5f);
        _mainMenuButton.setPosition(alignment->AlignObjectCenterX(_mainMenuButton), alignment->AlignObjectCenterY(_mainMenuButton) + 350);

	}

	void GameOverState::ReadHighScoreFile()
	{
		std::ifstream readFile; 
		readFile.open("Resources/db/Highscore.txt");
		if (readFile.is_open())
		{
			while(!readFile.eof())
			{
				readFile >> highScore;
			}
		}
		readFile.close( );
	}

	void GameOverState::WriteHighScoreFile()
	{
		std::ofstream writeFile( "Resources/db/Highscore.txt" );

		if (writeFile.is_open() )
		{
			if (score > highScore)
			{
				highScore = score;
			}
			writeFile << highScore; 
		}
		writeFile.close( ); 
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
				_buttonPressSound.play();
				_data->machine.AddState(StateRef(new GameState(_data)), true);
			}
			if (_data->input.IsSpriteClicked(_mainMenuButton, sf::Mouse::Left, _data->window)|| sf::Keyboard::isKeyPressed(sf::Keyboard::H))
			{
				_buttonPressSound.play();
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
		_data->window.draw(_highScore);
		_data->window.draw(_highScoreText);
		_data->window.draw(_gameOverText);
		
		_data->window.draw(_playAgainButton);
		_data->window.draw(_mainMenuButton);

		_data->window.display();
	
	}
}