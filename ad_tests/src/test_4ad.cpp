#include <iostream>
#include <cmath>

#include "test_common.h"
#include "test_4ad.h"

#include "../../ad_lib/include/ad_taylor.h"
#include "../../ad_lib/include/ad_taylor_derivative.h"

//#include "../../ad_lib/include/ad_derivative.h"

const int C_ND = 5;

struct func1_test4
{
	template<typename realT>
	static realT func(realT x)
	{
		return log(x);
	}

	static const char* name()
	{
		return "Func1: log(x)";
	}

	static int get_expected_results(const double **data_ref)
	{
		const int num_tests = 2;
		static const double data[num_tests][2+C_ND] = 
		{
			//x,   f,          f1,  f2,    f3,   f4,     f5
			{ 1.0, 0.0,        1.0, -1.0,  2.0,  -6.0,   24.0 },
			{ 2.0, 0.69314718, 0.5, -0.25, 0.25, -0.375, 0.75 }
		};

		*data_ref = (double*)data;
		return num_tests;
	}
};

struct func2_test4
{
	template<typename realT>
	static realT func(realT x)
	{
		return 2*x*x*x*x + 3*x*x*x + 4*x*x + 5*x + 6;
	}

	static const char* name()
	{
		return "Func2: 2*x^4 + 3*x^3 + 4*x^2 + 5*x + 6";
	}

	static int get_expected_results(const double **data_ref)
	{
		const int num_tests = 2;
		static const double data[num_tests][2+C_ND] = 
		{
			//x,   f,    f1,   f2,   f3,   f4,   f5
			{ 0.0, 6.0,  5.0,  8.0,  18.0, 48.0, 0.0 },
			{ 1.0, 20.0, 30.0, 50.0, 66.0, 48.0, 0.0 }
		};

		*data_ref = (double*)data;
		return num_tests;
	}
};


template<class FUNC>
bool test_tailor4(double h)
{
	printf("  test_tailor4 for %s\n", FUNC::name());
	double h2 = h*h;
	//
	const double *data;
	const int num_inputs = FUNC::get_expected_results(&data);
	bool result = true;
	//
	fast_derivative_calculator<double, C_ND> fdc;

	//
	for(int i=0; i<num_inputs; i++)
	{
		int idx = i*(2+C_ND);
		double x = data[idx];
		ad_taylor_var_t<double, C_ND, 1> ax, ay;
		//
		ax = x;
		for (int i=1; i<=C_ND; i++) ax.set(1, i, h);
		ay = FUNC::func(ax);
		//
		double fn[C_ND];
		fdc.compute_derivatives(ay, 1, h, fn);
		verify_value2(result, x, "nf1",  data[idx+2], fn[0]);
		verify_value2(result, x, "nf2",  data[idx+3], fn[1]);
		verify_value2(result, x, "nf3",  data[idx+4], fn[2]);
		verify_value2(result, x, "nf4",  data[idx+5], fn[3]);
		verify_value2(result, x, "nf5",  data[idx+6], fn[4]);

		//
		double f = ay.v;
		double f1 = 1* ay.get(1, 1) / h;
		double f2 = 2*(ay.get(1, 2) - ay.get(1, 1)) / (h*h);
		double f3 = 2*3*(ay.get(1, 3) - 2*ay.get(1, 2) + ay.get(1, 1)) / (h*h*h);
		double f4 = 2*3*4*(ay.get(1, 4) - 3*ay.get(1, 3) + 3*ay.get(1, 2) - ay.get(1, 1)) / (h*h*h*h);
		//
		verify_value2(result, x, "f",  data[idx+1], f);
		verify_value2(result, x, "f1",  data[idx+2], f1);
		verify_value2(result, x, "f2",  data[idx+3], f2);
		verify_value2(result, x, "f3",  data[idx+4], f3);
		verify_value2(result, x, "f4",  data[idx+5], f4);
		//
	}
	return result;
}


bool test_4ad()
{
	bool result = true;
	//
	result = test_tailor4<func1_test4>(0.1) && result;
	result = test_tailor4<func2_test4>(0.1) && result;
	//
	//
	return result;
}

