#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "Game.hpp"

#include "DEFINITIONS.hpp"

namespace WappieJump
{
    class Player
    {
    public:
        enum Angle
        {
            LEFT,
            RIGHT
        };
        enum Movement
        {
            JUMPING,
            BOOSTJUMPING,
            RISING,
            FLOATING,
            FALLING
        };

    public:
        Player(GameDataRef data);

        sf::Sprite& GetPlayerSprite();
        Movement GetPlayerMovement();
        void SetPlayerPosition(float x, float y);
        float GetPlayerVelocityY();
        void SetPlayerVelocityY(float velocity);
        void SetPlayerAngle(Angle newPlayerAngle);
        void SetPlayerMovement(Movement newPlayerMovement);
        void MoveRight();
        void MoveLeft();
        void Draw();
        void Update();

    private:
        GameDataRef _data;

        sf::Vector2f _velocity = {PLAYER_VELOCITY_X, PLAYER_VELOCITY_Y};

        Movement _playerMovement = FALLING;
        Angle _playerAngle = LEFT;

        sf::Sprite _player;
        int _playerState;
    };
}