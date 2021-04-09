#include "enor.h"

Enor::Enor(const std::string &str)
{
    _x.open(str);
    if(_x.fail()) throw FILEERROR;
}

void Enor::next()
{
    if ( !(_end = (abnorm==_sx)) ){
        std::string name = _dx.name;
        _curr = false;
        for( ; norm==_sx && _dx.name==name; read() ){
            _curr = _curr || ("rabbit"==_dx.kind);
        }
    }
}

void Enor::read()
{
    _x >> _dx.name >> _dx.kind >> _dx.weight;
    _sx = _x.fail() ? abnorm : norm;
}
