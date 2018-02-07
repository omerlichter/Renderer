//
// Created by omer on 1/19/18.
//

#ifndef RENDERER_RENDERER_H
#define RENDERER_RENDERER_H

#include <vector>
#include "Notifier.h"
#include "pixel.h"
#include "WriteBMP.h"
#include "Camera.h"
#include "Vector.h"
#include "Ray.h"
#include "Scene.h"

class Renderer : public Notifier {
public:
    void render(Scene &scene);
private:
    Pixel calculatePixelColor() const;
};


#endif //RENDERER_RENDERER_H
