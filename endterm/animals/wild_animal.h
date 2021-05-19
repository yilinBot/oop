#ifndef WILD_ANIMAL_H_INCLUDED
#define WILD_ANIMAL_H_INCLUDED

#include <iostream>
#include "animal.h"

class WildAnimal : public Animal {

public:
    WildAnimal(std::string name) : Animal(name) {}
};

#endif // WILD_ANIMAL_H_INCLUDED
