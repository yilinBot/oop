#pragma once
#include "noveny.h"

class Parcella
{
    protected:
        int _azon;
        Noveny* _noveny;
        int _ultetesiDatum;
    public:
        Parcella(int azon): _azon(azon), _noveny(nullptr), _ultetesiDatum(0) {}
        void ultet(Noveny* noveny, int datum) { _noveny = noveny; _ultetesiDatum = datum; }
        int getAzon() const { return _azon; }
        Noveny* getNoveny() const { return _noveny; }
        int getUltetesiDatum() const { return _ultetesiDatum; }
};
