#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"

#include <vector>

namespace Sonar
{
    class Player
    {
    public:
        Player(GameDataRef data);
        ~Player();

        void Draw();

        void Animate(float dt);

        void Update(float dt);

        void Tap();

    private:
        GameDataRef _data;

        sf::Sprite _playerSprite;
        sf::Sprite _playerSpriteMirrored;
        int _playerState;
    };
}