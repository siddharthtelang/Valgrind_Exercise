#include <iostream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "Sensor.hpp"

class MockSensor : public Sensor {
 public:
    MOCK_METHOD1(read, int(int));
};

class MockReader : public Reader {
 public:
    MOCK_METHOD1(readData, int(int));
};
