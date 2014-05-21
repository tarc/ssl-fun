cmake_minimum_required (VERSION 2.8)

project (ast)

set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake_modules/")

# Compiler specific settings:
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
  # using Intel C++

elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  # using Visual Studio C++
endif ()


add_subdirectory (src)
add_subdirectory (test)

enable_testing ()
file (GLOB TEST_SOURCES test/*.cc)
foreach (test_source ${TEST_SOURCES})
	get_filename_component(test_src_cmd ${test_source} NAME_WE)
	add_test (NAME ${test_src_cmd}-test COMMAND ${test_src_cmd})
	list(APPEND TESTS ${test_src_cmd})
endforeach ()

add_custom_target (tests
	COMMAND ${CMAKE_CTEST_COMMAND} DEPENDS ${TESTS})

