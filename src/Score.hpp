#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
// #include "sqlite3.h"

#include "Game.hpp"

#include "DEFINITIONS.hpp"

namespace WappieJump
{
    class Score
    {
    public:
        Score(GameDataRef data);

        void Draw();
        // void OpenDatabase();
        long long int GetScore();
        void Update(float dt);
        void UpdateScore(int score);
        void SetPosition(float x, float y);

    private:
        GameDataRef _data;
        sf::Text _scoreText;
    };
}