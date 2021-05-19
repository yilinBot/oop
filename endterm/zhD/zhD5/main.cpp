#include <iostream>
#include "library/seqinfileenumerator.hpp"
#include "library/summation.hpp"
#include "library/stringstreamenumerator.hpp"
#include "library/linsearch.hpp"

using namespace std;

struct Contest
{
    string name;
    unsigned int place;
    friend istream &operator>> (istream &is, Contest &e)
    {
        is >> e.name >> e.place;
        return is;
    }
};

class HighJumpSearch : public LinSearch<Contest>
{
    bool cond(const Contest& e) const override
    {
        return e.name=="highjump";
    }
};

struct Contestant
{
    string name;
    string school;
    bool highJump;
    friend istream &operator>> (istream &is, Contestant &c)
    {
        string line;
        getline(is, line, '\n');
        stringstream ss(line);
        ss >> c.name >> c.school;
        StringStreamEnumerator<Contest> ss_enor(ss);
        HighJumpSearch pr;
        pr.addEnumerator(&ss_enor);
        pr.run();
        c.highJump = pr.found();
        return is;
    }
};

struct School
{
    string name;
    unsigned int highJumpCounter;
    unsigned int studentCounter;
    School() : name(""), highJumpCounter(0), studentCounter(0) { }
    School(const string &n, unsigned int hjc, unsigned int sc) : name(n), highJumpCounter(hjc), studentCounter(sc) { }
};

class SchoolSum : public Summation<Contestant,School>
{
public:
    SchoolSum(const string &schoolName) : _schoolName(schoolName) { }
private:
    School func(const Contestant& e) const  override
    {
        return School(e.school, e.highJump ? 1 : 0, 1);
    }
    School neutral() const override
    {
        return School();
    }
    School add( const School& a, const School& b) const  override
    {
        return School(b.name,
                      a.highJumpCounter + b.highJumpCounter,
                      a.studentCounter + b.studentCounter);
    }
    bool whileCond(const Contestant& current) const override
    {
        return current.school == _schoolName;
    }
    void first() override { }

    string _schoolName;
};

class SchoolEnumerator : public Enumerator<School>
{
private:
    SeqInFileEnumerator<Contestant>* _f;
    School _school;
    bool _end;
    bool _empty;
public:
    SchoolEnumerator(const string &fname): _empty(true)
    {
        _f = new SeqInFileEnumerator<Contestant>(fname);
    }
    ~SchoolEnumerator()
    {
        delete _f;
    }
    void first() override
    {
        _f->first();
        next();
        if (!end())
            _empty=false;
    }
    void next() override;
    School current() const override
    {
        return _school;
    }
    bool end() const override
    {
        return _end;
    }
    unsigned int getEmpty() const
    {
        return _empty;
    }
};

void SchoolEnumerator::next()
{
    if (_end = _f->end())
        return;
    _school.name = _f->current().school;
    SchoolSum pr(_school.name);
    pr.addEnumerator(_f);
    pr.run();
    _school = pr.result();
}

class Writer : public Summation<School, ostream>
{
public:
    Writer(ostream *o) : Summation<School, ostream> (o) { }
private:
    std::string func(const School& e) const override
    {
        ostringstream oss(e.name);
        oss << e.name << ", number of high jump entries: " << e.highJumpCounter << ", number of students: " << e.studentCounter << endl;
        return oss.str();
    }
    bool cond(const School& e) const override
    {
        return e.highJumpCounter > 9;
    }
};


int main()
{
    try
    {
        cout << "Schools with at least 10 high jump entries:\n\n";
        SchoolEnumerator enor("input.txt");
        Writer pr(&cout);
        pr.addEnumerator(&enor);
        pr.run();
        if (enor.getEmpty())
            cout << "There is none.\n";
    }
    catch (SeqInFileEnumerator<Contestant>::Exceptions err)
    {
        cerr<<"File not found!\n";
        return 1;
    }
    return 0;
}
