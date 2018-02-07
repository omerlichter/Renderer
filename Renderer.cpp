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

            Pixel pixel = this->calculatePixelColor(scene, ray);

            pixels[pixelNum].r = Pixel::Clamp(pixel.r);
            pixels[pixelNum].g = Pixel::Clamp(pixel.g);
            pixels[pixelNum].b = Pixel::Clamp(pixel.b);
        }
    }

    // end rendering
    this->notifyAll(END_RENDERING);

    // write b,p file of the finale render
    this->notifyAll(WRITE_BMP);
    WriteBMP writeBMP;
    writeBMP.write("test.bmp", width, height, pixels);
}

Pixel Renderer::calculatePixelColor(Scene &scene, Ray &ray) {
    Pixel pixel;
    Vector intersectionPoint;
    Object *object;
    if (scene.getIntersectionPoint(ray, intersectionPoint, object)) {
        //this->notifyAll(OBJECT_INTERSECTION);
        Vector normal = object->getNormalAt(intersectionPoint);
        Vector negLightDirection = scene.getDirectionalLight().getDirection().negative();

        double lightAngle = normal.dotProduct(negLightDirection);

        Color pixelColor = object->getColorAt(intersectionPoint) * lightAngle *
                scene.getDirectionalLight().getColor();

        pixel.r = pixelColor.getRed();
        pixel.g = pixelColor.getGreen();
        pixel.b = pixelColor.getBlue();
    }
    else {
        pixel.r = 0;
        pixel.g = 0;
        pixel.b = 0;
        pixel.a = 1;
    }
    return pixel;
}