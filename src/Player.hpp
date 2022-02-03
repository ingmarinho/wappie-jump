#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <math.h>

#include "Game.hpp"

#include "DEFINITIONS.hpp"

/// @file

/// Player
/// This class manages and controls all player based events/actions such as movement of the player,
/// applying gravity to the player, changing the color and correcting the player angle.

namespace WappieJump
{
    class Player
    {
    public:
        /// Player directions
        enum Angle
        {
            LEFT,
            RIGHT
        };
        /// Player movement states?
        enum Movement
        {
            JUMPING,
            RISING,
            FLOATING,
            FALLING,
            DEATHFALL
        };

    public:
        /// Construct by providing GameDataRef
        Player(GameDataRef data);
        /// Returns a bool on wether or not max distance has been reached
        bool hasReachedMaxDistance();
        /// Returns a reference to the chosen character sprite
        sf::Sprite* GetPlayerSprite();
        /// Returns the current movement state in which the player occurs
        Movement GetPlayerMovement();
        /// Returns the current speed of the player
        sf::Vector2f GetPlayerVelocity();

        /// Function to set the new velocity based on the platform category
        void SetJumpVelocity(float newVelocity);
        /// Function to set the current player position to a new X and Y
        void SetPlayerPosition(float x, float y);
        /// Fucntion to change the upwards (Y) velocity of the player
        void SetPlayerVelocityY(float velocity);
        /// Function to make the character look in the right direction based on keyboard input
        void SetPlayerAngle(Angle newPlayerAngle);
        /// Function to set the right variables with to the movement cases 
        void SetPlayerMovement(Movement newPlayerMovement);
        /// Function to fade the characters color for when he interacts with a booster platform
        void ChangePoisonColor();
        /// Sets the Color for when the character interacts with a booster platform
        void SetPoisonColor();
        /// Sets the color for when the character interacts with a monster and dies
        void SetPlayerDeathColor();
        /// Function to move the character right
        void MoveRight();
        /// Function to move the character left
        void MoveLeft();
        /// Makes sure the character stops moving on the horizontal axis 
        void Decelleration();
        /// Draws the player on the screen
        void Draw();
        /// Updates the characters position based on the current movement state
        void Update();

    private:
        GameDataRef _data;

        sf::Vector2f _velocity = {0.0f, -PLAYER_VELOCITY_Y};
        float _jumpVelocity = -PLAYER_VELOCITY_Y;
        float _boosterJumpVelocity = -BOOSTER_VELOCITY_Y;
        bool _reachedMaxDistance = false;
        float _poisonFadeValue = 155.0f;

        Movement _playerMovement = JUMPING;
        Angle _playerAngle = LEFT;

        sf::Sprite _player;
    };
}