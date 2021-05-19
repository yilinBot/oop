#pragma once
#include "parcel.h"
#include <vector>

class Garden
{
    protected:
        std::vector<Parcel*> _parcels;
    public:
        Garden(int n);
        Parcel* getParcel(int i) const ;
        void plant(int id, Plant* plant, int date){
            getParcel(id)->plant(plant, date);
        }
        std::vector<int> canHarvest(int date);
};
