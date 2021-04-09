#pragma once

#include <string>
#include <fstream>

enum Status { abnorm, norm };

struct Trophy {
    std::string name;
    std::string kind;
    int weight;
};

class Enor
{
    public:
        enum Errors { FILEERROR };
        Enor(const std::string &str);
        void first() { read(); next(); }
        void next();
        bool current() const { return _curr; }
        bool end() const { return _end; }
    private:
        std::ifstream _x;
        Trophy _dx;
        Status _sx;
        bool _curr;
        bool _end;

        void read();
};
