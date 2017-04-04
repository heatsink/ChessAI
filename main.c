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
    /*
    charBoard = createCharBoard(whiteBoard, blackBoard);
    printCharBoard(charBoard);
    */
    if (containsPiece(whiteBoard, blackBoard, MASK_FILE_A, MASK_RANK_2)) {
        printf("Pawn in the house!\n"); 
    }
    else {
        printf("No pawn here.\n"); 
    }
	return 0;
}
