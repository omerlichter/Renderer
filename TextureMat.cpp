//
// Created by omer on 2/9/18.
//

#include "TextureMat.h"

TextureMat::TextureMat(Texture &diffuseTexture) : diffuseTexture(diffuseTexture) {

}

Color TextureMat::getDiffuseColorAt(Vector &position) {
    return this->diffuseTexture.getColorAt(position.getx(), position.getz());
}

Color TextureMat::getSpecularColorAt(Vector &position) {
    return Color(0, 0, 0);
}

double TextureMat::getSpecularHardnessAt(Vector &position) {
    return 1;
}