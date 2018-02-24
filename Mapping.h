//
// Created by omer on 2/15/18.
//

#ifndef RENDERER_MAPPING_H
#define RENDERER_MAPPING_H


#include "Vector.h"

class Mapping {
public:
    virtual Vector getMapCoordinates(Vector &position) = 0;
};


#endif //RENDERER_MAPPING_H
