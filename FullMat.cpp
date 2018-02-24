//
// Created by omer on 2/14/18.
//

#include "FullMat.h"

FullMat::FullMat(Texture &diffuse, Texture &specular, double specularHardness, Texture &reflection) :
    diffuseTexture(diffuse), specularTexture(specular), specularHardness(specularHardness),
    reflectionTexture(reflection) {

}

Color FullMat::getDiffuseColorAt(Vector &position) {
    return this->diffuseTexture.getColorAt(position.getx(), position.getz());
}

Color FullMat::getSpecularColorAt(Vector &position) {
    return this->specularTexture.getColorAt(position.getx(), position.getz());
}

double FullMat::getSpecularHardnessAt(Vector &position) {
    return this->specularHardness;
}

double FullMat::getReflectionValueAt(Vector &position) {
    return this->reflectionTexture.getColorAt(position.getx(), position.getz()).grayScale();
}