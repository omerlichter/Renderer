//
// Created by omer on 2/14/18.
//

#include "PointLight.h"

PointLight::PointLight(double intensity, Vector &position, Color &diffuseColor,
                       Color &specularColor) {
    this->position = position;
    this->diffuseColor = diffuseColor;
    this->specularColor = specularColor;
    this->intensity = intensity;
}

double PointLight::getIntensityAt(Vector &point) {
    return (this->intensity / pow((point - this->position).magnitude(), 2));
}

Vector PointLight::getDirectionAt(Vector &point) {
    return (point - this->position).normalize();
}

Color PointLight::getDiffuseColor() {
    return this->diffuseColor;
}

Color PointLight::getSpecularColor() {
    return this->specularColor;
}