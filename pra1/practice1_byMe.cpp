#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std; 

// int times2(int number) {
//     return number * 2; 
// }

// void times2_ref(int &number) {  
//     number *= 2; 
//     cout << "times2_ref: " << number << endl;  
//     /*
//         如果是 &number 则可以改变传进来的数字；
//         如果是 number， 则里面的数字改变，但外面的数字不变。 
//     */
// }

void fill(vector<int> &v) {
    for (int i = 0; i < 100; ++i ){
        v.push_back(i); 
    }
}

void print(const vector<int> &v){
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << ", "; 
    }
    cout << endl; 
}

bool search_structogram(const vector<int> &v, int &ind) {
    bool l = false; 
    for (int i = 0; !l && i < v.size(); ++i ) {
        l = v[i] == 20;  // l = (v[i] == 20)
        ind = i; 
    }
    return l; 
}

bool search(const vector<int> &v, int &ind) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == 20) {
            ind = i; 
            return true; 
        }
    }
    return false; 
}


int main(){
    // int num = 12; 
    // //times2_ref(num);
    // cout << num << endl; 

    cout << "vector" << endl; 
    vector<int> numbers; 
    fill(numbers); 
    //print(numbers);

    cout << "search" << endl; 

    int ind = 0; 
    if (search(numbers, ind)) {
        cout << "We found the number 20 at index: " << ind+1 << endl; 
    } else {
        cout << "We couldn't find the number 20." << endl; 
    }
    cout << "reading numbers"


}