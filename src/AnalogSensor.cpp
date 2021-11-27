/* Copyright Siddharth [2021] */
#include "Sensor.hpp"
#include <numeric>
#include <vector>


AnalogSensor::AnalogSensor(std::unique_ptr<Reader> reader_)
                            : reader(std::move(reader_)) {}

int AnalogSensor::read(int serial) {
    return reader->readData(serial);
}
