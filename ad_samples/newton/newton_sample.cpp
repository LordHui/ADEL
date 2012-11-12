#include <stdio.h>
#include <cmath>

#include "ad_taylor_newton_optimization.h"

struct function_1_t
{
	template<typename valueT>
	inline static valueT function(const valueT (&x)[6])
	{
		valueT r = (x[0] * x[0] * x[0] * x[0] - 16) +  (x[1] * x[1] - 16) * (x[2] * x[2] - 9) * (x[5] * x[5] - 25) * (x[4] * x[4] - 4) + (x[3] * x[3] - 9);
		return r * r;
	}
};

struct function_2_t
{
	template<typename valueT>
	inline static valueT function(const valueT (&x)[3])
	{
		int NVARS = 3;
		double a[NVARS] = {2, 3, 4};
		valueT r = 0; 
		for(int i = 0; i < NVARS; i++)
		{
			r += (x[i] - a[i]) * (x[i] - a[i]); 
		}
		return  r + 6;
	}
};

struct function_3_t
{
	template<typename valueT>
	inline static valueT function(const valueT (&x)[6])
	{
		const int NVARS = 6;
		double a[NVARS] = {2, 3, 4, 11, 23, 46};
		valueT r = 0; 
		for(int i = 0; i < NVARS; i++)
		{
			r += (x[i] - a[i]) * (x[i] - a[i]); 
		}
		return  r + 6;
	}
};

struct function_4_t
{
	template<typename valueT>
	inline static valueT function(const valueT (&x)[6])
	{
		const int NVARS = 6;
		double a[NVARS] = {0.2, 0.3, 0.4, 0.11, 0.23, 0.46};
		valueT r = 0; 
		for(int i = 0; i < NVARS; i++)
		{
			r += (sin(x[i]) + a[i]) * (x[i] + a[i]); 
		}
		return  r + 6;
	}
};

struct function_5_t
{
	template<typename valueT>
	inline static valueT function(const valueT (&x)[6])
	{
		const int NVARS = 6;
		double a[NVARS] = {0.2, 0.3, 0.4, 0.11, 0.23, 0.46};
		valueT r = 0; 
		for(int i = 0; i < NVARS; i++)
		{
			r += (cos(x[i]) - a[i]) * (cos(x[i]) - a[i]); 
		}
		return  r + 6;
	}
};

struct function_6_t
{
	template<typename valueT>
	inline static valueT function(const valueT (&x)[6])
	{
		const int NVARS = 6;
		double a[NVARS] = {0.2, 0.3, 0.4, 0.11, 0.23, 0.46};
		valueT r = 0; 
		for(int i = 0; i < NVARS; i++)
		{
			r += exp(x[i]) * (cos(x[i]) + sin(x[i]) * exp(x[i]) - a[i]) * (cos(x[i]) - a[i]); 
		}
		return  r + 6;
	}
};

template<typename realT, int NVARS>
void show_solution(const realT solution[NVARS])
{
	printf("Newton solution:\n");
	for(int i = 0; i < NVARS; i++)
	{
		printf("%E ; ", solution[i]);
	}
	printf("\n");
}

int main(int argc, char*argv)
{
	const int NVAR = 6;
	const double EPSILON = 1e-12;

	double probe[NVAR] = {100, 10, 100, 10, 10, 10};

	newton_optimizator<double, NVAR, 100000, function_6_t>(probe, EPSILON);
	show_solution<double, NVAR>(probe);
	newton_optimizator<double, NVAR, 100000, function_4_t>(probe, EPSILON);
	show_solution<double, NVAR>(probe);
	newton_optimizator<double, NVAR, 100000, function_3_t>(probe, EPSILON);
	show_solution<double, NVAR>(probe);

}