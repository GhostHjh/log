#include <ctime>
#include <iostream>
#include "log.h"

using std::cout;
using std::endl;

int main(int argc, const char** argv)
{
    //time_t _time;
    //time(&_time);
    //auto _tm = gmtime(&_time);
    //std::cout << (1900+ _tm->tm_year) << '-' << _tm->tm_mon << '-' << _tm->tm_mday << ' '
    //    << _tm->tm_hour << ':' << _tm->tm_min << ':' << std::endl;
    


    cout << "Hello World!" << endl;
    cout << log::insetance()->open("log.txt") << endl;
    log::insetance()->DEBUG_read_log("main.cpp", 12, "测试");
    log::insetance()->close();

    return 0;
}




