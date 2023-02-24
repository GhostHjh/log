# 轻量Log日志库

## 安装

> * 安装
>   将 __include__ 目录下的 __log.h__ 头文件导入到你的头文件目录， 并编译时添加 __src__ 目录下 __log.cpp__ 文件

## 使用

> * 创建对象
>
>   ```cpp
>   //因为是单例模式, 所有不能自己创建对象, 使用下面的函数来返回对象
>   log::insetance()
>
>   ```
> * 设置用于存储log的文件
>
>   ```cpp
>   //下面的函数用于设置log文件的目录(非必要, 默认为"./")
>   log::insetance()->set_log_path(std::string log_file_path);
>
>   //下面的函数用于打开存数log的文件(必要)
>   log::insetance()->open(std::string log_file_name);
>
>   ```
> * 其它设置
>
>   ```cpp
>   //下面的函数用于设置log文件的最大大小(非必要, 默认为10MB, 但超过这个大小会自动使用时间作为备份log文件的前缀备份当前log文件)
>   log::insetance()->set_log_max_size(std::size_t log_max_size);
>
>   //下面这个函数用于设置最低记录的日志等级
>   //日志默认有4个等级, 从低到高分别是DEBUG, INFO, WARN, ERROR
>   //如果设置等级为INFO, 那DEBUG等级的目录就会被忽略
>   log::insetance()->set_read_Level(log::Level log_level);
>
>   ```
> * 写入日志
>
>   ```cpp
>   //最基础的写入方式
>   //参数为 日志等级, 触发写入的文件名称, 是第几行触发的写入, 日志内容
>   log::insetance()->const bool read_log(Level log_Level, std::string file_name, int file_line, const char* log_str);
>
>   //也有更方便的函数
>   //
>    const bool DEBUG_read_log(std::string file_name, int argv_file_line, const char* log_str);
>    const bool INFO_read_log(std::string file_name, int argv_file_line, const char* log_str);
>    const bool WARN_read_log(std::string file_name, int argv_file_line, const char* log_str);
>    const bool ERROR_read_log(std::string file_name, int argv_file_line, const char* log_str);
>
>   ```
