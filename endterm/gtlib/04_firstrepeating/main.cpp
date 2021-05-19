#include <iostream>
#include <vector>

#include "../library/seqinfileenumerator.hpp"
#include "../library/intervalenumerator.hpp"
#include "../library/linsearch.hpp"
#include "../library/summation.hpp"
#include "../library/arrayenumerator.hpp"

using namespace std;

class Copy : public Summation<int, vector<int> >
{
    int  func(const int &e) const override { return e; }
};

class InnerSearch : public LinSearch<int>
{
private:
    vector<int> _x;
    int _i;
public:
    InnerSearch(vector<int> x, int i) : _x(x), _i(i) {}
    bool cond(const int &j) const override { return _x[_i] == _x[j]; }
};

class OuterSearch : public LinSearch<int>
{
private:
    vector<int> _x;
public:
    OuterSearch(vector<int> x) : _x(x) {}
    bool cond(const int &i) const override
    {
        InnerSearch pr(_x, i);
        IntervalEnumerator enor(0, i-1);
        pr.addEnumerator(&enor);
        pr.run();
        return pr.found();
    }
};

int main(int argc, char* argv[])
{
    string inputfile_name = (argc==1)? "input.txt" : argv[1];

    // Filling the vector from a text file
    vector<int> x;
    Copy pr1;
    SeqInFileEnumerator<int> enor1(inputfile_name);
    pr1.addEnumerator(&enor1);
    pr1.run();
    x = pr1.result();

    // Finding the first repeating element of the array
    OuterSearch pr2(x);
    IntervalEnumerator enor2(1, x.size()-1);
    pr2.addEnumerator(&enor2);
    pr2.run();

    if(pr2.found())
        cout << x[pr2.elem()] << " is the first repeating element.\n";
    else
        cout << "All of the elements are different.\n";
    return 0;
}
