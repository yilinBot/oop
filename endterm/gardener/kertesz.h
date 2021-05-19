#pragma once
#include "kert.h"

class Kertesz
{
    public:
        Kertesz(Kert* k) :  _kert(k) {}
        void ultet(int azon, Noveny* noveny, int datum);
        void arat(int maiDatum);

        Kert* _kert;
};
