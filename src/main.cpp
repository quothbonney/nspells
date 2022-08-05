#include <iostream>
#include <ncursesw/ncurses.h>

#include "../include/Rectangle.h"
#include "../include/GameWindow.h"

int main() {

    setlocale(LC_ALL, "");
    initscr();
    GameWindow gw = GameWindow(20, 40, 0, 0, true);
    Rectangle rect = Rectangle(10, 20);
    refresh();

    gw.drawRectangle(rect, 2, 20);

    wrefresh(gw.win);

    refresh();
    getch();
    getch();
    endwin();

    return EXIT_SUCCESS;
}