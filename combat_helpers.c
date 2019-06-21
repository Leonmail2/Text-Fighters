/*
combat_helpers.c

Liam Muir, 2019

File to hold all functions that turn function uses
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "structs.h"

struct attack{
	//data for attack
	int range;
	int bonus;
};

struct dice{
	int min;
	int max;
};

struct attack attacktable[6] = {{3,1},{1,2},{1,3},{2,2},{5,-1},{1,3}}; //starts with fireball data, goes to dagger data, in up-down, left right order,
//data order is range, bonus

int actable[3] = {11,14,12}; //based on numbers for each class offered on help string, goes in order of mage, knight, archer

struct dice dicetable[6] = {{5,7},{3,5},{5,6},{2,4},{6,7},{2,5}};//starts with fireball, goes to dagger, in up-down, left right order
//data order is min, max

struct dice gauntletdice = {3,7}; //one off

struct attack gauntlets = {1,1}; //one off

struct dice healingpotion = {4,8}; //one off for healing perk

int dice(int min, int max){
	//set seed to current time
	time_t seed = time(NULL);
	srandom(seed);
	//uses seed for debuging purposes
	//make random number p between min and max
	//return the number
	return (random() % (max - min + 1))+min;
}

int calculate_hit(struct match* game, int player_num, int attack_num, int target){ //attack is one or two
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

int calculate_gauntlet_hit(struct match* game, int player_num, int target){
	struct player p_info;
	if (player_num == 1){
		p_info = game->p1;
	}else if(player_num == 2){
		p_info = game->p2;
	}else{
		return -1;
	}
	if (p_info.perk != GAUNT){
		return -1;
	}
	//using attack array, get index for dice and data by using index calculation
	//index is ((p_info class times two) - 2) + (attack_num-1)
	
	//check if attack is in range
	if(gauntlets.range < game->distance){
		return 0;
	}
	//if not, return 0
	//calculate dice roll with dice table and add/subtract bonus from attack table
	int r = dice(1,20) + gauntlets.bonus;
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

int gauntlet_damage(){
	return dice(gauntletdice.min,gauntletdice.max);
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

void add_health(struct match* game, int player_num){
	if (player_num == 1){
		if (game->p1.perk == HEAL){
			game->p1.hp = game->p1.hp + dice(healingpotion.min,healingpotion.max);
		}
	}else if (player_num == 2){
		if (game->p2.perk == HEAL){
			game->p2.hp = game->p2.hp + dice(healingpotion.min,healingpotion.max);
		}
	}else{
		return;
	}
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
//menu functions

void print_menu(struct match* game, int player){
	char melee[5];
	char bow[5];
	char lance[5];
	char fireball[5];
	if (game->distance > attacktable[5].range){
		strcpy(melee,"not ");
	}else{
		strcpy(melee,"");
	}
	if (game->distance > attacktable[4].range){
		strcpy(bow,"not ");
	}else{
		strcpy(bow,"");
	}
	if (game->distance > attacktable[3].range){
		strcpy(lance,"not ");
	}else{
		strcpy(lance,"");
	}
	if (game->distance > attacktable[0].range){
		strcpy(fireball,"not ");
	}else{
		strcpy(fireball,"");
	}

	if (player == 1){	//if player is one, execute code for the player one
		int index = ((game->p1.class * 2)-2);
		if (game->p1.class == MAGE){ // if then else for printing the first two items
			printf("1. Fireball (%sin range)\n2. Staff (%sin range)\n",fireball,melee);
		} else if (game->p1.class == KNIGHT){
			printf("1. Sword (%sin range)\n2. Lance (%sin range)\n",melee,lance);
		} else if (game->p1.class == ARCHER){
			printf("1. Bow (%sin range)\n2. Dagger (%sin range)\n",bow,melee);
		}

		printf("3. Block\n4. Move Forwards\n5. Move Backwards\n6. Status\n7. Continue\n"); //prints rest of regular actions

		if (game->p1.perk == GAUNT){ //if else for special perks that give an extra action
			char no[5];
			if (game->distance > gauntlets.range){
				strcpy(no,"not ");
			}else{
				strcpy(no,"");
			}
			printf("8. Gauntlets (%sin range)\n", no);
		} else if(game->p1.perk == HEAL){
			if (game->p1.healing_potions > 0){
				printf("8. Healing Potions (%i left)\n",game->p1.healing_potions);
			}		
		}
	}else if(player == 2){//if player is two, execute instructions for the player two
		if (game->p2.class == MAGE){ // if then else for printing the first two items
			printf("1. Fireball (%sin range)\n2. Staff (%sin range)\n",fireball,melee);
		} else if (game->p2.class == KNIGHT){
			printf("1. Sword (%sin range)\n2. Lance (%sin range)\n",melee,lance);
		} else if (game->p2.class == ARCHER){
			printf("1. Bow (%sin range)\n2. Dagger (%sin range)\n",bow,melee);
		}

		printf("3. Block\n4. Move Forwards\n5. Move Backwards\n6. Status\n7. Continue\n"); //prints rest of regular actions

		if (game->p2.perk == GAUNT){ //if else for special perks that give an extra action
			char no[5];
			if (game->distance > gauntlets.range){
				strcpy(no,"not ");
			}else{
				strcpy(no,"");
			}
			printf("8. Gauntlets (%sin range)\n", no);
		} else if(game->p2.perk == HEAL){
			if (game->p2.healing_potions > 0){
				printf("8. Healing Potions (%i left)\n",game->p2.healing_potions);
			}		
		}
	}else{ //don't continue if different
		return;
	}
}

void print_status(struct match* game, int player){
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
	if(player_data_a.perk == HEAL){
		printf("Healing Potions Left: %i\n", player_data_a.healing_potions);
	}

	printf("Distance: %i\n", game->distance);

	printf("Your HP: %i\n", player_data_a.hp);
	//print a ac
	printf("Your AC: %i\n", player_data_a.ac);
	//print healing potions if a has the perk
	
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
		char input[30];
		fgets(input, 30, stdin);
		printf("\n");
		p = atoi(input);
		if (p < 1 || p > 8){
			return 0;
		}else{
			return p;
		}
	}
}
