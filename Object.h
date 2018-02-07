//
// Created by omer on 1/25/18.
//

#ifndef RENDERER_OBJECT_H
#define RENDERER_OBJECT_H


#include "Vector.h"
#include "Ray.h"
#include "RayCastHit.h"

class Object {
public:
    virtual bool getIntersection(Ray &ray, RayCastHit &rayCastHit) = 0;
private:
};


#endif //RENDERER_OBJECT_H
