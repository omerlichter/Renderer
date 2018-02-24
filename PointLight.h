//
// Created by omer on 2/14/18.
//

#ifndef RENDERER_POINTLIGHT_H
#define RENDERER_POINTLIGHT_H


#include "Light.h"

class PointLight : public Light {
public:
    PointLight(double intensity, Vector &position,
               Color &diffuseColor, Color &specularColor);
    virtual Vector getDirectionAt(Vector &point);
    virtual double getIntensityAt(Vector &point);
    virtual Color getDiffuseColor();
    virtual Color getSpecularColor();
private:
    double intensity;
    Vector position;
    Color diffuseColor;
    Color specularColor;
};


#endif //RENDERER_POINTLIGHT_H
