#include "enor.h"

using namespace std;

Enor::Enor(const string &str)
{
    _x.open(str.c_str());
    if(_x.fail()) throw FILEERROR;
}

void Enor::next()
{
    if( !(_end = (abnorm==_sx) )){
/*
    _end = (abnorm==_sx);
    if (!end) {
*/
        _cur.number = _dx;
        _cur.count = 0;
        for( ; norm==_sx && _dx==_cur.number ; read() ){
            ++_cur.count;
        }
    }
}

void Enor::read()
{
    _sx = (_x >> _dx) ? norm : abnorm;
/*
    _x >> _dx;
    if ( _x.fail() ) _sx = abnorm;
    else _sx= norm;
*/
}
