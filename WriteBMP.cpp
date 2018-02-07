//
// Created by omer on 1/19/18.
//

#include "WriteBMP.h"

void WriteBMP::write(const char *fileName, int w, int h, Pixel *data) const {
    FILE *file;
    int k = w * h;
    int size = k * 4;
    int fileSize = size + 54;

    unsigned char bmpFileHeader[14] = {'B','M', 0,0,0,0, 0,0,0,0, 54,0,0,0};
    unsigned char bmpInfoHeader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0,32,0};

    bmpFileHeader[2] = (unsigned char) (fileSize);
    bmpFileHeader[3] = (unsigned char) (fileSize >> 8);
    bmpFileHeader[4] = (unsigned char) (fileSize >> 16);
    bmpFileHeader[5] = (unsigned char) (fileSize >> 24);

    bmpInfoHeader[4] = (unsigned char) (w);
    bmpInfoHeader[5] = (unsigned char) (w >> 8);
    bmpInfoHeader[6] = (unsigned char) (w >> 16);
    bmpInfoHeader[7] = (unsigned char) (w >> 24);

    bmpInfoHeader[8] = (unsigned char) (h);
    bmpInfoHeader[9] = (unsigned char) (h >> 8);
    bmpInfoHeader[10] = (unsigned char) (h >> 16);
    bmpInfoHeader[11] = (unsigned char) (h >> 24);

    bmpInfoHeader[20] = (unsigned char) (size);
    bmpInfoHeader[21] = (unsigned char) (size >> 8);
    bmpInfoHeader[22] = (unsigned char) (size >> 16);
    bmpInfoHeader[23] = (unsigned char) (size >> 24);

    file = fopen(fileName, "wb");
    fwrite(bmpFileHeader, 1, 14, file);
    fwrite(bmpInfoHeader, 1, 40, file);

    for (int i = 0; i < k; i++) {
        Pixel pixel = data[i];

        double red = pixel.r * 255;
        double green = pixel.g * 255;
        double blue = pixel.b * 255;
        double alpha = pixel.a * 255;

        unsigned char color[4] = {(unsigned char) blue, (unsigned char) green, (unsigned char) red, (unsigned) alpha};

        fwrite(color, 1, 4, file);
    }
    fclose(file);
}