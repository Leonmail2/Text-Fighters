/*
structs.h

Liam Muir, 2019,

A header file that defines structs used by the whole program.
*/

#ifndef STRUCTS
#define STRUCTS

#define MAGE 1
#define KNIGHT 2
#define ARCHER 3
#define POTION 1
#define MAGIC 2
#define GAUNT 3

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

#endif
