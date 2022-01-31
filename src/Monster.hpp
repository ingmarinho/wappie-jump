#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Game.hpp"

namespace WappieJump
{
	
	struct monster
	{
		sf::Sprite monsterSprite;
		bool collided = false;
		int fadeValue = 255;
		
		monster(sf::Sprite monsterSprite)
				: monsterSprite(monsterSprite)
		{}
	};
	
	
	class Monster
	
	{
	
	public:
		
		Monster(GameDataRef data);
		void AddCoronaMonster(float randomWidth, float invisiblePlatY);
		void DrawMonster();
		float CalculateRandomWidth(float monsterWidth);
		void MoveMonsterY(float velocity);
		void SpawnMonster(float invisiblePlatY);
	
	private:
		
		GameDataRef _data;
		monster* corona = nullptr;
		float _monsterWidth;
		float _monsterHeight;
		
	};
	
	
}

