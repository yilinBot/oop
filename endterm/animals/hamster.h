#ifndef HAMSTER_H_INCLUDED
#define HAMSTER_H_INCLUDED

#include <iostream>
#include "pet.h"

class Hamster: public Pet {

public:
    Hamster(std::string name) : Pet(name) {}
    void makeSound() override {
        std::cout << name << " the hamster squeaks!" << std::endl;
    }
};

#endif // HAMSTER_H_INCLUDED
