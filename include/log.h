#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <mutex>

class log
{
public:
    enum Level
    {
        DEBUG = 0,
        INFO,
        WARN,
        ERROR
    };

    static const char* Level_s[4];

public:
    static log* insetance();

public:
    const bool open(std::string argv_file_name);
    void close();

    const bool read_log(Level argv_log_Level, std::string argv_file_name, int argv_file_line, const char* argv_log_str);
    const bool DEBUG_read_log(std::string argv_file_name, int argv_file_line, const char* argv_log_str);
    const bool INFO_read_log(std::string argv_file_name, int argv_file_line, const char* argv_log_str);
    const bool WARN_read_log(std::string argv_file_name, int argv_file_line, const char* argv_log_str);
    const bool ERROR_read_log(std::string argv_file_name, int argv_file_line, const char* argv_log_str);


private:
    log();
    ~log();

private:
    static log * _log;

    std::string file_name;
    std::ofstream _file;

    char timestr[32];

private:
    std::mutex _read_file_mutex;
};




