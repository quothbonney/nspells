//
// Created by quothbonney on 8/5/22.
//

#ifndef BIN_SPELLS_RECTANGLE_H
#define BIN_SPELLS_RECTANGLE_H


class Rectangle {
private:
    wchar_t* f;

    wchar_t*** initSprite();

public:
    int spriteX, spriteY;
    wchar_t*** sprite;

    Rectangle(int y, int x, wchar_t* fill=L"\u2588");

    ~Rectangle();
};


#endif //BIN_SPELLS_RECTANGLE_H
