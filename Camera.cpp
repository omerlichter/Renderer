//
// Created by omer on 1/21/18.
//

#include "Camera.h"

Camera::Camera(double width, double aspectRatio, Vector &position, Vector &direction, double filedOfView) {
    this->width = width;
    this->aspectRatio = aspectRatio;
    this->height = (1 / aspectRatio) * width;
    this->centerPos = (0.5 * width) / tan(filedOfView * M_PI / 180);
    this->position = position;
    this->direction = direction.normalize();

    // set right axis and up axis
    Vector worldUpAxis(0, 1, 0);
    this->rightAxis = this->direction.crossProduct(worldUpAxis).negative().normalize();
    this->upAxis = this->direction.crossProduct(this->rightAxis).normalize();
}

void Camera::setDirection(Vector &direction) {
    this->direction = direction.normalize();
    // set right axis and up axis
    Vector worldUpAxis(0, 1, 0);
    this->rightAxis = this->direction.crossProduct(worldUpAxis).negative().normalize();
    this->upAxis = this->direction.crossProduct(this->rightAxis).normalize();
}

void Camera::setPosition(Vector &position) {
    this->position = position;
}

Ray Camera::generateRay(double x, double y) const {
    // calculate the origin of the ray
    Vector rayOrigin = this->position + (this->direction.negative() * this->centerPos);
    // calculate the point on the camera
    Vector leftBottomCameraPoint = (this->upAxis.negative() * (this->height / 2))
                                + (this->rightAxis.negative() * (this->width / 2));
    Vector cameraPoint = leftBottomCameraPoint + (this->rightAxis * x * this->width)
                         + (this->upAxis * y * this->height);
    Vector rayDirection = cameraPoint - rayOrigin;
    return Ray(rayOrigin, rayDirection);
}

ostream &operator <<(ostream &out, const Camera &camera) {
    out << endl;
    out << "------Camera------" << endl;
    out << "width: " << camera.width << " aspect_ratio: " << camera.aspectRatio << endl;
    out << "position: " << camera.position << " direction: " << camera.direction << endl;
    out << "right_axis: " << camera.rightAxis << " up_axis: " << camera.upAxis << endl;
    out << "center_pos: " << camera.centerPos << endl;
    out << endl;
    return out;
}