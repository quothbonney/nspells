//
// Created by quothbonney on 8/7/22.
//

#ifndef NSPELLS_RECTANGLE_H
#define NSPELLS_RECTANGLE_H

#include "Element.h"

class Rectangle : Element {
public:
    Rectangle(int y, int x, wchar_t* fill=L"\u2588");

    wchar_t*** initSprite();
};


#endif //NSPELLS_RECTANGLE_H
