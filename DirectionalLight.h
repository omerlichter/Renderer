//
// Created by omer on 2/7/18.
//

#ifndef RENDERER_DIRECTIONALLIGHT_H
#define RENDERER_DIRECTIONALLIGHT_H


#include "Vector.h"
#include "Color.h"

class DirectionalLight {
public:
    DirectionalLight(Vector &direction, Color &color);
    Vector &getDirection();
    Color &getColor();
private:
    Vector direction;
    Color color;
};


#endif //RENDERER_DIRECTIONALLIGHT_H
