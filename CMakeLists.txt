cmake_minimum_required(VERSION 3.6)
project(ex2tests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(BOOST_ROOT CACHE PATH "/usr/include/boost/")
find_package(Boost 1.58.0 COMPONENTS serialization system)
include_directories(${Boost_INCLUDE_DIR})

set(core_sockets sockets/Socket.cpp sockets/Socket.h sockets/Udp.cpp sockets/Udp.h sockets/Tcp.cpp sockets/Tcp.h)
add_library(sockets ${core_sockets})

set(SOURCE_FILES_CLIENT ClientMain.cpp src/Point.h src/Point.cpp src/Grid.cpp src/BFS.cpp src/BFS.h src/Grid.h src/Node.cpp src/Node.h src/Matrix.cpp src/Matrix.h src/Cab.cpp src/Cab.h src/Listener.cpp src/Listener.h src/Notifier.cpp src/Notifier.h src/Passenger.cpp src/Passenger.h src/Driver.cpp src/Driver.h src/LuxuryCab.cpp src/LuxuryCab.h src/StandardCab.cpp src/StandardCab.h src/TaxiCenter.cpp src/TaxiCenter.h src/TransportationFlow.cpp src/TransportationFlow.h src/Trip.cpp src/Trip.h src/ThreadManagement.cpp src/ThreadManagement.h src/Checker.cpp src/Checker.h src/ThreadPool.cpp src/ThreadPool.h src/Job.cpp src/Job.h)

set(SOURCE_FILES_SERVER ServerMain.cpp src/Point.h src/Point.cpp src/Grid.cpp src/BFS.cpp src/BFS.h src/Grid.h src/Node.cpp src/Node.h src/Matrix.cpp src/Matrix.h src/Cab.cpp src/Cab.h src/Listener.cpp src/Listener.h src/Notifier.cpp src/Notifier.h src/Passenger.cpp src/Passenger.h src/Driver.cpp src/Driver.h src/LuxuryCab.cpp src/LuxuryCab.h src/StandardCab.cpp src/StandardCab.h src/TaxiCenter.cpp src/TaxiCenter.h src/TransportationFlow.cpp src/TransportationFlow.h src/Trip.cpp src/Trip.h src/ThreadManagement.cpp src/ThreadManagement.h src/Checker.cpp src/Checker.h src/ThreadPool.cpp src/ThreadPool.h src/Job.cpp src/Job.h)

add_executable(Server ${SOURCE_FILES_SERVER})
add_executable(Client ${SOURCE_FILES_CLIENT})

target_link_libraries(Server sockets ${Boost_LIBRARIES})
target_link_libraries(Client sockets ${Boost_LIBRARIES})