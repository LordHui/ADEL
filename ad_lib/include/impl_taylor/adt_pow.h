#pragma once

#include "adt_define.h"
#include "adt_helper.h"
#include "adt_ops.h"
#include "adt_var.h"

namespace ns
{

template<typename realT, int ND, int NV, int ID, int IV = NV>
struct ad_fpe_v_helper
{
	AD_MOD static void assign(ad_holder<realT, ND, NV> &r, const realT &a)
	{
		ad_fpe_v_helper<realT, ND, NV, ID, IV-1>::assign(r, a);
		r.V[IV-1].D[ID-1] = a;
	}
};

template<typename realT, int ND, int NV, int ID>
struct ad_fpe_v_helper<realT, ND, NV, ID, 0>
{
	AD_MOD static void assign(ad_holder<realT, ND, NV> &r, const realT &a)
	{
	}
};

template<typename realT, int ND, int NV, int ID = ND>
struct ad_fpe_helper
{
	AD_MOD static void unroll(ad_holder<realT, ND, NV> &r, const realT &b, const realT &fpe0, const realT &fpe1)
	{
		ad_fpe_helper<realT, ND, NV, ID-1>::unroll(r, b, fpe0, fpe1);
		realT expDiff = b - ID;
		if (expDiff > 1)
			ad_fpe_v_helper<realT, ND, NV, ID>::assign(r, 0);
		if (expDiff > 0 && expDiff < 1)
			ad_fpe_v_helper<realT, ND, NV, ID>::assign(r, fpe1);
		if (expDiff < 0)
			ad_fpe_v_helper<realT, ND, NV, ID>::assign(r, fpe0);
	}
};

template<typename realT, int ND, int NV>
struct ad_fpe_helper<realT, ND, NV, 0>
{
	AD_MOD static void unroll(ad_holder<realT, ND, NV> &r, const realT &b, const realT &fpe0, const realT &fpe1)
	{
	}
};

/////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename realT, int ND>
struct ad_op_pow_mul_direct
{
//r.d1_1 = 0.0;
//r.d1_4 = a.d1_1 * a.d1_3 + a.d1_2 * a.d1_2 + a.d1_3 * a.d1_1;
	template<int ID>
	AD_MOD static void impl(ad_var_holder<realT, ND> &r, const ad_var_holder<realT, ND> &a)
	{
		realT sum = 0;
		if (ID > 1)
		{
			sum = a.D[0] * a.D[ID-1-1];
			ad_mad_helper<realT, ND, 2, ID-2, ID-2>::unroll(sum, a, a);
		}
		r.D[ID-1] = sum;
	}
};

template<typename realT, int ND>
struct ad_op_pow_mul_reverse
{
//r.d1_4 = r.v * a.d1_3 + r.d1_1 * a.d1_2 + r.d1_2 * a.d1_1 + r.d1_3 * a.v;
//r.d1_1 = r.v * a.v;
	template<int ID>
	AD_MOD static void impl(ad_var_holder<realT, ND> &r, const ad_var_holder<realT, ND> &a, const realT &rv, const realT &av)
	{
		realT sum = rv * a.D[ID-1-1];
		ad_mad_helper<realT, ND, 1, ID-2, ID-2>::unroll(sum, r, a);
		r.D[ID-1] = sum + r.D[ID-1-1] * av;
	}
};

template<typename realT, int ND>
struct ad_op_pow_final
{
//s.d1_1 = 1 * a.d1_1;
//t.d1_1 = recip * (b * (r.v * s.d1_1) - (0.0));
//r.d1_1 = t.d1_1 / 1;

//s.d1_4 = 4 * a.d1_4;
//t.d1_4 = recip * (b * (r.v * s.d1_4 + r.d1_1 * s.d1_3 + r.d1_2 * s.d1_2 + r.d1_3 * s.d1_1) - (a.d1_1 * t.d1_3 + a.d1_2 * t.d1_2 + a.d1_3 * t.d1_1));
//r.d1_4 = t.d1_4 / 4;
	template<typename CT, int ID>
	AD_MOD static void impl(ad_var_holder<realT, ND> &r, ad_var_holder<realT, ND> &t, ad_var_holder<realT, ND> &s, const ad_var_holder<realT, ND> &ad, const realT &rv, const realT &recip, const CT &b)
	{
		s.D[ID-1] = ad_const_helper<realT, ID>::mulc(ad.D[ID-1]);
		//
		realT sum1 = rv*s.D[ID-1];
		ad_mad_helper<realT, ND, 1, ID-1, ID-1>::unroll(sum1, r, s);
		//
		realT sum2 = 0;
		ad_mad_helper<realT, ND, 1, ID-1, ID-1>::unroll(sum2, ad, t);
		//
		realT sum = b*sum1 - sum2;
		t.D[ID-1] = sum = recip*sum;
		r.D[ID-1] = ad_const_helper<realT, ID>::divc(sum);
	}
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename realT, int ND, int NV>
struct ad_pow_helper
{
	AD_MOD static void internal_pow0i(ad_t &r, const ad_t &a, int b)
	{
		if (b == 1)
		{
			ad_v_helper<realT, ND, NV, ad_assign<realT, ND>>::unroll(r.AD, a.AD);
		}
		else
		{
			ad_v_helper<realT, ND, NV, ad_op_pow_mul_direct<realT, ND>>::unroll(r.AD, a.AD);
			for(int j=3; j<=b; j+=1)
			{
				ad_v_helper<realT, ND, NV, ad_op_pow_mul_reverse<realT, ND>>::unroll_reverse(r.AD, a.AD, r.v, a.v);
			}
		}
	}
};

template<typename realT>
AD_MOD realT makeFPE(const realT& n, const realT& d) 
{
	return n / d;
}


}
/////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////
AD_TEMPL AD_MOD_NOINLINE ad_t pow(const ad_t& a, const ad_t& b)
{
	return exp(b * log(a));
}

AD_TEMPL AD_MOD_NOINLINE  ad_t pow(const realT& a, const ad_t& b)
{
	return exp(b * log(a));
}

AD_TEMPL AD_MOD_NOINLINE  ad_t pow(const ad_t& a, const realT& b)
{
	ad_t r;
	r.v = pow(a.v, b);

	if (a.v == 0)
	{
		const realT fpe0 = ns::makeFPE<realT>(0, 0);
		if (b <= 0)
		{
			ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, fpe0);
		}
		else
		{
			const realT fpe1 = ns::makeFPE<realT>(1, 0);
			if ((b - floor(b)) != 0)
			{
				ns::ad_fpe_helper<realT, ND, NV>::unroll(r.AD, b, fpe0, fpe1);
			}
			else
			{
				ns::ad_pow_helper<realT, ND, NV>::internal_pow0i(r, a, int(b));
			}
		}
	}
	else
	{
		ns::ad_var_holder<realT, ND> s, t;
		realT recip = 1 / a.v;
		ns::ad_v_helper<realT, ND, NV, ns::ad_op_pow_final<realT, ND>>::unroll(r.AD, t, s, a.AD, r.v, recip, b);
	}

	return r;
}


AD_TEMPL AD_MOD_NOINLINE  ad_t pow(const ad_t& a, const int& b)
{
	ad_t r;
	r.v = pow(a.v, b);

	if (a.v == 0)
	{
		const realT fpe0 = ns::makeFPE<realT>(0, 0);
		if (b <= 0)
		{
			ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, fpe0);
		}
		else
		{
			ns::ad_pow_helper<realT, ND, NV>::internal_pow0i(r, a, b);
		}
	}
	else
	{
		ns::ad_var_holder<realT, ND> s, t;
		realT recip = 1 / a.v;
		ns::ad_v_helper<realT, ND, NV, ns::ad_op_pow_final<realT, ND>>::unroll(r.AD, t, s, a.AD, r.v, recip, b);
	}

	return r;
}