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
		if (Exist)
		{
			return;
		}
		

		int chance = rand() % 100;
		if (chance <= 25)
		{
			float randomWidth = CalculateRandomWidth(_monsterWidth);
			AddCoronaMonster(randomWidth, invisiblePlatY);
		}
	}
	
	void Monster::AddCoronaMonster(float randomWidth, float invisiblePlatY)
	{
		Exist = true;
		monsterSprite = sf::Sprite(_data->assets.GetTexture("Corona"));
		
		monsterSprite.setPosition(randomWidth, invisiblePlatY - _monsterHeight * 1.2f);
		monster corona;
		corona.monsterSprite = monsterSprite;
	}
	
	
	void Monster::MoveMonsterY(float velocity)
	{
		if(Exist){
			if (corona.monsterSprite.getPosition().y > _data->window.getSize().y)
			{
				Exist = false;
			}
			else
			{
				corona.monsterSprite.move(0, velocity);
			}
		}
	}
	
	void Monster::DrawMonster()
	{
		if(Exist)
		{
			_data->window.draw(corona.monsterSprite);
		}
	}
	
}