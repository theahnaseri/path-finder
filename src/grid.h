#ifndef GRID_H
#define GRID_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#define true 1
#define false 0
#define path '-'
#define wall '#'
#define start 'S'
#define goal 'G'

void ClearScreen();
void SetGrid(int width, int height, char grid[height][width]);
void DrawGrid(int width, int height, char* algorithm, char grid[height][width]);
void EditGrid(int width, int height, char* algorithm, char grid[height][width]);
void SetAlgorithm(char** algorithm);

#endif //GRID_H