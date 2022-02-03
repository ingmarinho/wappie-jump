#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
// #include "sqlite3.h"

#include "Game.hpp"

#include "DEFINITIONS.hpp"

/// @file

namespace WappieJump
{
    /// Score
    ///
    /// The Score class shows and calculates the score
    class Score
    {
    public:
        /// Construct by providing GameDataRef
        Score(GameDataRef data);
        /// Draws the score on the screen
        void Draw();
        /// Returns the score
        long long int GetScore();
        void Update(float dt);
        /// Calculates the new score
        void UpdateScore(int score);
        /// Sets the text pos of the score
        void SetPosition(float x, float y);

    private:
        GameDataRef _data;
        sf::Text _scoreText;
    };
}