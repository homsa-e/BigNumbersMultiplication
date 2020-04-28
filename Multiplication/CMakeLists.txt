cmake_minimum_required(VERSION 3.5)

project(Multiplication LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCE main.cpp Multiplicator/multiplicator.cpp School/school.cpp
     Number/number.cpp
     d_and_c/d_and_c.cpp karatsuba/karatsuba.cpp experiment/experiment.cpp)
add_executable(Multiplication ${SOURCE})
