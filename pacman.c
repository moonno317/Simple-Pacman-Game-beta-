#include <stdio.h>
#include <ncurses.h>

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
        "###################", };

    int pacmanX = 1;
    int pacmanY = 1;

    int ch;
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

		board[pacmanY][pacmanX] = 'C'; } while (ch != 'q');

    endwin();

    return 0; }