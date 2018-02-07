//
// Created by omer on 2/7/18.
//

#include "DirectionalLight.h"

DirectionalLight::DirectionalLight(Vector &direction, Color &color) {
    this->direction = direction.normalize();
    this->color = color;
}

Vector& DirectionalLight::getDirection() {
    return this->direction;
}

Color& DirectionalLight::getColor() {
    return this->color;
}