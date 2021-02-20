#include "point.h"

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(double x1, double y1) {
    x = x1;
    y = y1;
}

double Point::getX() {
    return x;
}

double Point::getY() {
    return y;
}

void Point::setX(double a) {
    x = a;
}

void Point::setY(double b) {
    y = b;
}
