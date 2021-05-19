#ifndef LION_H_INCLUDED
#define LION_H_INCLUDED

#include <iostream>
#include "wild_animal.h"

class Lion : public WildAnimal {

public:
    Lion(std::string name) : WildAnimal(name) {}
    void makeSound() override {
        std::cout << name << " the lion roars!" << std::endl;
    }
};

#endif // LION_H_INCLUDED
