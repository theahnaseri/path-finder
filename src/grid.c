#include "grid.h"

#ifdef _WIN32
#include <conio.h>
void ClearScreen() {
    system("cls");
}
int GetChar() {
    getch();
}

#elif __linux__
#include <termios.h>
void ClearScreen() {
    system("clear");
}
int GetChar()
{
    int ch;
    struct termios oldt;
    struct termios newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar(); 
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#endif



void ResetGrid(int width, int height, char grid[height][width]) {
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            grid[i][j] = path;
        }
    }
}

void DrawGrid(int width, int height, char* algorithm, char grid[height][width], char* log) {
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
    printf("\n[Log: %s]\n\n", log);
}

void EditGrid(int width, int height, char* algorithm, char grid[height][width], Point *start_point, Point *goal_point, int clear_grid) {
    char type;
    int row, column;
    char log[50] = "";

    if (clear_grid) {
        ResetGrid(width, height, grid);
    }
    while(true) {
        DrawGrid(width, height, algorithm, grid, log);

        printf("***Edit Grid***\n\n");
        printf("Just set what you want put (wall, start or goal)\nand which row and column you want to put\n\n");

        printf("[-:path] [#:wall] [S:start] [G:goal] [E:end]\n");
        printf("> Type(-/#/S/G/E): ");
        fflush(stdin);
        scanf("%c", &type);
        type = toupper(type);
        if (type == 'E') {
            break;;
        }
        else if (type != path && type != wall && type != start && type != goal) {
            strcpy(log, "Choose valid type!");
            continue;
        }
        else if (type == start) {
            if (start_point->specified) {
                strcpy(log, "Start point selected!");
                continue;
            }
            start_point->specified = true;
        }
        else if (type == goal) {
            if (goal_point->specified) {
                strcpy(log, "Goal point selected!");
                continue;
            }
            goal_point->specified = true;
        }

        printf("> Row: ");
        fflush(stdin);
        scanf("%i", &row);
        printf("> Column: ");
        fflush(stdin);
        scanf("%i", &column);
        printf("\n");

        if (grid[row][column] == start) {
            start_point->specified  = false;
        }
        else if (grid[row][column] == goal) {
            goal_point->specified = false;
        }

        if (type == start) {
            start_point->x = column;
            start_point->y = row;
        }
        else if (type == goal) {
            goal_point->x = column;
            goal_point->y = row;
        }
        grid[row][column] = type;
    }
}

void SetAlgorithm(int width, int height, char** algorithm, char grid[height][width]) {
    char *input = malloc(10);
    char log[50] = "";
    while (true) {
        DrawGrid(width, height, *algorithm, grid, log);
        printf("***Edit algorithm***\n\n");
        printf("> Algorithm(BFS/DFS/A*): ");
        gets(input);
        for (int i=0; i<strlen(input); i++) {
            input[i] = toupper(input[i]);
        }
        if (strcmp(input, "BFS") && strcmp(input, "DFS") && strcmp(input, "A*")) {
            strcpy(log, "Choose valid algorithm!");
            continue;
        }
        else {
            *algorithm = input;
            break;
        }
    }
}