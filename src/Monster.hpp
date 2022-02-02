#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Game.hpp"

namespace WappieJump
{
	
	class Monster
	{
		enum direction
		{
			RIGHT,
			LEFT,
			NONE
		};
		
		struct monster
		{
			sf::Sprite monsterSprite;
			bool collided = false;
			int fadeValue = 255;
			direction monsterDirection = LEFT;
		};

	public:
		Monster(GameDataRef data);

		void AddCoronaMonster(float randomWidth, float invisiblePlatY);
		bool Exists();
		sf::Sprite GetMonsterSprite();
		void DrawMonster();
		float CalculateRandomWidth(float monsterWidth);
		void MoveMonsterY(float velocity);
		void SpawnMonster(float invisiblePlatY);
		void MoveMonsterX();

	private:
		GameDataRef _data;
		monster corona;
		sf::Sprite monsterSprite;
		float _monsterWidth;
		float _monsterHeight;
		bool exist = false;
	};

}
