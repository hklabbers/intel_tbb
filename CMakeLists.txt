cmake_minimum_required(VERSION 3.12)
project(Intel_tbb)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES  standalone_functions.cpp Forex.cpp Forex.h Forex_reader.cpp Forex_reader.h standalone_functions.h Serial_moving_average_calculator.cpp Serial_moving_average_calculator.h Stopwatch.h Parallel_moving_average_calculator.cpp Parallel_moving_average_calculator.h)

add_executable(serial_calc ${SOURCE_FILES} serial_calc.cpp)
add_executable(parallel_calc ${SOURCE_FILES} parallel_calc.cpp)

set(HOME /home/vagrant)

set(TBB_INCLUDE_DIR "${HOME}/dev-deps/tbb-2018_U5/include")
set(TBB_LIB_DIR "${HOME}/dev-deps/lib")
set(TBB_LIBS "${TBB_LIB_DIR}/libtbb.so")

set(POCO_INCLUDE_DIR "${HOME}/dev-deps/include")
set(POCO_LIB_DIR "${HOME}/dev-deps/lib")
set(POCO_LIBS "${POCO_LIB_DIR}/libPocoFoundationd.a")

target_include_directories(serial_calc PRIVATE "${TBB_INCLUDE_DIR}" "${POCO_INCLUDE_DIR}")
target_link_libraries(serial_calc "${POCO_LIBS}" "${TBB_LIBS}")

target_include_directories(parallel_calc PRIVATE "${TBB_INCLUDE_DIR}" "${POCO_INCLUDE_DIR}")
target_link_libraries(parallel_calc "${POCO_LIBS}" "${TBB_LIBS}")
