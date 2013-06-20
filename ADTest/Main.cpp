#include "ADTest.h"

const int baseTestIterations = 1000;

int main() {
    printf("Testing the ADReverse mode\n");
    ADCorrectnessTest<ADReverse>();
    ADPerformanceTest<ADReverse>(baseTestIterations);
    printf("\n");
    printf("Testing the ADTaylor mode\n");
    ADCorrectnessTest<ADTaylor>();
    ADPerformanceTest<ADTaylor>(baseTestIterations);
};
