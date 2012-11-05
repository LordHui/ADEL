#include <iostream>
#include <cmath>

#include "test_common.h"
#include "test_2_10.h"
#include "test_funcs.h"

#include "../../ad_lib/include/ad_taylor.h"
//#include "../../ad_lib/include/ad_taylor_cuda.h"
//#include "../../ad_lib/include/ad_derivative.h"


static const int NUM_TEST_POINTS = 3;
static double C_TEST_POINTS[NUM_TEST_POINTS] = { 0.2, 0.3, 0.4 };

template<class FUNC, class FUNC2>
bool internal_test_tailor_2x10()
{
	bool result = true;
	printf("  test_tailor_2x10 for %s: y=%s\n", FUNC2::name(), FUNC::name());

	for (int pointIdx=0; pointIdx<NUM_TEST_POINTS; pointIdx++)
	{
		const int directions=2;
		const int order=10;

		double myEps=1.E-13;
		double xCoeff[directions][order];
		double yCoeff[directions][order];
		ad_taylor_var_t<double, order, directions> x, y;
		//
		double xp = C_TEST_POINTS[pointIdx];
		//
		for(int i=0; i<directions; i++)
		{ 
			for(int j=0; j<order; j++) 
				xCoeff[i][j]=0;
			xCoeff[i][1]=i*0.3;
		}
 
		// initialize the active input
		x = xp;
		for(int i=0; i<directions; i++) 
		{ 
			for(int j=0; j<order; j++) 
				x.set(i+1,j+1,xCoeff[i][j]);
		} 

		// populate the coefficients with something nontrivial
		x = FUNC2::func_fwd(x);

		// run the identities
		y = FUNC::func(x);

		//
		y = FUNC2::func_rev(y);

		// test the value: 
		verify_value2(result, xp, "y.v", xp, y.v);
		for(int i=0; i<directions; i++) 
		{ 
			for(int j=0; j<order; j++) 
			{
				char buf[100];
				sprintf(buf, "y[%i][%i]", directions, order);
				yCoeff[i][j] = y.get(i+1,j+1);
				verify_value2(result, xp, buf, xCoeff[i][j], yCoeff[i][j]);
			}
		}
	}

	return result;
}

template<class FUNC>
bool test_tailor_2x10()
{
	bool result = true;
	result = internal_test_tailor_2x10<FUNC, FSIN>() && result;
	result = internal_test_tailor_2x10<FUNC, FCOS>() && result;
	result = internal_test_tailor_2x10<FUNC, FLOG>() && result;
	return result;
}

bool test_tailor_2_10()
{
	bool result = true;
	//
	result = test_tailor_2x10<F0>() && result;
	result = test_tailor_2x10<F1>() && result;
	result = test_tailor_2x10<F2>() && result;
	result = test_tailor_2x10<F3>() && result;
	result = test_tailor_2x10<F4>() && result;
	result = test_tailor_2x10<F5>() && result;
	result = test_tailor_2x10<F6>() && result;
	result = test_tailor_2x10<F7>() && result;
	result = test_tailor_2x10<F8>() && result;
	result = test_tailor_2x10<F9>() && result;
	result = test_tailor_2x10<F10>() && result;
	result = test_tailor_2x10<F11>() && result;
	result = test_tailor_2x10<F12>() && result;
	//
	return result;
}
