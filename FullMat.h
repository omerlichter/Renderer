//
// Created by omer on 2/14/18.
//

#ifndef RENDERER_FULLMAT_H
#define RENDERER_FULLMAT_H


#include "Material.h"
#include "Texture.h"

class FullMat : public Material{
public:
    FullMat(Texture &diffuse, Texture &specular, double specularHardness, Texture &reflection);
    virtual Color getDiffuseColorAt(Vector &position);
    virtual Color getSpecularColorAt(Vector &position);
    virtual double getSpecularHardnessAt(Vector &position);
    virtual double getReflectionValueAt(Vector &position);

private:
    Texture &diffuseTexture;
    Texture &specularTexture;
    double specularHardness;
    Texture &reflectionTexture;
};


#endif //RENDERER_FULLMAT_H
