/*
initalize_players.c

Liam Muir, 2019

implementations of functions to initalize player data.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "initalize_players.h"
#include "structs.h"

#define MAGE 1
#define KNIGHT 2
#define ARCHER 3

const char* helpClass = "The character you choose determines the attacks you can use and the HP you have.\nThe mage has fireball, staff, and has 30 HP.\nThe knight has sword, lance, and has 40 HP.\nThe archer has bow, dagger, and has 35 HP";
const char* helpPerks = "The perk you choose determines the special actions you can take to give you an edge against your opponent\nYou get three healing potions that heal 4-8 HP each if you choose healing.\nThe magic weapons deal %20 percent more damage than normal.\nThe gauntlets allow you to punch your opponents, dealing 3-7 damage when used.";

/*

Interface Idea:

Welcome to Text Fighters!
Choose your fighter! 
1:mage, 2:knight, 3:archer, 4:help: *2*
Choose your special perk! 
1:health potions, 2:magic weapons, 3:gauntlets, 4:help: *2*
Choose your difficulty! 
1:wimp, 2:good enough, 3:the real deal, 4:help: *1*
<repeat once>
(player) vs (player)!
*/

static int getBeginData(char* question,char* option_one, char* option_two, char* option_three, const char* help_text){//general logic for question asking
	while(1){
		printf("\n%s\n\n", question);
		printf("1:%s, 2:%s, 3:%s, 4:help: ", option_one, option_two, option_three);
		int answer;
		scanf("%i", &answer);
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
		}
	}
	return 0;
}

static struct player* beginPlayer(){ //handles the begining text and gets players choice 
	int class = getBeginData("Choose Your Fighter!","mage","knight","archer",helpClass);
	int perk = getBeginData("Choose Your Special Perk!","healing potions","magic weapons","gauntlets",helpPerks);
	struct player newplayer = malloc(sizeof(struct player));
	newplayer->class = class;
	newplayer->perk = perk;
	return newplayer;
}

static void printClassVs(struct match* game){ //prints versus message
	switch(game->p1->class){
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
	switch(game->p2->class){
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
}

struct match* initgame(){ //initalizes game
	struct match* game = malloc(sizeof(struct match));
	printf("\nWelcome to Text Fighters!\n");
	printf("\nPlayer one,\n");
	game->p1 = beginPlayer();
	printf("\nPlayer two,\n");
	game->p2 = beginPlayer();
	printClassVs(game);
	return game;
}













