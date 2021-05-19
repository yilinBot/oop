#pragma once
#include <vector>
#include "parcella.h"

class Kert
{
    protected:
        std::vector<Parcella*> _parcellak;
    public:
        Kert(int n){
            _parcellak.resize(n);
            for(int i = 0; i<n; ++i) _parcellak[i] = new Parcella(i);
        }

        Parcella* getParcella(int i) const {
            if(i>=0 && i<(int)_parcellak.size()) return _parcellak[i];
            else return nullptr;
        }
        int getDarabParcella() const { return _parcellak.size(); }
};
