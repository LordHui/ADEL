#pragma once

#include <stdio.h>
#include <math.h>

inline bool verify_value(bool &total_res, const char *name, double expected, double actual)
{
	if (fabs(expected - actual) < 1.0e-7)
		return true;

	printf("      %s: expected=%f, actual=%f\n", name, expected, actual);
	total_res = false;
	return false;
}

inline bool verify_value2(bool &total_res, double x, const char *name, double expected, double actual)
{
	if (fabs(expected - actual) < 1.0e-7)
		return true;

	printf("      x=%f %s: expected=%f, actual=%f\n", x, name, expected, actual*100);
	total_res = false;
	return false;
}

inline void verify_test_result(bool &total_res, const char *name, bool res)
{
	if (res) 
		printf("%s  -  PASSED\n", name);
	else 
	{
		total_res = false;
		printf("%s  -  FAILED\n", name);
	}
}

