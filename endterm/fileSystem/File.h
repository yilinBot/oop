#ifndef FILE_H
#define FILE_H

#include "Entry.h"
#include <iostream>

class File : public Entry
{
    public:
        File(const std::string &name,unsigned int size):Entry(name),_size(size) { }
        unsigned int getSize() const override { return _size; }
        Entry* searchFor(const std::string &entryName) override;
        std::string getVec() const override { return " nothing"; }

    private:
        unsigned int _size;
};

#endif // FILE_H
