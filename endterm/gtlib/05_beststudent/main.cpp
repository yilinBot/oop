#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "../library/seqinfileenumerator.hpp"
#include "../library/stringstreamenumerator.hpp"
#include "../library/maxsearch.hpp"
#include "../library/summation.hpp"

using namespace std;

struct Student
{
    string name;
    double avr;

    friend istream& operator>>(istream& inp, Student &s);
};

class BestStudent : public MaxSearch<Student, double>
{
protected:
    double func(const Student &e) const override { return e.avr; }
};

int main(int argc, char* argv[])
{
    string inputfile_name = (argc==1)? "input.txt" : argv[1];

    BestStudent pr;
    SeqInFileEnumerator<Student> enor("input.txt");
    pr.addEnumerator(&enor);

    pr.run();

    if(pr.found()){
        cout.setf(ios::fixed);
        cout << "The best student is " << pr.optElem().name << " with average: " << pr.opt() << endl;
    }else cout << "Empty file!\n";
    return 0;
}

struct Result
{
    double sum;
    int count;
    Result(){}
    Result(double s, int c): sum(s), count(c) {}
};

class Average : public Summation<int, Result>
{
protected:
    Result func(const int &e) const override { return Result(e,1);}
    Result neutral() const override { return Result(0.0, 0);}
    Result add(const Result& a, const Result& b) const override {
        return Result(a.sum+b.sum, a.count+b.count);
    }
};

istream& operator>>(istream& inp, Student &s)
{
    string line;
    getline(inp, line);
    stringstream is(line);
    is >> s.name;

    Average pr;
    StringStreamEnumerator<int> enor(is);
    pr.addEnumerator(&enor);

    pr.run();

    s.avr = pr.result().sum / pr.result().count;

    return inp;
}
