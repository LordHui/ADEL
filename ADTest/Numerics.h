#ifndef NUMERICS_H
#define NUMERICS_H

#include "../ADTestGen/TestGenHelper.h"

const double relEPS = 1.0e-2;
const double absEPS = 1.0e-2;
const double h = 1.0e-4;

bool Compare(real expected, real recieved, const char* name, int testCase) {
    real absDelta = fabs(expected - recieved);
    real relDelta = absDelta / (std::max(fabs(expected), fabs(recieved)));

    if ((absDelta > absEPS) && (relDelta > relEPS)) {
        //printf("Test: %d, %s expected: %f, recieved: %f\n", testCase, name, expected, recieved);
        return false;
    }
    return true;
};

bool FirstOrderNumeric(FunctionBase<real>* function, const real(&args)[DataInSize], int direction, real recieved, int testCase) {
    real localArgs[DataInSize];

    memcpy(localArgs, args, DataInSize * sizeof(real));
    localArgs[direction] += h;
    real gradExpected = function->TestFunction(localArgs);

    memcpy(localArgs, args, DataInSize * sizeof(real));
    localArgs[direction] -= h;
    gradExpected -= function->TestFunction(localArgs);

    gradExpected /= 2 * h;

    std::string name = "Gradient in direction: " + IntToStr(direction);
    return Compare(gradExpected, recieved, name.c_str(), testCase);
};

bool SecondOrderNumeric(FunctionBase<real>* function, const real(&args)[DataInSize], int directionX, int directionY, real recieved, int testCase) {
    real localArgs[DataInSize];

    memcpy(localArgs, args, DataInSize * sizeof(real));
    localArgs[directionX] += h;
    localArgs[directionY] += h;
    real hessExpected = function->TestFunction(localArgs);

    memcpy(localArgs, args, DataInSize * sizeof(real));
    localArgs[directionX] += h;
    localArgs[directionY] -= h;
    hessExpected -= function->TestFunction(localArgs);

    memcpy(localArgs, args, DataInSize * sizeof(real));
    localArgs[directionX] -= h;
    localArgs[directionY] -= h;
    hessExpected += function->TestFunction(localArgs);

    memcpy(localArgs, args, DataInSize * sizeof(real));
    localArgs[directionX] -= h;
    localArgs[directionY] += h;
    hessExpected -= function->TestFunction(localArgs);

    hessExpected /= 4 * h * h;

    std::string name = "Hessian in direction: " + IntToStr(directionX) + ", " + IntToStr(directionY);
    return Compare(hessExpected, recieved, name.c_str(), testCase);
};

#endif  // NUMERICS_H
