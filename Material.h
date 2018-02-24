//
// Created by omer on 2/8/18.
//

#ifndef RENDERER_MATERIAL_H
#define RENDERER_MATERIAL_H


#include "Vector.h"
#include "Color.h"

class Material {
public:
    virtual Color getDiffuseColorAt(Vector &position) = 0;
    virtual Color getSpecularColorAt(Vector &position) = 0;
    virtual double getSpecularHardnessAt(Vector &position) = 0;
    virtual double getReflectionValueAt(Vector &position) = 0;
};


#endif //RENDERER_MATERIAL_H
