#ifndef DOG_H_INCLUDED
#define DOG_H_INCLUDED

#include <iostream>
#include "pet.h"

class Dog : public Pet {

public:
    Dog(std::string name) : Pet(name) {}
    void makeSound() override {
        std::cout << name << " the dog barks!" << std::endl;
    }
};

#endif // DOG_H_INCLUDED
