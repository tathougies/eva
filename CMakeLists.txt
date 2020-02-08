cmake_minimum_required(VERSION 3.13)
project(eva LANGUAGES CXX)
SET(CMAKE_CXX_STANDARD 14)

enable_testing()

SET(BUILD_SHARED_LIBS 1)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
add_library(eva src/types.cpp src/primitive.cpp)

# add_executable(eva-http
#add_executable(eva-tests tests/types.cpp)
#target_link_libraries(eva-tests ${Boost_LIBRARIES})

#add_test(NAME eva_test COMMAND eva-test)
