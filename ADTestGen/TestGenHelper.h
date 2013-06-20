#ifndef TESTGENHELPER_H
#define TESTGENHELPER_H

#include <sstream>
#include <iomanip>

const int Precision = 3;

std::string IntToStr(int value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

std::string DoubleToStr(double value) {
    std::stringstream ss;
    ss << std::setprecision(Precision + 1) << std::showpoint;
    ss << value;
    return ss.str();
}

#endif  // TESTGENHELPER_H
