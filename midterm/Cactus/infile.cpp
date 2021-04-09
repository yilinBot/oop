//Készítette:   Mészáros Áron Attila
//E-mail:       meszaros.aron.attila@gmail.com
//Dátum:        2018.03.02.

// Translated by Balazs Pinter

#include "infile.h"
#include <iostream>
#include <cstdlib>
#include <sstream>

InFile::InFile(std::string filename){
    f.open(filename.c_str());
    if(f.fail()){
        throw FILEERROR;
    }
}

bool InFile::read(Cactus &dx, Status &sx){
    std::string line;
    getline(f, line);
    if (!f.fail() && line != "") {
        sx = norm;
        std::stringstream ss(line);
        ss >> dx.name;
        ss >> dx.country;
        ss >> dx.color;
        ss >> dx.size;
    }
    else {
        sx = abnorm;
    }

    return norm==sx;
}
