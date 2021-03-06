#ifndef DATA_H
#define DATA_H

#define BOARD_SIZE 64
#define U64 long unsigned long
#define board struct chessBoard
#define MASK_FILE_A 0x8080808080808080
#define MASK_FILE_B 0x4040404040404040
#define MASK_FILE_C 0x2020202020202020
#define MASK_FILE_D 0x1010101010101010
#define MASK_FILE_E 0x0808080808080808
#define MASK_FILE_F 0x0404040404040404
#define MASK_FILE_G 0x0202020202020202
#define MASK_FILE_H 0x0101010101010101

#define CLEAR_FILE_A 0x7F7F7F7F7F7F7F7F
#define CLEAR_FILE_B 0xBFBFBFBFBFBFBFBF
#define CLEAR_FILE_C 0xDFDFDFDFDFDFDFDF
#define CLEAR_FILE_D 0xEFEFEFEFEFEFEFEF
#define CLEAR_FILE_E 0xF7F7F7F7F7F7F7F7
#define CLEAR_FILE_F 0xFBFBFBFBFBFBFBFB
#define CLEAR_FILE_G 0xFDFDFDFDFDFDFDFD
#define CLEAR_FILE_H 0xFEFEFEFEFEFEFEFE

#define MASK_RANK_1 0x00000000000000FF
#define MASK_RANK_2 0x000000000000FF00
#define MASK_RANK_3 0x0000000000FF0000
#define MASK_RANK_4 0x00000000FF000000
#define MASK_RANK_5 0x000000FF00000000
#define MASK_RANK_6 0x0000FF0000000000
#define MASK_RANK_7 0x00FF000000000000
#define MASK_RANK_8 0xFF00000000000000

#define CLEAR_RANK_1 0xFFFFFFFFFFFFFF00
#define CLEAR_RANK_2 0xFFFFFFFFFFFF00FF
#define CLEAR_RANK_3 0xFFFFFFFFFF00FFFF
#define CLEAR_RANK_4 0xFFFFFFFF00FFFFFF
#define CLEAR_RANK_5 0xFFFFFF00FFFFFFFF
#define CLEAR_RANK_6 0xFFFF00FFFFFFFFFF
#define CLEAR_RANK_7 0xFF00FFFFFFFFFFFF
#define CLEAR_RANK_8 0x00FFFFFFFFFFFFFF

typedef int bool;
enum bool { false, true };

/*
typedef int color;
enum color { white, black };

*/
struct chessBoard {
    long unsigned long pawns;
    long unsigned long rooks;
    long unsigned long knights;
    long unsigned long bishops;
    long unsigned long kings;
    long unsigned long queens;
    //color color;
};
// Bit level operations
U64 maskRank(int i);
U64 maskFile(int j);
U64 maskRankAndFile(int i, int j);
U64 clearRank(int i);
U64 clearFile(int j);
U64 clearRankAndFile(int i, int j);
bool lShift(U64 *val);
// Chess board function prototypes
void clearFromBoard(board *chessBoard, U64 rankAndFile);
void initializeWhiteBoard(board *chessBoard);
void initializeBlackBoard(board *chessBoard);
bool containsPiece(board *whiteBoard, board *blackBoard, U64 rank, U64 file);
void clearFromBoard(board *chessBoard, U64 rankAndFile);
void clearFromBitBoards(board *whiteBoard, board *blackBoard, int i, int j);
// Piece Checks
bool isPawn(board *whiteBoard, U64 rank, U64 file);
bool isRook(board *whiteBoard, U64 rank, U64 file);
bool isKnight(board *whiteBoard, U64 rank, U64 file);
bool isBishop(board *whiteBoard, U64 rank, U64 file);
bool isQueen(board *whiteBoard, U64 rank, U64 file);
bool isKing(board *whiteBoard, U64 rank, U64 file);
void verifyBoard(board *whiteBoard, board *blackBoard);
// Move Generation
U64 whitePawnMoves(board *whiteBoard, board *blackBoard, U64 rank, U64 file);

#endif
