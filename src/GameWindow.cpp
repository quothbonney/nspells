//
// Main window for application; draws shapes; can be centered with cent boolean or manually offset with xOff and yOff class attributes
//

#include <ncursesw/ncurses.h>
#include <iostream>

#include "../include/GameWindow.h"
#include "../include/global.h"

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
template<typename T> void GameWindow::drawShape(T& r, int y, int x) {
    for(int i = 0; i < r.spriteY; i++) {
        for(int j = 0; j < r.spriteX; j++) {
            // Check that index is within GameWindow.win
            // Avoids edge garbage
            if(y+i >= 0 && y+i < sizeY && x+j >= 0 && x+j < sizeX) {
                // REFERENCE: mvwaddwstr(win, y, x, str);
                wmove(win, y+i, x+j);
                wchar_t* s = r.sprite[i][j];
                waddwstr(win, s);
            }

        }
    }
}

// Repetitive function better than nested template garbage
// instead of y and x, takes struct elementPosition defined as shape.pos
template<typename T> void GameWindow::drawShapeFromPosition(T& r, elementPosition& e) {
    for(int i = 0; i < r.spriteY; i++) {
        for(int j = 0; j < r.spriteX; j++) {
            // Check that index is within GameWindow.win
            // Avoids edge garbage
            if(e.posY + i >= 0 && e.posY+i < sizeY && e.posX+j >= 0 && e.posX+j < sizeX) {
                // REFERENCE: mvwaddwstr(win, y, x, str);
                wmove(win, e.posY + i, e.posX + j);
                wchar_t* s = r.sprite[i][j];
                waddwstr(win, s);
            }

        }
    }
}

// Instantiate drawShape template for given types in include/GameWindow.h
template void GameWindow::drawShape<Rectangle>(Rectangle& r, int y, int x);

// Ditto, but for drawShapeFromPosition
template void GameWindow::drawShapeFromPosition<Rectangle>(Rectangle& r, elementPosition& e);