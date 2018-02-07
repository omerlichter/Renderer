//
// Created by omer on 1/25/18.
//

#include "RayCastHit.h"

RayCastHit::RayCastHit() {

}

Vector RayCastHit::getIntesectionPoint() const {
    return this->intersectionPoint;
}

double RayCastHit::getDistance() const {
    return this->distance;
}

void RayCastHit::setIntersectionPoint(Vector intesectionPoint) {
    this->intersectionPoint = intesectionPoint;
}

void RayCastHit::setDistance(double distance) {
    this->distance = distance;
}