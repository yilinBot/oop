#include <cmath>
#include "circle.h"

Circle::Circle(Point center1, double r1) {
    center = center1;
    r = r1;
}

double Circle::dist(Point p) {
    return sqrt((center.getX() - p.getX())*(center.getX() - p.getX())
               +(center.getY() - p.getY())*(center.getY() - p.getY()));
}

double Circle::area() {
    return r*r*3.1415;
}

bool Circle::inside(Point p) {
    return dist(p) < r;
}
