cmake_minimum_required(VERSION 3.17)

# set the project name
project(StanagKlvParser VERSION 0.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE C_STANDARD 17)
set(CMAKE C_STANDARD_REQUIRED True)

set(HEADERS klvparser/StreamParser.h klvparser/common.h klvparser/KLVParser.h)
set(SOURCES klvparser.cpp klvparser/StreamParser.cpp klvparser/common.cpp klvparser/KLVParser.cpp)

# add the executable
add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

set(CMAKE_CXX_FLAGS "-D__STDC_CONSTANT_MACROS")

find_package(PkgConfig REQUIRED)

if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /EHsc /W3 /MD)
else()
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

configure_file(Config.h.in Config.h)

target_include_directories(${PROJECT_NAME} 
    PUBLIC
        "${PROJECT_BINARY_DIR}"
)

target_link_libraries(${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME} DESTINATION ${PROJECT_BINARY_DIR}/bin)
install(FILES file(GET_RUNTIME_DEPENDENCIES LIBRARIES) DESTINATION ${PROJECT_BINARY_DIR}/bin)