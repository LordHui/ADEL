#ifndef TAYLORADTEST_H
#define TAYLORADTEST_H

#include "TestFunctions.h"
#include "Numerics.h"

typedef ad_taylor_var_t < real, 2, DataInSize* (DataInSize + 1) / 2 > taylor_t;

void TaylorADCorrectnessTest() {
    FunctionBase<real>* numericTests[SimpleTestCases + ComplexTestCases];
    FunctionBase<taylor_t>* forwardADTests[SimpleTestCases + ComplexTestCases];
    Initialize<real>(numericTests);
    Initialize<taylor_t>(forwardADTests);
    ad_taylor_grad_and_hessian_t<real, DataInSize> test_pd;
    int passedCounter = 0;
    for (int t = 0; t < SimpleTestCases + ComplexTestCases; t++) {
        test_pd.compute(realArgs, forwardADTests[t]);
        real valueExpected = numericTests[t]->TestFunction(realArgs);
        bool passed = true;
        passed &= Compare(valueExpected, test_pd.value, "Value", t);
        for (int i = 0; i < DataInSize; i++)
            passed &= FirstOrderNumeric(numericTests[t], realArgs, i, test_pd.gradient[i], t);
        for (int i = 0; i < DataInSize; i++)
            for (int j = 0; j < DataInSize; j++)
                passed &= SecondOrderNumeric(numericTests[t], realArgs, i, j, test_pd.hessian[i][j], t);
        if (passed)
            passedCounter++;
    }
    printf("  Correctness: %d/%d.\n", passedCounter, SimpleTestCases + ComplexTestCases);
    Finalize<taylor_t>(forwardADTests);
    Finalize<real>(numericTests);
};

void TaylorADPerformanceTest(int iterations) {
    clock_t t = clock();
    FunctionBase<taylor_t>* forwardADTests[SimpleTestCases + ComplexTestCases];
    Initialize<taylor_t>(forwardADTests);
    ad_taylor_grad_and_hessian_t<real, DataInSize> test_pd;
    real optBypass = 0;
    for (int k = 0; k < iterations; k++)
        for (int t = 0; t < SimpleTestCases; t++) {
            test_pd.compute(realArgs, forwardADTests[t]);
            optBypass += test_pd.value;
        }
    t = clock() - t;
    printf("  Performance[Simple]: %d ms. Checksum: %.0f\n", t, fmod(optBypass, real(10.0)));
    t = clock();
    optBypass = 0;
    for (int k = 0; k < iterations; k++)
        for (int t = 0; t < ComplexTestCases; t++) {
            test_pd.compute(realArgs, forwardADTests[SimpleTestCases + t]);
            optBypass += test_pd.value;
        }
    t = clock() - t;
    printf("  Performance[Complex]: %d ms. Checksum: %.0f\n", t, fmod(optBypass, real(10.0)));
    Finalize<taylor_t>(forwardADTests);
};

#endif  // TAYLORADTEST_H
