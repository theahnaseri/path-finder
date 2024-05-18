#include "grid.h"

#ifdef _WIN32
void ClearScreen() {
    system("cls");
}
#elif __linux__
void ClearScreen() {
    system("clear");
}
#endif

void SetGrid(int width, int height, char grid[height][width]) {
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            grid[i][j] = path;
        }
    }
}

void DrawGrid(int width, int height, char* algorithm, char grid[height][width]) {
    ClearScreen();
    printf("[Width:%i]  [Height:%i]  [Algorithm:%s]\n\n", width, height, algorithm);
    printf("[-:path] [#:wall] [S:start] [G:goal]\n\n");
    printf("   ");
    for (int j=0; j<width; j++) {
        if (j < 10) {
            printf("%i  ", j);
        }
        else {
            printf("%i ", j);
        }
    }
    printf("\n");
    for (int i=0; i<height; i++) {
        if (i < 10) {
            printf("%i  ", i);
        }
        else {
            printf("%i ", i);
        }
        for (int j=0; j<width; j++) {
            printf("%c  ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void EditGrid(int width, int height, char* algorithm, char grid[height][width]) {
    char type;
    int row, column;
    int startSelected = false;
    int goalSeclected = false;

    printf("> Edit Grid:\n\n");
    printf("Put wall, set start point and goal point\n");
    printf("Just set what you want put (wall, start or goal)\nand which row and column you want to put\n\n");

    while(true) {
        printf("[-:path] [#:wall] [S:start] [G:goal] [E:end]\n");
        printf("Type(-/#/S/G/E): ");
        fflush(stdin);
        scanf("%c%*c", &type);
        type = toupper(type);
        if (type == 'E') {
            break;;
        }
        if (type != path && type != wall && type != start && type != goal) {
            printf("Choose valid type!\n\n");
            continue;
        }
        if (type == start) {
            if (startSelected) {
                printf("Start point selected!\n\n");
                continue;
            }
            startSelected = true;
        }
        if (type == goal) {
            if (goalSeclected) {
                printf("Goal point selected!\n\n");
                continue;
            }
            goalSeclected = true;
        }
        printf("Row: ");
        fflush(stdin);
        scanf("%i", &row);
        printf("Column: ");
        fflush(stdin);
        scanf("%i", &column);
        printf("\n");

        if (grid[row][column] == start) {
            startSelected = false;
        }
        if (grid[row][column] == goal) {
            goalSeclected = false;
        }

        grid[row][column] = type;
        DrawGrid(width, height, algorithm, grid);
        printf("> Edit Grid\n\n");
        printf("Put wall, set start point and goal point\n");
        printf("Just set what you want put (wall, start or goal)\nand which row and column you want to put\n\n");
    }
}

void SetAlgorithm(char** algorithm) {
    char *input = malloc(5);
    while (true) {
        printf("Algorithm(BFS/DFS/A*): ");
        gets(input);
        for (int i=0; i<strlen(input); i++) {
            input[i] = toupper(input[i]);
        }
        if (strcmp(input, "BFS") && strcmp(input, "DFS") && strcmp(input, "A*")) {
            printf("Choose valid algorithm!\n");
            continue;
        }
        else {
            *algorithm = input;
            break;
        }
    }
}