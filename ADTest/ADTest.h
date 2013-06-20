#ifndef ADTEST_H
#define ADTEST_H

#include "..\ReverseAD\ReverseAD.h"
#include "..\ad_lib\include\ad_taylor.h"

#include "TestFunctions.h"
#include "Numerics.h"

typedef ADVariable<2, DataInSize> ADReverse;
typedef ad_taylor_var_t < real, 2, DataInSize* (DataInSize + 1) / 2 > ADTaylor;

struct ADResult {
    real Value;
    real Gradient[DataInSize];
    real Hessian[DataInSize* DataInSize];
};

template<typename ADType>
void ADCorrectnessTest() {
    FunctionBase<real>* numericTests[TotalTestCases];
    FunctionBase<ADType>* ADTests[TotalTestCases];
    Initialize<real>(numericTests);
    Initialize<ADType>(ADTests);
    ADType args[DataInSize];
    InitializeArgs<ADType>(args);

    int passedCounter = 0;
    for (int t = 0; t < TotalTestCases; t++) {
        ADResult adResult;
        Compute<ADType>(ADTests[t], args, adResult);
        real valueExpected = numericTests[t]->TestFunction(realArgs);
        bool passed = true;
        passed &= Compare(valueExpected, adResult.Value, "Value", t);
        for (int i = 0; i < DataInSize; i++)
            passed &= FirstOrderNumeric(numericTests[t], realArgs, i, adResult.Gradient[i], t);
        for (int i = 0; i < DataInSize; i++)
            for (int j = 0; j < DataInSize; j++)
                passed &= SecondOrderNumeric(numericTests[t], realArgs, i, j, adResult.Hessian[i * DataInSize + j], t);
        if (passed)
            passedCounter++;
    }
    printf("  Correctness: %d/%d.\n", passedCounter, TotalTestCases);
    Finalize<ADType>(ADTests);
    Finalize<real>(numericTests);
};

template<typename ADType>
void InitializeArgs(ADType(&x)[DataInSize]) {}

template<>
void InitializeArgs<ADReverse>(ADReverse(&args)[DataInSize]) {
    for (int r = 0; r < DataInSize; r++) {
        args[r].Value = realArgs[r];
        args[r].ID = r;
        args[r].Base = true;
    }
}

template<>
void InitializeArgs<ADTaylor>(ADTaylor(&args)[DataInSize]) {
    const int directions = DataInSize * (DataInSize + 1) / 2;
    for (int i = 1; i <= 2; i++) {
        int dim = 1;
        for (int j = 0; j < DataInSize; j++)
            for (int k = 0; k < directions; k++)
                args[j].set(k + 1, i, 0);
        for (int j = 0; j < DataInSize; j++)
            for (int k = 0; k < DataInSize - j; k++) {
                args[j    ].set(dim,   i, 1);
                args[j + k].set(dim++, i, 1);
            }
    }
    for (int i = 0; i < DataInSize; i++) args[i].v = realArgs[i];
}

template<typename ADType>
void Compute(FunctionBase<ADType>* function, ADType(&args)[DataInSize], ADResult& result) {}

template<>
void Compute<ADReverse>(FunctionBase<ADReverse>* function, ADReverse(&args)[DataInSize], ADResult& result) {
    ADReverse tmpRes = function->TestFunction(args);
    result.Value = tmpRes.Value;
    for (int r = 0; r < DataInSize; r++)
        result.Gradient[r] = tmpRes.Data[r];
    for (int r = 0; r < DataInSize * DataInSize; r++)
        result.Hessian[r] = tmpRes.Data[DataInSize + r];
}

template<>
void Compute<ADTaylor>(FunctionBase<ADTaylor>* function, ADTaylor(&args)[DataInSize], ADResult& result) {
    ADTaylor tmpRes = function->TestFunction(args);
    result.Value = tmpRes.v;
    int idx_direction = 0;
    for (int i = 0; i < DataInSize; i++) {
        result.Gradient[i] = tmpRes.get(1, 2 * idx_direction + 1);
        idx_direction += DataInSize - i;
    }
    idx_direction = 0;
    for (int i = 0; i < DataInSize; i++) {
        result.Hessian[i * DataInSize + i] = 2 * (tmpRes.get(1, 2 * idx_direction + 2) - result.Gradient[i]);
        idx_direction += DataInSize - i;
    }
    idx_direction = 0;
    for (int i = 0; i < DataInSize; i++) {
        for (int j = 1; j < DataInSize - i; j++)
            result.Hessian[i * DataInSize + i + j] = result.Hessian[(i + j) * DataInSize + i] = tmpRes.get(1, 2 * (idx_direction + j) + 2) - tmpRes.get(1, 2 * (idx_direction + j) + 1) - (result.Hessian[i * DataInSize + i] + result.Hessian[(i + j) * DataInSize + i + j]) / 2;
        idx_direction += DataInSize - i;
    }
}

template<typename ADType>
void ADPerformanceTest(int iterations) {
    clock_t time = clock();
    FunctionBase<ADType>* ADTests[TotalTestCases];
    Initialize<ADType>(ADTests);
    ADType args[DataInSize];
    InitializeArgs<ADType>(args);

    real optBypass = 0;
    for (int k = 0; k < iterations; k++) {
        for (int t = 0; t < SimpleTestCases; t++) {
            ADResult adResult;
            Compute<ADType>(ADTests[t], args, adResult);
            optBypass += adResult.Value;
        }
    }
    time = clock() - time;
    printf("  Performance[Simple]: %d ms. Checksum: %.0f\n", time, fmod(optBypass, real(10.0)));
    time = clock();
    optBypass = 0;
    for (int k = 0; k < iterations; k++) {
        for (int t = 0; t < ComplexTestCases; t++) {
            ADResult adResult;
            Compute<ADType>(ADTests[SimpleTestCases + t], args, adResult);
            optBypass += adResult.Value;
        }
    }
    time = clock() - time;
    printf("  Performance[Complex]: %d ms. Checksum: %.0f\n", time, fmod(optBypass, real(10.0)));
    time = clock();
    optBypass = 0;
    for (int k = 0; k < iterations; k++) {
        for (int t = 0; t < LoopTestCases; t++) {
            ADResult adResult;
            Compute<ADType>(ADTests[SimpleTestCases + ComplexTestCases + t], args, adResult);
            optBypass += adResult.Value;
        }
    }
    time = clock() - time;
    printf("  Performance[Loop]: %d ms. Checksum: %.0f\n", time, fmod(optBypass, real(10.0)));
    Finalize<ADType>(ADTests);
};

#endif  // ADTEST_H
