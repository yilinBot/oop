#include "plant.h"

Potatoe* Potatoe::_instance = nullptr;
Potatoe* Potatoe::instance()
{
    if(nullptr==_instance) _instance = new Potatoe();
    return _instance;
}

Pea* Pea::_instance = nullptr;
Pea* Pea::instance()
{
    if(nullptr==_instance) _instance = new Pea();
    return _instance;
}

Onion* Onion::_instance = nullptr;
Onion* Onion::instance()
{
    if(nullptr==_instance) _instance = new Onion();
    return _instance;
}

Rose* Rose::_instance = nullptr;
Rose* Rose::instance()
{
    if(nullptr==_instance) _instance = new Rose();
    return _instance;
}

Carnation* Carnation::_instance = nullptr;
Carnation* Carnation::instance()
{
    if(nullptr==_instance) _instance = new Carnation();
    return _instance;
}

Tulip* Tulip::_instance = nullptr;
Tulip* Tulip::instance()
{
    if(nullptr==_instance) _instance = new Tulip();
    return _instance;
}
