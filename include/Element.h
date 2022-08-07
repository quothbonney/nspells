//
// Created by quothbonney on 8/5/22.
//

#ifndef BIN_SPELLS_ELEMENT_H
#define BIN_SPELLS_ELEMENT_H

#include "global.h"

class Element {
protected:
    wchar_t* f;
    virtual wchar_t*** initSprite() = 0;
    elementPosition pos;

public:
    int spriteX;
    int spriteY;
    wchar_t*** sprite;

    Element(int y, int x);
    ~Element();

    // Initialize elementPosition struct
    void definePosition(int y, int x);

    // elementPosition struct getter
    elementPosition getPosition();

    // Offset position by parameters
    void modifyPosition(int y, int x);

};


#endif //BIN_SPELLS_ELEMENT_H
