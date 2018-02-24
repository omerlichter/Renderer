//
// Created by omer on 2/7/18.
//

#include "DirectionalLight.h"

DirectionalLight::DirectionalLight(double intensity,
         Vector &direction, Color &diffuseColor, Color &specularColor) {
    this->direction = direction.normalize();
    this->diffuseColor = diffuseColor;
    this->specularColor = specularColor;
    this->intensity = intensity;
}

Color DirectionalLight::getDiffuseColor() {
    return this->diffuseColor;
}

Color DirectionalLight::getSpecularColor() {
    return this->specularColor;
}

Vector DirectionalLight::getDirectionAt(Vector &point) {
    return this->direction;
}

double DirectionalLight::getIntensityAt(Vector &point) {
    return this->intensity;
}