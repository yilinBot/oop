/*
ZH megoldas
A kivalo szint fajlszerkezetere lett irva, a ket megoldas egyben talalhato.

*/

#ifndef INFILE_H
#define INFILE_H

#include <fstream> //file stream , read in and out file
#include <sstream>  //string stream , read from a string, and output to a string
#include <iostream> //input and output standard


struct Measurement
{
    std::string date;
    int weight;
    int distance;
    friend std::istream& operator >> (std::istream& is, Measurement& m);
    //这里就是告诉 程序， 如何读取 measurement

    /*
    friend 是个function
    friend 就是让这个function用这个class的private

    fstream  是 从一个file里读取各种，和输出到一个file里
    istream （input stream） 从某个东西里读取东西
    ifstream 只能从一个file 里读取
    */

};

struct Station ///blackhole
{
    std::string name;
    std::string station;
    int lastWeight; 
    bool close; // 这里是看 一行 （一个station 就是 一行）有没有小于 2700
    
    friend std::istream& operator >> (std::istream &is, Station& s);
    // 这个friend的 funciton 就是为了 读取这些 内容
    // 从 istream 读 Station
};

struct BlackHole 
{
    std::string name;  //黑洞的名字
    double avgOfWeights;
    bool allClose; //就是 确保 每个 station 记录的 黑洞 都是小于 2700， 如果不是， 就不算平均值
};

enum Status {norm, abnorm};
//这个就类似于 boolean 里的 true 和false， 
//这里是说 status 有 norm 和abnorm

class inFileMax //只读一行
{
    public:
        enum Error {FILE_ERROR}; //找不到这个 file 就是这个error
        
        inFileMax(const std::string& fileName); //constructor 
        
        ~inFileMax() { _x.close(); }  //destructor 
        
        void first() { read(); }
        
        void next() { read(); }
        
        Station current() const { return _dx; } //返回现在的station
        //这里的const 是 不改变 inFileMax 的 object; 
        //比如，现在有 f.current(), 这个f 就不变。 
        // 这样就不会在 function 里 不小心更改。 
        
        bool end() const { return _sx==abnorm; } //是看整个文件有没有结束

    private:
        std::ifstream _x;
        Station _dx;
        Status _sx;

        void read();
};


class inFile  //读一个record， 比如相同的 blackhhole name
{
    public:
        enum Error {FILE_ERROR};
        inFile(const std::string& fileName); //construcor 
        ~inFile() { _x.close(); } //destructor
        
        void first() { read(); next(); }
        // 因为这里 我们不确定 这一行之后的 黑洞名字是否 相同， 
        // 所以我们需要 next（） 进行查看
        
        void next();
        
        BlackHole current() const { return _cur; }
        
        bool end() const { return _end; }

    private:
        std::ifstream _x;
        Station _dx;
        Status _sx;  // _sx 是 读完每一行 看文件有没有结束
        bool _end;  // 读一个 group 看文件有没有结束
        BlackHole _cur;

        void read();
};

#endif // INFILE_H
