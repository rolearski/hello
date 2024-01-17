cmake_minimum_required(VERSION 2.8)

project(go)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0) # look into FindPkgConfig.cmake, 

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread -pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++17")

link_directories(
    ${GTKMM_LIBRARY_DIRS}  )

include_directories(
    ${GTKMM_INCLUDE_DIRS}  )

add_executable(${PROJECT_NAME} "main.cc" "examplewindow.cc")

target_link_libraries(go
    ${GTKMM_LIBRARIES}  )

#set(THREADS_PREFER_PTHREAD_FLAG ON)
#find_package(Threads REQUIRED)
