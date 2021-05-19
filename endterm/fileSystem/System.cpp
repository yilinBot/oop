#include "System.h"
#include <iostream>

System::System(const std::string &name,const std::string &type,const std::vector<Entry*> &entries): _name(name),_type(type)
{
    for (Entry* entry : entries)
        if (entry!=nullptr)
            _sysEntries.push_back(entry);
}
void System::addEntry(Entry* entry)
{
    if (entry!=nullptr)
        _sysEntries.push_back(entry);
}
unsigned int System::getSize() const
{
    unsigned int sum = 0;
    for (Entry* entry : _sysEntries)
    {
        sum += entry->getSize();
    }
    return sum;
}
Entry* System::searchFor(const std::string &entryName) const
{
    for (Entry* entry : _sysEntries)
    {
        Entry* found = entry->searchFor(entryName);
        if (found != nullptr) return found;
    }
    return nullptr;
}
