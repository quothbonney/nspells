//
// Main window for application; draws shapes; can be centered with cent boolean or manually offset with xOff and yOff class attributes
//

#include "../include/GameWindow.h"
#include <ncursesw/ncurses.h>
#include <iostream>

void GameWindow::updateOffset() {
    getmaxyx(stdscr, scrSizeY, scrSizeX);
    offsetX = (scrSizeX - sizeX) / 2;
    offsetY = (scrSizeY - sizeY) / 2;
}

GameWindow::GameWindow(int y, int x, int xOff, int yOff, bool cent) {
    this->sizeX = x;
    this->sizeY = y;
    this->offsetX = xOff;
    this->offsetY = yOff;

    // Init scrSize variable
    getmaxyx(stdscr, scrSizeY, scrSizeX);

    // Update offset to center
    if (cent) { updateOffset(); }

    // Ensure board fits to screen
    if (sizeX + offsetX > scrSizeX || sizeY + offsetY > scrSizeY) {
        std::cerr << "FATAL: GameWindow with size " << sizeX << "x" << sizeY
                  << " exceeds terminal size! Expand window and rerun." << std::endl;
        exit(1);
    }

    // Init window
    win = newwin(sizeY, sizeX, offsetY, offsetX);
}

void GameWindow::drawRectangle(Rectangle& r, int y, int x) {
    for(int i = 0; i < r.spriteY; i++) {
        for(int j = 0; j < r.spriteX; j++) {
            //mvwaddwstr(win, y+i, x+j, str);
            wmove(win, y+i, x+j);
            wchar_t* s = r.sprite[i][j];
            waddwstr(win, s);
        }
    }

}