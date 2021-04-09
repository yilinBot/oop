#ifndef ENOR_H_INCLUDED
#define ENOR_H_INCLUDED

//competitor ; circuit ; time

//accept level
/*
which competitor of which circuit has finished most of the laps
in less than 90 s.
*/
//HAM Eifel 92410 92165 92543 92153 88971

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

struct Times
{
    int lapTime;

    friend std::istream& operator >> (std::istream& is, Times& t);
};

struct People
{
    std::string competitor;
    std::string circuit;

    int less90;

    friend std::istream& operator >> (std::istream& is, People& p);
};

enum Status {norm, abnorm };

class One
{
public:
    enum Error {FILEERROR};
    One(const std::string& fileName);
    ~One(){_x.close();}
    void first(){read();}
    void next(){read(); }
    People current() const {return _dx; }

    bool end() const{return _sx==abnorm; }

private:
    std::ifstream _x;
    People _dx;
    Status _sx;

    void read();
};


#endif // ENOR_H_INCLUDED
