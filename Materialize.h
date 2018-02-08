//
// Created by omer on 2/7/18.
//

#ifndef RENDERER_MATERIALIZE_H
#define RENDERER_MATERIALIZE_H

#include "Material.h"

class Materialize {
public:
    virtual Material &getMaterial() = 0;
};


#endif //RENDERER_MATERIALIZE_H
