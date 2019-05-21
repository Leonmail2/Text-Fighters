/*
core_logic.h

Liam Muir, 2019

the header for core_logic.h
*/


#ifndef __CORE_LOGIC__
#define __CORE_LOGIC__

static void print_menu(int player, struct match* game); //prints action menu

static void print_status(int player, struct match* game); //prints status of player

struct match* turn(int player, struct match* game); //deals with input and actions of player one or two

int dead(int player, struct match* game); //chects if player is dead

void resolve(struct match* game); //says who won

int playagain(); //asks player if they want to play again

#endif