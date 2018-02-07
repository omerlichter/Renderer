//
// Created by omer on 1/25/18.
//

#include "RayCastHit.h"

RayCastHit::RayCastHit() {

}

Vector RayCastHit::getIntersectionPoint() const {
    return this->intersectionPoint;
}

double RayCastHit::getDistance() const {
    return this->distance;
}

void RayCastHit::setIntersectionPoint(Vector intersectionPoint) {
    this->intersectionPoint = intersectionPoint;
}

void RayCastHit::setDistance(double distance) {
    this->distance = distance;
}