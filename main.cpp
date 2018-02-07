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
    Vector cameraPos(0, 0, 0);
    Vector cameraDir(0, 0, 1);
    Camera camera(1, 1.777, cameraPos, cameraDir, 30);

    // create light
    Vector lightDirection(1, -1, 1);
    Color color(1, 1, 1);
    DirectionalLight directionalLight(lightDirection, color);

    // create vector of objects
    vector<Object*> objectsList;
    // add sphere
    Object *sphere1 = new Sphere(0, 0, 2, 0.5);
    objectsList.push_back(sphere1);

    Scene scene(camera, directionalLight, objectsList);
    renderer.render(scene);
    return 0;
}