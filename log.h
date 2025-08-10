//
// Created by anon on 25-8-9.
//

#ifndef LOG_H
#define LOG_H
#include <iostream>

#include "queue.h"
#include "singleton.h"
#include <string>


struct Log : public Singleton<Log>
{
private:
    using message = std::unique_ptr<LogMessage>;
    queue<message> queue_;
public:
    void log(const std::string& log, const std::string& filename)
    {
        queue_.push(std::make_unique<LogMessage>(log, filename));
    }

    void write()
    {
        try
        {
            std::cout << "Queue size: " << queue_.size() << std::endl;
            int i = 1000;
            while (i)
            {
                const message msg = queue_.pop();
                std::cout << msg->get_log() << std::endl;
                --i;
            }
        }
        catch (const std::exception& e)
        {
            std::cerr << "线程异常:" << e.what() << std::endl;
        }
    }
};

#endif //LOG_H
