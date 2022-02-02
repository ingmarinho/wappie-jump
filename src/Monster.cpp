#include "Monster.hpp"
#include "DEFINITIONS.hpp"

namespace WappieJump
{
	
	Monster::Monster(GameDataRef data) : _data(data)
	{
		monsterSprite.setTexture(_data->assets.GetTexture("Corona"));
		monsterSprite.setScale(0.72f, 0.72f);

		_monsterWidth = monsterSprite.getGlobalBounds().width;
		_monsterHeight = monsterSprite.getGlobalBounds().height;

		corona.monsterSprite = monsterSprite;
	}

	bool Monster::Exists()
	{
		return exist;
	}
	
	sf::Sprite Monster::GetMonsterSprite()
	{
		return corona.monsterSprite;
	}

	float Monster::CalculateRandomWidth(float monsterWidth)
	{
		int maxWidth = _data->window.getSize().x * 0.99f - monsterWidth;
		return rand() % maxWidth + _data->window.getSize().x * 0.005f;
	}
	
	
	void Monster::SpawnMonster(float invisiblePlatY)
	{
		if (exist)
		{
			return;
		}
		
		int probability = ( _data->score - ( 100 * _data->difficultyLevel ) ) / ( 1/33 * _data->score + 400 );
		int randNum = rand() % 100;
		if (randNum <= probability)
		{
		}
		float randomWidth = CalculateRandomWidth(_monsterWidth);
		AddCoronaMonster(randomWidth, invisiblePlatY);
	}
	
	void Monster::AddCoronaMonster(float randomWidth, float invisiblePlatY)
	{
		exist = true;
		
		corona.monsterSprite.setPosition(randomWidth, invisiblePlatY - 5.0f);

	}
	
	
	void Monster::MoveMonsterY(float velocity)
	{
		if(exist)
		{
			if (corona.monsterSprite.getPosition().y > _data->window.getSize().y)
			{
				exist = false;
			}
			else
			{
				corona.monsterSprite.move(0, velocity);
			}
		}
	}
	
	void Monster::MoveMonsterX()
	{
		switch (corona.monsterDirection)
		{
			case Monster::LEFT:
				if (corona.monsterSprite.getPosition().x <= 0.0f)
				{
					corona.monsterDirection = Monster::RIGHT;
					break;
				}
				else corona.monsterSprite.move(-PLATFORM_MOVEMENT_SPEED, 0.0f);
				break;
			
			case Monster::RIGHT:
				if (corona.monsterSprite.getPosition().x + _platformWidth >= SCREEN_WIDTH)
				{
					corona.monsterDirection = Monster::LEFT;
					break;
				}
				else corona.monsterSprite.move(PLATFORM_MOVEMENT_SPEED, 0.0f);
				break;
			
			default:
				break;
		}

	}
	
	void Monster::DrawMonster()
	{
		if(exist)
		{
			_data->window.draw(corona.monsterSprite);
		}
	}
}