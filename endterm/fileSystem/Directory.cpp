#include "Directory.h"
#include <iostream>

unsigned int Directory::getSize() const
{
    unsigned int sum = 0;
    for (Entry* entry : _dirEntries)
    {
        sum += entry->getSize();
    }
    return sum;
}

Entry* Directory::searchFor(const std::string &entryName)
{
    std::cout<<"looking into " << _name << "..." << std::endl;
    if (entryName == _name)
        return this;
    for (Entry* entry : _dirEntries)
    {
        Entry* found = entry->searchFor(entryName);
        if (found != nullptr)
            return found;
    }
    return nullptr;
}

std::string Directory::getVec() const
{
    std::string s="\n";
    for(Entry* e : _dirEntries)
    {
        s += e->getName()+"\n";
    }
    return s;
}
