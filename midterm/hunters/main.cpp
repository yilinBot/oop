#include <iostream>
#include "enor.h"

using namespace std;

int main()
{
    Enor t("inp.txt");
    bool l = true;
    for( t.first(); l && !t.end(); t.next() ){
        l = t.current();
    }
    if(l) cout << "Everyone has shot a rabbit.\n";
    else  cout << "Not everyone has shot a rabbit.\n";
    return 0;
}
