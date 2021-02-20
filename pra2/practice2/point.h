#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

class Point {

private:
    double x;
    double y;

public:
    Point();
    Point(double x1, double y1);
    double getX();
    double getY();
    void setX(double a);
    void setY(double b);
};

#endif // POINT_H_INCLUDED
