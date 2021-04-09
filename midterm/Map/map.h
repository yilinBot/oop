#ifndef PRIORSOR_H_INCLUDED
#define PRIORSOR_H_INCLUDED
#include <string>
#include <iostream>
#include <vector>
#include "read.hpp"

///function for controlled data reading
///To avoid multiple declaration, it is inline.
inline bool valid(int a){return true;}

struct Item
{
    ///public attributes
    int key;
    std::string data;

    ///constructors
    Item() {};
    Item(int key,std::string data)
    {
        this->key = key;
        this->data = data;
    }

    friend std::istream& operator>>(std::istream& s, Item& e)
    {
        e.key=read<int>("Key: ","Integer is needed!",valid);
        std::cout<<"Data: ";
        s>>e.data;
        return s;
    }
    friend std::ostream& operator<<(std::ostream& s, const Item& e)
    {
        s<<"key: "<<e.key<<" data: "<<e.data<<" ";
        return s;
    }

    ///for testing
    bool operator==(const Item& b)
    {
        return (key==b.key && data==b.data);
    }
};

class Map
{
    public:
        enum MapError{MISSING_KEY,EXISTING_KEY};

        ///Map(); //Not needed
        ///~Map() {} //Not needed
        int count() const;
        void insert(Item a);
        void erase(int key) throw (MapError);
        bool isIn(int key) const;
        std::string &operator[](int key)  throw (MapError);
        bool isEmpty() const {return _vec.size()==0;}

        ///Methods for testing
        friend std::ostream& operator<<(std::ostream& s, const Map& m); ///print a line
        unsigned int getLength() const {return _vec.size();}
        unsigned int getCapacity() const {return _vec.capacity();}
        std::vector<Item> getItems() const;
        std::pair<bool,int> getLogSearch(int key) const {return logSearch(key);}

    private:
        std::vector<Item> _vec; ///array implemented as a vector

        std::pair<bool,int> logSearch(int key) const;

};


#endif // PRIORSOR_H_INCLUDED
