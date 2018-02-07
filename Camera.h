//
// Created by omer on 1/21/18.
//

#ifndef RENDERER_CAMERA_H
#define RENDERER_CAMERA_H

#include "Vector.h"
#include "Ray.h"
#include <math.h>

class Camera {
public:
    Camera(double width, double aspectRatio, Vector &position, Vector &direction, double filedOfView);
    Ray generateRay(double x, double y) const;
    void setDirection(Vector &direction);
    void setPosition(Vector &position);
    friend ostream &operator <<(ostream &out, const Camera &camera);
private:
    double width;
    double height;
    double aspectRatio;
    Vector position;
    Vector direction;
    double centerPos;
    Vector rightAxis;
    Vector upAxis;
};


#endif //RENDERER_CAMERA_H
