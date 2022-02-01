#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Game.hpp"

namespace WappieJump
{

	class Monster
	{
		struct monster
		{
			sf::Sprite monsterSprite;
			bool collided = false;
			int fadeValue = 255;
		};

	public:
		Monster(GameDataRef data);

		void AddCoronaMonster(float randomWidth, float invisiblePlatY);
		void DrawMonster();
		float CalculateRandomWidth(float monsterWidth);
		void MoveMonsterY(float velocity);
		void SpawnMonster(float invisiblePlatY);

	private:
		GameDataRef _data;
		monster corona;
		sf::Sprite monsterSprite;
		float _monsterWidth;
		float _monsterHeight;
		bool Exist = false;
	};

}
