#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <math.h>

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

        bool hasReachedMaxDistance();

        sf::Sprite& GetPlayerSprite();
        Movement GetPlayerMovement();
        float GetPlayerVelocityY();

        void SetJumpVelocity(float newVelocity);
        void SetBoostJumpVelocity(float newVelocity);

        void SetPlayerPosition(float x, float y);
        void SetPlayerVelocityY(float velocity);
        void SetPlayerAngle(Angle newPlayerAngle);
        void SetPlayerMovement(Movement newPlayerMovement);

        void MoveRight();
        void MoveLeft();

        void Draw();
        void Update();

    private:
        GameDataRef _data;

        sf::Vector2f _velocity = {PLAYER_VELOCITY_X, -PLAYER_VELOCITY_Y};
        float _jumpVelocity = -PLAYER_VELOCITY_Y;
        float _boosterJumpVelocity = -BOOSTER_VELOCITY_Y;
        bool _reachedMaxDistance = false;

        Movement _playerMovement = FALLING;
        Angle _playerAngle = LEFT;

        sf::Sprite _player;
    };
}