cmake_minimum_required(VERSION 3.31)
project(logger)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        logger
        message.h
        log.h
        singleton.h
        buffer.cpp
        buffer.h
        queue.h
        main.cpp

)