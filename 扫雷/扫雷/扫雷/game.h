#include <stdio.h>
#include <time.h>
#include<stdlib.h>


#pragma once
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define LEI_COUNT 10

void InitBoard(char mein[ROWS][COLS], int rows, int cols,char set);
void DispalyBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char board[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);