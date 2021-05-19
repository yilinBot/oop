#ifndef SYSTEM_H
#define SYSTEM_H

#include "Entry.h"

class System
{
public:
    System(const std::string &name,const std::string &type="FAT32"): _name(name),_type(type) {}
    System(const std::string &name,const std::string &type,const std::vector<Entry*> &entries);
    void addEntry(Entry* entry);
    unsigned int getSize() const;
    Entry* searchFor(const std::string &entryName) const;

    std::string getName() const { return _name; }
    std::string getType() const { return _type; }
    int getVecSize() const { return _sysEntries.size(); }


private:
    std::string _name;
    std::string _type;
    std::vector<Entry*> _sysEntries;
};

#endif // SYSTEM_H
