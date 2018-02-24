//
// Created by omer on 1/20/18.
//

#ifndef RENDERER_VECTOR_H
#define RENDERER_VECTOR_H

#include <math.h>
#include <iostream>

using namespace std;

class Vector {
public:
    Vector();
    Vector(double x, double y, double z);

    double getx() const ;
    double gety() const ;
    double getz() const ;

    Vector operator +(const Vector &other) const ;
    Vector operator -(const Vector &other) const ;
    Vector operator *(double factor) const ;
    friend Vector operator *(double factor, const Vector &vector);
    double magnitude() const ;
    Vector normalize() const ;
    Vector negative() const ;
    double dotProduct(Vector &other) const ;
    Vector crossProduct(Vector &other) const ;
    bool operator ==(const Vector &other) const ;
    friend ostream &operator <<(ostream &out, const Vector &vector);
private:
    double x;
    double y;
    double z;
};

#endif //RENDERER_VECTOR_H
