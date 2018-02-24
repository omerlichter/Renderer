//
// Created by omer on 2/7/18.
//

#ifndef RENDERER_DIRECTIONALLIGHT_H
#define RENDERER_DIRECTIONALLIGHT_H


#include "Vector.h"
#include "Color.h"
#include "Light.h"

class DirectionalLight : public Light {
public:
    DirectionalLight(double intensity, Vector &direction, Color &diffuseColor, Color &specularColor);
    virtual Vector getDirectionAt(Vector &point);
    virtual double getIntensityAt(Vector &point);
    virtual Color getDiffuseColor();
    virtual Color getSpecularColor();
private:
    double intensity;
    Vector direction;
    Color diffuseColor;
    Color specularColor;
};


#endif //RENDERER_DIRECTIONALLIGHT_H
