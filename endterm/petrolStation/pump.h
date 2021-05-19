#pragma once

#include "cash.h"

class Pump
{
public:
    Pump() : _quantity(0) { }

    void fill(int l) { _quantity = l; }

    int getQuantity() const { return _quantity; }


    friend Cash;

private:
    int _quantity;

    void resetQuantity() { _quantity = 0; }
};
