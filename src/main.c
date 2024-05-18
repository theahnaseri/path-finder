#include "grid.h"

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Must set grid width and height in arguments\n");
        printf("./main [width] [height]\n");
        getch();
        return 1;
    }

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    char* algorithm = "";
    char grid[height][width];

    SetGrid(width, height, grid);
    DrawGrid(width, height, algorithm, grid);
    while(true) {
        printf("> Edit grid: press [E]\n> Edit algorithm: press [A]\n> Find path: press [F]\n> Exit app: press [Other key]\n");
        fflush(stdin);
        char key = toupper(getch());
        if (key == 'E') {
            DrawGrid(width, height, algorithm, grid);
            EditGrid(width, height, algorithm, grid);
            DrawGrid(width, height, algorithm, grid);
        }
        else if (key == 'A') {
            DrawGrid(width, height, algorithm, grid);
            SetAlgorithm(&algorithm);
            DrawGrid(width, height, algorithm, grid);
        }
        else if (key == 'F') {
            return 0;
        }
        else {
            return 0;
        }
    }
}

