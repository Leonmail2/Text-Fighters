/*
initalize_players.c

Liam Muir, 2019

implementations of functions to initalize player data.
*/

#ifndef __INITALIZE_PLAYERS__
#define __INITALIZE_PLAYERS__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "initalize_players.h"
#include "structs.h"

static int getBeginData(char* question,char* option_one, char* option_two, char* option_three, const char* help_text);//general logic for question asking
	

static struct player* beginPlayer(); //handles the begining text and gets players choice 

static void printClassVs(struct match* game); //prints versus message

struct match* initgame(); //initalizes game

#endif