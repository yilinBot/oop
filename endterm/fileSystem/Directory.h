#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "Entry.h"

class Directory : public Entry
{
    public:
        Directory(const std::string &name):Entry(name) { }
        void addEntry(Entry* entry) {if (entry!=nullptr) _dirEntries.push_back(entry); }
        unsigned int getSize() const override;
        Entry* searchFor(const std::string &entryName) override;
        std::string getVec() const override;

    private:
        std::vector<Entry*> _dirEntries;
};

#endif // DIRECTORY_H
