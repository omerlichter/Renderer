//
// Created by omer on 2/15/18.
//

#include "PlaneMapping.h"

PlaneMapping::PlaneMapping(Vector &normal, double distance) {
    this->normal = normal.normalize();
    this->distance = distance;
    if (this->normal == Vector(0, 1, 0)) {
        this->localXAxis = Vector(1, 0, 0);
    } else {
        this->localXAxis = Vector(0, 1, 0).crossProduct(this->normal).normalize();
    }
    this->localZAxis = localXAxis.crossProduct(this->normal).normalize();
    this->center = this->normal * this->distance;
}

Vector PlaneMapping::getMapCoordinates(Vector &position) {
    Vector pointToCenter = position - this->center;
    double xLength = pointToCenter.dotProduct(this->localXAxis);
    double zLength = pointToCenter.dotProduct(this->localZAxis);
    return Vector(xLength, 0, zLength);
}