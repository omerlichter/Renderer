//
// Created by omer on 1/19/18.
//

#include "Renderer.h"
#include "pixel.h"

#define WIDTH 1920;
#define HEIGHT 1080;

void Renderer::render(Scene &scene) {
    int width = WIDTH;
    int height = HEIGHT;
    int size = width * height;
    Pixel *pixels = new Pixel[size];

    // start rendering
    this->notifyAll(START_RENDERING);

    Camera main_camera = scene.getCamera();
    cout << main_camera;


    for (int i = 0; i < height; i++) {
        int line = i * width;
        for (int j = 0; j < width; j++) {
            int pixelNum = line + j;

            // generate pixel from camera
            Ray ray = main_camera.generateRay(j * (1 / (double) width),
                                              i * (1 / (double) height));

            Color pixelColor = this->calculatePixelColor(scene, ray);

            pixels[pixelNum].r = Pixel::Clamp(pixelColor.getRed());
            pixels[pixelNum].g = Pixel::Clamp(pixelColor.getGreen());
            pixels[pixelNum].b = Pixel::Clamp(pixelColor.getBlue());
            pixels[pixelNum].a = Pixel::Clamp(pixelColor.getAlpha());
        }
    }

    // end rendering
    this->notifyAll(END_RENDERING);

    // write b,p file of the finale render
    this->notifyAll(WRITE_BMP);
    WriteBMP writeBMP;
    writeBMP.write("test.bmp", width, height, pixels);
}

Color Renderer::calculatePixelColor(Scene &scene, Ray &ray) {
    Color pixelColor;
    Vector intersectionPoint;
    Object *object;
    if (scene.getIntersectionPoint(ray, intersectionPoint, object)) {
        //this->notifyAll(OBJECT_INTERSECTION);
        Material &objectMaterial = object->getMaterial();
        Vector normal = object->getNormalAt(intersectionPoint);
        Vector lightDirection = scene.getDirectionalLight().getDirection();
        Vector negLightDirection = lightDirection.negative();

        // calculate light angle for diffuse
        double lightAngle = normal.dotProduct(negLightDirection);

        // calculate specular value
        Vector doubledNormalDot = 2 * (lightAngle * normal);
        Vector reflectionDirection = lightDirection + doubledNormalDot;
        double specularValue = ray.getDirection().negative().dotProduct(reflectionDirection);
        if (specularValue > 0) {
            specularValue = pow(specularValue, objectMaterial.getSpecularHardnessAt(intersectionPoint));
        } else {
            specularValue = 0;
        }

        // calculate pixel color
        pixelColor = (objectMaterial.getDiffuseColorAt(intersectionPoint) * lightAngle *
                scene.getDirectionalLight().getDiffuseColor()) +
                (objectMaterial.getSpecularColorAt(intersectionPoint) * specularValue *
                 scene.getDirectionalLight().getSpecularColor());
    }
    else {
        pixelColor = Color(0, 0, 0, 1);
    }
    return pixelColor;
}