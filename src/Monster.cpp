#include "Monster.hpp"
#include "DEFINITIONS.hpp"

namespace WappieJump
{
	
	Monster::Monster(GameDataRef data) : _data(data)
	{
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
			float randomWidth = CalculateRandomWidth(_monsterWidth);
			AddCoronaMonster(randomWidth, invisiblePlatY);
		}
	}
	
	void Monster::AddCoronaMonster(float randomWidth, float invisiblePlatY)
	{
		exist = true;
		monsterSprite = sf::Sprite(_data->assets.GetTexture("Corona"));
		
		monsterSprite.setPosition(randomWidth, invisiblePlatY - _monsterHeight * 1.2f);
		monster corona;
		corona.monsterSprite = monsterSprite;
	}
	
	
	void Monster::MoveMonsterY(float velocity)
	{
		if(exist){
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
	
	void Monster::DrawMonster()
	{
		if(exist)
		{
			_data->window.draw(corona.monsterSprite);
		}
	}
}