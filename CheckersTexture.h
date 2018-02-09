//
// Created by omer on 2/9/18.
//

#ifndef RENDERER_CHECKERSTEXTURE_H
#define RENDERER_CHECKERSTEXTURE_H

#include "Texture.h"

class CheckersTexture : public Texture {
public:
    CheckersTexture();
    CheckersTexture(double cellSize);
    CheckersTexture(double cellSize, Color &color1, Color &color2);
    virtual Color getColorAt(double x, double y);
private:
    double cellSize;
    Color color1;
    Color color2;
};


#endif //RENDERER_CHECKERSTEXTURE_H
