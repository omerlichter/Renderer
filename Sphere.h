//
// Created by omer on 1/25/18.
//

#ifndef RENDERER_SPHERE_H
#define RENDERER_SPHERE_H


#include "Object.h"
#include "ZeroMapping.h"

class Sphere : public Object {
public:
    Sphere(Vector &position, double radius, Material &material);
    Sphere(double x, double y, double z, double radius, Material &material);
    virtual bool getIntersection(Ray &ray, RayCastHit &rayCastHit);
    virtual Vector getNormalAt(Vector &position);
    virtual Material &getMaterial();
    virtual Mapping &getMapping();

private:
    Vector position;
    double radius;
    Material &material;
    ZeroMapping mapping;
};


#endif //RENDERER_SPHERE_H
