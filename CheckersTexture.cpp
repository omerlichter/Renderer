//
// Created by omer on 2/9/18.
//

#include <math.h>
#include "CheckersTexture.h"

CheckersTexture::CheckersTexture() {
    this->cellSize = 1;
    this->color1 = Color(0, 0, 0);
    this->color2 = Color(1, 1, 1);
}

CheckersTexture::CheckersTexture(double cellSize) {
    this->cellSize = cellSize;
    this->color1 = Color(0, 0, 0);
    this->color2 = Color(1, 1, 1);
}

CheckersTexture::CheckersTexture(double cellSize, Color &color1, Color &color2) {
    this->cellSize = cellSize;
    this->color1 = color1;
    this->color2 = color2;
}

Color CheckersTexture::getColorAt(double x, double y) {
    int valueX = (int)(fabs(x) * this->cellSize + 0.5);
    int valueY = (int)(fabs(y) * this->cellSize + 0.5);
    if ((valueX % 2 == 0 && valueY % 2 == 0) ||
            (valueX % 2 != 0 && valueY % 2 != 0)) {
        return this->color1;
    }
    return this->color2;
}