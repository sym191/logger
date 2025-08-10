//
// Created by anon on 25-8-9.
//

#ifndef QUEUE_H
#define QUEUE_H
#include <condition_variable>
#include <queue>
#include <memory>
#include <mutex>
#include "message.h"

template<typename T>
class queue {
private:
    std::queue<T> queue_;
    mutable std::mutex mutex_;
    std::condition_variable variable_;
public:
    void push(T&& message)
    {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            queue_.push(std::forward<T>(message));
        }
        variable_.notify_one();
    }

    T pop()
    {
        std::unique_lock<std::mutex> lock(mutex_);
        variable_.wait(lock, [this](){return !queue_.empty();});
        T t = std::move(queue_.front());
        queue_.pop();
        return t;
    }

    bool empty() const
    {
        std::lock_guard<std::mutex> lock(mutex_);
        return queue_.empty();
    }

    std::size_t size() const
    {
        std::lock_guard<std::mutex> lock(mutex_);
        return queue_.size();
    }

};



#endif //QUEUE_H
