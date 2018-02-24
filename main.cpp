#include <iostream>
#include "Renderer.h"
#include "RenderLog.h"
#include "Sphere.h"
#include "DiffuseMat.h"
#include "DiffuseSpecularMat.h"
#include "Plane.h"
#include "CheckersTexture.h"
#include "PointLight.h"
#include "FullMat.h"
#include "TintTexture.h"

using namespace std;

int main() {
    Renderer renderer;
    RenderLog renderLog;
    renderer.addListener(renderLog);

    // create camera
    Vector cameraPos(0, 2, -5);
    Vector cameraDir(0, -0.25, 1);
    Camera camera(1, 1.777, cameraPos, cameraDir, 30);

    // create ambient color
    Color ambientColor(0.05, 0.05, 0.05);

    // create vector of lights
    vector<Light*> lightsList;
    // create directional light
    Vector light1Direction(3, -3, 1);
    Color light1DiffuseColor(1, 1, 1);
    Color light1SpecularColor(1, 1, 1);
    Light *directionalLight1 = new DirectionalLight(0.5, light1Direction,
                                                    light1DiffuseColor, light1SpecularColor);

    lightsList.push_back(directionalLight1);

    // create directional light
    Vector light2Position(-1, 2, 3);
    Color light2DiffuseColor(1, 1, 1);
    Color light2SpecularColor(1, 1, 1);
    Light *directionalLight2 = new PointLight(1, light2Position,
                                                    light2DiffuseColor, light2SpecularColor);

    lightsList.push_back(directionalLight2);

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
    Color sphere2DiffuseColor(0, 0, 0);
    Texture *sphere2DiffuseTex = new TintTexture(sphere2DiffuseColor);
    Color sphere2SpecularColor(1, 1, 1);
    Texture *sphere2SpeculareTex = new TintTexture(sphere2SpecularColor);
    Color sphere2reflectionColor(1, 1, 1);
    Texture *sphere2reflectionTex = new TintTexture(sphere2reflectionColor);

    Material *sphere2Material = new FullMat(*sphere2DiffuseTex, *sphere2SpeculareTex,
                                            30, *sphere2reflectionTex);
    Object *sphere2 = new Sphere(0.5, 1, 4, 1, *sphere2Material);
    objectsList.push_back(sphere2);
    Object *sphere3 = new Sphere(-1.5, 0.5, 3, 0.5, *sphere2Material);
    objectsList.push_back(sphere3);
    // add plane
    Texture *diffuseTex = new CheckersTexture();
    Color specularColor(1, 1, 1);
    Texture *specularTex = new TintTexture(specularColor);
    Color reflectionValue(0.3, 0.3, 0.3);
    Texture *reflectionTex = new TintTexture(reflectionValue);
    Material *planeMaterial = new FullMat(*diffuseTex, *specularTex, 30, *reflectionTex);
    //Material *planeMaterial = new DiffuseMat(planeColorDiffuse);
    Object *plane = new Plane(0, 1, 0, 0, *planeMaterial);
    objectsList.push_back(plane);

    // add sphere4
    // sphere4 material
    Color sphere4DiffuseColor(1, 0, 0);
    Material *material = new DiffuseMat(sphere4DiffuseColor);
    Object *sphere4 = new Sphere(-1, 0.5, 0, 0.5, *material);
    objectsList.push_back(sphere4);

    // create scene
    Scene scene(camera, ambientColor, lightsList, objectsList);
    // render scene
    renderer.render(scene);


    delete(sphere1);
    delete(sphere1Material);
    delete(sphere2);
    delete(sphere2Material);
    return 0;
}