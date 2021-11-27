#include <gtest/gtest.h>
#include "Sensor.hpp"

TEST(readData, read) {
  Reader *read = new Reader();
  auto ret = read->readData(3);
  ASSERT_EQ(ret, 5);
}

TEST(readData, invalid_data) {
  Reader *read = new Reader();
  auto ret = read->readData(-58);
  ASSERT_EQ(ret, -1);
}

TEST(analog_sensor, readData) {
  std::unique_ptr<Reader> reader(new Reader());
  Sensor* s = new AnalogSensor(std::move(reader));
  auto ret = s->read(10);
  ASSERT_EQ(ret, 12);
}

TEST(analog_sensor, invalid_data) {
  std::unique_ptr<Reader> reader(new Reader());
  Sensor* s = new AnalogSensor(std::move(reader));
  auto ret = s->read(-5);
  ASSERT_EQ(ret, -1);
}
