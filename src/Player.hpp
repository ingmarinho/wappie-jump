#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

#include "DEFINITIONS.hpp"


namespace Sonar
{
    class Player
    {
    public:
        Player(GameDataRef data);

        void Draw();

        void Animate(float dt);

        void Update(float dt);

        void Tap();

    private:
        GameDataRef _data;

        sf::Sprite _playerSprite;
        sf::Sprite _playerSpriteMirrored;
        sf::Sprite _playerCurrent;
        int _playerState;
    };
}