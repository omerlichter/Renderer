//
// Created by omer on 2/8/18.
//

#ifndef RENDERER_DIFFUSESPECULARMAT_H
#define RENDERER_DIFFUSESPECULARMAT_H


#include "Material.h"

class DiffuseSpecularMat : public Material {
public:
    DiffuseSpecularMat(Color &diffuseColor, Color &specularColor, double specularHardness);
    virtual Color getDiffuseColorAt(Vector &position);
    virtual Color getSpecularColorAt(Vector &position);
    virtual double getSpecularHardnessAt(Vector &position);
    virtual double getReflectionValueAt(Vector &position);

private:
    Color diffuseColor;
    Color specularColor;
    double specularHardness;
};


#endif //RENDERER_DIFFUSESPECULARMAT_H
