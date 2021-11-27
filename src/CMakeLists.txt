include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

add_library(reader_writer
            reader.cpp
            AnalogSensor.cpp
            ${CMAKE_SOURCE_DIR}/include/reader.hpp
            ${CMAKE_SOURCE_DIR}/include/Sensor.hpp
            )

target_include_directories(reader_writer PUBLIC ../include)