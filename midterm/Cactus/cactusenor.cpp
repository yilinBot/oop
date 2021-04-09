//Készítette:       Mészáros Áron Attila
//E-mail            meszaros.aron.attila@gmail.com
//Dátum:            2018.02.28.

// Translated by Balazs Pinter

#include <cstdlib>
#include <sstream>
#include "cactusenor.h"

CactusEnor::CactusEnor(std::string filename){
    f.open(filename.c_str());
    if(f.fail()){
        throw FILEERROR;
    }
}

void CactusEnor::next(){
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
}
