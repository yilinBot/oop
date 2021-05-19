#ifndef CAT_H_INCLUDED
#define CAT_H_INCLUDED

#include <iostream>
#include "pet.h"

class Cat : public Pet {

public:
    Cat(std::string name) : Pet(name) {}
    void makeSound() override {
        std::cout << name << " the cat meows!" << std::endl;
    }
};

#endif // CAT_H_INCLUDED
