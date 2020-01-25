cmake_minimum_required(VERSION 2.8.12)
project(csv_stats)

#link dlib here
add_subdirectory(dlib dlib_build)

add_executable(csv_stats csv_stats.cpp)
#this depends on dlib
target_link_libraries(csv_stats dlib::dlib)

