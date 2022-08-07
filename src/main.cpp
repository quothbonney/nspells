#include <iostream>
#include <ncursesw/ncurses.h>
#include <unistd.h>

#include "../include/Rectangle.h"
#include "../include/GameWindow.h"


int main() {

    setlocale(LC_ALL, "");
    initscr();
    noecho();
    start_color();
    curs_set(0);
    GameWindow gw = GameWindow(60, 150, 0, 0, true, 2);
    Rectangle rect = Rectangle(10, 20);
    Rectangle rect2 = Rectangle(5, 15);
    Rectangle rect3 = Rectangle(4, 10);

    rect3.definePosition(4, 4);
    refresh();

    for(int i = 0; i < 40; i++) {

        gw.drawShape(rect, i, i);
        gw.drawShape(rect2, 10, i, 4);
        elementPosition pos = rect3.getPosition();
        gw.drawShapeFromPosition(rect3, pos);
        rect3.modifyPosition(0, (int)i/2);
        gw.refresh(500);
        waddstr(gw.win, "Hello");
    }
    refresh();
    getch();
    getch();
    endwin();

    return EXIT_SUCCESS;
}