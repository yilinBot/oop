#include "car.h"

#include "petrol.h"
#include "pump.h"
#include "cash.h"

#include <iostream>
#include <sstream>


void Car::refuel(PetrolStation* ps, unsigned int i, int l)
{
    std::ostringstream os1; os1 << _name << " starts to fuel\n"; std::cout << os1.str();

    Pump *pump = ps->getPump(i);
    if( nullptr==pump ) throw WRONG_PUMP_IDENTITY;

    pump->fill(l);
    std::ostringstream os2; os2 << _name << " is fueling " << l << " liter petrol\n"; std::cout << os2.str();

    int c = chooseCash(ps);
    int n = ps->getCash(c)->pay(i);
    std::ostringstream os3; os3 << _name << " has paid: " << n << " Ft" << std::endl; std::cout << os3.str();

}

int Car::chooseCash(PetrolStation* ps) const
{
    return rand()%ps->getCashNumber();
}
