#include <iostream>

class Reader {
 public:
    Reader();
    virtual int readData(int serial);
 private:
    int data = 2;
    int serial;
};
