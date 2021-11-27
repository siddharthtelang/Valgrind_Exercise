include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

add_library(reader_writer
            reader.cpp
            ${CMAKE_SOURCE_DIR}/include/reader.hpp
            )

target_include_directories(reader_writer PUBLIC ../include)