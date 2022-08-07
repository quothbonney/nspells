#include <iostream>
#include <ncursesw/ncurses.h>
#include <unistd.h>

#include "../include/Element.h"
#include "../include/GameWindow.h"
#include "../include/Rectangle.h"


int main() {

    setlocale(LC_ALL, "");
    initscr();
    noecho();
    start_color();
    curs_set(0);
    GameWindow gw = GameWindow(20, 40, 0, 0, true, 2);
    Rectangle rect = Rectangle(10, 10);

    refresh();

    for(int i = 0; i < 40; i++) {
        gw.drawShape(rect, i, i);
        gw.refresh(500);
        waddstr(gw.win, "Hello");
    }
    refresh();
    getch();
    getch();
    endwin();

    return EXIT_SUCCESS;
}