#include "grid.h"
#include "algorithms.h"

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Must set grid width and height in arguments\n");
        printf("./main [width] [height]\n");
        GetChar();
        return 1;
    }

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    char* algorithm = "";
    char grid[height][width];
    Point start_point;
    start_point.specified = false;
    Point goal_point;
    goal_point.specified = false;
    int clear_grid = false;

    ResetGrid(width, height, grid);
    char log[50] = "Wellcome to Path Finder :)";

    while(true) {
        DrawGrid(width, height, algorithm, grid, log);
        strcpy(log, "Wellcome to Path Finder :)");
        printf("> Edit grid: press [E]\n> Edit algorithm: press [A]\n> Find path: press [F]\n> Quit: press [Q]\n");
        fflush(stdin);
        char key = toupper(GetChar());
        switch (key) {
            case 'E':
                EditGrid(width, height, algorithm, grid, &start_point, &goal_point, clear_grid);
                clear_grid = false;
                break;
            case 'A':
                SetAlgorithm(width, height, &algorithm, grid);
                clear_grid = false;
                break;
            case 'F':
                if (!start_point.specified) {
                    strcpy(log, "The starting point must be specified!");
                    break;
                }
                else if (!goal_point.specified) {
                    strcpy(log, "The goal point must be specified!");
                    break;
                }
                if (!strcmp(algorithm, "BFS")) {
                    DrawGrid(width, height, algorithm, grid, "");
                    if (DoBFS(width, height, grid, start_point, goal_point)) {
                        strcpy(log, "Goal point found successfully!");
                    }
                    else {
                        strcpy(log, "No path to continue!");
                    }
                    clear_grid = true;
                }
                else if (!strcmp(algorithm, "DFS")) {
                    DrawGrid(width, height, algorithm, grid, "Do DFS algorithm to find path ...");
                    if (DoDFS(width, height, grid, start_point, goal_point)) {
                        strcpy(log, "Goal point found successfully!");
                    }
                    else {
                        strcpy(log, "No path to continue!");
                    }
                    clear_grid = true;
                }
                else if (!strcmp(algorithm, "A*")) {
                    DrawGrid(width, height, algorithm, grid, "Do A* algorithm to find path ...");
                    if (DoAstar(width, height, grid, start_point, goal_point)) {
                        strcpy(log, "Goal point found successfully!");
                    }
                    else {
                        strcpy(log, "No path to continue!");
                    }
                    clear_grid = true;
                }
                else {
                    strcpy(log, "Algorithm must be specified!");
                }
                break;
            case 'Q':
                printf("Goodbye :(\n");
                sleep(1);
                return 0;
            default:
                strcpy(log, "Enter valid key please!");
        }
    }
}

