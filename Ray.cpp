//
// Created by omer on 1/21/18.
//

#include "Ray.h"

Ray::Ray(Vector &origin, Vector &direction) {
    this->origin = origin;
    this->direction = direction;
}

Vector& Ray::getDirection() {
    return this->direction;
}

Vector& Ray::getOrigin() {
    return this->origin;
}

ostream &operator <<(ostream &out, const Ray &ray) {
    out << "Ray{" << ray.origin << ", " << ray.direction << "}";
}