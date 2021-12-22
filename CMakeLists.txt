cmake_minimum_required(VERSION 3.0.0)
project(omniwheel_control VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(omniwheel_control main.cpp DCMotor.cpp EncoderDCMotor.cpp)
target_include_directories(omniwheel_control PUBLIC ${CMAKE_SOURCE_DIR}/include)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
