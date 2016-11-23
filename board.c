#include <stdint.h>
#include <stdio.h>
#include "board.h"
// Macro
#define SQ64(sq120) Sq120ToSq64[sq120]
// Global Board
uint64_t board = 0;
int main () {
	//extern int SQ64[64]
	printBoard();
	return 0;
}
void printBoard() {
	printf("test\n");
	printf("test\n");
	printf("test\n");
	printf("test\n");
	printf("Printing board\n");
	printf("♖ ♘ ♗ ♕ ♔ ♗ ♘ ♖\n");	
	printf("♙ ♙ ♙ ♙ ♙ ♙ ♙ ♙\n");	
	printf("- - - - - - - -\n");	
	printf("- - - - - - - -\n");	
	printf("- - - - - - - -\n");	
	printf("- - - - - - - -\n");	
	printf("♟ ♟ ♟ ♟ ♟ ♟ ♟ ♟\n");	
	printf("♜ ♞ ♝ ♛ ♚ ♝ ♞ ♜\n");	
}
