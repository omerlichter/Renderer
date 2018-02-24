//
// Created by omer on 2/14/18.
//

#ifndef RENDERER_TINTTEXTURE_H
#define RENDERER_TINTTEXTURE_H


#include "Texture.h"

class TintTexture : public Texture {
public:
    TintTexture(Color &color);
    virtual Color getColorAt(double x, double y);
private:
    Color color;
};


#endif //RENDERER_TINTTEXTURE_H
