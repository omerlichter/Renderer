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
        int line = i * width;
        for (int j = 0; j < width; j++) {
            int pixelNum = line + j;

            // generate pixel from camera
            Ray ray = main_camera.generateRay(j * (1 / (double) width),
                                              i * (1 / (double) height));

            Color pixelColor = this->calculatePixelColor(scene, ray, 8);

            pixels[pixelNum].r = Pixel::Clamp(pixelColor.getRed());
            pixels[pixelNum].g = Pixel::Clamp(pixelColor.getGreen());
            pixels[pixelNum].b = Pixel::Clamp(pixelColor.getBlue());
            if (pixelColor.getAlpha() > 0) {
                pixels[pixelNum].a = 1;
            } else {
                pixels[pixelNum].a = 0;
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

Color Renderer::calculatePixelColor(Scene &scene, Ray &ray, int reflectionDeep) {
    Color pixelColor;
    Vector intersectionPoint;
    Object *object;
    if (scene.getIntersectionPoint(ray, intersectionPoint, object)) {

        Material &objectMaterial = object->getMaterial();
        Mapping &objectMapping = object->getMapping();
        Vector intersectionMapping = objectMapping.getMapCoordinates(intersectionPoint);
        Vector normal = object->getNormalAt(intersectionPoint);
        Vector rayDirection = ray.getDirection();
        Vector negRayDirection = rayDirection.negative();
        vector<Light*> &lightsList = scene.getLightsList();

        pixelColor += scene.getAmbientColor() * objectMaterial.getDiffuseColorAt(intersectionMapping);

        for (vector<Light*>::iterator it = lightsList.begin(); it != lightsList.end(); it++) {
            Light *light = *it;
            Vector lightDirection = light->getDirectionAt(intersectionPoint);
            Vector negLightDirection = lightDirection.negative();

            // shadow light
            bool isShadowed = false;
            Vector shadowRayOrigin = intersectionPoint + (negLightDirection * 0.0001);
            Ray shadowRay(shadowRayOrigin, negLightDirection);
            Vector shadowRayIntersection;
            Object *shadowRayIntersectionObject;
            // ------- if is shadowed ----------
            if (scene.getIntersectionPoint(shadowRay, shadowRayIntersection, shadowRayIntersectionObject)) {
                isShadowed = true;
            }

            // ------- if is not shadowed ---------
            if (isShadowed == false) {
                // calculate diffuse
                double lightAngle = normal.dotProduct(negLightDirection);
                pixelColor += objectMaterial.getDiffuseColorAt(intersectionMapping) *
                                          lightAngle * light->getDiffuseColor() *
                                          light->getIntensityAt(intersectionPoint);

                // calculate specular
                Vector doubledNormalDot = 2 * (lightAngle * normal);
                Vector specularDirection = lightDirection + doubledNormalDot;
                double specularValue = negRayDirection.dotProduct(specularDirection);
                if (specularValue > 0) {
                    specularValue = pow(specularValue,
                                        objectMaterial.getSpecularHardnessAt(intersectionMapping));
                } else {
                    specularValue = 0;
                }
                pixelColor += objectMaterial.getSpecularColorAt(intersectionMapping) *
                                          specularValue * light->getSpecularColor() *
                                          light->getIntensityAt(intersectionPoint);
            }
        }

        // calculate reflection
        double reflectionValue = objectMaterial.getReflectionValueAt(intersectionMapping);
        Color reflectionColor(0, 0, 0);
        if (reflectionDeep > 0 && reflectionValue > 0) {
            double rayNormalDot = normal.dotProduct(negRayDirection);
            Vector reflectionNormalDistance = 2 * ((normal * rayNormalDot) + rayDirection);
            Vector reflectionDirection = (negRayDirection + reflectionNormalDistance).normalize();
            Vector reflectionOrigin = intersectionPoint + (reflectionDirection * 0.0001);
            Ray reflectionRay(reflectionOrigin, reflectionDirection);
            reflectionColor = this->calculatePixelColor(scene, reflectionRay, reflectionDeep - 1);
            pixelColor += reflectionValue * reflectionColor;
        }
    }
    else {
        pixelColor = Color(0, 0, 0, 0);
    }
    return pixelColor;
}