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
    int bgColor;

    void initColor();



public:
    WINDOW* win;

    void updateOffset();
    GameWindow(int y, int x, int xOff, int yOff, bool cent=false, int bgColor=0);

    void refresh(int time);

    template<typename T> void drawShape(T& r, int y, int x, int color=8);

    template<typename T> void drawShapeFromPosition(T& r, elementPosition& e, int color=8);

    void drawBg();
};


#endif //BIN_SPELLS_GAMEWINDOW_H
