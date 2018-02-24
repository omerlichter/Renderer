//
// Created by omer on 2/22/18.
//

#ifndef RENDERER_ZEROMAPPING_H
#define RENDERER_ZEROMAPPING_H


#include "Mapping.h"

class ZeroMapping : public Mapping {
public:
    ZeroMapping();
    virtual Vector getMapCoordinates(Vector &position);
private:

};


#endif //RENDERER_ZEROMAPPING_H
