#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "support.h"

/*
 * Initializes white pieces with default values
 */
void initializeWhiteBoard(board *chessBoard) {
    chessBoard->pawns = 0x000000000000FF00;
    chessBoard->rooks = 0x0000000000000081;
    chessBoard->knights  = 0x0000000000000042;
    chessBoard->bishops = 0x0000000000000024;
    chessBoard->kings = 0x0000000000000008;
    chessBoard->queens = 0x0000000000000010;
    chessBoard->color = white;
}

/*
 * Initializes black pieces with default values
 */
void initializeBlackBoard(board *chessBoard) {
    chessBoard->pawns = 0x00FF000000000000;
    chessBoard->rooks = 0x8100000000000000;
    chessBoard->knights  = 0x4200000000000000;
    chessBoard->bishops = 0x2400000000000000;
    chessBoard->kings = 0x0800000000000000;
    chessBoard->queens = 0x1000000000000000;
    chessBoard->color = black;
}

/*
 * Shifts left and returns true if a piece exists
 */
bool lShift(long unsigned long *val) {
    bool status = *val & 1;
    *val >>= 1;
    return status;
}

/*
 * Returns bits for any piece of both color boards (specifications required)
 */
U64 allPieces(board *whiteBoard, board *blackBoard) {
    return whiteBoard->pawns + whiteBoard->rooks + whiteBoard->knights
        + whiteBoard->bishops + whiteBoard-> queens + whiteBoard-> kings
        + blackBoard->pawns + blackBoard->rooks + blackBoard->knights
        + blackBoard->bishops + blackBoard-> queens + blackBoard-> kings;
}

/*
 * Returns bits for any piece of the color board specified
 */
U64 allPiecesOfColor(board *whiteBoard) {
    return whiteBoard->pawns + whiteBoard->rooks + whiteBoard->knights
        + whiteBoard->bishops + whiteBoard-> queens + whiteBoard-> kings;
}

/*
 * Returns true if any piece is found in the rank and file specified
 */
bool containsPiece(board *whiteBoard, board *blackBoard, U64 rank, U64 file) {
    if ((allPieces(whiteBoard, blackBoard) & rank & file) == (rank&file)) {
        return true;
    }
    return false;
}

/*
 * Returns true if a piece of the color board specified is found in the rank 
 * and file specified
 */
bool containsPieceOfColor(board *chessBoard, U64 rank, U64 file) {
    if ((allPiecesOfColor(chessBoard) & rank & file) == (rank&file)) {
        return true;
    }
    return false;
}
