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
		if (corona != nullptr)
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
		sf::Sprite monsterSprite(_data->assets.GetTexture("Corona"));
		
		platformSprite.setPosition(randomWidth, invisiblePlatY - _monsterHeight * 1.2f);
		corona = &monster(monsterSprite);
	}
	
	
	void Monster::MoveMonsterY(float velocity)
	{
		if(corona != nullptr){
			if (corona.monsterSprite.getPosition().y > _data->window.getSize().y)
			{
				corona = nullptr;
			}
			else
			{
				corona.monsterSprite.move(0, velocity);
			}
		}
	}
	
	void Monster::DrawMonster()
	{
		if(corona != nullptr)
		{
			_data->window.draw(corona.monsterSprite);
		}
	}
	
}