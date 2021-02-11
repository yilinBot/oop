#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

int times2(int number) {
    return number * 2;
}

void times2_ref(int &number) {
    number = number * 2;
    cout << "times2_ref " << number << endl;
}

void fill(vector<int> &v) {
    for (int i = 0; i < 100; ++i) {
        v.push_back(i);
    }
}

void print(const vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << ", ";
    }
    cout << endl;
}

bool search_structogram(const vector<int> &v, int &ind) {
    bool l = false;
    for (int i = 0; !l && i < v.size(); ++i) {
        l = v[i] == 20;
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

int main()
{
    cout << times2(12) << endl;
    int num = 12;
    times2_ref(num);
    cout << num << endl;
    
    cout << "vector" << endl;
    vector<int> numbers;
    fill(numbers);
    print(numbers);
    cout << "search" << endl;
    int ind = 0;
    if (search(numbers, ind)) {
        cout << "We found the number 20 at index " << ind+1 << endl;
    } else {
        cout << "We couldn't find the number 20." << endl;
    }
    cout << "reading numbers" << endl;
    ifstream ns;
    ns.open("numbers.txt");
    if (ns.fail()) {
        cout << "Cannot open the input file!" << endl;
        exit(-1);
    }
    int number;
    vector<int> read_numbers;
    while (ns >> number) {
        read_numbers.push_back(number);
    }
    if (search(read_numbers, ind)) {
        cout << "We found the number 20 at index " << ind+1 << endl;
    } else {
        cout << "We couldn't find the number 20." << endl;
    }
    print(read_numbers);
    cout << "ifstream" << endl;
    ifstream fs;
    fs.open("main.cpp");
    if (fs.fail()) {
        cout << "Cannot open the input file!" << endl;
        exit(-1);
    }
//    string word;
//    while (fs >> word) {
//        cout << word << "...";
//    }
//    cout << endl;

    string line;
    getline(fs, line);
    while (fs) {
        cout << line << endl;
        getline(fs, line);
    }
    
    return 0;
}
