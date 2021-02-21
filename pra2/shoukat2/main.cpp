#include <iostream>
#include <fstream>
#include <vector>
#include "point.h"
#include "circle.h"

using namespace std; 

bool search(const Circle& cir, const vector<Point>& t, unsigned int& ind);

int main(){
    ifstream f("input.txt");
    if(f.fail()) 
    cout << "Wrong file name!\n";

    double a, b, c; 
    f >> a >> b >> c; 
    Circle cir(Point(a, b), c);
    /*
        Point p = Point(a, b);
        Circle cir(p, c);
    */

    vector<Point> t; 
    while (f >> a >> b) {
        t.push_back(Point(a, b));
    }

    unsigned int ind; 
    if(search(cir, t, ind)) {
        cout << "( " << t[ind]._x << " , " << t[ind]._y << " ) is in the circle.\n";
        //cout << "( " << t[ind].getX() << " , " << t[ind].getY() << " ) is in the circle.\n";
    }else {
        cout << "None of them is in the circle.\n";
    }

    return 0; 
}

bool search (const Circle& cir, const vector<Point>& t, unsigned int& ind) {
    //unsigened int when we are sure that the number is 0 or positive
    bool l = false; 
    for (unsigned int i = 0; !l && i<t.size(); ++i) {
        l = cir.in(t[i]);
        ind = i; 
    }
    return l; 

    /*
        for(ind = 0; ind < t.size(); ++ind) {
            if( cir.in(t[i]) ) return true; 
        }
        return false; 
    */
}
