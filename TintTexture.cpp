//
// Created by omer on 2/14/18.
//

#include "TintTexture.h"

TintTexture::TintTexture(Color &color) {
    this->color = color;
}

Color TintTexture::getColorAt(double x, double y) {
    return this->color;
}