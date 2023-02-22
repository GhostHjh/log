#include "log.h"
#include <mutex>
#include <string.h>
#include <time.h>

const char* log::Level_s[4] = {"DEBUG", "INFO", "WARN", "ERROR"};

log* log::_log = nullptr;

log::log() {}
log::~log() {}

log* log::insetance()
{
    if (log::_log == nullptr)
        log::_log = new log();
    
    return log::_log;
}

void log::close()
{
    if (log::_log != nullptr)
        delete log::_log;
    
    if (_file.is_open())
        _file.close();
}

const bool log::open(std::string argv_file_name)
{
    file_name = argv_file_name;

    _file.open(file_name.c_str(), std::ios::app);

    return _file.is_open();
}

const bool log::read_log(Level argv_log_Level, std::string argv_file_name, int argv_file_line, const char *argv_log_str)
{
    {
        std::unique_lock<std::mutex> _mutex_lock(log::_read_file_mutex);

        if (!_file.is_open())
            return false;
    
        time_t _time = time(nullptr);
        tm* _tm = localtime(&_time);
        memset(log::timestr, 0, 32);
        strftime(log::timestr, 32, "%Y-%m-%d %H:%M:%S", _tm);
        //std::cout << log::timestr << std::endl;
    
    
        _file << '[' << log::Level_s[argv_log_Level] << ']' << ' '
            << '(' << log::timestr << ')' << ' '
            << '{' << argv_file_name << ' ' << argv_file_line << '}' << ' '
            << argv_log_str << "\r\n";

        _file.flush();
    }

    return true;
}

const bool log::DEBUG_read_log(std::string argv_file_name, int argv_file_line, const char* argv_log_str)
{
    return read_log(log::DEBUG, argv_file_name, argv_file_line, argv_log_str);
}
const bool log::INFO_read_log(std::string argv_file_name, int argv_file_line, const char* argv_log_str)
{
    return read_log(log::INFO, argv_file_name, argv_file_line, argv_log_str);
}
const bool log::WARN_read_log(std::string argv_file_name, int argv_file_line, const char* argv_log_str)
{
    return read_log(log::WARN, argv_file_name, argv_file_line, argv_log_str);
}
const bool log::ERROR_read_log(std::string argv_file_name, int argv_file_line, const char* argv_log_str)
{
    return read_log(log::ERROR, argv_file_name, argv_file_line, argv_log_str);
}


