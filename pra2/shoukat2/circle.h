#pragma once 
//specifies that the compiler includes the header file only once, 
//this reduces build time while compiling 

#include "point.h"

class Circle {
    private:
        Point _c; 
        //center of the circle x and y coordinate
        double _r; 
    
    //default constructor   
    public: 
        Circle(){}
        Circle(const Point& p, double d) : _c(p), _r(d) {}
        bool in(const Point& p) const {
            return _c.distance(p) <= _r; 
        }
};