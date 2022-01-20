#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.hpp"

#include "DEFINITIONS.hpp"

namespace WappieJump
{
    class Score
    {
    public:
        Score(GameDataRef data);

        void Draw();
        void Update(float dt);
        void UpdateScore(int score);

    private:
        GameDataRef _data;
        sf::Text _scoreText;
    };
}