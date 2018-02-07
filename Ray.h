//
// Created by omer on 1/21/18.
//

#ifndef RENDERER_RAY_H
#define RENDERER_RAY_H

#include "Vector.h"

class Ray {
public:
    Ray(Vector &origin, Vector &direction);
    Vector &getOrigin();
    Vector &getDirection();
    friend ostream &operator <<(ostream &out, const Ray &ray);
private:
    Vector origin;
    Vector direction;
};


#endif //RENDERER_RAY_H
