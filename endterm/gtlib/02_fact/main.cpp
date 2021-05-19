#include <iostream>
#include <cmath>
#include "../library/summation.hpp"
#include "../library/intervalenumerator.hpp"

using namespace std;

class Factorial : public Summation<int>
{
protected:
    int neutral() const override { return 1; }
    int add(const int &a, const int &b) const override { return a * b; }
    int func(const int &e) const override { return e;}
};

int main(int argc, char* argv[])
{
    int n;
    cout << "Natural number: ";
    cin >> n;
    Factorial pr;
    IntervalEnumerator enor(2, n);
    pr.addEnumerator(&enor);

    pr.run();

    cout << "Factorial: " << pr.result() << endl;

    return 0;
}
