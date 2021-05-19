#include "File.h"

Entry* File::searchFor(const std::string &entryName)
{
    std::cout << _name << " is checked\n";
    if (entryName == _name)
        return this;
    else
        return nullptr;
}
