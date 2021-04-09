#include "enor.h"

std::istream& operator >> (std::istream& is, Times& t)
{
    is >> t.lapTime;
    return is;
}

std::istream& operator >> (std::istream& is, People& p)
{
    std::string line;
    getline(is, line, '\n');
    std::stringstream ss(line);

    ss>>p.competitor>>p.circuit;

    p.less90 = 0;

    Times t;

    while(ss>>t)
    {
        if(t.lapTime < 90000)
        {
            p.less90++;
        }
    }

    return is;
}

One::One(const std::string& fileName)
{
    _x.open(fileName.c_str());
    if(_x.fail()) throw FILEERROR;
}

void One::read()
{
    _sx = (_x >> _dx) ? norm : abnorm;
}

