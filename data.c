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
    //chessBoard->color = white;
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
    //chessBoard->color = black;
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

U64 maskRank(int i) {
    switch(i) {
        case 1:
            return MASK_RANK_1;
            break;
        case 2:
            return MASK_RANK_2;
            break;
        case 3:
            return MASK_RANK_3;
            break;
        case 4:
            return MASK_RANK_4;
            break;
        case 5:
            return MASK_RANK_5;
            break;
        case 6:
            return MASK_RANK_6;
            break;
        case 7:
            return MASK_RANK_7;
            break;
        case 8:
            return MASK_RANK_8;
            break;
        default:
            fprintf(stderr, "Internal Error. Attempting to mask rank#%d\n", i);
            exit(-1);
    }
}

U64 maskFile(int j) {
    switch(j) {
        case 1:
            return MASK_FILE_A;
            break;
        case 2:
            return MASK_FILE_B;
            break;
        case 3:
            return MASK_FILE_C;
            break;
        case 4:
            return MASK_FILE_D;
            break;
        case 5:
            return MASK_FILE_E;
            break;
        case 6:
            return MASK_FILE_F;
            break;
        case 7:
            return MASK_FILE_G;
            break;
        case 8:
            return MASK_FILE_H;
            break;
        default:
            fprintf(stderr, "Internal Error. Attempting to mask file#%d\n", j);
            exit(-1);
    }
}

U64 maskRankAndFile(int i, int j) {
    return maskRank(i)&maskFile(j);
}

U64 clearRank(int i) {
    switch(i) {
        case 1:
            return CLEAR_RANK_1;
            break;
        case 2:
            return CLEAR_RANK_2;
            break;
        case 3:
            return CLEAR_RANK_3;
            break;
        case 4:
            return CLEAR_RANK_4;
            break;
        case 5:
            return CLEAR_RANK_5;
            break;
        case 6:
            return CLEAR_RANK_6;
            break;
        case 7:
            return CLEAR_RANK_7;
            break;
        case 8:
            return CLEAR_RANK_8;
            break;
        default:
            fprintf(stderr, "Internal Error. Attempting to clear rank#%d\n", i);
            exit(-1);
    }
}

U64 clearFile(int j) {
    switch(j) {
        case 1:
            return CLEAR_FILE_A;
            break;
        case 2:
            return CLEAR_FILE_B;
            break;
        case 3:
            return CLEAR_FILE_C;
            break;
        case 4:
            return CLEAR_FILE_D;
            break;
        case 5:
            return CLEAR_FILE_E;
            break;
        case 6:
            return CLEAR_FILE_F;
            break;
        case 7:
            return CLEAR_FILE_G;
            break;
        case 8:
            return CLEAR_FILE_H;
            break;
        default:
            fprintf(stderr, "Internal Error. Attempting to clear file#%d\n", j);
            exit(-1);
    }
}

U64 clearRankAndFile(int i, int j) {
    return ~(maskRank(i)&maskFile(j));
}

U64 whitePawnMoves(board *whiteBoard, U64 rank, U64 file) {
    U64 moves = rank&file;
    //printf("rank&file: %llu\n", rank&file);
    //moves <<= 8;
    moves = moves << 8;
    return moves;
}

U64 blackPawnMoves(board *blackBoard, U64 rank, U64 file) {
    U64 moves = rank&file;
    moves >>= 8;
    return moves;
}


bool isPawn(board *whiteBoard, U64 rank, U64 file) {
    if ((whiteBoard->pawns&rank&file) == (rank&file)) {
        return true;
    }
    return false;
}

bool isRook(board *whiteBoard, U64 rank, U64 file) {
    if ((whiteBoard->rooks&rank&file) == (rank&file)) {
        return true;
    }
    return false;
}

bool isKnight(board *whiteBoard, U64 rank, U64 file) {
    if ((whiteBoard->knights&rank&file) == (rank&file)) {
        return true;
    }
    return false;
}

bool isBishop(board *whiteBoard, U64 rank, U64 file) {
    if ((whiteBoard->bishops&rank&file) == (rank&file)) {
        return true;
    }
    return false;
}

bool isQueen(board *whiteBoard, U64 rank, U64 file) {
    if ((whiteBoard->queens&rank&file) == (rank&file)) {
        return true;
    }
    return false;
}

bool isKing(board *whiteBoard, U64 rank, U64 file) {
    if ((whiteBoard->kings&rank&file) == (rank&file)) {
        return true;
    }
    return false;
}

void clearFromBoard(board *chessBoard, U64 rankAndFile) {
    chessBoard->pawns = chessBoard->pawns&rankAndFile;
    chessBoard->rooks = chessBoard->rooks&rankAndFile;
    chessBoard->knights  = chessBoard->knights&rankAndFile;
    chessBoard->bishops = chessBoard->bishops&rankAndFile;
    chessBoard->kings = chessBoard->kings&rankAndFile;
    chessBoard->queens = chessBoard->queens&rankAndFile;
}

void clearFromBitBoards(board *whiteBoard, board *blackBoard, int i, int j) {
    clearFromBoard(whiteBoard, clearRankAndFile(i, j));
    clearFromBoard(blackBoard, clearRankAndFile(i, j));
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
