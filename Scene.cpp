//
// Created by omer on 1/25/18.
//

#include "Scene.h"

Scene::Scene(Camera &camera, Color &ambientColor, vector<Light*> &lights, vector<Object*> &objects) :
        camera(camera), ambientColor(ambientColor), lightsList(lights), objectsList(objects) {

}

Camera& Scene::getCamera() const {
    return this->camera;
}

Color& Scene::getAmbientColor() const {
    return this->ambientColor;
}

vector<Light*>& Scene::getLightsList() const {
    return this->lightsList;
}

vector<Object*>& Scene::getObjectsList() const {
    return this->objectsList;
}

bool Scene::getIntersectionPoint(Ray &ray, Vector &intersectionPoint, Object *&intersectionObject) const {
    double distance = INFINITY;
    Vector point;
    bool isIntersect = false;
    Object *intersectionObj = NULL;
    vector<Object*>::iterator it;
    for (it = this->objectsList.begin(); it != this->objectsList.end(); it++) {
        RayCastHit hit;
        Object *object = *it;
        if (object->getIntersection(ray, hit)) {
            if (hit.getDistance() < distance) {
                isIntersect = true;
                distance = hit.getDistance();
                point = hit.getIntersectionPoint();
                intersectionObj = object;
            }
        }
    }
    if (isIntersect) {
        intersectionPoint = point;
        intersectionObject = intersectionObj;
        return true;
    }
    return false;
}