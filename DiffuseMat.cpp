//
// Created by omer on 2/8/18.
//

#include "DiffuseMat.h"

DiffuseMat::DiffuseMat(Color &diffuseColor) {
    this->diffuseColor = diffuseColor;
}

Color DiffuseMat::getDiffuseColorAt(Vector &position) {
    return this->diffuseColor;
}

Color DiffuseMat::getSpecularColorAt(Vector &position) {
    return Color(0, 0, 0);
}

double DiffuseMat::getSpecularHardnessAt(Vector &position) {
    return 1;
}