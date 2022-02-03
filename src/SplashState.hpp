#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace WappieJump
{
	/// Splash State
	///
	///	This class is responsible for showing a splash screen before showing the main menu state.
	///	It also loads in certain assets such as the sounds.

	class SplashState : public State
	{
	public:
		/// Construct by providing GameDataRef
		SplashState(GameDataRef data);

		/// Loads all screen object images and sets their positions 
		void Init();						
		///	Manages hardware input 	
		void HandleInput();
		/// Handles how long splash state is visible and the switch to main menu state 
		void Update();
		/// Draws the screen objects
		void Draw();						

	private:
		GameDataRef _data;

		sf::Clock _clock;
		sf::Sprite _background;
		
		
	};
}