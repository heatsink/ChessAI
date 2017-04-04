#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "support.h"

/*
 * Inserts chess ascii characters in reverse order into an array taking bit values
 */
char **createCharBoard(struct chessBoard *whiteBoard, struct chessBoard *blackBoard) {
    static char *charBoard[BOARD_SIZE]; 
    for (int i = BOARD_SIZE-1; i >=0; i--) {
        charBoard[i] = "-";
    }
    for (int i = BOARD_SIZE-1; i >= 0; i--) {
        if (detectPiece(i, blackBoard->pawns) == true) {
            charBoard[i] = "♟";
        }
        if (detectPiece(i, blackBoard->rooks) == true) {
            charBoard[i] = "♜";
        }
        if (detectPiece(i, blackBoard->knights) == true) {
            charBoard[i] = "♞";
        }
        if (detectPiece(i, blackBoard->bishops) == true) {
            charBoard[i] = "♝";
        }
        if (detectPiece(i, blackBoard->queens) == true) {
            charBoard[i] = "♛";
        }
        if (detectPiece(i, blackBoard->kings) == true) {
            charBoard[i] = "♚";
        }
        if (detectPiece(i, whiteBoard->pawns) == true) {
            charBoard[i] = "♙";
        }
        if (detectPiece(i, whiteBoard->rooks) == true) {
            charBoard[i] = "♖";
        }
        if (detectPiece(i, whiteBoard->knights) == true) {
            charBoard[i] = "♘";
        }
        if (detectPiece(i, whiteBoard->bishops) == true) {
            charBoard[i] = "♗";
        }
        if (detectPiece(i, whiteBoard->kings) == true) {
            charBoard[i] = "♔";
        }
        if (detectPiece(i, whiteBoard->queens) == true) {
            charBoard[i] = "♕";
        }
    }
    return charBoard;
}

/*
 * Prints array of characters row by row in chess board orientation
 */
void printCharBoard(char **charBoard) {
    for (int i = 0; i < 64; i++) {
        if (i != 0 && i % 8 == 0) {
            printf("\r\n");
        }
        printf("%s", charBoard[i]);
    }
    printf("\r\n");
}

/*
 * Associated with filling a charBoard for printing the board
 */
bool detectPiece(int rowAndCol, long unsigned long val) {
    for (int i = rowAndCol+1; i < BOARD_SIZE; i++) {
        val >>= 1;
    }
    bool status = val & 1;
    return status;
}

/*
 * Checks for a valid memory allocation before returning allocation
 */
void *checked_malloc(size_t size) {
    void *p = malloc(size);
    if (p == NULL){ 
        perror("broken allocation\r\n");
        exit(-1);
    }
    return p;
}

/*
 * Checks for a valid memory reallocation before returning allocation
 */
void *checked_realloc(void *pointer, size_t size) {
    void *p = realloc(pointer, size);
    if (p == NULL){ 
        perror("broken reallocation\r\n");
        exit(-1);
    }
    return p;
}
