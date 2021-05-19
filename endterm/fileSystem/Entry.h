#pragma once
#include <vector>
#include <string>

class Entry
{
    public:
        Entry(const std::string &name): _name(name) { }
        virtual unsigned int getSize() const = 0;
        std::string getName() const { return _name; }
        virtual Entry* searchFor(const std::string &entryName) { return nullptr; };
        virtual std::string getVec() const {return "";}

    protected:
        std::string _name;
};
