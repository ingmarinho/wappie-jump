#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "State.hpp"
#include "Game.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"

namespace WappieJump
{
	class CharacterSelectionState: public State
	{
	public:
		CharacterSelectionState(GameDataRef data);

		void BounceCharacter();
		int AlignObjectCenterX(sf::Sprite object);
        int AlignObjectCenterY(sf::Sprite object);
		void Init();

		void HandleInput();
		void Update();
		void Draw();


	private:		
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _title;
		sf::Sprite _char1;
		sf::Sprite _char2;
		sf::Sprite _char3;
		sf::Sprite _char4;
		sf::Sprite _char5;
		sf::Sprite _char6;
		sf::Sprite _char7;
		sf::Sprite _char8;
	
		sf::Sprite _leftArrow;
		sf::Sprite _rightArrow;
		sf::Sprite _selectButton;
		sf::Sprite _homeButton;

		std::vector<sf::Sprite*> _chars = {&_char1, &_char2, &_char3, &_char4, &_char5, &_char6, &_char7, &_char8};

		float _characterVelocityY = -PLAYER_VELOCITY_Y * 0.7f;
		sf::Sprite &_selectedCharacter = *_chars[0];
		float _basePositionY;
		int _selected = 0;
		bool mouseClicked = false;
	};
}