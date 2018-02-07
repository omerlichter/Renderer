//
// Created by omer on 1/25/18.
//

#ifndef RENDERER_SPHERE_H
#define RENDERER_SPHERE_H


#include "Object.h"

class Sphere : public Object {
public:
    Sphere(Vector &position, double radius);
    Sphere(double x, double y, double z, double radius);
    virtual bool getIntersection(Ray &ray, RayCastHit &rayCastHit);

private:
    Vector position;
    double radius;
};


#endif //RENDERER_SPHERE_H
