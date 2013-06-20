#ifndef FADBADTEST_H
#define FADBADTEST_H

#include "..\FADBAD\badiff.h"
#include "..\FADBAD\fadiff.h"
#include "TestFunctions.h"
#include "Numerics.h"

typedef fadbad::B<fadbad::F<real>> fadbadVar;

void InitializeArgs(fadbadVar(&independentArgs)[DataInSize]) {
    for (int r = 0; r < DataInSize; r++) {
        independentArgs[r] = realArgs[r];
        independentArgs[r].x().diff(r, DataInSize);
    }
}

void FADBADCorrectnessTest() {
    FunctionBase<real>* numericTests[SimpleTestCases + ComplexTestCases];
    FunctionBase<fadbadVar>* FADBADTests[SimpleTestCases + ComplexTestCases];
    Initialize<real>(numericTests);
    Initialize<fadbadVar>(FADBADTests);
    fadbadVar independentArgs[DataInSize];
    int passedCounter = 0;
    for (int t = 0; t < SimpleTestCases + ComplexTestCases; t++) {
        InitializeArgs(independentArgs);
        fadbadVar FADBADResult = FADBADTests[t]->TestFunction(independentArgs);
        FADBADResult.diff(0, 1);
        real valueExpected = numericTests[t]->TestFunction(realArgs);
        bool passed = true;
        passed &= Compare(valueExpected, FADBADResult.x().x(), "Value", t);
        for (int i = 0; i < DataInSize; i++)
            passed &= FirstOrderNumeric(numericTests[t], realArgs, i, independentArgs[i].d(0).x(), t);
        for (int i = 0; i < DataInSize; i++)
            for (int j = 0; j < DataInSize; j++)
                passed &= SecondOrderNumeric(numericTests[t], realArgs, i, j, independentArgs[i].d(0).d(j), t);
        if (passed)
            passedCounter++;
    }
    printf("  Correctness: %d/%d.\n", passedCounter, SimpleTestCases + ComplexTestCases);
    Finalize<fadbadVar>(FADBADTests);
    Finalize<real>(numericTests);
};

void FADBADPerformanceTest(int iterations) {
    clock_t t = clock();
    FunctionBase<fadbadVar>* FADBADTests[SimpleTestCases + ComplexTestCases];
    Initialize<fadbadVar>(FADBADTests);
    fadbadVar independentArgs[DataInSize];
    real optBypass = 0;
    for (int k = 0; k < iterations; k++)
        for (int t = 0; t < SimpleTestCases; t++) {
            InitializeArgs(independentArgs);
            fadbadVar FADBADResult = FADBADTests[t]->TestFunction(independentArgs);
            optBypass += FADBADResult.x().x();
        }
    t = clock() - t;
    printf("  Performance[Simple]: %d ms. Checksum: %.0f\n", t, fmod(optBypass, real(10.0)));
    t = clock();
    optBypass = 0;
    for (int k = 0; k < iterations; k++)
        for (int t = 0; t < ComplexTestCases; t++) {
            InitializeArgs(independentArgs);
            fadbadVar FADBADResult = FADBADTests[SimpleTestCases + t]->TestFunction(independentArgs);
            optBypass += FADBADResult.x().x();
        }
    t = clock() - t;
    printf("  Performance[Complex]: %d ms. Checksum: %.0f\n", t, fmod(optBypass, real(10.0)));
    Finalize<fadbadVar>(FADBADTests);
};

#endif  // FADBADTEST_H
