/* Copyright Siddharth [2021] */
#include <iostream>
#include <Sensor.hpp>

int main() {
    std::unique_ptr<Reader> reader(new Reader());
    Sensor* s = new AnalogSensor(std::move(reader));
    std::cout << "read data = " << s->read(10) << std::endl;
}
