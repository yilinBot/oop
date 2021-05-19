#pragma once
#include "department.h"

class Store
{
    public:
        Store(const std::string &fname, const std::string &tname);

        Department* _technical;
        Department* _foods;
};
