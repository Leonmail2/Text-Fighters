#ifndef CORE_LOGIC
#define CORE_LOGIC
#include "structs.h"

struct match* turn(int player, struct match* game); //deals with input and actions of player one or two

int dead(int player, struct match* game); //chects if player is dead

void resolve(struct match* game);

#endif