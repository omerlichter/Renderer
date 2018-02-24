//
// Created by omer on 2/9/18.
//

#ifndef RENDERER_PLANE_H
#define RENDERER_PLANE_H


#include "Object.h"
#include "PlaneMapping.h"

class Plane : public Object {
public:
    Plane(Vector &normal, double distance, Material &material);
    Plane(double x, double y, double z, double distance, Material &material);
    virtual bool getIntersection(Ray &ray, RayCastHit &rayCastHit);
    virtual Vector getNormalAt(Vector &position);
    virtual Material &getMaterial();
    virtual Mapping &getMapping();

    Vector &getNormal();
    double getDistance();

private:
    Vector normal;
    double distance;
    Material &material;
    PlaneMapping mapping;
};


#endif //RENDERER_PLANE_H
