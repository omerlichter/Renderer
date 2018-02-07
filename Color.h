//
// Created by omer on 2/7/18.
//

#ifndef RENDERER_COLOR_H
#define RENDERER_COLOR_H


typedef struct Color {
    Color(double r = 0, double g = 0, double b = 0) {
        this->r = r;
        this->g = g;
        this->b = b;
    }
    double r;
    double g;
    double b;
} Color;


#endif //RENDERER_COLOR_H
