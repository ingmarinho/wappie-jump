#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "State.hpp"
#include "Game.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"

///@file

namespace WappieJump
{
	/// Character Selection State
	///
	/// The character selection state is a point in the game 
	/// where the player can choose between eight different characters to play with.
	
	class CharacterSelectionState: public State
	{
	public:
		/// Construct by providing GameDataRef
		CharacterSelectionState(GameDataRef data);

    	/// Function that sets the position 
		/// for all the character sprites and makes them go up down
		void BounceCharacter(); 			
		/// Returns the X position to center an object on the X-axis
		int AlignObjectCenterX(sf::Sprite object);		
		/// Returns the Y position to center an object on the Y-axis
        int AlignObjectCenterY(sf::Sprite object);		
		
		/// Loads all screen object images and sets their positions 
		void Init();
		///	Manages hardware input 									
		void HandleInput();	
		/// Updates the sprite when user scrolls through characters							
		void Update();	
		/// Draws the screen objects								
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

		sf::Sound &_buttonPressSound; 

		std::vector<sf::Sprite*> _chars = {&_char1, &_char2, &_char3, &_char4, &_char5, &_char6, &_char7, &_char8};

		float _characterVelocityY = -PLAYER_VELOCITY_Y * 0.7f;
		sf::Sprite &_selectedCharacter = *_chars[0];
		float _basePositionY;
		int _selected = 0;
		bool mouseClicked = false;
	};
}