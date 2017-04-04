#ifndef SUPPORT_H
#define SUPPORT_H
// Support Functions
void *checked_malloc(size_t size);
void *checked_realloc(void *pointer, size_t size);
// Chess Board Print Functions
bool detectPiece(int rowAndCol, long unsigned long val);
char **createCharBoard(struct chessBoard *whiteBoard, struct chessBoard *blackBoard);
void printCharBoard(char **charBoard);
#endif
