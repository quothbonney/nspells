//
// Created by quothbonney on 8/7/22.
//

#include "../include/Rectangle.h"

Rectangle::Rectangle(int y, int x, wchar_t* fill) : Element(y, x) {
    // wchar_t fill character defined in Element.h
    this->f = fill;

    sprite = initSprite();
}

wchar_t*** Rectangle::initSprite() {
    wchar_t*** sp = new wchar_t**[spriteY];
    for(int row = 0; row < spriteY; row++) {
        sp[row] = new wchar_t*[spriteX];
        for(int elem = 0; elem < spriteX; elem++)
            sp[row][elem] = f;
    }
    return sp;
}