// Készítette:   Mészáros Áron Attila
// E-mail:       meszaros.aron.attila@gmail.com
// Dátum:        2018.03.02.
// File egy sora pl.:
// nev2 oshaza2 piros 5

// Translated by Balazs Pinter

#ifndef _INFILE_KAKTUSZ_H_
#define _INFILE_KAKTUSZ_H_

#include "cactus.h"
#include <fstream>
#include <string>


class InFile{
public:
    enum Status {abnorm,norm};
    enum Exceptions{FILEERROR};

    InFile(std::string filename = "");
    bool read(Cactus &dx, Status &sx);
private:
    std::ifstream f;
};

#endif // _INFILE_KAKTUSZ_H_
