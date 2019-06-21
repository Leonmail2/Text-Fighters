/*
core_logic.h

Liam Muir, 2019

the header for core_logic.h
*/


#ifndef __CORE_LOGIC__
#define __CORE_LOGIC__

struct match;

#include "structs.h"

//------------------------------------------------------------------------
int turn(struct match* game, int player); //deals with input and actions of player one or two

int dead(struct match* game, int player); //chects if player is dead

void resolve(struct match* game); //says who won

int again();

#endif