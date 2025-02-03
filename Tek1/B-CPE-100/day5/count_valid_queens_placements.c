/*
** EPITECH PROJECT, 2024
** count_valid_queens_placements
** File description:
** displays the number of positions of n queens on a n*n chessboard
*/

void my_putchar(char c);

static int coord(int size, int *board, int i)
{
    for (int j = 0; j < size; j++) {
        if (board[i * size + j] == 1)
            return j;
    }
    return -1;
}

static int diagonales(int para[3], int *board, int fact_i, int fact_j)
{
    if (para[0] + fact_i >= 0 && para[0] + fact_i < para[2]
        && para[1] + fact_j >= 0 && para[1] + fact_j < para[2]) {
        if (board[(para[0] + fact_i) * para[2] + (para[1] + fact_j)] == 1)
            return 1;
    }
    return 0;
}

static int limits(int size, int *board, int i, int j)
{
    int fact;
    int para[3] = {i, j, size};

    fact = 1;
    while (i - fact >= 0 && j + fact < size) {
        if (diagonales(para, board, - fact, fact) == 1)
            return 1;
        fact++;
    }
    fact = 1;
    while (i + fact < size && j + fact < size) {
        if (diagonales(para, board, fact, fact) == 1)
            return 1;
        fact++;
    }
    return 0;
}

int limits2(int size, int *board, int i, int j)
{
    int fact;
    int para[3] = {i, j, size};

    fact = 1;
    while (i + fact < size && j - fact >= 0) {
        if (diagonales(para, board, fact, - fact) == 1)
            return 1;
        fact++;
    }
    fact = 1;
    while (i - fact >= 0 && j - fact >= 0) {
        if (diagonales(para, board, - fact, - fact) == 1)
            return 1;
        fact++;
    }
    return 0;
}

static void create_board(int size, int *board)
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i * size + j] = 0;
        }
    }
}

static int is_safe(int size, int *board, int i, int j)
{
    for (int k = 0; k < size; k++) {
        if (board[i * size + k] == 1)
            return 0;
    }
    for (int l = 0; l < size; l++) {
        if (board[l * size + j] == 1)
            return 0;
    }
    if (limits(size, board, i, j) == 1 || limits2(size, board, i, j) == 1)
        return 0;
    return 1;
}

int all_safe(int size, int *board, int i)
{
    int sum = 0;

    if (i == size) {
        return 1;
    }
    for (int j = 0; j < size; j++) {
        if (is_safe(size, board, i, j)) {
            board[i * size + j] = 1;
            sum += all_safe(size, board, i + 1);
            board[i * size + j] = 0;
        }
    }
    return sum;
}

int count_valid_queens_placements(int n)
{
    int board[n * n];

    if (n <= 0)
        return 0;
    create_board(n, board);
    return all_safe(n, board, 0);
}
