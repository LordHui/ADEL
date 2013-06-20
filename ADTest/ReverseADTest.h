#ifndef REVERSEADTEST_H
#define REVERSEADTEST_H

#include "TestFunctions.h"
#include "Numerics.h"

const int reverseTestLevel = 2;

void ReverseADCorrectnessTest() {
    FunctionBase<real>* numericTests[SimpleTestCases + ComplexTestCases];
    FunctionBase<ADVariable<reverseTestLevel, DataInSize>>* reverseADTests[SimpleTestCases + ComplexTestCases];
    Initialize<real>(numericTests);
    Initialize<ADVariable<reverseTestLevel, DataInSize>>(reverseADTests);
    ADVariable<reverseTestLevel, DataInSize> independentArgs[DataInSize];
    for (int r = 0; r < DataInSize; r++) {
        independentArgs[r].ID = r;
        independentArgs[r].Value = realArgs[r];
        independentArgs[r].Independent = true;
    }
    int passedCounter = 0;
    for (int t = 0; t < SimpleTestCases + ComplexTestCases; t++) {
        ADVariable<reverseTestLevel, DataInSize> reverseADResult = reverseADTests[t]->TestFunction(independentArgs);
        real valueExpected = numericTests[t]->TestFunction(realArgs);
        bool passed = true;
        passed &= Compare(valueExpected, reverseADResult.Value, "Value", t);
        for (int i = 0; i < DataInSize; i++)
            passed &= FirstOrderNumeric(numericTests[t], realArgs, i, reverseADResult.Data[Offset<1, DataInSize>::Start + i], t);
        for (int i = 0; i < DataInSize; i++)
            for (int j = 0; j < DataInSize; j++)
                passed &= SecondOrderNumeric(numericTests[t], realArgs, i, j, reverseADResult.Data[Offset<2, DataInSize>::Start + i*DataInSize + j], t);
        if (passed)
            passedCounter++;
    }
    printf("  Correctness: %d/%d.\n", passedCounter, SimpleTestCases + ComplexTestCases);
    Finalize<ADVariable<reverseTestLevel, DataInSize>>(reverseADTests);
    Finalize<real>(numericTests);
};

void ReverseADPerformanceTest(int iterations) {
    clock_t t = clock();
    FunctionBase<ADVariable<reverseTestLevel, DataInSize>>* reverseADTests[SimpleTestCases + ComplexTestCases];
    Initialize<ADVariable<reverseTestLevel, DataInSize>>(reverseADTests);
    ADVariable<reverseTestLevel, DataInSize> independentArgs[DataInSize];
    for (int r = 0; r < DataInSize; r++) {
        independentArgs[r].ID = r;
        independentArgs[r].Value = realArgs[r];
        independentArgs[r].Independent = true;
    }
    real optBypass = 0;
    for (int k = 0; k < iterations; k++)
        for (int t = 0; t < SimpleTestCases; t++) {
            ADVariable<reverseTestLevel, DataInSize> reverseADResult = reverseADTests[t]->TestFunction(independentArgs);
            optBypass += reverseADResult.Value;
        }
    t = clock() - t;
    printf("  Performance[Simple]: %d ms. Checksum: %.0f\n", t, fmod(optBypass, real(10.0)));
    t = clock();
    optBypass = 0;
    for (int k = 0; k < iterations; k++)
        for (int t = 0; t < ComplexTestCases; t++) {
            ADVariable<reverseTestLevel, DataInSize> reverseADResult = reverseADTests[SimpleTestCases + t]->TestFunction(independentArgs);
            optBypass += reverseADResult.Value;
        }
    t = clock() - t;
    printf("  Performance[Complex]: %d ms. Checksum: %.0f\n", t, fmod(optBypass, real(10.0)));
    Finalize<ADVariable<reverseTestLevel, DataInSize>>(reverseADTests);
};

#endif  // REVERSEADTEST_H
