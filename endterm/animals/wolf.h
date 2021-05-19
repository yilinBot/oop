#ifndef WOLF_H_INCLUDED
#define WOLF_H_INCLUDED

#include <iostream>
#include "wild_animal.h"

class Wolf : public WildAnimal {

public:
    Wolf(std::string name) : WildAnimal(name) {}
    void makeSound() override {
        std::cout << name << " the wolf howls!" << std::endl;
    }
};

#endif // WOLF_H_INCLUDED
