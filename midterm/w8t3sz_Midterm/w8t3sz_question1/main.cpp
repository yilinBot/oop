#include <iostream>
#include "enor.h"

using namespace std;
bool emptyFile(const string &fileName);

int main()
{
    cout << "----find the one who finished most of the laps in less than 90 seconds----" << endl;

    string fileName = "inp.txt";

    try
    {
        if(emptyFile(fileName))
        {
            cout << "Empty file!\n";
            return 1;
        }


        //Maximum search
        People elem;
        One t(fileName);

        t.first();
        int maxp = t.current().less90;
        elem.competitor = t.current().competitor;
        elem.circuit = t.current().circuit;

        t.next();

        while(!t.end())
        {
            if(t.current().less90 > maxp)
            {
                maxp = t.current().less90;
                elem.competitor = t.current().competitor;
                elem.circuit = t.current().circuit;
                t.next();
            }
            else
            {
                t.next();
            }
        }

        cout << "The competitor " << elem.competitor << " in " << elem.circuit <<
        " circuit has " << maxp << " laps finished in less than 90 seconds." << endl;

    }
    catch (One::Error exp)
    {
        cout << "Wrong file name !\n";
        return 2;
    }

    return 0;
}

bool emptyFile(const string &fileName)
{
    One t(fileName);
    t.first();
    if (t.end())
    {
        return true;
    }
    return false;
}
