//Készítette:   Mészáros Áron Attila
//E-mail:       meszaros.aron.attila@gmail.com
//Dátum:        2018.03.02.

// Translated by Balazs Pinter

#ifndef _KAKTUSZ_ENOR_H_
#define _KAKTUSZ_ENOR_H_

#include <fstream>
#include "cactus.h"


class CactusEnor{
public:
    enum Status{abnorm,norm};
    enum Exceptions{FILEERROR};

    CactusEnor(std::string filename = "");
    void first() {next();}
    void next();
    Cactus current() const { return dx;}
    bool end() const {return sx==abnorm;}
private:
    Cactus dx;
    Status sx;
    std::ifstream f;
};

#endif // _KAKTUSZ_ENOR_H_
