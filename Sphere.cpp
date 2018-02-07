//
// Created by omer on 1/25/18.
//

#include "Sphere.h"

Sphere::Sphere(Vector &position, double radius) {
    this->position = position;
    this->radius = radius;
}

Sphere::Sphere(double x, double y, double z, double radius) {
    this->position = Vector(x, y, z);
    this->radius = radius;
}

bool Sphere::getIntersection(Ray &ray, RayCastHit &rayCastHit) {
    Vector o = ray.getOrigin().normalize();
    Vector d = ray.getDirection().normalize();
    Vector l = this->position - ray.getOrigin();
    double tca = l.dotProduct(d);
    double m = l.dotProduct(l) - (tca * tca);
    if (m < 0) {
        return false;
    } else {
        m = sqrt(m);
        if (m > this->radius) {
            return false;
        }

        double thc = sqrt((this->radius * this->radius) - (m * m));
        double t0 = tca - thc;
        double t1 = tca + thc;

        if (t0 < 0 && t1 >= 0) {
            Vector intesectionPoint = o + (t1 * d);
            rayCastHit.setIntersectionPoint(intesectionPoint);
            rayCastHit.setDistance(t1);
        } else if (t1 < 0 && t0 >= 0) {
            Vector intesectionPoint = o + (t0 * d);
            rayCastHit.setIntersectionPoint(intesectionPoint);
            rayCastHit.setDistance(t0);
        } else if (t0 > t1) {
            if (t1 < 0) {
                return false;
            }
            Vector intesectionPoint = o + (t1 * d);
            rayCastHit.setIntersectionPoint(intesectionPoint);
            rayCastHit.setDistance(t1);
        } else if (t1 > t0) {
            if (t0 < 0) {
                return false;
            }
            Vector intesectionPoint = o + (t0 * d);
            rayCastHit.setIntersectionPoint(intesectionPoint);
            rayCastHit.setDistance(t0);
        }
        return true;
    }
}