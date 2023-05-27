set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_COMPILER /usr/bin/g++-13)

project(backtest)

set (SOURCES 
     ${CMAKE_CURRENT_SOURCE_DIR}/strategies.cxx
)

add_executable(backtest ${SOURCES} main.cxx)