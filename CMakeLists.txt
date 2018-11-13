cmake_minimum_required (VERSION 2.6)
project (langtonant)

IF (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17")
ELSE()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
ENDIF()

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall")

set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/gnuplot-iostream)
    add_definitions(-DGNUPLOT_USE)
    set(GNUPLOT_USE TRUE)
else()
    set(GNUPLOT_USE FALSE)
endif()


if (GNUPLOT_USE)
    include_directories(gnuplot-iostream)

    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -lboost_iostreams -lboost_system -lboost_filesystem")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lboost_iostreams -lboost_system -lboost_filesystem")
endif()

add_executable(main_analyse main_analyse.cpp langtonant.cpp)