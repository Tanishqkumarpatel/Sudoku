#include <stdio.h>
#include <stdlib.h>

int board[9][9];

int isSolved() {
    for (int i = 0; i < 9; i++) {

        // Initialize row and column tracking arrays
        int row[9] = {0};  // Array to track numbers seen in row
        int column[9] = {0};  // Array to track numbers seen in column

        for (int j = 0; j < 9; j++) {

            // Checking for valid numbers (1-9)
            if (board[i][j] < 1 || board[i][j] > 9)
                return 0;  // Invalid value

            // Check if the number is repeated in the row
            if (row[board[i][j] - 1] == 1) {
                return 0;  // Duplicate found in row
            } else {
                row[board[i][j] - 1] = 1;  // Mark number as seen in the row
            }

            // Check if the number is repeated in the column
            if (column[board[j][i] - 1] == 1) {
                return 0;  // Duplicate found in column
            } else {
                column[board[j][i] - 1] = 1;  // Mark number as seen in the column
            }
        }
    }

    // Checking 9 3x3 sub-grids for duplicates
    for (int gridRow = 0; gridRow < 9; gridRow += 3) {
        for (int gridCol = 0; gridCol < 9; gridCol += 3) {
            int grid[9] = {0};  // Array to track numbers seen in 3x3 grid
            for (int row = gridRow; row < gridRow + 3; row++) {
                for (int col = gridCol; col < gridCol + 3; col++) {
                    if (grid[board[row][col] - 1] == 1) {
                        return 0;  // Duplicate found in sub-grid
                    } else {
                        grid[board[row][col] - 1] = 1;  // Mark number as seen in grid
                    }
                }
            }
        }
    }

    return 1;  // No duplicates found, board is solved
}

void printSudoku() {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0)
            printf(" -----------\n");
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0)
                printf("|");
            printf("%d", board[i][j]);
            if (j == 8)
                printf("|");
        }
        printf("\n");
        if (i == 8)
            printf(" -----------\n");
    }
}

int main(int arg, char **argc) {
    if (arg != 82) {
        printf("invalid input: need all 81 values blank as 0");
        return 1;
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            board[i][j] = atoi(argc[j + 1 + (i * 9)]);
        }
    }

    printSudoku();
}





