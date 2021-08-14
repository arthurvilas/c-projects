#include <stdio.h>

#define LEN 3   // Length of table side

int game_won(int table[][LEN]);
void print_table(int table[][LEN]);
void new_turn(int table[][LEN]);

int main(void) {

    int winner, table[LEN][LEN] = {0};

    for (int i = 0; i < LEN * LEN; i++) {
        print_table(table);
        new_turn(table);

        if ((winner = game_won(table)) != 0) {
            print_table(table);
            printf("\nFINISHED! '%c' has won.\n", winner > 0 ? 'X' : 'O');
            return 0;
        }
    }
    printf("Draw!\n");
    return 0;
}

// Prints table structure and current state of the table
void print_table(int table[][LEN]) {
    printf("\n-------------------------");
    printf("\n  ## TABLE STRUCTURE ##\n");
    int i = 0;
    for (int row = 0; row < LEN; row++) {
        putchar('\t');
        for (int col = 0; col < LEN; col++) {
            printf("%d", i++);
            if (col != LEN - 1) {
                printf(" | ");
            }
        }
        if (row != LEN - 1) {
            printf("\n\t---------\n");
        } else {
            putchar('\n');
        }
    }
    printf("-------------------------\n\n");

    for (int row = 0; row < LEN; row++) {
        putchar('\t');
        for (int col = 0; col < LEN; col++) {
            switch (table[row][col])
            {
            case 1:
                putchar('X');
                break;
            case -1:
                putchar('O');
                break;
            default:
                putchar(' ');
                break;
            }
            if (col != LEN - 1) {
                printf(" | ");
            }
        }
        if (row != LEN - 1) {
            printf("\n\t---------\n");
        } else {
            putchar('\n');
        }
    }
}

// Checks if the player has won and returns winning player
int game_won(int table[][LEN]) {
    
    int sum;
    // Vertical wins
    for (int col = 0; col < LEN; col++) {
        sum = 0;
        for (int row = 0; row < LEN; row++) {
            sum += table[row][col];
        }

        if (sum == LEN) {
            return 1;
        } else if (sum == -LEN) {
            return -1;
        }
    }

    // Horizontal wins
    for (int row = 0; row < LEN; row++) {
        sum = 0;
        for (int col = 0; col < LEN; col++) {
            sum += table[row][col];
        }

        if (sum == LEN) {
            return 1;
        } else if (sum == -LEN) {
            return -1;
        }
    }

    // Diagonal wins
    sum = 0;
    for (int row = 0; row < LEN; row++) {
        int col = row;
        sum += table[row][col];

        if (sum == LEN) {
            return 1;
        } else if (sum == -LEN) {
            return -1;
        }
    }
    sum = 0;
    for (int col = LEN-1; col >= 0; col--) {
        int row = (LEN - 1) - col;
        sum += table[row][col];

        if (sum == LEN) {
            return 1;
        } else if (sum == -LEN) {
            return -1;
        }
    }

    return 0;
}

// Runs a turn
void new_turn(int table[][LEN]) {
    static int player = 1;

    int position, *p = &table[0][0];

    printf("\nPlayer %c, type a position: ", player > 0 ? 'X' : 'O');
    scanf("%d", &position);
    p += position;

    while (position < 0 || position >= (LEN * LEN) || *p != 0) {
        p = &table[0][0];
        printf("\n--- Invalid position, try again. ---\n");
        printf("\nPlayer %c, type a position: ", player > 0 ? 'X' : 'O');
        scanf("%d", &position);
        p += position;
    }
    *p = player;

    player = player > 0 ? -1 : 1;
}