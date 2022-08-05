#include <iostream>
#include <ncursesw/ncurses.h>
#include <unistd.h>

#include "../include/Rectangle.h"
#include "../include/GameWindow.h"

int main() {

    setlocale(LC_ALL, "");
    initscr();
    GameWindow gw = GameWindow(40, 80, 0, 0, true);
    Rectangle rect = Rectangle(10, 20);
    Rectangle rect2 = Rectangle(5, 10);
    refresh();
    for(int i = 0; i < 40; i++) {
        gw.drawShape(rect, i, i);
        gw.drawShape(rect2, 10, i);
        wrefresh(gw.win);
        usleep(100000);
        werase(gw.win);
    }
    refresh();
    getch();
    getch();
    endwin();

    return EXIT_SUCCESS;
}