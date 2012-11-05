#pragma once

namespace ns
{

//////////////////////////////// aux helpers ////////////////////////////

template<typename realT, int ND, int LHS, int RHS, int CNT>
struct ad_mad_helper
{
	AD_MOD static void unroll(realT &sum, const ad_var_holder<realT, ND> &l, const ad_var_holder<realT, ND> &r)
	{
		sum += l.D[LHS-1]*r.D[RHS-1];
		ad_mad_helper<realT, ND, LHS+1, RHS-1, CNT-1>::unroll(sum, l, r);
	}
};

template<typename realT, int ND, int LHS, int RHS>
struct ad_mad_helper<realT, ND, LHS, RHS, 0>
{
	AD_MOD static void unroll(realT &sum, const ad_var_holder<realT, ND> &l, const ad_var_holder<realT, ND> &r)
	{
	}
};

template<typename realT, int ND, int LHS, int RHS>
struct ad_mad_helper<realT, ND, LHS, RHS, -1>
{
	AD_MOD static void unroll(realT &sum, const ad_var_holder<realT, ND> &l, const ad_var_holder<realT, ND> &r)
	{
	}
};


template<typename realT, int C>
struct ad_const_helper
{
	AD_MOD static realT mulc(const realT &v)
	{
		return v * C;
	}

	AD_MOD static realT divc(const realT &v)
	{
		return v / C;
	}
};

template<typename realT>
struct ad_const_helper<realT, 1>
{
	AD_MOD static realT mulc(const realT &v)
	{
		return v;
	}

	AD_MOD static realT divc(const realT &v)
	{
		return v;
	}
};

}
