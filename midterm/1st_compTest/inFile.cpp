#include "inFile.h"

std::istream& operator>>(std::istream& is, Measurement& m)
{
    is >> m.date >> m.weight >> m.distance;
    return is;
}

std::istream& operator>>(std::istream& is, Station& st) //是 operator， 像function
{
    std::string line;
    
    getline(is,line,'\n'); //读一行， 直到 这一行 换行
    
    std::stringstream ss(line); //从line 里， 再读 string
    
    ss >> st.name >> st.station; 
    // 这里就是用 stringstream 读了 line 里的 前两个 黑洞名字 和 空间站
    
    st.close = false;
    
    st.lastWeight = 0;
    
    Measurement m;

    while (ss >> m)  // 这里就是用 stringstream 读 measurement
    {
        st.close = st.close || (m.distance < 2700);
        st.lastWeight = m.weight;
        // 因为是while loop ， 所以这个 lastweight 是不断改变， 直到最后一次测量
    }
    return is;
    //返回 从哪里 读来的 ， 从 is 里 读的 station ， 和从is 里读的 measurement
}


inFileMax::inFileMax(const std::string &fileName)
{
    _x.open(fileName.c_str());
    if (_x.fail()) throw FILE_ERROR;
}

void inFileMax::read()
{
    /// variable = condition ? value if true : value if false;
    _sx = (_x >> _dx) ? norm : abnorm;
}



inFile::inFile(const std::string fileName)
{
    _x.open(fileName.c_str());
    if (_x.fail()) throw FILE_ERROR;
}

void inFile::read()
{
    _sx = (_x >> _dx) ? norm : abnorm; 
    //从 _x file 里 读一行 到 _dx station 里。 
}

void inFile::next()
{
    if ( !(_end = (_sx == abnorm)))
    {
        _cur.name = _dx.name;
        _cur.allClose = true; /// AND-ing bool values
        //假设所有都是小于2700， 如果大于2700 这里就是 false
        
        int sumOfWeights = 0;
        int countOfStations = 0;
        for ( ; _sx == norm && _cur.name == _dx.name; read() )
        {
            sumOfWeights += _dx.lastWeight;
            ++countOfStations;
            _cur.allClose = _cur.allClose && _dx.close;
            
        }
        if (countOfStations > 0)
        {
            _cur.avgOfWeights = double(sumOfWeights) / countOfStations;
        }
        else
        {
            _cur.avgOfWeights = 0;
        }
    }
}
