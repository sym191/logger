//
// Created by anon on 25-8-9.
//

#ifndef MESSAGE_H
#define MESSAGE_H
#include <vector>
#include <string>

struct LogMessage
{
private:
    std::string _log;
    std::string _file_name;
public:
    explicit LogMessage(const std::string& log,const std::string& file): _log(log), _file_name((file)){}
    inline std::string& get_log()
    {
        return _log;
    }

    inline std::string& get_filename()
    {
        return _file_name;
    }
};

#endif //MESSAGE_H
