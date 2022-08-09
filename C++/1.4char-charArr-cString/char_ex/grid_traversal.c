#include <stdio.h>
/*
Given, a N*N Grid
0,0----------(0,N)
|----------------|
|----------------|
|----------------|
|----------------|
(N,0)---------(N,N)

A robot starting from (x,y) position, after moving U|D|R|L reaches (x',y') position
Take input initial(x,y) position and directions that the robot will move,
then print the final position (x',y')

Example:
Move the robot in U|D|R|L direction (q to stop):
D
moved 🡣
R
moved 🡢
D
moved 🡣
R
moved 🡢
q
Final postion of the robot is: 4,4

 */
int main() {
    int x, y;
    char c;
    printf("Enter the initial position: ");
    scanf("%d %d", &x, &y);

    int grid[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grid[i][j] = 1;
        }
    }

    int n;
    printf("Please enter number of blocked cells:");
    scanf("%d", &n);
    int x_block, y_block;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x_block, &y_block);
        grid[x_block][y_block] = 0;
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    printf("Move the robot in U|D|R|L direction (q to stop):\n");
    while (1) {
        scanf("%c", &c);
        if (c == 'q')
            break;
        else if (c == 'U') {
            if (grid[x - 1][y]) {
                x--;
                printf("moved 🡡\n");
            } else {
                printf("Obstacle ahead 🚩\n");
            }
        }

        else if (c == 'D') {
            if (grid[x + 1][y]) {
                x++;
                printf("moved 🡣\n");
            } else {
                printf("Obstacle ahead 🚩\n");
            }

        } else if (c == 'R') {
            if (grid[x][y + 1]) {
                y++;
                printf("moved 🡢\n");
            } else {
                printf("Obstacle ahead 🚩\n");
            }

        } else if (c == 'L') {
            if (grid[x][y - 1]) {
                y--;
                printf("moved 🡠\n");
            } else {
                printf("Obstacle ahead 🚩\n");
            }
        }
    }
    printf("Final postion of the robot is: %d,%d", x, y);

    return 0;
}
