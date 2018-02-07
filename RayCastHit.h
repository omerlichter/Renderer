//
// Created by omer on 1/25/18.
//

#ifndef RENDERER_RAYCASTHIT_H
#define RENDERER_RAYCASTHIT_H


#include "Vector.h"

class RayCastHit {
public:
    RayCastHit();
    void setIntersectionPoint(Vector intesectionPoint);
    void setDistance(double distance);
    Vector getIntesectionPoint() const ;
    double getDistance() const ;
private:
    Vector intersectionPoint;
    double distance;
};


#endif //RENDERER_RAYCASTHIT_H
