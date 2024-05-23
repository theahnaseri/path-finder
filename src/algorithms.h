#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "grid.h"

int DoBFS(int width, int height, char grid[height][width], Point start_point, Point goal_point);
int DoDFS(int width, int height, char grid[height][width], Point start_point, Point goal_point);
int DoAstar(int width, int height, char grid[height][width], Point start_point, Point goal_point);
int IsValidPath(int width, int height, char grid[height][width], int x, int y);

#endif //ALGORITHMS_H