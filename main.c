/*
main.c

Liam Muir, 2019,

main file to launch game.
*/

#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "combat_helpers.h"
#include "initalize_players.h"
#include "core_logic.h"

int main(){
	struct match* game = initgame();
	while(1){
		while(1){ //main loop for the cycle of play
			turn(game,1); //player one's turn
			if(dead(game,2)){ //checks if opponent is dead
				break; //stop the game
			}
			turn(game,2); //player two's turn
			if(dead(game,1)){ //checks if opponent is dead
				break; //stop the game
			}
		}
		resolve(game); //say who won
		free(game);
		}
	printf("\n\nDo you want to play again? (y/n): ");
	char input[10];
	fgets(input, 10, stdin);
	if (strcmp(input,"y")==0){
		printf("\n\n");
		continue;
	}else{
		printf("Thanks for playing!\n\n");
		break;
	}
	return 0;
}
