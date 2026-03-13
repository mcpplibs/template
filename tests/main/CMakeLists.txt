enable_testing()

file(GLOB TESTS_SRC "*.cpp")

set(TEST_EXECUTABLE_NAME main_tests)
add_executable(${TEST_EXECUTABLE_NAME} ${TESTS_SRC})

target_link_libraries(${TEST_EXECUTABLE_NAME} PRIVATE GTest::gtest GTest::gmock GTest::gmock_main GTest::gtest_main)
target_compile_features(${TEST_EXECUTABLE_NAME} PRIVATE cxx_std_23)

target_link_libraries(${TEST_EXECUTABLE_NAME} PRIVATE ${PROJECT_NAME})

add_test(
        NAME ${TEST_EXECUTABLE_NAME}
        COMMAND $<TARGET_FILE:${TEST_EXECUTABLE_NAME}>
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)