/*
core_logic.c

Liam Muir, 2019,

implementations of functions that are used as the main logic while game is in progress.

Combat system spec:

attacks are done by determining a random number between one and twenty.

if the number exeeds the ac of the opponent, the attack hits.

all weapons have a bonus to the attack roll, it is added. negative bonuses are allowed.

if the player is not in range, alert player and return to menu

the players can't move backwards if the distance is eight (to account for random 1 or 2 forwards or backwards, if the final result is 8 or more
after moving backwards, it sets the distance to 8)

the players can't move forwards if the distance is one (to account for random 1 or 2 forwards or backwards, if the final result is 1 or less 
after moving forwards, it sets the distance to 1)



*/

#include <stdio.h>
#include <unistd.h>
#include "combat_helpers.h"
#include "structs.h"
#include "core_logic.h"

int turn(struct match* game, int player){ //deals with input and actions of player one or two
	//make attack_num variable and set to 0
	int attack_num = 0;
	//make move variable and set it to 0
	int move = 0;

	struct player* p;
	struct player* op;
	//reset parry
	reset_parry(game,player);
	//print "Your turn, player x!"
	printf("Your turn, player %i!\n", player);

	if (player == 1){
		p = &game->p1;
		op = &game->p2;
	}else if (player == 2){
		p = &game->p2;
		op = &game->p1;
	}else{
		return -1;
	}

	while(1){
		//enter loop
		printf("\n");
		//print list of actions based on player class and perk (calls print_menu)
		print_menu(game, player);
		//get input from command line

		int input = get_input();

		//if attack one
		if(input == 1){
			attack_num = 1;//set attack_num to 1
		}else if(input == 2){
			attack_num = 2;//set attack_num to 2
		}else if(input == 3){
			//call parry function
			parry(game, player);
		}else if(input == 4){
		//if move variable is 0
		//move forwards
		//set move variable to 1
		//continue
			if (move == 0){
				move_forwards(game);
				move = 1;
			}else{
				printf("You have already moved\n");
			}
			continue;
		}else if(input == 5){
			//else if move_backwards
			//if move variable is 0
			//move backwards
			//set move variable to 1
			//continue
			if (move == 0){
				move_backwards(game);
				move = 1;
			}else{
				printf("You have already moved\n");
			}
			continue;
		}else if(input == 6){
		//else if status
			print_status(game, player);
		//print status
			continue;
		//continue
		}else if(input == 7){
		//else if continue
		//break
			break;
		}else if(input == 8 && p->perk == GAUNT){
			attack_num = 3;
		}else if(input == 8 && p->perk == HEAL){
			add_health(game, player);
			printf("\nYour HP is now %i\n", p->hp);
			sleep(1);
			break;
		}else{
			continue;
		}

		//if attack_num is not equal to 0
		//call calculate hit with attack two towards opponent
		//if not in range, 
		//error message
		//set attack_num to 0
		//continue
		//if a hit
		//print "your attack hit"
		//calculate damage and 
		//return
		//else
		//print "your attack did not hit"
		//return
		if (attack_num != 0){
			int hit;
			if (attack_num == 1 || attack_num == 2){
				hit = calculate_hit(game, player, attack_num, op->ac);
			}else if(attack_num == 3){
				hit = calculate_gauntlet_hit(game, player, op->ac);
			}else{
				return -1;
			}
			if(hit == 0){
				printf("\nAttack not in range\n");
				sleep(1);
				attack_num = 0;
				continue;
			}
			printf("Rolling...\n\n");
			sleep(1);
			if (hit == 1){
				printf("Attack did not hit opponent\n\n");
				sleep(1);
				break;
			}else if (hit == 2){
				printf("Attack hit opponent\n\n");
				sleep(1);
				printf("Rolling...\n\n");
				int d;
				if (attack_num == 1 || attack_num == 2){
					d = damage(p->class, attack_num);
				}else if(attack_num == 3){
					d = gauntlet_damage();
				}else{
					return -1;
				}
				
				sleep(1);
				printf("Your attack did %i damage\n\n", d);
				sleep(1);
				op->hp -= d;
				break;
			}
			
		}
	}

}

int dead(struct match* game, int player){ //chects if player is dead
	//if player is one
	//check if ones health is 0 or less
	//return 1
	//else return 0
	//if player is two
	//check if twos health is 0 or less
	//return 1
	//else return 0
	//else
	//return 0;
}

void resolve(struct match* game){ //says who won
	//if player one is dead
	//player two wins
	//if player two is dead
	//player one wins
	//print (Player (x), you have won!)
}

int playagain(){ //asks player if they want to play again
	//print "Do you want to play again? (y/n): "
	//get input
	//if answer is y, return 1
	//else return 0
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
