//Készítette:   Mészáros Áron Attila
//E-mail:       meszaros.aron.attila@gmail.com
//Dátum:        2018.03.02.

// Translated by Balazs Pinter

#include <iostream>
#include <cstdlib>
#include "outfile.h"

OutFile::OutFile(const std::string& filename)
{
    f.open(filename.c_str());
    if(f.fail()){
        throw FILEERROR;
    }
}

void OutFile::write(const Cactus &dx)
{
    f << dx.name << std::endl;
}

