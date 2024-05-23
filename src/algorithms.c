#include "algorithms.h"

int DoBFS(int width, int height, char grid[height][width], Point start_point, Point goal_point) {
    return 0;
}

int DoDFS(int width, int height, char grid[height][width], Point start_point, Point goal_point) {
    Point current_point;
    current_point.x = start_point.x;
    current_point.y = start_point.y;
    int path_counter = 1;
    
    while (true) {
        if ((current_point.y == goal_point.y) && (current_point.x == goal_point.x)) {
            return 1;
        }
        else if ((current_point.y - 1 >= 0) && (IsValidPath(width, height, grid, current_point.x, current_point.y - 1))) {
            grid[current_point.y][current_point.x] = '^';
            current_point.y--;
        }
        else if ((current_point.x + 1 <+ width) && (IsValidPath(width, height, grid, current_point.x + 1, current_point.y))) {
            grid[current_point.y][current_point.x] = '>';
            current_point.x++;
        }
        else if ((current_point.y + 1 < height) && (IsValidPath(width, height, grid, current_point.x, current_point.y + 1))) {
            grid[current_point.y][current_point.x] = 'v';
            current_point.y++;
        }
        else if ((current_point.x - 1 >= 0) && (IsValidPath(width, height, grid, current_point.x - 1, current_point.y))) {
            grid[current_point.y][current_point.x] = '<';
            current_point.x--;
        }
        else {
            return 0;
        }

        DrawGrid(width, height, "DFS", grid, "Do BFS algorithm to find path ...");
        usleep(50 * 1000);
    }
}

int DoAstar(int width, int height, char grid[height][width], Point start_point, Point goal_point) {
    return 0;
}


int IsValidPath(int width, int height, char grid[height][width], int x, int y) {
    if (grid[y][x] == '>' || grid[y][x] == '<' || grid[y][x] == '^' || grid[y][x] == 'v' || grid[y][x] == wall) {
        return 0;
    }
    return 1;
}