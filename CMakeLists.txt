cmake_minimum_required(VERSION 2.8)

project(ast)

file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/src/*.cc")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake_modules/")

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS thread system regex REQUIRED)

find_package(OpenSSL REQUIRED)
find_package(CppCMS REQUIRED)

include_directories(${Boost_INCLUDE_DIRS} ${OPENSSL_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES})
