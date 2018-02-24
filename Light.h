//
// Created by omer on 2/14/18.
//

#ifndef RENDERER_LIGHT_H
#define RENDERER_LIGHT_H


#include "Vector.h"
#include "Color.h"

class Light {
public:
    virtual Vector getDirectionAt(Vector &point) = 0;
    virtual double getIntensityAt(Vector &point) = 0;
    virtual Color getDiffuseColor() = 0;
    virtual Color getSpecularColor() = 0;
};


#endif //RENDERER_LIGHT_H
