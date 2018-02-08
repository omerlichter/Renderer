//
// Created by omer on 2/8/18.
//

#include "DiffuseSpecularMat.h"

DiffuseSpecularMat::DiffuseSpecularMat(Color &diffuseColor, Color &specularColor, double specularHardness) {
    this->diffuseColor = diffuseColor;
    this->specularColor = specularColor;
    this->specularHardness = specularHardness;
}

Color DiffuseSpecularMat::getDiffuseColorAt(Vector &position) {
    return this->diffuseColor;
}

Color DiffuseSpecularMat::getSpecularColorAt(Vector &position) {
    return this->specularColor;
}

double DiffuseSpecularMat::getSpecularHardnessAt(Vector &position) {
    return this->specularHardness;
}