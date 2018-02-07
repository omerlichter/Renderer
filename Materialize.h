//
// Created by omer on 2/7/18.
//

#ifndef RENDERER_MATERIALIZE_H
#define RENDERER_MATERIALIZE_H


#include "Color.h"
#include "Vector.h"

class Materialize {
public:
    virtual Color getColorAt(Vector &position) = 0;
};


#endif //RENDERER_MATERIALIZE_H
