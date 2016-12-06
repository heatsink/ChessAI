#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include "board.h"
// Macro
#define SQ64(sq120) Sq120ToSq64[sq120]
// Global Board
uint64_t board = 0xFF000000000000FF;
uint64_t pawn =  0x00FF00000000FF00;
uint64_t rook = 0;
uint64_t knight = 0;
uint64_t bishop = 0;
uint64_t king = 0;
uint64_t queen = 0;



int main () {
	//extern int SQ64[64]
	printBoard();
    testBoard();
	return 0;
}
void testBoard() {
    printf("Printing bitboard\n");
    printf("%" PRIu64 "\n", board);
    printf("Printing bitboard after shift\n");
    board >>= 8;
    printf("%" PRIu64 "\n", board);
    printf("Pawns\n");
    printf("%" PRIu64 "\n", pawn);
    printf("Rooks\n");
    printf("%" PRIu64 "\n", rook);
    printf("Knights\n");
    printf("%" PRIu64 "\n", knight);
    printf("Bishops\n");
    printf("%" PRIu64 "\n", bishop);
    printf("Kings\n");
    printf("%" PRIu64 "\n", king);
    printf("Queens\n");
    printf("%" PRIu64 "\n", queen);
 


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
