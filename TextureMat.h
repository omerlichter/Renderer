//
// Created by omer on 2/9/18.
//

#ifndef RENDERER_TEXTUREMAT_H
#define RENDERER_TEXTUREMAT_H


#include "Material.h"
#include "Texture.h"

class TextureMat : public Material{
public:
    TextureMat(Texture &diffuseTexture);
    virtual Color getDiffuseColorAt(Vector &position);
    virtual Color getSpecularColorAt(Vector &position);
    virtual double getSpecularHardnessAt(Vector &position);

private:
    Texture &diffuseTexture;
};


#endif //RENDERER_TEXTUREMAT_H
