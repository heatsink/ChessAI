#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "data.h"
#include "support.h"

int main() {
    board *whiteBoard = checked_malloc(sizeof(board));
    board *blackBoard = checked_malloc(sizeof(board));
    initializeWhiteBoard(whiteBoard);
    initializeBlackBoard(blackBoard);
    char **charBoard = createCharBoard(whiteBoard, blackBoard);
    printCharBoard(charBoard);
    //Checks if there is a piece in the rank and file specified
    if (containsPiece(whiteBoard, blackBoard, MASK_FILE_A, MASK_RANK_2)) {
        printf("Pawn in the house!\n"); 
    }
    else {
        printf("No pawn here.\n"); 
    }
    // Removes a piece from the board and prints it
    /*
    clearFromBitBoards(whiteBoard, blackBoard, 1, 3);
    charBoard = createCharBoard(whiteBoard, blackBoard);
    printCharBoard(charBoard);
    */

    U64 moves = whitePawnMoves(whiteBoard, MASK_FILE_A, MASK_RANK_2);
    printf("Pawn moves: %llu\n", moves);
    whiteBoard->pawns = whiteBoard->pawns | moves;

    clearFromBitBoards(whiteBoard, blackBoard, 2, 1);
    charBoard = createCharBoard(whiteBoard, blackBoard);
    printCharBoard(charBoard);
	return 0;
}
