cmake_minimum_required(VERSION 3.17)
project(Bilete)

set(CMAKE_CXX_STANDARD 14)

add_executable(Bilete main.cpp Film.cpp Film.h Sala.cpp Sala.h Loc.cpp Loc.h Bilet.cpp Bilet.h Client.cpp Client.h util.h)