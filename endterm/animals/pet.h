#ifndef PET_H_INCLUDED
#define PET_H_INCLUDED

#include <iostream>
#include "animal.h"

class Pet : public Animal {

public:
    Pet(std::string name) : Animal(name) {}
};

#endif // PET_H_INCLUDED
