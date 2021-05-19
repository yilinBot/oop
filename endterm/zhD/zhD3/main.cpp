#include <iostream>
#include "library/seqinfileenumerator.hpp"
#include "library/summation.hpp"
#include "library/stringstreamenumerator.hpp"
#include "library/linsearch.hpp"

using namespace std;

struct Contest
{
    string name;
    int rank;
    friend istream &operator>>(istream &is, Contest &c)
    {
        is >> c.name >> c.rank;
        return is;
    }
};

struct SumResult
{
    int bestRank;
    bool highJump;
    int noOfSilver;
    SumResult() {}
    SumResult(int bR,bool hJ, int nOS) : bestRank(bR), highJump(hJ), noOfSilver(nOS) {}
};

class ReadContestant : public Summation<Contest,SumResult>
{
    SumResult func(const Contest& e) const override {
        return SumResult(e.rank, e.name=="highjump", (e.rank==2) ? 1 : 0);
    }
    SumResult neutral() const override { return SumResult(999, false, 0); }
    SumResult add( const SumResult& a, const SumResult& b) const override {
        return SumResult((a.bestRank < b.bestRank) ? a.bestRank : b.bestRank,
                         a.highJump || b.highJump,
                         a.noOfSilver + b.noOfSilver);
    }
};

struct Contestant
{
    string name;
    string school;
    int bestRank;
    bool highJump;
    int noOfSilver;
    friend istream &operator>>(istream &is, Contestant &c)
    {
        string line;
        getline (is,line,'\n');
        stringstream ss(line);
        ss>>c.name>>c.school;
        StringStreamEnumerator<Contest> ssenor(ss);
        ReadContestant pr;
        pr.addEnumerator(&ssenor);
        pr.run();
        c.bestRank=pr.result().bestRank;
        c.highJump=pr.result().highJump;
        c.noOfSilver=pr.result().noOfSilver;
        return is;
    }
};

class MySearch : public LinSearch<Contestant,false>
{
    bool cond(const Contestant& e) const override { return e.highJump && e.bestRank == 2;}
};

int main()
{
    try
    {
        cout << "Student in highjump with silver as best:\n\n";
        SeqInFileEnumerator<Contestant> enor("input.txt");
        MySearch pr;
        pr.addEnumerator(&enor);
        pr.run();
        if (pr.found()) {
                cout << pr.elem().name << " from " << pr.elem().school << " with " << pr.elem().noOfSilver << " silvers.\n";
        }
    }
    catch (SeqInFileEnumerator<Contestant>::Exceptions err)
    {
        cerr<<"File not found!\n";
        return 1;
    }
    return 0;
}
