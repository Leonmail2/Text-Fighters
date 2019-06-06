#ifndef __COMBAT_HELPERS__
#define __COMBAT_HELPERS__

struct match;

#include "structs.h"

int dice(int min, int max);

int calculate_hit(struct match* game, int attack_num, int target, int player_num);

int calculate_gauntlet_hit(struct match* game, int target, int player_num);

int damage(int class, int attack_num);

void move_forwards(struct match* game);

void move_backwards(struct match* game);

void parry(struct match* game, int player_num);

void reset_parry(struct match* game, int player_num);

//------------------------------------------------------------------------
//output functions

void print_menu(struct match* game, int player); //prints action menu

void print_status(struct match* game, int player); //prints status of player

int get_input();

#endif

