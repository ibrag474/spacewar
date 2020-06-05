#include "object.h"

Object::Object(int x, int y) {
    coordX = x;
    coordY = y;
}

void Object::setCoords(int x, int y) {
    coordX = x;
    coordY = y;
}

void Object::setX(int x) {
    coordX = x;
}

void Object::setY(int y) {
    coordY = y;
}

int Object::getX() {
    return coordX;
}

int Object::getY() {
    return coordY;
}
