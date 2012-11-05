#pragma once

#include "adt_define.h"
#include "adt_helper.h"
#include "adt_aux.h"

namespace ns
{

template<typename realT, int ND>
struct ad_assign
{
	template<int ID>
	AD_MOD static void impl(ad_var_holder<realT, ND> &r, const ad_var_holder<realT, ND> &a)
	{
		r.D[ID-1] = a.D[ID-1];
	}

	template<int ID>
	AD_MOD static void impl(volatile ad_var_holder<realT, ND> &r, const volatile ad_var_holder<realT, ND> &a)
	{
		r.D[ID-1] = a.D[ID-1];
	}

	template<typename CT, int ID>
	AD_MOD static void impl(ad_var_holder<realT, ND> &r, const CT &a)
	{
		r.D[ID-1] = a;
	}

	template<typename CT, int ID>
	AD_MOD static void impl(volatile ad_var_holder<realT, ND> &r, const CT &a)
	{
		r.D[ID-1] = a;
	}
};


////////////////////////////////////////////////////////////////////////////////////////////////

template<typename realT, int ND>
struct ad_assign_neg
{
	template<int ID>
	AD_MOD static void impl(ad_var_holder<realT, ND> &r, const ad_var_holder<realT, ND> &a)
	{
		r.D[ID-1] = -a.D[ID-1];
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////

template<typename realT, int ND>
struct ad_abs
{
	template<int ID>
	AD_MOD static void impl(ad_var_holder<realT, ND> &r, const ad_var_holder<realT, ND> &ad)
	{
		realT a = ad.D[ID-1];
		r.D[ID-1] = a < 0 ? -a : a;
	}
};


////////////////////////////////////////////////////////////////////////////////////////////////

template<typename realT, int ND>
struct ad_add
{
	template<int ID>
	AD_MOD static void impl(ad_var_holder<realT, ND> &r, const ad_var_holder<realT, ND> &a, const ad_var_holder<realT, ND> &b)
	{
		r.D[ID-1] = a.D[ID-1] + b.D[ID-1];
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////

template<typename realT, int ND>
struct ad_inc
{
	template<int ID>
	AD_MOD static void impl(ad_var_holder<realT, ND> &r, const ad_var_holder<realT, ND> &b)
	{
		r.D[ID-1] += b.D[ID-1];
	}

	template<int ID>
	AD_MOD static void impl(volatile ad_var_holder<realT, ND> &r, const volatile ad_var_holder<realT, ND> &b)
	{
		r.D[ID-1] += b.D[ID-1];
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////


template<typename realT, int ND>
struct ad_dec
{
	//AD_MOD static void impl(ad_var_holder<realT, ND> &r, const ad_var_holder<realT, ND> &b);
	template<int ID>
	AD_MOD static void impl(volatile ad_var_holder<realT, ND> &r, const volatile ad_var_holder<realT, ND> &b)
	{
		r.D[ID-1] -= b.D[ID-1];
	}
};


////////////////////////////////////////////////////////////////////////////////////////////////

template<typename realT, int ND>
struct ad_sub
{
	template<int ID>
	AD_MOD static void impl(ad_var_holder<realT, ND> &r, const ad_var_holder<realT, ND> &ad, const ad_var_holder<realT, ND> &bd)
	{
		r.D[ID-1] = ad.D[ID-1] - bd.D[ID-1];
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////

template<typename realT, int ND>
struct ad_mul
{
	template<int ID>
	AD_MOD static void impl(ad_var_holder<realT, ND> &r, const ad_var_holder<realT, ND> &ad, const ad_var_holder<realT, ND> &bd, const realT &av, const realT &bv)
	{
		realT sum = av * bd.D[ID-1];
		ad_mad_helper<realT, ND, 1, ID-1, ID-1>::unroll(sum, ad, bd);
		sum += ad.D[ID-1] * bv;
		r.D[ID-1] = sum;
	}

	template<typename CT, int ID>
	AD_MOD static void impl(ad_var_holder<realT, ND> &r, const ad_var_holder<realT, ND> &ad, const CT &b)
	{
		r.D[ID-1] = ad.D[ID-1] * b;
	}
};


////////////////////////////////////////////////////////////////////////////////////////////////

template<typename realT, int ND>
struct ad_div
{
	template<int ID>
	AD_MOD static void impl(ad_var_holder<realT, ND> &r, const ad_var_holder<realT, ND> &ad, const ad_var_holder<realT, ND> &bd, const realT &recip, const realT &rv)
	{
		realT sum = rv * bd.D[ID-1];
		ad_mad_helper<realT, ND, 1, ID-1, ID-1>::unroll(sum, r, bd);
		sum = ad.D[ID-1] - sum;
		r.D[ID-1] = recip * sum;
	}

	template<typename CT, int ID>
	AD_MOD static void impl(ad_var_holder<realT, ND> &r, const ad_var_holder<realT, ND> &ad, const CT &b)
	{
		r.D[ID-1] = ad.D[ID-1] / b;
	}

	template<typename CT, int ID>
	AD_MOD static void impl(ad_var_holder<realT, ND> &r, const CT &rv, const ad_var_holder<realT, ND> &bd)
	{
		realT sum = rv * bd.D[ID-1];
		ad_mad_helper<realT, ND, 1, ID-1, ID-1>::unroll(sum, r, bd);
		r.D[ID-1] = -rv * sum;
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////


template<typename realT, int ND>
struct ad_sqrt
{
	template<typename CT, int ID>
	AD_MOD static void impl(ad_var_holder<realT, ND> &r, const CT &recip, const ad_var_holder<realT, ND> &ad)
	{
		realT sum;
		if (ID > 1)
		{
			sum = r.D[0] * r.D[ID-1-1];
			ad_mad_helper<realT, ND, 2, ID-2, ID-2>::unroll(sum, r, r);
			sum = ad.D[ID-1] - sum;
		}
		else
		{
			sum = ad.D[0];
		}
		r.D[ID-1] = recip * sum;
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////

template<typename realT, int ND>
struct ad_exp
{
	template<int ID>
	AD_MOD static void impl(ad_var_holder<realT, ND> &r, ad_var_holder<realT, ND> &s, const ad_var_holder<realT, ND> &ad, const realT &rv)
	{
		s.D[ID-1] = ad_const_helper<realT, ID>::mulc(ad.D[ID-1]);
		realT sum = rv * s.D[ID-1];
		ad_mad_helper<realT, ND, 1, ID-1, ID-1>::unroll(sum, s, r);
		r.D[ID-1] = ad_const_helper<realT, ID>::divc(sum);
	}
};


////////////////////////////////////////////////////////////////////////////////////////////////

template<typename realT, int ND>
struct ad_log
{
	template<int ID>
	AD_MOD static void impl(ad_var_holder<realT, ND> &r, ad_var_holder<realT, ND> &t, const ad_var_holder<realT, ND> &ad, const realT &recip)
	{
		realT sum;
		if (ID > 1)
		{
			sum = t.D[0] * ad.D[ID-1-1];
			ad_mad_helper<realT, ND, 2, ID-2, ID-2>::unroll(sum, t, ad);
			sum = ad_const_helper<realT, ID>::mulc(ad.D[ID-1]) - sum;
		}
		else
		{
			sum = ad.D[0];
		}
		t.D[ID-1] = sum = recip * sum;
		r.D[ID-1] = ad_const_helper<realT, ID>::divc(sum);
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////

template<typename realT, int ND>
struct ad_sincos
{
//t.d1_4 = 4 * a.d1_4;
//c.d1_4 = -(t.d1_4 * s.v     + t.d1_1 * s.d1_3 + t.d1_2 * s.d1_2 + t.d1_3 * s.d1_1);
//s.d1_4 =  (t.d1_4 * c.v     + t.d1_1 * c.d1_3 + t.d1_2 * c.d1_2 + t.d1_3 * c.d1_1);
//c.d1_4 = c.d1_4 / 4;
//s.d1_4 = s.d1_4 / 4;

	template<int ID>
	AD_MOD static void impl(ad_var_holder<realT, ND> &s, ad_var_holder<realT, ND> &c, ad_var_holder<realT, ND> &t, const ad_var_holder<realT, ND> &ad, const realT &sv, const realT &cv)
	{
		t.D[ID-1] = ad_const_helper<realT, ID>::mulc(ad.D[ID-1]);
		realT sum;
		//
		sum = t.D[ID-1] * sv;
		ad_mad_helper<realT, ND, 1, ID-1, ID-1>::unroll(sum, t, s);
		c.D[ID-1] = ad_const_helper<realT, ID>::divc(-sum);
		//
		sum = t.D[ID-1] * cv;
		ad_mad_helper<realT, ND, 1, ID-1, ID-1>::unroll(sum, t, c);
		s.D[ID-1] = ad_const_helper<realT, ID>::divc(sum);
	}
};

template<typename realT, int ND>
struct ad_asincos
{
//t.d1_4 = 4 * a.d1_4;
//r.d1_4 = t.d1_4 * h.v +    t.d1_1 * h.d1_3 + t.d1_2 * h.d1_2 + t.d1_3 * h.d1_1;
//r.d1_4 = r.d1_4 / 4;

	template<int ID>
	AD_MOD static void impl(ad_var_holder<realT, ND> &r, ad_var_holder<realT, ND> &t, const ad_var_holder<realT, ND> &h, const ad_var_holder<realT, ND> &ad, const realT &hv)
	{
		t.D[ID-1] = ad_const_helper<realT, ID>::mulc(ad.D[ID-1]);
		realT sum = t.D[ID-1] * hv;
		ad_mad_helper<realT, ND, 1, ID-1, ID-1>::unroll(sum, t, h);
		r.D[ID-1] = ad_const_helper<realT, ID>::divc(sum);
	}
};


template<typename realT, int ND>
struct ad_atan
{
//s.d1_4 = 4 * a.d1_4;
//r.d1_4 = 4 * (y.v * a.d1_4);
//r.d1_4 = r.d1_4    +     s.d1_3 * y.d1_1 + s.d1_2 * y.d1_2 + s.d1_1 * y.d1_3;
//r.d1_4 = r.d1_4 / 4;

	template<int ID>
	AD_MOD static void impl(ad_var_holder<realT, ND> &r, ad_var_holder<realT, ND> &s, const ad_var_holder<realT, ND> &y, const ad_var_holder<realT, ND> &ad, const realT &yv)
	{
		s.D[ID-1] = ad_const_helper<realT, ID>::mulc(ad.D[ID-1]);
		realT sum = ad_const_helper<realT, ID>::mulc(yv * ad.D[ID-1]);
		ad_mad_helper<realT, ND, 1, ID-1, ID-1>::unroll(sum, y, s);
		r.D[ID-1] = ad_const_helper<realT, ID>::divc(sum);
	}
};

}
