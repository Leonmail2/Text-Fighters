/*
combat_data.h

Liam Muir, 2019

A file to 
*/


#ifndef __COMBAT_DATA__
#define __COMBAT_DATA__

struct attack{
	//data for attack
	int range;
	int bonus;
};

struct dice{
	int min;
	int max;
};

struct attack attacktable[6] = {{3,2},{1,1},{1,3},{2,2},{5,-2},{1,3}}; //starts with fireball, goes to dagger, in up-down, left right order,
//struct order is range, bonus

int actable[3] = {11,14,12}; //based on numbers for each class offered on help string

struct dice dicetable[6] = {{5,7},{3,5},{5,6},{2,4},{6,7},{2,5}};//starts with fireball, goes to dagger, in up-down, left right order

struct dice gauntlets = {3,7}; //one off for gauntlets perk

struct dice healingpotion = {4,8};


#endif