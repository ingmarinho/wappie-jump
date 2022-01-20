#include "Collision.hpp"

namespace Sonar
{
    Collision::Collision(GameDataRef data) : _data(data)
	{
	}

    bool Collision::CheckPlatformBounceCollision(sf::Sprite platform, sf::Sprite player)
    {
        sf::FloatRect platformRect = platform.getGlobalBounds();
        sf::FloatRect playerRect = player.getGlobalBounds();


        return  platformRect.top <= playerRect.top + playerRect.height // bottom of player
                &&
                platformRect.left < playerRect.left + playerRect.width * 0.8
                &&
                platformRect.left + platformRect.width >= playerRect.left + playerRect.width * 0.3
                && 
                platformRect.top + platformRect.height >= playerRect.top + playerRect.height;

                // &&
                // platformRect.left + platformRect.width > playerRect.left + 0.2 * playerRect.width; 
        // return  platformRect.top <= playerRect.top + playerRect.height // bottom of player
        //         &&
        //         platformRect.left < playerRect.left + playerRect.width * 0.8
        //         &&
        //         platformRect.left + platformRect.width > playerRect.left + 0.2 * playerRect.width; 
    }

    bool Collision::CheckWindowBottomBounceCollision(sf::Sprite player)
    {
        return SCREEN_HEIGHT <= player.getPosition().y + player.getGlobalBounds().height;
    }
}