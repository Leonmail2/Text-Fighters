/*
test.c

Liam Muir, 2019

a test file to ensure that functions are working as expected
*/

#include "core_logic.h"
#include "initalize_players.h"
#include "structs.h"

int main(int argc, char const *argv[]){
	struct match* p = initgame();
	printf("%i %i",p->p1.class, p->p2.class);
	printf("\n");
	print_menu(1,p);
	print_status(1,p);
	print_menu(2,p);
	print_status(2,p);
	return 0;
}