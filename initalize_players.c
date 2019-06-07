/*
initalize_players.c

Liam Muir, 2019

implementations of functions to initalize player data.

1 is healing potions, 2 is magic weapons, 3 is gauntlets
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "initalize_players.h"

int actableinit[3] = {11,14,12}; //based on numbers for each class offered on help string, goes in order of mage, knight, archer
int hptableinit[3] = {30,40,35};


const char* helpClass = "The character you choose determines the attacks you can use, the HP you have, and your AC.\nThe mage has fireball, staff, 30 HP and an AC of 11.\nThe knight has sword, lance, 40 HP and an AC of 14.\nThe archer has bow, dagger, 35 HP and an AC of 12";
const char* helpPerks = "The perk you choose determines the special actions you can take to give you an edge against your opponent\nYou get three healing potions that heal 4-8 HP each if you choose healing.\nThe magic weapons deal 3 more damage than normal.\nThe gauntlets allow you to punch your opponents, dealing 3-7 damage when hit.";

static int getBeginData(char* question,char* option_one, char* option_two, char* option_three, const char* help_text){//general logic for three choice question asking
	while(1){
		printf("\n%s\n\n", question);
		printf("1:%s, 2:%s, 3:%s, 4:help: ", option_one, option_two, option_three);
		int answer;
		char input[30];
		fgets(input,30,stdin);
		answer = atoi(input);
		switch(answer){
			case 1:
			return 1; 
			break;
			case 2:
			return 2;
			break;
			case 3:
			return 3;
			break;
			case 4:
			printf("\n%s\n", help_text);
			break;
			default:
			break;
		}
	}
	return 0;
}

static struct player* beginPlayer(){ //handles the begining text and gets players choice 
	int class = getBeginData("Choose Your Fighter!","Mage","Knight","Archer",helpClass);
	int perk = getBeginData("Choose Your Special Perk!","Healing Potions","Magic Weapons","Gauntlets",helpPerks);
	struct player* newplayer = calloc(1,sizeof(struct player));
	newplayer->class = class;
	newplayer->perk = perk;
	newplayer->ac = actableinit[class-1];
	newplayer->hp = hptableinit[class-1];
	if (perk == 1)
		newplayer->healing_potions = 3;
	return newplayer;
}

static void printClassVs(struct match* game){ //prints versus message
	switch(game->p1.class){
		case MAGE:
		printf("\nMage");
		break;
		case ARCHER:
		printf("\nArcher");
		break;
		case KNIGHT:
		printf("\nKnight");
		break;
	}
	printf(" vs ");
	switch(game->p2.class){
		case MAGE:
		printf("Mage!\n");
		break;
		case ARCHER:
		printf("Archer!\n");
		break;
		case KNIGHT:
		printf("Knight!\n");
		break;
	}
	printf("\n");
}

struct match* initgame(){ //initalizes game
	struct match* game = malloc(sizeof(struct match));
	printf("\nWelcome to Text Fighters!\n");
	printf("\nPlayer one,\n");
	game->p1 = *beginPlayer();
	printf("\nPlayer two,\n");
	game->p2 = *beginPlayer();
	game->distance = 2;
	game->p1.parry = 0;
	game->p2.parry = 0;
	printClassVs(game);
	return game;
}