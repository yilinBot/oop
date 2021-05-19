#include <iostream>
#include <sstream>
#include "petrol.h"
#include "car.h"

using namespace std;

int main()
{
    PetrolStation p;
    Car* a = new Car("red car");
    a->refuel(&p, 3, 25);

    return 0;
}
