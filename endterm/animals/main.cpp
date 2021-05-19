#include <iostream>
#include <vector>

#include "cat.h"
#include "dog.h"
#include "hamster.h"
#include "lion.h"
#include "wolf.h"

using namespace std;

int main()
{
    vector<Animal*> animals;
    animals.push_back(new Wolf("White"));
    animals.push_back(new Lion("Simba"));
    animals.push_back(new Wolf("Red"));
    animals.push_back(new Hamster("Quick"));
    animals.push_back(new Dog("Happy"));
    animals.push_back(new Cat("Grumpy"));
    for (auto animal : animals) {
        animal->makeSound();
    }
    return 0;
}
