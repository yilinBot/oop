#pragma once

#include <string>
#include <time.h>
#include <stdlib.h>

class PetrolStation;

enum Erors { WRONG_PUMP_IDENTITY };
class Car
{
public:
    Car(const std::string &str) : _name(str) { srand(time(NULL)); }
    std::string getName() const { return _name; }

    void refuel(PetrolStation* p, unsigned int i, int l);
private:
    std::string _name;

    int chooseCash(PetrolStation* p) const;
};
