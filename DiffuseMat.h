//
// Created by omer on 2/8/18.
//

#ifndef RENDERER_DIFFUSEMAT_H
#define RENDERER_DIFFUSEMAT_H

#include "Material.h"

class DiffuseMat : public Material {
public:
    DiffuseMat(Color &diffuseColor);
    virtual Color getDiffuseColorAt(Vector &position);
    virtual Color getSpecularColorAt(Vector &position);
    virtual double getSpecularHardnessAt(Vector &position);
    virtual double getReflectionValueAt(Vector &position);
private:
    Color diffuseColor;
};


#endif //RENDERER_DIFFUSEMAT_H
