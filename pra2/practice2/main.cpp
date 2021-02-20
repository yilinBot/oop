#include <iostream>
#include <vector>

#include "point.h"
#include "circle.h"

using namespace std;

int main()
{
    Point p;
    cout << "x=" << p.getX() << ", y=" << p.getY() << endl;
    Point p2(3, 4);
    cout << "x=" << p2.getX() << ", y=" << p2.getY() << endl;
    vector<Point> points;
    for (int i = 0; i < 5; ++i) {
        //Point p(0, i);
        //point.push_back(p);
        points.push_back(Point(0, i));
    }
    Circle circle(Point(0, 0), 2.1);
    int c = 0;
    for (int i = 0; i < points.size(); ++i) {
        if (circle.inside(points[i])) {
            c++;
        }
    }
    cout << c << " points were inside the circle." << endl;
    return 0;
}
