//
// Created by omer on 2/9/18.
//

#ifndef RENDERER_TEXTURE_H
#define RENDERER_TEXTURE_H


#include "Color.h"

class Texture {
public:
    virtual Color getColorAt(double x, double y) = 0;
};


#endif //RENDERER_TEXTURE_H
