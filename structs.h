#ifndef __STRUCTS__
#define __STRUCTS__

struct player{
	int hp;
	int ac;
	int class;
	int perk;
	int healing_potions;
};

struct match{
	struct player p1;
	struct player p2;
	int distance_between;
};

#endif