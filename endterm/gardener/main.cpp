#include <iostream>
#include "gardener.h"
#include "plant.h"

using namespace std;

int main()
{
    Garden* garden = new Garden(5);
    Gardener* gardener = new Gardener(garden);

    gardener->_garden->plant(1, Potatoe::instance(), 3);
    gardener->_garden->plant(2, Pea::instance(), 3);
    gardener->_garden->plant(4, Pea::instance(), 3);

    cout << "The identifiers of harvestable parcels: ";
    for( int i : gardener->_garden->canHarvest(6)){
        cout << i << " ";
    }
    cout << endl;

    delete garden;
    delete gardener;

    return 0;
}
