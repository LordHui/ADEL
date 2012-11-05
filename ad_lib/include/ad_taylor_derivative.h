#pragma once

#include "ad_taylor.h"
#include <memory.h>

template<class realT, int ND>
class fast_derivative_calculator
{
private:
	int *m_Cnk;

	int get_Cnk(int n, int k)
	{
	    if (n < k) return 0; 
		if (k == 0 || n==k ) return 1; 
		//
		int v = m_Cnk[n*ND+k];
		if (v == 0)
		{
			m_Cnk[n*ND+k] = v = get_Cnk(n-1,k) + get_Cnk(n-1,k-1);
		}
		return v;
	}

public:
	fast_derivative_calculator()
	{
		size_t sz = sizeof(int*) * (ND*ND);
		m_Cnk = (int*)malloc(sz);
		memset(m_Cnk, 0, sz);
		if (ND >= 2)
		{
			m_Cnk[2*ND+1] = 2;
		}
	}

	~fast_derivative_calculator()
	{
		free(m_Cnk);
	}

	template<int NV>
	void compute_derivatives(const ad_taylor_var_t<realT, ND, NV> &ad, int varIndex, const realT h, realT *result)
	{
		unsigned long long nFact = 1;
		realT hn = 1;
		for (int n=0; n<ND; n++)
		{
			nFact = nFact * (n+1);
			hn = hn*h;
			//
			realT sum = 0;
			for (int k=0; k<=n; k++)
			{
				realT coef = get_Cnk(n, k) * ad.get(varIndex, k+1);
				if (((n-k) & 1) == 0)
					sum += coef;
				else
					sum -= coef;
			}
			result[n] = nFact*sum/hn;
		}
	}

};
