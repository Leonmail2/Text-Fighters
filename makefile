all: text_fighters

run: text_fighters
	./text_fighters

test.o: test.c
	gcc -c test.c

text_fighters: core_logic.o initalize_players.o combat_helpers.o main.o
	gcc core_logic.o initalize_players.o combat_helpers.o main.o -o text_fighters
	echo "\nrun with ./text_fighters"

core_logic.o: core_logic.c core_logic.h
	gcc -c core_logic.c core_logic.h

initalize_players.o: initalize_players.c initalize_players.h
	gcc -c initalize_players.c initalize_players.h

conbat_helpers.o: combat_helpers.c combat_helpers.h
	gcc -c combat_helpers.c combat_helpers.h

main.o: main.c
	gcc -c main.c

clean:
	rm core_logic.o initalize_players.o main.o structs.o text_fighters initalize_players.h.gch core_logic.h.gch structs.h.gch combat_helpers.h.gch combat_helpers.o test test.o