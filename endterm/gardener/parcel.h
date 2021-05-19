#pragma once
#include "plant.h"

class Parcel
{
    protected:
        int _id;
        Plant* _plant;
        int _plantingDate;
    public:
        Parcel(int id): _id(id), _plant(nullptr), _plantingDate(0) {}
        void plant(Plant* plant, int date) { _plant = plant; _plantingDate = date; }
        int getId() const { return _id; }
        Plant* getPlant() const { return _plant; }
        int getplantingDate() const { return _plantingDate; }
};
