#include <stdio.h>
#include <stdlib.h>

int board[9][9];

int isSafe(int row, int col, int num);
int solve();

int assignValue(int row, int col) {
    for (int num = 1; num <= 9; num++) {
        if (isSafe(row, col, num)) {
            board[row][col] = num;

            // Recursively solve the rest of the board
            if (solve()) {
                return 1;
            }

            // Backtrack
            board[row][col] = 0;
        }
    }
    return 0;  // Trigger backtracking
}

int isSafe(int row, int col, int num) {
    // Check row
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num)
            return 0;
    }

    // Check column
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num)
            return 0;
    }

    // Check 3x3 sub-grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num)
                return 0;
        }
    }

    return 1;
}

int solve() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                return assignValue(i, j);
            }
        }
    }
    return 1;  // Solved
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

int isValidPuzzle() {
    for (int i = 0; i < 9; i++) {
        int row[9] = {0};
        int column[9] = {0};
        for (int j = 0; j < 9; j++) {
            // Check rows
            if (board[i][j] != 0) {
                if (row[board[i][j] - 1] == 1) {
                    return 0; // Duplicate found in row
                }
                row[board[i][j] - 1] = 1;
            }

            // Check columns
            if (board[j][i] != 0) {
                if (column[board[j][i] - 1] == 1) {
                    return 0; // Duplicate found in column
                }
                column[board[j][i] - 1] = 1;
            }
        }
    }

    // Check 3x3 grids
    for (int gridRow = 0; gridRow < 9; gridRow += 3) {
        for (int gridCol = 0; gridCol < 9; gridCol += 3) {
            int grid[9] = {0};
            for (int i = gridRow; i < gridRow + 3; i++) {
                for (int j = gridCol; j < gridCol + 3; j++) {
                    if (board[i][j] != 0) {
                        if (grid[board[i][j] - 1] == 1) {
                            return 0; // Duplicate found in grid
                        }
                        grid[board[i][j] - 1] = 1;
                    }
                }
            }
        }
    }

    return 1; // Puzzle is valid
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

    if (!isValidPuzzle()) {
        printf("Sudoku is unsolvable: check values on board");
    }

   
    printf("\nSolving...\n\n");
    if (solve()) {
        printSudoku();
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
