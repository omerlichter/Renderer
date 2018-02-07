//
// Created by omer on 2/7/18.
//

#ifndef RENDERER_COLLIDABLE_H
#define RENDERER_COLLIDABLE_H


#include "RayCastHit.h"
#include "Ray.h"

class Collidable {
public:
    virtual bool getIntersection(Ray &ray, RayCastHit &rayCastHit) = 0;
    virtual Vector getNormalAt(Vector &position) = 0;
};


#endif //RENDERER_COLLIDABLE_H
