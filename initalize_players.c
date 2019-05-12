/*
initalize_players.c:

Liam Muir, 2019

Interface Idea:

Welcome to Text Fighters!
Choose your fighter! 
1:mage, 2:knight, 3:archer, 4:help: *2*
Choose your special perk! 
1:health potions, 2:magic weapons, 3:gauntlets, 4:help: *2*
Choose your difficulty! 
1:wimp, 2:good enough, 3:the real deal, 4:help: *1*
(player) vs (insert ai opponent here)!
Your Turn:
(player/opponent can move once and attack/perk once, and status unlimited times)

<for archer>
1. Bow
2. Dagger
3. Block
4. Move Away
5. Move Forward
6. (insert special perk, magic does not show up here)
7. Status

<for knight>
1. Sword
2. Lance
3. Block
4. Move Away
5. Move Forward
6. (insert special perk, magic does not show up here)
7. Status

<for mage>
1. Fireball
2. Staff
3. Block
4. Move Away (this will randomly move 1 or 2 back)
5. Move Forward (this will randomly move 1 or 2 forwards)
6. (insert special perk, magic does not show up here)
7. Status

<when status is selected>

HP: (x)
AC: (X)
Opponents HP: (x)
Opponents AC: (x)
Distance from Opponent: (x, this type will be an integer and move away and move forward affect this)

<if perk is potions>
Potions left: (x, starts with 2 and heals 6 - 8 hp)
<during any attack>
Rolling... (waits two seconds)
<if in range and succesful>
Your attack has hit your opponent!
<if in range and not succesful>
Your attack did not hit your opponent...
<if not in range and succesful>
Your attack did not reach your opponent...
<all cases>
Your attack did (x) damage.
<if opponent dead>
You Win! (end)

Opponents Turn... (waits 5 seconds)
<only attack/perk>
Opponent used (attack/perk).
<attack/perk and move>
Opponent used (attack/perk) and moved (back,forwards).
<all cases>
The attack did (x) damage.

<if dead>
You died! (end)

<if not dead>
(repeat)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAGE 1
#define KNIGHT 2
#define ARCHER 3
#define EASY 1
#define MID 2
#define HARD 3
#define POTION 1
#define MAGIC 2
#define GAUNT 3

const char* helpClass = "The character you choose determines the attacks you can use and the HP you have.\nThe mage has fireball, staff, and has 30 HP.\nThe knight has sword, lance, and has 40 HP.\nThe archer has bow, dagger, and has 35 HP";
const char* helpPerks = "The perk you choose determines the special actions you can take to give you an edge against your opponent\nYou get three healing potions that heal 4-8 HP each if you choose healing.\nThe magic weapons deal %20 percent more damage than normal.\nThe gauntlets allow you to punch your opponents, dealing 3-7 damage when used.";

struct player{
	int hp;
	int class;
	int perk;
};

struct match{
	struct player p1;
	struct player p2;
	int distance_between;
};

int getBeginData(char* question,char* option_one, char* option_two, char* option_three, const char* help_text){//general logic for question asking
	while(1){
		printf("\n%s\n\n", question);
		printf("1:%s, 2:%s, 3:%s, 4:help:", option_one, option_two, option_three);
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

struct player beginPlayer(){ //handles the begining text and	gets players choice 
	int class = getBeginData("Choose Your Fighter!","mage","knight","archer",helpClass);
	int perk = getBeginData("Choose Your Special Perk!","healing potions","magic weapons","gauntlets",helpPerks);
	struct player newplayer;
	newplayer.class = class;
	newplayer.perk = perk;
	return newplayer;
}

void printClassVs(struct match game){
	switch(game.p1.class){
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
	switch(game.p2.class){
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

int dead(struct match game, int playernumber){
	switch(playernumber){
		case 1:
		if (game.p1.hp == 0){
			return 1;
		}else{
			return 0;
		}
		break;
		case 2:
		if (game.p2.hp == 0){
			return 1;
		}else{
			return 0;
		}
		break;
		default:
		return -1;
	}
}

int initgame(){
	struct match game;
	printf("\nWelcome to Text Fighters!\n");
	printf("\nPlayer one,\n");
	game.p1 = beginPlayer();
	printf("\nPlayer two,\n");
	game.p2 = beginPlayer();
	printClassVs(game);
	return game;
}













