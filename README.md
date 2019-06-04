# Text Fighters

Text Fighters is a text based fighting game. You can choose from three classes, and three perks to assist in your fight. Combat is based on choosing attacks, and moving forwards and backwards to avoid counter attacks.

Here is a sample interaction:

Interface Idea:

Welcome to Text Fighters!

Player One, Choose your fighter! 

1:mage, 2:knight, 3:archer, 4:help: 2

Choose your special perk! 

1:health potions, 2:magic weapons, 3:gauntlets, 4:help: 2

Player Two, Choose your fighter! 

1:mage, 2:knight, 3:archer, 4:help: 2

Choose your special perk! 

1:health potions, 2:magic weapons, 3:gauntlets, 4:help: 2

Knight vs !

Your Turn, Player One!

(player/opponent can move once and attack/perk once, and status unlimited times)

for archer

1. Bow
2. Dagger
3. Parry
4. Move Forwards (this will randomly move 1 or 2 forwards)
5. Move Backwards (this will randomly move 1 or 2 back)
6. Status
7. Nothing
8. (insert special perk, magic does not show up here)

for knight

1. Sword
2. Lance
3. Parry
4. Move Forwards (this will randomly move 1 or 2 forwards)
5. Move Backwards (this will randomly move 1 or 2 back)
6. Status
7. Nothing
8. (insert special perk, magic does not show up here)

for mage

1. Fireball
2. Staff
3. Parry
4. Move Forwards (this will randomly move 1 or 2 forwards)
5. Move Backwards (this will randomly move 1 or 2 back)
6. Status
7. Nothing
8. (insert special perk, magic does not show up here)

when status is selected

HP: (x)
AC: (X)
Opponents HP: (x)
Opponents AC: (x)
Distance from Opponent: (x, this type will be an integer and move away and move forward affect this)

if perk is potions

Potions left: (x, starts with 2 and heals 6 - 8 hp)

output during any attack

Rolling... (waits two seconds)

#if in range and succesful

Your attack has hit your opponent!

#if in range and not succesful

Your attack did not hit your opponent...

#if not in range and succesful

Your attack did not reach your opponent...

#all cases

Your attack did (x) damage.

#if opponent dead

You Win! (end)

Opponents Turn... (waits 5 seconds)

#only attack/perk

Opponent used (attack/parry/perk).

#attack/perk and move

Opponent used (attack/parry/perk) and moved (back/forwards).

#all cases

The attack did (x) damage.

if dead
You died! (end)

if not dead
(repeat)



