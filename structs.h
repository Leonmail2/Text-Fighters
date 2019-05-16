#ifndef STRUCTS
#define STRUCTS

struct attack{
	//data for attack
	int range;
	int bonus;
}

struct player{
	int hp;
	int ac;
	int class;
	int perk;
};

struct match{
	struct player p1;
	struct player p2;
	int distance_between;
};

#endif