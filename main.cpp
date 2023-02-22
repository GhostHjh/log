#include <ctime>
#include <iostream>
#include <unistd.h>
#include <vector>
#include <thread>
#include "log.h"

using std::cout;
using std::endl;

void test_rean_log()
{
    for (int i = 0; i < 10000; ++i)
    {
        log::insetance()->DEBUG_read_log("main.cpp", i, "测试123");
    }
}

int main(int argc, const char** argv)
{
    //time_t _time;
    //time(&_time);
    //auto _tm = gmtime(&_time);
    //std::cout << (1900+ _tm->tm_year) << '-' << _tm->tm_mon << '-' << _tm->tm_mday << ' '
    //    << _tm->tm_hour << ':' << _tm->tm_min << ':' << std::endl;

    //cout << "Hello World!" << endl;
    cout << log::insetance()->open("log.txt") << endl;
    
    std::vector< std::thread > tmp_vec;
    for (int i = 0; i < 10; ++i)
        tmp_vec.emplace_back( &test_rean_log );    

    for (auto &i : tmp_vec)
        i.join();

    log::insetance()->close();

    return 0;
}




