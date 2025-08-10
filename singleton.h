//
// Created by anon on 25-8-9.
//

#ifndef SINGLETON_H
#define SINGLETON_H

#include <memory>
#include <mutex>

template<typename T>
class Singleton
{
private:
protected:
    static std::shared_ptr<T> _instance;
    Singleton()= default;
public:
    Singleton(const Singleton<T>&) = delete;
    static std::shared_ptr<T> get_instance()
    {
        static std::once_flag flag;
        std::call_once(flag, []()
        {
           _instance = std::make_shared<T>();
        });
        return _instance;
    }
};

template<typename T>
std::shared_ptr<T> Singleton<T>::_instance = nullptr;

#endif //SINGLETON_H
