#include "kertesz.h"
#include "kert.h"
#include "parcella.h"
#include <iostream>

using namespace std;

void Kertesz::arat(int maiDatum)
{
    for(int i = 0; i < _kert->getDarabParcella(); ++i){
        if(nullptr!=_kert->getParcella(i)->getNoveny() &&
           maiDatum - _kert->getParcella(i)->getUltetesiDatum() == _kert->getParcella(i)->getNoveny()->getEresIdo() ) cout << i << " ";
    }
}

void Kertesz::ultet(int azon, Noveny* noveny, int datum)
{
    _kert->getParcella(azon)->ultet(noveny, datum);
}
