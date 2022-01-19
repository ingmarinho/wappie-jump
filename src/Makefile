#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := AssetManager.cpp Game.cpp GameOverState.cpp GameState.cpp InputManager.cpp MainMenuState.cpp SplashState.cpp StateMachine.cpp Platform.cpp Player.cpp Collision.cpp

# header files in this project
HEADERS := AssetManager.hpp DEFINITIONS.hpp Game.hpp GameOverState.hpp GameState.hpp InputManager.hpp MainMenuState.hpp SplashState.hpp State.hpp StateMachine.cpp Platform.hpp Player.hpp Collision.hpp

# other places to look for files for this project
SEARCH  := 

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.native
