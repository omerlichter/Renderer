//
// Created by omer on 1/19/18.
//

#ifndef RENDERER_WRITEBMP_H
#define RENDERER_WRITEBMP_H

#include "pixel.h"
#include <iostream>
#include <string>
#include "pixel.h"

using namespace std;

class WriteBMP {
public:
    void write(const char *fileName, int w, int h, Pixel *data) const;
};


#endif //RENDERER_WRITEBMP_H
