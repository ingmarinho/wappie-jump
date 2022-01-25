#include "Score.hpp"

namespace WappieJump
{
	Score::Score(GameDataRef data) : _data(data)
	{
		_scoreText.setFont(_data->assets.GetFont("Font"));
		_scoreText.setString("0");
		_scoreText.setCharacterSize(50);
		_scoreText.setFillColor(sf::Color::Magenta);
		_scoreText.setOrigin(sf::Vector2f(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2));
		_scoreText.setPosition(SCORE_X, SCORE_Y);
	}
	void Score::SetPosition(float x, float y)
	{
		_scoreText.setPosition(x, y);
	}

	void Score::Draw()
	{
		_data->window.draw(_scoreText);
	}

	void Score::UpdateScore(int score)
	{
		_scoreText.setString(std::to_string(score));
	} 
}