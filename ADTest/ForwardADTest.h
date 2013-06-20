#ifndef FORWARDADTEST_H
#define FORWARDADTEST_H

#include "..\ReverseAD\ReverseAD.h"
#include "TestFunctions.h"
#include "Numerics.h"

const int forwardTestLevel = 2;

void ForwardADCorrectnessTest() {
    FunctionBase<real>* numericTests[SimpleTestCases + ComplexTestCases];
    FunctionBase<Dependent<forwardTestLevel, DataInSize>, Dependent<forwardTestLevel, DataInSize>>* reverseADTests[SimpleTestCases + ComplexTestCases];
    Initialize<real, real>(numericTests);
    Initialize<Dependent<forwardTestLevel, DataInSize>, Dependent<forwardTestLevel, DataInSize>>(reverseADTests);
    Dependent<forwardTestLevel, DataInSize> independentArgs[DataInSize];
    for (int r = 0; r < DataInSize; r++) {
        independentArgs[r] = realArgs[r];
        independentArgs[r].SetGradient(r, 1.0);
    }
    int passedCounter = 0;
    for (int t = 0; t < SimpleTestCases + ComplexTestCases; t++) {
        Dependent<forwardTestLevel, DataInSize> reverseADResult = reverseADTests[t]->TestFunction(independentArgs);
        real valueExpected = numericTests[t]->TestFunction(realArgs);
        bool passed = true;
        passed &= Compare(valueExpected, reverseADResult.GetValue(), "Value", t);
        for (int i = 0; i < DataInSize; i++)
            passed &= FirstOrderNumeric(numericTests[t], realArgs, i, reverseADResult.Gradient[i].GetValue(), t);
        for (int i = 0; i < DataInSize; i++)
            for (int j = 0; j < DataInSize; j++)
                passed &= SecondOrderNumeric(numericTests[t], realArgs, i, j, reverseADResult.Gradient[i].Gradient[j], t);
        if (passed)
            passedCounter++;
    }
    printf("  Correctness: %d/%d.\n", passedCounter, SimpleTestCases + ComplexTestCases);
    Finalize<Dependent<forwardTestLevel, DataInSize>, Dependent<forwardTestLevel, DataInSize>>(reverseADTests);
    Finalize<real, real>(numericTests);
};

void ForwardADPerformanceTest(int iterations) {
    clock_t t = clock();
    FunctionBase<Dependent<forwardTestLevel, DataInSize>, Dependent<forwardTestLevel, DataInSize>>* reverseADTests[SimpleTestCases + ComplexTestCases];
    Initialize<Dependent<forwardTestLevel, DataInSize>, Dependent<forwardTestLevel, DataInSize>>(reverseADTests);
    Dependent<forwardTestLevel, DataInSize> independentArgs[DataInSize];
    for (int r = 0; r < DataInSize; r++) {
        independentArgs[r] = realArgs[r];
    }
    real optBypass = 0;
    for (int k = 0; k < iterations; k++)
        for (int t = 0; t < SimpleTestCases; t++) {
            Dependent<forwardTestLevel, DataInSize> reverseADResult = reverseADTests[t]->TestFunction(independentArgs);
            optBypass += reverseADResult.GetValue();
        }
    t = clock() - t;
    printf("  Performance[Simple]: %d ms. Checksum: %.0\n", t, fmod(optBypass, real(10.0)));
    optBypass = 0;
    for (int k = 0; k < iterations; k++)
        for (int t = 0; t < ComplexTestCases; t++) {
            Dependent<forwardTestLevel, DataInSize> reverseADResult = reverseADTests[SimpleTestCases + t]->TestFunction(independentArgs);
            optBypass += reverseADResult.GetValue();
        }
    t = clock() - t;
    printf("  Performance[Complex]: %d ms. Checksum: %.0\n", t, fmod(optBypass, real(10.0)));
    Finalize<Dependent<forwardTestLevel, DataInSize>, Dependent<forwardTestLevel, DataInSize>>(reverseADTests);
};

#endif  //FORWARDADTEST_H
