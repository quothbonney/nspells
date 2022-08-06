//
// Created by quothbonney on 8/5/22.
//

#include "../include/Rectangle.h"
#include "../include/global.h"

wchar_t*** Rectangle::initSprite() {
    wchar_t*** sp = new wchar_t**[spriteY];
    for(int row = 0; row < spriteY; row++) {
        sp[row] = new wchar_t*[spriteX];
        for(int elem = 0; elem < spriteX; elem++)
            sp[row][elem] = f;
    }
    return sp;
}

Rectangle::Rectangle(int y, int x, wchar_t* fill) {
    this->spriteY = y;
    this->spriteX = x;
    this->f = fill;

    sprite = initSprite();
}

Rectangle::~Rectangle() {
    delete[] sprite;
}

void Rectangle::definePosition(int y, int x) {
    pos.posX = x;
    pos.posY = y;
}

elementPosition Rectangle::getPosition() {
    return pos;
}

void Rectangle::modifyPosition(int y, int x) {
    pos.posY += y;
    pos.posX += x;
}