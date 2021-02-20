#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "point.h"

class Circle {

private:
    Point center;
    double r;

public:
    Circle(Point center1, double r1);
    double dist(Point p);
    double area();
    bool inside(Point p);
    double getR() { return r; }
    void setR(double r1) { r = r1; }
    double getX() { return center.getX(); }
    double getY() { return center.getY(); }
    void setX(double x1) { center.setX(x1); }
    void setY(double y1) { center.setY(y1); }
};

#endif // CIRCLE_H_INCLUDED
