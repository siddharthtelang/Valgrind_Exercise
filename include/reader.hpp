#include <iostream>

class Reader {
 public:
    Reader();
    virtual int readData(int serial);
    virtual ~Reader();
 private:
    int data = 2;
    int serial;
};
