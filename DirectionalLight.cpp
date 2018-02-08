//
// Created by omer on 2/7/18.
//

#include "DirectionalLight.h"

DirectionalLight::DirectionalLight(Vector &direction, Color &diffuseColor, Color &specularColor) {
    this->direction = direction.normalize();
    this->diffuseColor = diffuseColor;
    this->specularColor = specularColor;
}

Vector& DirectionalLight::getDirection() {
    return this->direction;
}

Color& DirectionalLight::getDiffuseColor() {
    return this->diffuseColor;
}

Color& DirectionalLight::getSpecularColor() {
    return this->specularColor;
}