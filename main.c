/*
main.c

Liam Muir, 2019,

main file to launch game.
*/

#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "initalize_players.h"
#include "core_logic.h"

int main(){
	struct match* game = initgame();
	while(1){
		turn(1,game);
		if(dead(1,game)){
			break;
		}
		turn(2,game);
		if(dead(2,game)){
			break;
		}
	}
	resolve(game);
	free(game);
	return 0;
}
