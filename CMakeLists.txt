cmake_minimum_required(VERSION 3.26)
project(TeaxsHoldem)

set(CMAKE_CXX_STANDARD 17)

add_executable(TeaxsHoldem main.cpp
        startup.h
        startup.cpp
        dealer.h
        player.h
        cards.h
        cards.cpp
        dealer.cpp
        dealer.cpp
        player.cpp
        bot.h
        bot.h
        bot.cpp)
