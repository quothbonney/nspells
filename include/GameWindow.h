//
// Created by quothbonney on 8/5/22.
//

#ifndef BIN_SPELLS_GAMEWINDOW_H
#define BIN_SPELLS_GAMEWINDOW_H

#include <ncursesw/ncurses.h>
#include "Element.h"

class GameWindow {
private:
    int sizeX, sizeY;
    int scrSizeX, scrSizeY;
    int offsetX, offsetY;
    int bgColor;

    void initColor();

public:
    WINDOW* win;


    GameWindow(int y, int x, int xOff, int yOff, bool cent=false, int bgColor=0);

    // Final command in game loop
    // Clears screen, draws background, and initializes a new frame
    // Takes parameter time in milliseconds
    void refresh(int time);

    // Center GameWindow
    void updateOffset();

    // Draws element in position defined by parameters
    // Takes type T as a subclass of Element
    // Valid types are initialized in GameWindow.cpp
    // Takes color as color_pair name defined in GameWindow.cpp
    template<typename T> void drawShape(T& r, int y, int x, int color=8);

    // Draw element in position defined by elementPosition struct
    template<typename T> void drawShapeFromPosition(T& r, elementPosition& e, int color=8);

    // Draws background as color bgColor
    void drawBg();
};


#endif //BIN_SPELLS_GAMEWINDOW_H
