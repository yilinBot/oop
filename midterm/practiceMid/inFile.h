#ifndef INFILE_H_INCLUDED
#define INFILE_H_INCLUDED

#include <fstream>
#include <vector>
#include <sstream> //read in the string/ string inside another string
#include <iostream>

struct Measurement
{
    std::string date;
    int weight;
    int distance;

    friend std::istream& operator >> (std::istream& is, Measurement& m);
    // it means we read information from 'is' file, to 'm' Measurement .
    /*
    CX896 NASA  1984.03.12 6000 3000 2003.11.23 8500 2500
    */
};

struct Station
{
    std::string name; //black hole name
    std::string station; //station name

    int lastWeight;

    bool close; //in one line, whether it has the distance smaller than 2700

    friend std::istream& operator >> (std::istream& is, Station& s);

};

struct BlackHole
{
    std::string name;
    double avgofWeights;
    bool allClose;
};

enum Status
{
    norm; //not end
    abnorm; //end
};

class inFileMax
{
private:
    std::ifstream _x; // read the file, and file name is _x
    Station _dx;
    Status _sx;

    void read();

public:
    enum Error {FILEERROR};

    inFileMax(const std::string& filename); //constructor

    ~inFileMax() {_x.close();} //destructor

    void first() {read();}

    void next() {read(); }

    Station current() const {return _dx; }

    bool end() const {return _sx == abnorm; }
};

class inFile
{
private:
    std::ifstream _x;
    Station _dx;
    Status _sx;
    bool _end;
    BlackHole _cur;

    void read();

public:
    enum Error {FILEERROR};

    inFile(const std::string& fileName); //constructor
    ~inFile() { _x.close(); } //destructor

    void first () {read(); next(); }

    void next();

    BlackHole current() const {return _cur; }

    bool end() const { return _end; }

};



#endif // INFILE_H_INCLUDED
