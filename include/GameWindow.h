//
// Created by quothbonney on 8/5/22.
//

#ifndef BIN_SPELLS_GAMEWINDOW_H
#define BIN_SPELLS_GAMEWINDOW_H

#include <ncursesw/ncurses.h>
#include "Rectangle.h"

class GameWindow {
private:
    int sizeX, sizeY;
    int scrSizeX, scrSizeY;
    int offsetX, offsetY;

public:
    WINDOW* win;

    void updateOffset();
    GameWindow(int y, int x, int xOff, int yOff, bool cent=false);
    void drawRectangle(Rectangle& r, int y, int x);
};


#endif //BIN_SPELLS_GAMEWINDOW_H
