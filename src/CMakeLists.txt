file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")
list(REMOVE_ITEM SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/main.cc)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS thread system regex program_options filesystem REQUIRED)

find_package(OpenSSL REQUIRED)
find_package(CppCMS REQUIRED)

include_directories(${Boost_INCLUDE_DIRS}
	${OPENSSL_INCLUDE_DIRS}
	${CppCMS_INCLUDE_DIRS})

add_library(${PROJECT_NAME} ${SOURCES})
add_executable(${PROJECT_NAME}-demo main.cc)

target_link_libraries(${PROJECT_NAME}
	${Boost_LIBRARIES}
	${OPENSSL_LIBRARIES}
	${CppCMS_LIBRARIES})

target_link_libraries(${PROJECT_NAME}-demo ${PROJECT_NAME})
