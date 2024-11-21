cmake_minimum_required(VERSION 3.22)
project(CI_Demo)

set(CMAKE_CXX_STANDARD 11)
option(BUILD_TESTS "Build the tests" OFF)

#Create Main Project Target
#--------------------------
add_executable(${PROJECT_NAME} 
        "src/main.cpp" 
        "src/calculator.cpp")
target_include_directories(${PROJECT_NAME} PRIVATE "./inc")


#Create Test Project Target (if required)
#--------------------------
if(BUILD_TESTS)

    set(TEST_PROJECT_NAME ${PROJECT_NAME}_DocTest)

    #Fetch DocTest
    include(FetchContent)
    FetchContent_Declare(
    doctest
    URL https://github.com/doctest/doctest/archive/refs/tags/v2.4.11.tar.gz # Github Release Package
    )
    FetchContent_MakeAvailable(doctest)

    #Create Test Target
    add_executable(${TEST_PROJECT_NAME}
            "src/calculator.cpp"
            "test/calculator_test.cpp")

    target_include_directories(${TEST_PROJECT_NAME} PRIVATE "./inc")
    target_link_libraries(${TEST_PROJECT_NAME} PRIVATE doctest)

    #Enable CTest
    enable_testing()
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${doctest_SOURCE_DIR}/scripts/cmake/")
    include(doctest)
    doctest_discover_tests(${TEST_PROJECT_NAME})

endif()