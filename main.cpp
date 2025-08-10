//
// Created by anon on 25-8-10.
//

#include "log.h"
#include <thread>
#include <atomic>
#include <format>

void foo(const std::string& s)
{
    try
    {
        static std::atomic<int> i = 0;
        while (i.load() < 1000)
        {
            if (auto j = i.load(); i.compare_exchange_weak(j, j+1))
            {
              Log::get_instance()->log(std::format("{}:{}", s, i.load()), "1");
            }
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "线程异常:" << s << e.what() << std::endl;
    }
}

int main()
{
    std::thread t([](){ Log::get_instance()->write();});
    std::thread t1([](){foo("1");});
    std::thread t2([](){foo("2");});
    std::thread t3([](){foo("3");});
    std::thread t4([](){foo("4");});
    t.join();
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}