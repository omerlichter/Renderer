//
// Created by omer on 2/7/18.
//

#include "Color.h"

Color::Color(double r, double g, double b, double a) : r(r), g(g), b(b), a(a){
}

double Color::getRed() const {
    return this->r;
}

double Color::getGreen() const {
    return this->g;
}

double Color::getBlue() const {
    return this->b;
}

double Color::getAlpha() const {
    return this->a;
}

Color Color::operator+(const Color &color) const {
    return Color(this->r + color.r, this->g + color.g, this->b + color.b, this->a + color.a);
}

void Color::operator+=(const Color &color) {
    this->r += color.r;
    this->g += color.g;
    this->b += color.b;
    this->a += color.a;
}

Color Color::operator-(const Color &color) const {
    return Color(this->r - color.r, this->g - color.g, this->b - color.b, this->a - color.a);
}

Color Color::operator*(const Color &color) const {
    return Color(this->r * color.r, this->g * color.g, this->b * color.b, this->a * color.a);
}

Color Color::operator*(double value) const {
    return Color(this->r * value, this->g * value, this->b * value, this->a * value);
}

double Color::grayScale() {
    return ((this->r + this->g + this->b) / 3);

}

Color operator*(double value, const Color &color) {
    return Color(color.r * value, color.g * value, color.b * value, color.a * value);
}