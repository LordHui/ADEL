#pragma once

#include "adt_define.h"
#include "adt_helper.h"
#include "adt_ops.h"
#include "adt_var.h"

//////////////////////////////////////////  Special functions /////////////////////////////////////////////////////////

AD_TEMPL AD_MOD ad_t abs(const ad_t& a)
{
	ad_t r;
	if (a.v != 0.0)
	{
		if (a.v < 0)
			ns::ad_v_helper<realT, ND, NV, ns::ad_assign_neg<realT, ND>>::unroll(r.AD, a.AD);
		else
			ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, a.AD);
	}
	else
	{
		ns::ad_v_helper<realT, ND, NV, ns::ad_abs<realT, ND>>::unroll(r.AD, a.AD);
	}
	r.v = fabs(a.v);
	return r;
}


//////////////////////////////////////////  Math funcs /////////////////////////////////////////////////////////

AD_TEMPL AD_MOD ad_t sqrt(const ad_t& a)
{
	ad_t r;
	r.v = sqrt(a.v);
	realT recip = (realT)0.5 / r.v;
	ns::ad_v_helper<realT, ND, NV, ns::ad_sqrt<realT, ND>>::unroll(r.AD, recip, a.AD);
	return r;
}

AD_TEMPL AD_MOD ad_t exp(const ad_t& a)
{
	ad_t r;
	r.v = exp(a.v);
	ns::ad_var_holder<realT, ND> tmp;
	ns::ad_v_helper<realT, ND, NV, ns::ad_exp<realT, ND>>::unroll(r.AD, tmp, a.AD, r.v);
	return r;
}

AD_TEMPL AD_MOD ad_t log(const ad_t& a)
{
	ad_t r;
	realT recip = (realT)1.0 / a.v;
	r.v = log(a.v);
	ns::ad_var_holder<realT, ND> tmp;
	ns::ad_v_helper<realT, ND, NV, ns::ad_log<realT, ND>>::unroll(r.AD, tmp, a.AD, recip);
	return r;
}

/////////////////////////////////////// Trigonometric funcs ///////////////////////////////////
AD_TEMPL AD_MOD ad_t sin(const ad_t& a)
{
	ad_t r;
	realT cv;
	r.v = sin(a.v); 
	cv = cos(a.v);
	ns::ad_var_holder<realT, ND> c, t;
	ns::ad_v_helper<realT, ND, NV, ns::ad_sincos<realT, ND>>::unroll(r.AD, c, t, a.AD, r.v, cv);
	return r;
}

AD_TEMPL AD_MOD ad_t cos(const ad_t& a)
{
	ad_t r;
	realT sv;
	sv = sin(a.v); 
	r.v = cos(a.v);
	ns::ad_var_holder<realT, ND> s, t;
	ns::ad_v_helper<realT, ND, NV, ns::ad_sincos<realT, ND>>::unroll(s, r.AD, t, a.AD, sv, r.v);
	return r;
}

AD_TEMPL AD_MOD ad_t tan(const ad_t& a)
{
	// to be optimized
	ad_t s, c;
	s.v = sin(a.v); 
	c.v = cos(a.v);
	ns::ad_var_holder<realT, ND> t;
	ns::ad_v_helper<realT, ND, NV, ns::ad_sincos<realT, ND>>::unroll(s.AD, c.AD, t, a.AD, s.v, c.v);
	return s / c;
}

AD_TEMPL AD_MOD ad_t asin(const ad_t& a)
{
	ad_t r;
	r.v = asin(a.v);
	ad_t h = 1 / sqrt(1 - a*a);
	ns::ad_var_holder<realT, ND> t;
	ns::ad_v_helper<realT, ND, NV, ns::ad_asincos<realT, ND>>::unroll(r.AD, t, h.AD, a.AD, h.v);
	return r;
}

AD_TEMPL AD_MOD ad_t acos(const ad_t& a)
{
	//ad_t r;
	//r.v = acos(a.v);
	//ad_t h = -1 / sqrt(1 - a*a);
	//ad_var_holder<realT, ND> t;
	//ad_v_helper<realT, ND, NV, ad_asincos<realT, ND>>::unroll(r.AD, t, h.AD, a.AD, h.v);
	//return r;
	return (realT)(PI/2) - asin(a);
}

AD_TEMPL AD_MOD ad_t atan(const ad_t& a)
{
	ad_t r;
	ad_t y = 1 / (1 + a*a);
	r.v = atan(a.v);
	ns::ad_var_holder<realT, ND> t;
	ns::ad_v_helper<realT, ND, NV, ns::ad_atan<realT, ND>>::unroll(r.AD, t, y.AD, a.AD, y.v);
	return r;
}

