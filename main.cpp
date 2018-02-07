#include <iostream>
#include "Renderer.h"
#include "RenderLog.h"
#include "Sphere.h"

using namespace std;

int main() {
    Renderer renderer;
    RenderLog renderLog;
    renderer.addListener(renderLog);

    // create camera
    Vector cameraPos(0 ,0 ,0);
    Vector cameraDir(0, 0, 1);
    Camera camera(2, 1.777, cameraPos, cameraDir, 20);

    // create vector of objects
    vector<Object*> objectsList;
    // add sphere
    Object *sphere1 = new Sphere(0, 0, 2, 0.5);
    objectsList.push_back(sphere1);
    Object *sphere2 = new Sphere(0.5, 0, 1, 0.5);
    objectsList.push_back(sphere2);

    Scene scene(camera, objectsList);
    renderer.render(scene);
    return 0;
}