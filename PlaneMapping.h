//
// Created by omer on 2/15/18.
//

#ifndef RENDERER_PLANEMAPPING_H
#define RENDERER_PLANEMAPPING_H


#include "Mapping.h"

class PlaneMapping : public Mapping {
public:
    PlaneMapping(Vector &normal, double distance);
    virtual Vector getMapCoordinates(Vector &position);
private:
    Vector normal;
    double distance;
    Vector localXAxis;
    Vector localZAxis;
    Vector center;
};


#endif //RENDERER_PLANEMAPPING_H
