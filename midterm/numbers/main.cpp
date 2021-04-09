#include <iostream>

#include "enor.h"

using namespace std;

ostream& operator<<(ostream& o, const Statistic &e);

int main()
{
    Enor t("inp.txt");

    for( t.first(); !t.end(); t.next() ){
        cout << t.current(); // cout << t.current().number << " " << t.current().count << endl;
    }

    return 0;
}

// void write(ostream& o, const Statistic &e)
ostream& operator<<(ostream& o, const Statistic &e)
{
    o << e.number << " " << e.count << endl;
    return o;
}
