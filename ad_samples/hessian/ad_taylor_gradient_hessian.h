#include "../../ad_lib/include/ad_taylor.h"
#include "../../ad_lib/include/ad_taylor_derivative.h"

template<typename realT, int NVARS, class FUNC>
struct ad_taylor_partial_series_t
{

	typedef ad_taylor_var_t<realT, 2, NVARS * (NVARS + 1) / 2> taylor_t;
	const int directions;
	taylor_t x[NVARS];

	ad_taylor_partial_series_t() : directions(NVARS * (NVARS + 1) / 2) 
	{
		for(int i = 1; i <= 2; i++)
		{
			int dim = 1;
			for(int j = 0; j < NVARS; j++)
			{
				for(int k = 0; k < directions; k++)
				{
					x[j].set(k + 1, i, 0);
				}
			}
			for(int j = 0; j < NVARS; j++)
			{
				for(int k = 0; k < NVARS - j; k++)
				{
					x[j    ].set(dim,   i, 1);
					x[j + k].set(dim++, i, 1);
				}
			}
		}
	}

	taylor_t compute_ad_taylor_series(const realT (&args)[NVARS])
	{
		
		for(int i = 0; i < NVARS; i++)	x[i].v = args[i];
		return FUNC::function<taylor_t>(x);
	}
};

template<typename realT, int NVARS, class FUNC>
struct ad_taylor_grad_and_hessian_t : public ad_taylor_partial_series_t<realT, NVARS, FUNC>
{
	realT value;
	realT gradient[NVARS];
	realT hessian[NVARS][NVARS];

	void compute(const realT (&args)[NVARS])
	{
		
		taylor_t y = compute_ad_taylor_series(args);

		value = y.v;

		int idx_direction;

		idx_direction = 0;
		for(int i = 0; i < NVARS; i++)
		{
			gradient[i] = y.get(1, 2 * idx_direction + 1);
			idx_direction += NVARS - i;
		}

		idx_direction = 0;
		for(int i = 0; i < NVARS; i++)
		{
			hessian[i][i] = 2 * (y.get(1, 2 * idx_direction + 2) - gradient[i]);
			idx_direction += NVARS - i;
		}
		idx_direction = 0;
		for(int i = 0; i < NVARS; i++)
		{
			for(int j = 1; j < NVARS - i; j++)
				hessian[i][i + j] = hessian[i + j][i] = y.get(1, 2 * (idx_direction + j) + 2) - y.get(1, 2 * (idx_direction + j) + 1) - (hessian[i][i] + hessian[i + j][i + j]) / 2;
			idx_direction += NVARS - i;
		}
	}
};

