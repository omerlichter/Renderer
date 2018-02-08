//
// Created by omer on 2/7/18.
//

#ifndef RENDERER_DIRECTIONALLIGHT_H
#define RENDERER_DIRECTIONALLIGHT_H


#include "Vector.h"
#include "Color.h"

class DirectionalLight {
public:
    DirectionalLight(Vector &direction, Color &diffuseColor, Color &specularColor);
    Vector &getDirection();
    Color &getDiffuseColor();
    Color &getSpecularColor();
private:
    Vector direction;
    Color diffuseColor;
    Color specularColor;
};


#endif //RENDERER_DIRECTIONALLIGHT_H
