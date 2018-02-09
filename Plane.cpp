//
// Created by omer on 2/9/18.
//

#include "Plane.h"

Plane::Plane(Vector &normal, double distance, Material &material) : material(material) {
    this->normal = normal.normalize();
    this->distance = distance;
}

Plane::Plane(double x, double y, double z, double distance, Material &material) : material(material) {
    this->normal = Vector(x, y, z).normalize();
    this->distance = distance;
}

Vector Plane::getNormalAt(Vector &position) {
    return this->normal;
}

bool Plane::getIntersection(Ray &ray, RayCastHit &rayCastHit) {
    Vector o = ray.getOrigin();
    Vector d = ray.getDirection().normalize();
    double nv = d.dotProduct(this->normal);
    if (fabs(nv) > 0.000001) {
        double np = o.dotProduct(this->normal);
        double t = -(np + this->distance) / nv;
        if (t < 0) {
            return false;
        }
        Vector intersectionPoint = o + (t * d);
        rayCastHit.setDistance(t);
        rayCastHit.setIntersectionPoint(intersectionPoint);
        return true;
    }
    return false;
}

Material& Plane::getMaterial() {
    return this->material;
}