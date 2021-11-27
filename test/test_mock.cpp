#include "gmock/gmock.h"
#include <gtest/gtest.h>
#include "mock_class_and_functions.hpp"

using :: testing::_;

// Mock methods

TEST(mock_sensor_test, test_read) {
  // SETUP
  std::unique_ptr<MockSensor> mockSensor(new MockSensor());
  std::unique_ptr<Reader> reader(new Reader());

  // ARRANGE
  int data = 5;
  EXPECT_CALL(*mockSensor, read(_))
             .WillOnce(::testing::Return(data+2));

  // ACT
  auto ret = mockSensor->read(data);
  EXPECT_EQ(ret, data+2);
}

TEST(mock_sensor_test, test_invalid_read) {
  // SETUP
  std::unique_ptr<MockSensor> mockSensor(new MockSensor());
  std::unique_ptr<Reader> reader(new Reader());

  // ARRANGE
  int data = -5;
  EXPECT_CALL(*mockSensor, read(_))
             .WillOnce(::testing::Return(-1));

  // ACT
  auto ret = mockSensor->read(data);
  EXPECT_EQ(ret, -1);
}

TEST(mock_reader_test, test_readData) {
  // SETUP
  std::unique_ptr<MockReader> mockReader(new MockReader());

  // ARRANGE
  int data = 5;
  EXPECT_CALL(*mockReader, readData(_))
             .WillOnce(::testing::Return(data+2));

  Sensor* s = new AnalogSensor(std::move(mockReader));

  // ACT
  auto ret = s->read(data);
  EXPECT_EQ(ret, data+2);
  // mockReader.reset();
}

TEST(mock_reader_test, test_invalid_readData) {
  // SETUP
  std::unique_ptr<MockReader> mockReader(new MockReader());

  // ARRANGE
  int data = -5;
  EXPECT_CALL(*mockReader, readData(_))
             .WillOnce(::testing::Return(-1));

  Sensor* s = new AnalogSensor(std::move(mockReader));

  // ACT
  auto ret = s->read(data);
  EXPECT_EQ(ret, -1);
  mockReader.reset();
}
