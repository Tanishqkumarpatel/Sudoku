#include <stdio.h>
#include <stdlib.h>

int board[9][9];



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





