//
// Created by omer on 1/19/18.
//

#ifndef RENDERER_PIXEL_H
#define RENDERER_PIXEL_H

typedef struct {
    double r;
    double g;
    double b;
    double a;

    static double Clamp(double value) {
        if (value < 0) {
            value = 0;
        } else if (value > 1) {
            value = 1;
        }
        return value;
    }
} Pixel;
#endif //RENDERER_PIXEL_H
