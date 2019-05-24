/*
core_logic.c

Liam Muir, 2019,

implementations of functions that are used as the main logic while game is in progress.
*/

#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "core_logic.h"

struct attack{
	//data for attack
	int range;
	int bonus;
};

struct dice{
	int min;
	int max;
};

struct attack attacktable[6] = {{3,2},{1,1},{1,3},{2,2},{5,-2},{1,3}}; //starts with fireball data, goes to dagger data, in up-down, left right order,
//data order is range, bonus

int actable[3] = {11,14,12}; //based on numbers for each class offered on help string, goes in order of mage, knight, archer

struct dice dicetable[6] = {{5,7},{3,5},{5,6},{2,4},{6,7},{2,5}};//starts with fireball, goes to dagger, in up-down, left right order
//data order is min, max

struct dice gauntlets = {3,7}; //one off for gauntlets perk

struct dice healingpotion = {4,8}; //one off for healing perk

void print_menu(int player, struct match* game){

	struct player player_data;
	if (player == 1){	//if player is one, set player_data to the player one
		struct player player_data = game->p1;
	}else if(player == 2){//if player is two, set player_data to the player two
		struct player player_data = game->p2;
	}else{ //don't continue if different
		return;
	}

	if (player_data.class == MAGE){ // if then else for printing the first two items
		printf("1. Fireball\n2. Staff\n");
	} else if (player_data.class == KNIGHT){
		printf("1. Sword\n2. Lance\n");
	} else if (player_data.class == MAGE){
		printf("1. Bow\n2. Dagger\n");
	}

	printf("3. Block\n4. Move Forwards\n5. Move Backwards\n6. Status\n"); //prints rest of regular actions

	if (player_data.perk == GAUNT){ //if else for special perks that give an extra action
		printf("7. Gauntlets\n");
	} else if(player_data.perk == HEAL){
		if (player_data.healing_potions > 0){
			printf("7. Healing Potions\n");
		}		
	}
	return;
}

void print_status(int player, struct match* game){
	//if player is one, set player_data_a to the player one and set player_data_b to the player two
	//if player is two, set player_data_a to the player two and set player_data_b to the player ones
	struct player player_data_a;
	struct player player_data_b;
	if (player == 1){
		player_data_a = game->p1;
		player_data_b = game->p2;
	}else if(player == 2){
		player_data_a = game->p2;
		player_data_b = game->p1;
	}else{ //don't continue if number is not in range
		return;
	}


	//print a health
	printf("HP: %i\n", player_data_a.hp);
	//print a ac
	printf("AC: %i\n", player_data_a.ac);
	//print healing potions if a has the perk
	if(player_data_a.perk == HEAL){
		printf("Healing Potions Left: %i\n", player_data_a.healing_potions);
	}
	//print b health
	printf("Opponents HP: %i\n", player_data_b.hp);
	//print b ac
	printf("Opponents AC: %i\n", player_data_b.ac);

	//print healing potions if b has the perk
	if(player_data_b.perk == HEAL){
		printf("Opponents Healing Potions Left: %i\n", player_data_b.healing_potions);
	}
	return;
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