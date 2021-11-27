#include "reader.hpp"

Reader::Reader() {
}

int Reader::readData(int serial) {
    if (serial < 0)
        return -1;
    else
        return serial + data;
}
