//
// Created by omer on 1/25/18.
//

#include "Scene.h"

Scene::Scene(Camera &camera, vector<Object*> &objects) : camera(camera), objectsList(objects) {

}

Camera& Scene::getCamera() const {
    return this->camera;
}

vector<Object*>& Scene::getObjectsList() const {
    return this->objectsList;
}

bool Scene::getIntersectionPoint(Ray &ray, Vector &intersectionPoint) const {
    double distance = INFINITY;
    Vector point;
    bool isIntersect = false;
    vector<Object*>::iterator it;
    for (it = this->objectsList.begin(); it != this->objectsList.end(); it++) {
        RayCastHit hit;
        Object *object = *it;
        if (object->getIntersection(ray, hit)) {
            if (hit.getDistance() < distance) {
                isIntersect = true;
                distance = hit.getDistance();
                point = hit.getIntesectionPoint();
            }
        }
    }
    if (isIntersect) {
        intersectionPoint = point;
        return true;
    }
    return false;
}