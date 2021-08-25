cmake_minimum_required(VERSION 3.19)
project(MonstersHotel)

set(CMAKE_CXX_STANDARD 14)

add_executable(MonstersHotel main.cpp Users/User.cpp Users/User.h Users/Monster.cpp Users/Monster.h Users/Human.cpp Users/Human.h Users/Guest.cpp Users/Guest.h Properties/HotelProperties.cpp Properties/HotelProperties.h)