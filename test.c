/*
test.c

Liam Muir, 2019

a test file to ensure that functions are working as expected
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "core_logic.h"
#include "combat_helpers.h"
#include "initalize_players.h"
#include "structs.h"

int main(int argc, char const *argv[]){
	struct match* game = initgame();
	printf("hp op: %i\n", game->p2.hp);
	turn(game,1);
	printf("hp op: %i\n", game->p2.hp);
}