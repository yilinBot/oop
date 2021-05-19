#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED

#include <iostream>

class Animal {

protected:
    std::string name;

public:
    Animal(std::string name): name(name) {}
    virtual void makeSound() = 0;
};

#endif // ANIMAL_H_INCLUDED
