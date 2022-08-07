//
// Created by quothbonney on 8/5/22.
//

#include "../include/Element.h"
#include "../include/global.h"


Element::Element(int y, int x) {
    this->spriteY = y;
    this->spriteX = x;
}

Element::~Element() {
    delete[] sprite;
}

void Element::definePosition(int y, int x) {
    pos.posX = x;
    pos.posY = y;
}

elementPosition Element::getPosition() {
    return pos;
}

void Element::modifyPosition(int y, int x) {
    pos.posY += y;
    pos.posX += x;
}