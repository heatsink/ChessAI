# This target will compile all targets
Compile: Board Move AI Main
Board:
	gcc -o Board board.c
Move:
	gcc -o Move move.c
AI:
	gcc -o AI ai.c
Main:
	gcc -o Main main.c
clean:
	rm -f *.o Board Move AI Main
