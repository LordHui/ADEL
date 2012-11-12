#include <stdlib.h>
#include <stdio.h>
#include <cmath>

#include "ad_taylor_gradient_hessian.h"

struct function_1_t
{
	template<typename valueT>
	inline static valueT function(const valueT (&x)[4])
	{
		valueT r = (x[0] * x[0] * x[0]) * (x[1] * x[1]) * (x[2] * x[2]) * (x[3] * x[3]);
		return r;
	}
};

struct function_2_t
{
	template<typename valueT>
	inline static valueT function(const valueT (&x)[4])
	{
		valueT r = (x[0] * x[0] * x[0]) * (x[1] * x[1]) * (x[2] * x[2]);
		return r;
	}
};

struct function_3_t
{
	template<typename valueT>
	inline static valueT function(const valueT (&x)[6])
	{
		valueT r = (x[0] * x[0] * x[0]) * (x[1] * x[1]) * (x[2] * x[2]) + (x[3]) + (x[4] * x[4] * x[4]) * (x[5]);
		return r;
	}
};

template<typename realT, int NVAR, class FUNC>
void run_sample(const realT (&args)[NVAR])
{
	ad_taylor_grad_and_hessian_t<realT, NVAR, FUNC> test_pd;
	test_pd.compute(args);

	printf("Value:\n%G\n", test_pd.value);
	printf("Gradient:\n");
	for(int i = 0; i < NVAR; i++)
	{
		printf("%G ; ", test_pd.gradient[i]);
	}
	printf("\n");
	
	printf("Hessian:\n");
	for(int i = 0; i < NVAR; i++)
	{
		for(int j = 0; j < NVAR; j++)
		{
			printf("%G ; ", test_pd.hessian[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(int argn, char* argv)
{
	double args4[4] = {2, 2, 2, 2};
	run_sample<double, 4, function_1_t>(args4);
	run_sample<double, 4, function_2_t>(args4);

	double args6[6] = {2, 2, 2, 2, 2, 2};
	run_sample<double, 6, function_3_t>(args6);

	return 0;
}