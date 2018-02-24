//
// Created by omer on 2/9/18.
//

#include "Plane.h"

Plane::Plane(Vector &normal, double distance, Material &material) :
        material(material), normal(normal.normalize()), distance(distance), mapping(normal, distance) {
}

Plane::Plane(double x, double y, double z, double distance, Material &material) :
        normal(Vector(x, y, z).normalize()), distance(distance), material(material),
        mapping(normal, distance) {
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

Mapping& Plane::getMapping() {
    return this->mapping;
}

Vector& Plane::getNormal() {
    return this->normal;
}

double Plane::getDistance() {
    return this->distance;
}