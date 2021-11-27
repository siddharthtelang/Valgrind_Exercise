/* Copyright Siddharth [2021] */
#pragma once

#include <iostream>
#include <string>
#include <memory>
#include "reader.hpp"

class Sensor {
 public:
    virtual int read(int serial) = 0;
   //  virtual int write(int serial) = 0;
   //  virtual std::string type(int serial) = 0;
    virtual ~Sensor() {}
};

class AnalogSensor : public Sensor {
 public:
     explicit AnalogSensor(std::unique_ptr<Reader> reader);
    ~AnalogSensor() {}
    int read(int serial);
   //  int write(int serial);
   //  std::string type(int serial);
 private:
    std::unique_ptr<Reader> reader;
};
