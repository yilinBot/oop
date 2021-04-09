#pragma once

#include <fstream>

struct Statistic {
    int number;
    int count;
};

enum Status { abnorm, norm };

class Enor
{
    public:
        enum Errors { FILEERROR };

        Enor(const std::string &str);
        void first() { read(); next(); }
        void next();
        Statistic current() const { return _cur; }
        bool end() const { return _end; }
    private:
        std::ifstream _x;
        int _dx;
        Status _sx;
        Statistic _cur;
        bool _end;

        void read();
};
