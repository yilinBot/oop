#include "cash.h"

#include "petrol.h"
#include "pump.h"

int Cash::pay(unsigned int i)
{
    int liter = _petrol->getPump(i)->getQuantity();
    _petrol->getPump(i)->resetQuantity();
    return liter* _petrol->getUnit();
}
