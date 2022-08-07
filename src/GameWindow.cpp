//
// Main window for application; draws shapes; can be centered with cent boolean or manually offset with xOff and yOff class attributes
//

#include <ncursesw/ncurses.h>
#include <iostream>
#include <unistd.h>

#include "../include/GameWindow.h"
#include "../include/global.h"
#include "../include/Rectangle.h"

void GameWindow::initColor() {
    bool hc = has_colors();
    bool cc = can_change_color();
    if(!hc || !cc) {
        std::cerr << "initColor(): terminal does not support colors!";
        exit(1);
    }
    init_pair(1, COLOR_BLACK, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_BLUE, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_CYAN, COLOR_BLACK);
    init_pair(8, COLOR_WHITE, COLOR_WHITE);
}

void GameWindow::drawBg() {
    wattron(win, COLOR_PAIR(bgColor));
    wchar_t* block = L"\u2588";
    for(int i = 0; i < sizeX * sizeY; i++)
        waddwstr(win, block);
    wattroff(win, COLOR_PAIR(bgColor));
}

void GameWindow::refresh(int time) {
    wrefresh(win);
    usleep(time * 100);
    werase(win);
    updateOffset();
    drawBg();
}

void GameWindow::updateOffset() {
    getmaxyx(stdscr, scrSizeY, scrSizeX);
    offsetX = (scrSizeX - sizeX) / 2;
    offsetY = (scrSizeY - sizeY) / 2;
}

GameWindow::GameWindow(int y, int x, int xOff, int yOff, bool cent, int bg) {
    this->sizeX = x;
    this->sizeY = y;
    this->offsetX = xOff;
    this->offsetY = yOff;
    this->bgColor = bg;

    initColor();

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
template<typename T> void GameWindow::drawShape(T& r, int y, int x, int color) {
    wattron(win, COLOR_PAIR(color));
    // Because the inherited attributes of T& r from Element are protected,
    // Go up a level to superclass Element to access the attributes publicly
    for(int i = 0; i < reinterpret_cast<Element&>(r).spriteY; i++) {
        for(int j = 0; j < reinterpret_cast<Element&>(r).spriteX; j++) {
            // Check that index is within GameWindow.win
            // Avoids edge garbage
            if(y+i >= 0 && y+i < sizeY && x+j >= 0 && x+j < sizeX) {
                // REFERENCE: mvwaddwstr(win, y, x, str);
                wmove(win, y+i, x+j);
                wchar_t* s = reinterpret_cast<Element&>(r).sprite[i][j];
                waddwstr(win, s);
            }

        }
    }
    wattroff(win, COLOR_PAIR(color));
}

// Repetitive function better than nested template garbage
// instead of y and x, takes struct elementPosition defined as shape.pos
template<typename T> void GameWindow::drawShapeFromPosition(T& r, elementPosition& e, int color) {
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
template void GameWindow::drawShape<Rectangle>(Rectangle& r, int y, int x, int color);

// Ditto, but for drawShapeFromPosition
template void GameWindow::drawShapeFromPosition<Element>(Element& r, elementPosition& e, int color);