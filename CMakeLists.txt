cmake_minimum_required(VERSION 3.17)
project(top10tweet)

set(CMAKE_CXX_STANDARD 11)

set(PROJECT_HEADERS
        top10Tweet.h
        )
set(PROJECT_SOURCES
        main.cpp
        top10Tweet.cpp
        )
add_executable(top10tweet ${PROJECT_SOURCES} ${PROJECT_HEADERS})