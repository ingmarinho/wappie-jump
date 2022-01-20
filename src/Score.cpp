#include "Score.hpp"

namespace Sonar
{
	Score::Score(GameDataRef data) : _data(data)
	{
        _score.setFont(this->_data->assets.GetFont("Font")); 

		_score.setString("0");

		_score.setCharacterSize(50);

		_score.setFillColor(sf::Color::Magenta);

		_score.setOrigin(sf::Vector2f(_score.getGlobalBounds().width / 2, _score.getGlobalBounds().height / 2));

		_score.setPosition(SCORE_X, SCORE_Y);
	}

	void Score::Draw()
	{
		_data->window.draw(_score);
	}

	void Score::UpdateScore(int score)
	{   
        _score.setString(std::to_string(score));
	}
}