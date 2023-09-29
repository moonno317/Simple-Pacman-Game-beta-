#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_WIDTH 20
#define BOARD_HEIGHT 10

int main() {
    char board[BOARD_HEIGHT][BOARD_WIDTH] = {
        "###################",
        "#                 #",
        "#                 #",
        "#                 #",
        "#                 #",
        "#                 #",
        "#                 #",
        "#                 #",
        "#                 #",
        "###################"
    };

    int pacmanX = 1;
    int pacmanY = 1;
    int ghostX = 10;
    int ghostY = 5;
    int ch;
    int gameOver = 0;

    srand(time(NULL));

    initscr();
    keypad(stdscr, TRUE);
    noecho();

    do {
        clear();

        for (int y = 0; y < BOARD_HEIGHT; y++) {
            printw("%s\n", board[y]); }

        ch = getch();
        switch (ch) {
            case KEY_UP:
                if (board[pacmanY - 1][pacmanX] != '#') {
                    board[pacmanY][pacmanX] = ' ';
                    pacmanY--; }
                break;

            case KEY_DOWN:
                if (board[pacmanY + 1][pacmanX] != '#') {
                    board[pacmanY][pacmanX] = ' ';
                    pacmanY++; }
                break;

            case KEY_LEFT:
                if (board[pacmanY][pacmanX - 1] != '#') {
                    board[pacmanY][pacmanX] = ' ';
                    pacmanX--; }
                break;

            case KEY_RIGHT:
                if (board[pacmanY][pacmanX + 1] != '#') {
                    board[pacmanY][pacmanX] = ' ';
                    pacmanX++; }
                break; }

        if (pacmanX == ghostX && pacmanY == ghostY) {
            gameOver = 1;
            break; }

        int direction = rand() % 4;
        switch (direction) {
            case 0:
                if (board[ghostY - 1][ghostX] != '#') {
                    board[ghostY][ghostX] = ' ';
                    ghostY--; }
                break;

            case 1:
                if (board[ghostY + 1][ghostX] != '#') {
                    board[ghostY][ghostX] = ' ';
                    ghostY++; }
                break;

            case 2:
                if (board[ghostY][ghostX - 1] != '#') {
                    board[ghostY][ghostX] = ' ';
                    ghostX--; }
                break;

            case 3:
                if (board[ghostY][ghostX + 1] != '#') {
                    board[ghostY][ghostX] = ' ';
                    ghostX++; }
                break; }

        board[pacmanY][pacmanX] = 'C';
        board[ghostY][ghostX] = 'A'; } while (ch != 'q' && !gameOver);

    endwin();

    if (gameOver) {
        printf("Game Over! :( \n"); }

    return 0; }
