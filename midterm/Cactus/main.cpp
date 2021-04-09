//Készítette:       Mészáros Áron Attila
//E-mail            meszaros.aron.attila@gmail.com
//Dátum:            2018.02.28.
//Feladat:          Feladatgyûjtemény 7. feladat: Egy  szekvenciális  inputfájlban  egyes
//                  kaktuszfajtákról  ismerünk  néhány  adatot:  név,őshaza,  virágszín,  méret.
//                  Válogassuk  ki  egy  szekvenciális  outputfájlba  a  mexikói,  egy másikba a piros virágú kaktuszokat!
//File egy sora pl.:
//nev2 oshaza2 piros 5

// Problem: In a sequential input file, we have data about some cacti: name, country of origin, color of the flower, size
// Put all the Mexican cacti into a sequential output file and all the red cacti into another sequential output file.
// One line of the file: name country color size

// Translated by Balazs Pinter

#include <iostream>
#include "cactus.h"
#include "cactusenor.h"
#include "outfile.h"
#include "infile.h"

void MexicanRedEnor(const std::string&);
void MexicanAndRedEnor(const std::string&);
void MexicanRedFile(const std::string&);

int main()
{
    //MexicanRedEnor("inp.txt");
    MexicanAndRedEnor("inp.txt");
    //MexicanRedFile("inp.txt");
    return 0;
}

void MexicanRedFile(const std::string& inputFile){
    InFile input(inputFile);
    OutFile mexicoFile("mexico.txt");
    OutFile redFile("red.txt");

    Cactus dx;
    InFile::Status sx;
    while(input.read(dx,sx)){
        if(dx.country == "Mexico"){
            mexicoFile.write(dx);
        }
        if(dx.color == "red"){
            redFile.write(dx);
        }
    }
}

void MexicanRedEnor(const std::string& inputFile){
    CactusEnor x(inputFile);
    OutFile mexicoFile("mexico.txt");
    OutFile redFile("red.txt");

    Cactus dx;
    x.first();
    while(!x.end()){
        dx = x.current();
        if(dx.country == "Mexico"){
            mexicoFile.write(dx);
        }
        if(dx.color == "red"){
            redFile.write(dx);
        }
        x.next();
    }
}

void MexicanAndRedEnor(const std::string& inputFile){
    CactusEnor x(inputFile);
    OutFile mexicoFile("mexico.txt");
    OutFile redFile("red.txt");
    OutFile mexicoRedFile("mexicored.txt");

    Cactus dx;
    x.first();
    while(!x.end()){
        dx = x.current();
        if(dx.country == "Mexico"){
            mexicoFile.write(dx);
        }
        if(dx.color == "red"){
            redFile.write(dx);
        }
        if(dx.color == "red" && dx.country == "Mexico"){
            mexicoRedFile.write(dx);
        }
        x.next();
    }
}


