/*
structs.h

Liam Muir, 2019,

A file that defines structs used by the whole program.
*/

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
