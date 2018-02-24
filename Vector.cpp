//
// Created by omer on 1/20/18.
//

#include "Vector.h"

Vector::Vector() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector::Vector(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector Vector::operator+(const Vector &other) const {
    return Vector(this->x + other.x, this->y + other.y, this->z + other.z);
}

Vector Vector::operator-(const Vector &other) const {
    return Vector(this->x - other.x, this->y - other.y, this->z - other.z);
}

Vector Vector::operator*(double factor) const {
    return Vector(factor * this->x, factor * this->y, factor * this->z);
}

Vector operator *(double factor, const Vector &vector) {
    return Vector(factor * vector.x, factor * vector.y, factor * vector.z);
}

double Vector::magnitude() const {
    return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

Vector Vector::normalize() const {
    double magnitude = this->magnitude();
    return Vector(this->x / magnitude, this->y / magnitude, this->z / magnitude);
}

Vector Vector::negative() const {
    return Vector(-1 * this->x, -1 * this->y, -1 * this->z);
}

double Vector::dotProduct(Vector &other) const {
    return (this->x * other.x + this->y * other.y + this->z * other.z);
}

Vector Vector::crossProduct(Vector &other) const {
    return Vector(this->y * other.z - this->z * other.y,
                  this->z * other.x - this->x * other.z,
                  this->x * other.y - this->y * other.x);
}

double Vector::getx() const {
    return this->x;
}

double Vector::gety() const {
    return this->y;
}

double Vector::getz() const {
    return this->z;
}

bool Vector::operator==(const Vector &other) const {
    return ((other.x == this->x) && (other.y == this->y) && (other.z == this->z));
}

ostream &operator <<(ostream &out, const Vector &vector) {
    out << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
    return out;
}