/*
test.c

Liam Muir, 2019

a test file to ensure that functions are working as expected
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "core_logic.h"
#include "initalize_players.h"
#include "structs.h"

int main(int argc, char const *argv[]){
	struct match* game = initgame();
	game->distance = 8;
	for (int i = 0; i < 5; ++i){
		move_forwards(game);
		printf("%i\n", game->distance);
		sleep(1);
	}
	for (int i = 0; i < 5; ++i){
		move_backwards(game);
		printf("%i\n", game->distance);
		sleep(1);
	}
}