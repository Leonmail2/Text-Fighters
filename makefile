all: text_fighters

run: text_fighters
	./text_fighters

text_fighters: core_logic.o initalize_players.o main.o structs.o
	gcc core_logic.o initalize_players.o main.o structs.o -o text_fighters

core_logic.o: core_logic.c core_logic.h
	gcc -c core_logic.c core_logic.h

initalize_players.o: initalize_players.c initalize_players.h
	gcc -c initalize_players.c initalize_players.h

main.o: main.c
	gcc -c main.c

structs.o: structs.c
	gcc -c structs.c

clean:
	rm core_logic.o initalize_players.o main.o structs.o text_fighters initalize_players.h.gch core_logic.h.gch structs.h.gch