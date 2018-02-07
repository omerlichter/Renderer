//
// Created by omer on 2/7/18.
//

#ifndef RENDERER_COLOR_H
#define RENDERER_COLOR_H


class Color {
public:
    Color(double r = 0, double g = 0, double b = 0, double a = 0);
    double getRed() const;
    double getGreen() const;
    double getBlue() const;
    double getAlpha() const;
    Color operator +(const Color &color) const;
    Color operator -(const Color &color) const;
    Color operator *(const Color &color) const;
    Color operator *(double value) const;
    friend Color operator *(double value, const Color &color);
private:
    double r;
    double g;
    double b;
    double a;
};

#endif //RENDERER_COLOR_H
