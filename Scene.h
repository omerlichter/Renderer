//
// Created by omer on 1/25/18.
//

#ifndef RENDERER_SCENE_H
#define RENDERER_SCENE_H

#include <vector>
#include "Camera.h"
#include "Object.h"

class Scene {
public:
    Scene(Camera &camera, vector<Object*> &objects);
    Camera &getCamera() const ;
    vector<Object*>& getObjectsList() const ;

    bool getIntersectionPoint(Ray &ray, Vector &intersectionPoint) const ;
private:
    Camera &camera;
    vector<Object*> &objectsList;
};


#endif //RENDERER_SCENE_H
