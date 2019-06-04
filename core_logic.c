/*
core_logic.c

Liam Muir, 2019,

implementations of functions that are used as the main logic while game is in progress.

Combat system spec:

attacks are done by determining a random number between one and twenty.

if the number exeeds the ac of the opponent, the attack hits.

all weapons have a bonus to the attack roll, it is added. negative bonuses are allowed.

if the player is not in range, alert player and return to menu

the players can't move backwards if the distance is eight (to account for random 1 or 2 forwards or backwards, if the final result is 8 or more
after moving backwards, it sets the distance to 8)

the players can't move forwards if the distance is one (to account for random 1 or 2 forwards or backwards, if the final result is 1 or less 
after moving forwards, it sets the distance to 1)



*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

struct attack attacktable[6] = {{3,2},{1,1},{1,3},{2,2},{5,-1},{1,3}}; //starts with fireball data, goes to dagger data, in up-down, left right order,
//data order is range, bonus

int actable[3] = {11,14,12}; //based on numbers for each class offered on help string, goes in order of mage, knight, archer

struct dice dicetable[6] = {{5,7},{3,5},{5,6},{2,4},{6,7},{2,5}};//starts with fireball, goes to dagger, in up-down, left right order
//data order is min, max

struct dice gauntlets = {3,7}; //one off for gauntlets perk

struct dice healingpotion = {4,8}; //one off for healing perk
//---------------------------------------------------------------------------------------------------------------------------------------------------
//combat helpers

int dice(int min, int max){
	//set seed to current time
	time_t seed = time(NULL);
	srandom(seed);
	//uses seed for debuging purposes
	//make random number p between min and max
	//return the number
	return (random() % (max - min + 1))+min;
}

int calculate_hit(struct match* game, int attack_num, int target, int player_num){ //attack is one or two
	struct player p_info;
	if (player_num == 1){
		p_info = game->p1;
	}else if(player_num == 2){
		p_info = game->p2;
	}else{
		return -1;
	}
	//using attack array, get index for dice and data by using index calculation
	//index is ((p_info class times two) - 2) + (attack_num-1)
	int index = ((p_info.class * 2)-2)+(attack_num-1);
	
	//check if attack is in range
	if(attacktable[index].range < game->distance){
		return 0;
	}
	//if not, return 0
	//calculate dice roll with dice table and add/subtract bonus from attack table
	int r = dice(1,20) + attacktable[index].bonus;
	//if its more than o_info ac, then return 2
	if (r >= target){
		return 2;
	}else{
		return 1;
	}
	//if its less than o_info ac, then return 1
}

int damage(int class, int attack_num){//calculates damage from attack with class and attack number
	//get index for attack
	int index = ((class * 2)-2)+(attack_num-1);
	//calulate and return
	return dice(dicetable[index].min, dicetable[index].max);
}

void move_forwards(struct match* game){
	//randomly generate number between 1 and 2
	int r = dice(1,2);
	//if distance - random number is equal or less than 1
	if (game->distance - r <= 1){
		game->distance = 1;
	}else{
		game->distance -= r;
	}
	//set distance to one
	//else
	//distans equals distance minis random number
}

void move_backwards(struct match* game){
	//randomly generate number between 1 and 2
	int r = dice(1,2);
	//if distance - random number is more or equal to 1
	if (game->distance + r >= 8){
		game->distance = 8;
	}else{
		game->distance += r;
	}
	//set distance to one
	//else
	//distans equals distance minis random number
}

void parry(struct match* game, int player_num){ //parry adds +3 ac
	//set player one parry to 1 if player one
	//set player two parry to 1 if player two
	if (player_num == 1){
		game->p1.parry = 1;
	}else if(player_num == 2){
		game->p2.parry = 1;
	}else{
		return;
	}

}

void reset_parry(struct match* game, int player_num){ //parry adds +3 ac
	//set player one parry to 1 if player one
	//set player two parry to 1 if player two
	if (player_num == 1){
		game->p1.parry = 0;
	}else if(player_num == 2){
		game->p2.parry = 0;
	}else{
		return;
	}

}

//---------------------------------------------------------------------------------------------------------------------------------------------------
//menu functions

void print_menu(int player, struct match* game){

	if (player == 1){	//if player is one, execute code for the player one
		if (game->p1.class == MAGE){ // if then else for printing the first two items
			printf("1. Fireball\n2. Staff\n");
		} else if (game->p1.class == KNIGHT){
			printf("1. Sword\n2. Lance\n");
		} else if (game->p1.class == ARCHER){
			printf("1. Bow\n2. Dagger\n");
		}

		printf("3. Block\n4. Move Forwards\n5. Move Backwards\n6. Status\n7. Nothing\n"); //prints rest of regular actions

		if (game->p1.perk == GAUNT){ //if else for special perks that give an extra action
			printf("8. Gauntlets\n");
		} else if(game->p1.perk == HEAL){
			if (game->p1.healing_potions > 0){
				printf("8. Healing Potions\n");
			}		
		}
	}else if(player == 2){//if player is two, execute instructions for the player two
		if (game->p2.class == MAGE){ // if then else for printing the first two items
			printf("1. Fireball\n2. Staff\n");
		} else if (game->p2.class == KNIGHT){
			printf("1. Sword\n2. Lance\n");
		} else if (game->p2.class == ARCHER){
			printf("1. Bow\n2. Dagger\n");
		}

		printf("3. Block\n4. Move Forwards\n5. Move Backwards\n6. Status\n7. Nothing\n"); //prints rest of regular actions

		if (game->p2.perk == GAUNT){ //if else for special perks that give an extra action
			printf("8. Gauntlets\n");
		} else if(game->p2.perk == HEAL){
			if (game->p2.healing_potions > 0){
				printf("8. Healing Potions\n");
			}		
		}
	}else{ //don't continue if different
		return;
	}
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

int get_input(){ //gets input after print menu
	//print input line
	int p;
	while(1){
		printf("\nSelect an Option: ");
		scanf("%i",&p);
		if (p < 1 || p > 8){
			continue;
		}else{
			return p;
		}
	}
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
//high level functions

struct match* turn(int player, struct match* game){ //deals with input and actions of player one or two
	//make attack_num variable and set to 0
	//make move variable and set it to 0
	//reset parry
	//enter loop
	//print "Your turn, player x!"
	//print list of actions based on player class and perk (calls print_menu)
	//get input from command line

	//if attack one
	//set attack_num to 1

	//else if attack two
	//set attack_num to 2
	
	//else if parry
	//call parry function

	//else if move_forwards
	//if move variable is 0
	//move forwards
	//set move variable to 1
	//continue

	//else if move_backwards
	//if move variable is 0
	//move backwards
	//set move variable to 1
	//continue

	//else if status
	//print status
	//continue

	//else if nothing
	//break

	//else if special perk
	//if perk is potions
	//if potions left is more than or equal to one
	//potions left decrement
	//hp is hp plus dice of healing potion
	//continue

	//if move variable is not equal to 0
	//if move is more than one
	//move forwards
	//if move is less than one
	//move backwards

	//if attack_num is not equal to 0
	//call calculate hit with attack two towards opponent
	//if not in range, 
	//error message
	//set attack_num to 0
	//continue

	//if a hit
	//print "your attack hit"
	//calculate damage and 
	//break
	//else
	//print "your attack did not hit"
	//break
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

//---------------------------------------------------------------------------------------------------------------------------------------------------
