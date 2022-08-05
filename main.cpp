#include <iostream>
#include <ncursesw/ncurses.h>

class Rectangle {
private:
    wchar_t* f;

    wchar_t*** initSprite() {
        wchar_t*** sp = new wchar_t**[spriteY];
        for(int row = 0; row < spriteY; row++) {
            sp[row] = new wchar_t*[spriteX];
            for(int elem = 0; elem < spriteX; elem++)
                sp[row][elem] = f;
        }
        return sp;
    }

public:
    int spriteX, spriteY;
    wchar_t*** sprite;

    Rectangle(int y, int x, wchar_t* fill=L"\u2588") {
        this->spriteY = y;
        this->spriteX = x;
        this->f = fill;

        sprite = initSprite();
    }

    ~Rectangle() {
        delete[] sprite;
    }
};

//
// GameWindow: canvas for game.
//
class GameWindow {
private:
    int sizeX, sizeY;
    int scrSizeX, scrSizeY;
    int offsetX, offsetY;

public:
    WINDOW* win;

    void updateOffset() {
        getmaxyx(stdscr, scrSizeY, scrSizeX);
        offsetX = (scrSizeX - sizeX) / 2;
        offsetY = (scrSizeY - sizeY) / 2;
    }

    GameWindow(int y, int x, int xOff, int yOff, bool cent=false) {
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

    void drawRectangle(Rectangle& r, int y, int x) {
        for(int i = 0; i < r.spriteY; i++) {
            for(int j = 0; j < r.spriteX; j++) {
                //mvwaddwstr(win, y+i, x+j, str);
                wmove(win, y+i, x+j);
                wchar_t* s = r.sprite[i][j];
                waddwstr(win, s);
            }
        }

    }
};



int main() {

    setlocale(LC_ALL, "");
    initscr();
    GameWindow gw = GameWindow(40, 80, 0, 0, true);
    Rectangle rect = Rectangle(20, 40);
    refresh();

    gw.drawRectangle(rect, 2, 20);

    wrefresh(gw.win);

    refresh();
    getch();
    getch();
    endwin();
}