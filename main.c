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
	struct match game = initgame();
	return 0;
}
