/*
core_logic.c

Liam Muir, 2019,

implementations of functions that are used as the main logic while game is in progress.
*/

#include <stdio.h>
#include <stdlib.h>
#include "core_logic.h"
#include "structs.h"

/*
Your Turn:
(player/opponent can move once and attack/perk once, and status unlimited times)

<for archer>
1. Bow
2. Dagger
3. Block
4. Move Away
5. Move Forward
6. (insert special perk, magic does not show up here)
7. Status

<for knight>
1. Sword
2. Lance
3. Block
4. Move Away
5. Move Forward
6. (insert special perk, magic does not show up here)
7. Status

<for mage>
1. Fireball
2. Staff
3. Block
4. Move Away (this will randomly move 1 or 2 back)
5. Move Forward (this will randomly move 1 or 2 forwards)
6. (insert special perk, magic does not show up here)
7. Status

<when status is selected>

HP: (x)
AC: (X)
Opponents HP: (x)
Opponents AC: (x)
Distance from Opponent: (x, this type will be an integer and move away and move forward affect this)

<if perk is potions>
Potions left: (x, starts with 2 and heals 6 - 8 hp)
<during any attack>
Rolling... (waits two seconds)
<if in range and succesful>
Your attack has hit your opponent!
<if in range and not succesful>
Your attack did not hit your opponent...
<if not in range and succesful>
Your attack did not reach your opponent...
<all cases>
Your attack did (x) damage.
<if opponent dead>
You Win! (end)

Opponents Turn... (waits 5 seconds)
<only attack/perk>
Opponent used (attack/perk).
<attack/perk and move>
Opponent used (attack/perk) and moved (back,forwards).
<all cases>
The attack did (x) damage.

<if dead>
You died! (end)

<if not dead>
(repeat)
*/