//
// Created by omer on 1/25/18.
//

#ifndef RENDERER_SPHERE_H
#define RENDERER_SPHERE_H


#include "Object.h"

class Sphere : public Object {
public:
    Sphere(Vector &position, double radius, Color &color);
    Sphere(double x, double y, double z, double radius, Color &color);
    virtual bool getIntersection(Ray &ray, RayCastHit &rayCastHit);
    virtual Vector getNormalAt(Vector &position);
    virtual Color getColorAt(Vector &position);

private:
    Vector position;
    double radius;
    Color color;
};


#endif //RENDERER_SPHERE_H
