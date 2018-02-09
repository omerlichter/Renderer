#include <iostream>
#include "Renderer.h"
#include "RenderLog.h"
#include "Sphere.h"
#include "DiffuseMat.h"
#include "DiffuseSpecularMat.h"
#include "Plane.h"
#include "TextureMat.h"
#include "CheckersTexture.h"

using namespace std;

int main() {
    Renderer renderer;
    RenderLog renderLog;
    renderer.addListener(renderLog);

    // create camera
    Vector cameraPos(0, 0.5, 0);
    Vector cameraDir(0, 0, 1);
    Camera camera(1, 1.777, cameraPos, cameraDir, 30);

    // create light
    Vector lightDirection(1, -1, 1);
    Color diffuseColor(1, 1, 1);
    Color specularColor(1, 1, 1);
    DirectionalLight directionalLight(lightDirection, diffuseColor, specularColor);

    // create vector of objects
    vector<Object*> objectsList;
    // add sphere1
    // sphere1 material
    Color sphere1ColorDiffuse(0.2, 1, 0.2);
    Color sphere1ColorSpecular(1, 1, 1);
    Material *sphere1Material = new DiffuseSpecularMat(sphere1ColorDiffuse, sphere1ColorSpecular, 30);
    Object *sphere1 = new Sphere(0, 0.5, 2, 0.5, *sphere1Material);
    objectsList.push_back(sphere1);
    // add sphere2
    // sphere2 material
    Color sphere2Color(1, 0, 0);
    Material *sphere2Material = new DiffuseMat(sphere2Color);
    Object *sphere2 = new Sphere(0.5, 0.5, 3, 0.5, *sphere2Material);
    objectsList.push_back(sphere2);
    // add plane
    Texture *texture = new CheckersTexture();
    Material *planeMaterial = new TextureMat(*texture);
    //Material *planeMaterial = new DiffuseMat(planeColorDiffuse);
    Object *plane = new Plane(0, 1, 0, 0, *planeMaterial);
    objectsList.push_back(plane);

    // create scene
    Scene scene(camera, directionalLight, objectsList);
    // render scene
    renderer.render(scene);


    delete(sphere1);
    delete(sphere1Material);
    delete(sphere2);
    delete(sphere2Material);
    return 0;
}