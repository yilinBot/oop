#include <iostream>
#include <fstream> 
#include <vector> 

/*
find the higest valley.
give altitude measurements in a file. 
find the highest valey. (the highest measurement 
that is lower than the measurements before and after it)
*/

using namespace std; 

bool fileRead(vector<int>& vec, const string& fileName);
bool condMaxSearch(const vector<int>& vec, int& max, int& ind);
bool condMaxSearchFromFile(const string& fileName, int& max );

int main() {
    cout << "File's name: ";
    string fileName; 
    cin >> fileName; 
    vector<int> vec; 
    if(fileRead(vec, fileName)){
        int max, ind; 
        if(condMaxSearch(vec, max, ind)) {
            cout << "highest valley is " << max << " high.\n";
        }else{ 
            cout << "there is no valley. \n";
        } 

        //it is sure the file exist
        if (condMaxSearchFromFile(fileName, max)) { 
            cout << "highest valley is " << max << " high. \n";
        } else {
            cout << "there is no valley. \n";
        }
    }else {
        cout << "Wrong file name! \n";
        return 1; 
    }
    return 0; 
}


bool fileRead(vector<int>& vec, const string& fileName) {
    fstream f(fileName);
    if (f.fail()) {
        return false; 
    }
    int e; 
    vec.clear();
    while(f >> e){   //read the integer from the file, one by one 
        vec.push_back(e); 
    }
    f.close();  //close the file 
    return true; 
} 

bool condMaxSearch(const vector<int>& x, int& max, int& ind) {
    bool l = false; 
    unsigned int n = 1; 
    for(int i=1; i<int(x.size())-1; i++) {
        if(l && x[i] <= x[i-1] && x[i] <= x[i+1]) {
            if (max <x[i]){
                max = x[i];
                ind = i; 
            }
        }
        else if (!l && x[i] <= x[i=1] && x[i] <= x[i+1]){
            l = true; 
            max = x[i];
            ind = i; 
        }
    }
    return l; 
}

bool condMaxSearchFromFile(const string& fileName, int& max) {
    fstream f(fileName);
    bool l = false; 

    int before, current, after; 
    f >> before; 
    f >> current; 
    f >> after; 

    while (!f.fail()) {
        if(l && current <= before && current <= after) {
            if(max < current) {
                max = current; 
            }
        }
        else if(!l && current <= before && current <= after) {
            l = true; 
            max = current; 
        }
        before = current; 
        current = after; 
        f >> after; 
    }
    f.close(); 
    return true; 
}