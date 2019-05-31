/*
core_logic.h

Liam Muir, 2019

the header for core_logic.h
*/


#ifndef __CORE_LOGIC__
#define __CORE_LOGIC__

struct match;

#include "structs.h"

int dice(int min, int max);

int calculate_hit(struct match* game, int attack_num, int target, int player_num);

int damage(int class, int attack_num);

void print_menu(int player, struct match* game); //prints action menu

void print_status(int player, struct match* game); //prints status of player

int get_input();

struct match* turn(int player, struct match* game); //deals with input and actions of player one or two

int dead(int player, struct match* game); //chects if player is dead

void resolve(struct match* game); //says who won

int playagain(); //asks player if they want to play again

#endif