#pragma once

#include <memory>
#include <stack>

#include "State.hpp"

/// @file


namespace WappieJump
{
	/// State Machine
	///
	/// Contains functionality for switching between states and cleaning them up afterwards
	///
	typedef std::unique_ptr<State> StateRef;

	class StateMachine
	{
	public:
		StateMachine() { }
		~StateMachine() { }
		
		/// Function to declare a new state and switch to that state
		void AddState(StateRef newState, bool isReplacing = true);
		/// Function to remove previously visited states
		void RemoveState();
		/// Run at start of each loop in Game.cpp
		void ProcessStateChanges();
		/// Returns the current state
		StateRef &GetActiveState();

	private:
		std::stack<StateRef> _states;
		StateRef _newState;

		bool _isRemoving;
		bool _isAdding, _isReplacing;
	};
}