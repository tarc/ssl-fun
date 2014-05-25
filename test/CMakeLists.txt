find_package (Boost COMPONENTS unit_test_framework REQUIRED)
include_directories (${CMAKE_SOURCE_DIR}/src ${Boost_INCLUDE_DIRS})

add_definitions (-DBOOST_TEST_DYN_LINK)

enable_testing ()

file (GLOB TEST_SOURCES *.cc)
foreach (test_src ${TEST_SOURCES})
	get_filename_component(test_src_cmd ${test_src} NAME_WE)
	add_executable (${test_src_cmd} ${test_src})
	target_link_libraries (${test_src_cmd} ${Boost_LIBRARIES} ${PROJECT_NAME})

	add_test (NAME ${test_src_cmd}-test COMMAND ${test_src_cmd})
	list(APPEND TESTS ${test_src_cmd})
endforeach ( )

add_custom_target (tests
	COMMAND ${CMAKE_CTEST_COMMAND} DEPENDS ${TESTS})

