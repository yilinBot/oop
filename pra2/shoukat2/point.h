#pragma once 
#include <cmath>

//a class is a user defined data-type which has data members and member functions. 
/*
    private: members can't be accessed (or viewed) from outside the class.
    protected: memebers can't be accessed from outside the class. 
                However, they can be accessed in inherited classes. 
    public: members are accessible from outside the class. 
*/

class Point {
    public: 
        double _x, _y; 
    
    /*
    private: 
  	double _x, _y; 
    */
    
    //constructor
    //a constructor is a member funtion of a class which initializes objects of a class
    public: 
        Point(double a = 0, double b = 0) : _x(a), _y(b) {}
        double distance(const Point& p) const {
            return sqrt(pow(_x-p._x, 2) + pow(_y-p._y, 2));
        }
        
        /*
        	getters and setters 
        	double getX(){return _x;}
        	double getY(){return _y;}
        */
};
