/*
core_logic.c

Liam Muir, 2019,

implementations of functions that are used as the main logic while game is in progress.
*/

#include <stdio.h>
#include <stdlib.h>
#include "core_logic.h"
#include "structs.h"
#include "combat_data.h"

static void print_menu(int player, struct match* game){
	//if player is one, set player_data to the player one
	//if player is two, set player_data to the player two
	//print attack one
	//print attack two
	//print rest of stuff
	//if special perk is gauntlets or magic potions, print here
	//return
}

static void print_status(int player, struct match* game){
	//if player is one, set player_data_a to the player one and set player_data_b to the player two
	//if player is two, set player_data_a to the player two and set player_data_b to the player ones
	//print a health
	//print b ac
	//print b health
	//print b ac
}

struct match* turn(int player, struct match* game){ //deals with input and actions of player one or two
	//print list of actions based on player class and perk (calls print_menu)
	//get input from command line
	//if attack one
	//lookup attack variables based on class from attacks.h
	//if attack two
}

int dead(int player, struct match* game){ //chects if player is dead
	//if player is one
	//check if ones health is 0
	//return 1
	//else return 0
	//if player is two
	//check if twos health is 0
	//return 1
	//else return 0
	//return 0;
}

void resolve(struct match* game){ //says who won
	//if player one is dead
	//player two wins
	//if player two is dead
	//player one wins
	//print (Player (x), you have won!)
}

int playagain(){ //asks player if they want to play again
	//print "Do you want to play again? (y/n): "
	//get input
	//if answer is y, return 1
	//else return 0
}