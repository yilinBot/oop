#include "garden.h"

Garden::Garden(int n)
{
    _parcels.resize(n);
    for(int i = 0; i<n; ++i) _parcels[i] = new Parcel(i);
}

Parcel* Garden::getParcel(int i) const
{
    if(i>=0 && i<(int)_parcels.size()) return _parcels[i];
    else return nullptr;
}

std::vector<int> Garden::canHarvest(int date)
{
    std::vector<int> result;
    for(Parcel* p : _parcels){
        if( nullptr!=p->getPlant()
            &&  date - p->getplantingDate() == p->getPlant()->getRipeningTime() )
                result.push_back(p->getId());
    }
    return result;
}
