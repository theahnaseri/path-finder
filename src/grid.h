#ifndef GRID_H
#define GRID_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define true 1
#define false 0
#define path '-'
#define wall '#'
#define start 'S'
#define goal 'G'

typedef struct POINT {
    int specified;
    int x;
    int y;
} Point;

void ClearScreen();
int GetChar();
void ResetGrid(int width, int height, char grid[height][width]);
void DrawGrid(int width, int height, char* algorithm, char grid[height][width], char* log);
void EditGrid(int width, int height, char* algorithm, char grid[height][width], Point *start_point, Point *goal_point, int clear_grid);
void SetAlgorithm(int width, int height, char** algorithm, char grid[height][width]);

#endif //GRID_H