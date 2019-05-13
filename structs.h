#ifndef STRUCTS
#define STRUCTS

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