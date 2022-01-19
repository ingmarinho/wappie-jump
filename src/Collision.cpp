#include "Collision.hpp"
#include <iostream>

namespace Sonar
{
    bool Collision::CheckPlayerBounceCollision(sf::Sprite platform, sf::Sprite player)
    {
        sf::Rect<float> platformRect = platform.getGlobalBounds();
        sf::Rect<float> playerRect = player.getGlobalBounds();

        return  platformRect.top <= playerRect.top + playerRect.height // bottom of player
                &&
                platformRect.left < playerRect.left + playerRect.width * 0.8
                &&
                platformRect.left + platformRect.width > playerRect.left + 0.2 * playerRect.width; 
    }
}