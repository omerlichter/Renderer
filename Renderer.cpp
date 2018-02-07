//
// Created by omer on 1/19/18.
//

#include "Renderer.h"

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
        int line  = i * width;
        for (int j = 0; j < width; j++) {
            int pixelNum = line + j;

            // generate pixel from camera
            Ray ray = main_camera.generateRay(j * (1 / (double)width),
                                              i * (1 / (double)height));

            Vector intersectionPoint;
            if (scene.getIntersectionPoint(ray, intersectionPoint)) {
                pixels[pixelNum].r = 0.2; //* (1 - (intersectionPoint.getz() * intersectionPoint.getz()));
                pixels[pixelNum].g = 0.2; //* (1 - (intersectionPoint.getz() * intersectionPoint.getz()));
                pixels[pixelNum].b = 0.2; //* (1 - (intersectionPoint.getz() * intersectionPoint.getz()));
            } else {
                pixels[pixelNum].r = 0;
                pixels[pixelNum].g = 0;
                pixels[pixelNum].b = 0;
            }
        }
    }

    // end rendering
    this->notifyAll(END_RENDERING);

    // write b,p file of the finale render
    this->notifyAll(WRITE_BMP);
    WriteBMP writeBMP;
    writeBMP.write("test.bmp", width, height, pixels);
}

Pixel Renderer::calculatePixelColor() const {

}