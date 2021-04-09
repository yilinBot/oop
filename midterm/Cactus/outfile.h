//Készítette:   Mészáros Áron Attila
//E-mail:       meszaros.aron.attila@gmail.com
//Dátum:        2018.03.02.

// Translated by Balazs Pinter

#ifndef _OUTFILE_KAKTUSZ_H_
#define _OUTFILE_KAKTUSZ_H_

#include "cactus.h"
#include <fstream>
#include <string>

class OutFile{
public:
    enum Exceptions{FILEERROR};

    OutFile(const std::string& filename);
    void write(const Cactus &dx);
private:
    std::ofstream f;
};


#endif // _OUTFILE_KAKTUSZ_H_
