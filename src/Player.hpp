#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "Game.hpp"
#include "Platform.hpp"
#include "Collision.hpp"

#include "DEFINITIONS.hpp"

namespace Sonar
{
    class Player
    {
        enum movement
        {
            JUMPING,
            FALLING
        };

    public:
        Player(GameDataRef data, Platform* platform, Collision* collision);

        void setPlayerTexture(const sf::Texture &texture);
        void Draw();
        void Update(float dt);
        void MoveRight();
        void MoveLeft();

    private:
        GameDataRef _data;
        Platform* platform;
        Collision* collision;

        sf::Vector2f _velocity = {5.0f, -20.0f};
        float _gravity = 0.7f;
        movement playerMovement = FALLING;

        sf::Sprite _player;
        int _playerState;
    };
}