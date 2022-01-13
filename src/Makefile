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
SOURCES := Assets.cpp Doodler.cpp Engine.cpp EventLoop.cpp GameState.cpp IEntity.h IState.h KeyboardState.cpp Menu.cpp Overlay.cpp Platform.cpp Sprite.cpp States.cpp View.cpp

# header files in this project
HEADERS := Assets.h consts.h Doodler.h Engine.h enums.h EventLoop.h GameState.h IPhysicsObject.h KeyboardState.h Menu.h Overlay.h Platform.h Sprite.h States.h View.h

# other places to look for files for this project
SEARCH  := 

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.native
