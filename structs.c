/*
structs.h

Liam Muir,
2019-05-12

A header file to define structs used by the program.
*/


#define MAGE 1
#define KNIGHT 2
#define ARCHER 3
#define EASY 1
#define MID 2
#define HARD 3
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