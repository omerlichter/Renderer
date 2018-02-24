//
// Created by omer on 1/25/18.
//

#ifndef RENDERER_SCENE_H
#define RENDERER_SCENE_H

#include <vector>
#include "Camera.h"
#include "Object.h"
#include "DirectionalLight.h"

class Scene {
public:
    Scene(Camera &camera, Color &ambientColor, vector<Light*> &lights, vector<Object*> &objects);
    Camera &getCamera() const ;
    Color &getAmbientColor() const ;
    vector<Light*> &getLightsList() const ;
    vector<Object*> &getObjectsList() const ;

    bool getIntersectionPoint(Ray &ray, Vector &intersectionPoint, Object *&intersectionObject) const ;
private:
    Camera &camera;
    Color &ambientColor;
    vector<Light *> &lightsList;
    vector<Object*> &objectsList;
};


#endif //RENDERER_SCENE_H
