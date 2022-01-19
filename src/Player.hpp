#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>
#include <iostream>

#include "DEFINITIONS.hpp"

namespace Sonar
{
    class Player
    {
        enum movement
        {
            MOVING,
            STANDING,
            JUMPING,
            FALLING
        };

    public:
        Player(GameDataRef data);

        void setPlayerTexture(const sf::Texture &texture);

        void Draw();

        void Animate(float dt);

        void Update(float dt);

    private:
        GameDataRef _data;

        movement playerMovement = STANDING;

        sf::Sprite _player;
        int _playerState;
    };
}