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
    Vector cameraPos(0, 1, 0.5);
    Vector cameraDir(0, -0.5, 1);
    Camera camera(1, 1.777, cameraPos, cameraDir, 30);

    // create light
    Vector lightDirection(1, -1, 1);
    Color color(1, 1, 1);
    DirectionalLight directionalLight(lightDirection, color);

    // create vector of objects
    vector<Object*> objectsList;
    // add sphere1
    Color sphere1Color(1, 0, 0.5);
    Object *sphere1 = new Sphere(0, 0, 2, 0.5, sphere1Color);
    objectsList.push_back(sphere1);
    // add sphere2
    Color sphere2Color(0, 1, 0);
    Object *sphere2 = new Sphere(0.5, 0, 3, 0.5, sphere2Color);
    objectsList.push_back(sphere2);

    Scene scene(camera, directionalLight, objectsList);
    renderer.render(scene);
    return 0;
}