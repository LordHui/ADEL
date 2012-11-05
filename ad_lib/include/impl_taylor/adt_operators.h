#pragma once

#include "adt_define.h"
#include "adt_helper.h"
#include "adt_ops.h"
#include "adt_var.h"


///////////////////////////////////   +     //////

AD_TEMPL AD_MOD ad_t operator +(const ad_t& a, const ad_t& b)
{
	ad_t r;
	r.v = a.v + b.v;
	ns::ad_v_helper<realT, ND, NV, ns::ad_add<realT, ND>>::unroll(r.AD, a.AD, b.AD);
	return r;
}

AD_TEMPL AD_MOD ad_t operator +(const ad_t& a, const int& b)
{
	ad_t r;
	r.v = a.v + b;
	ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, a.AD);
	return r;
}

AD_TEMPL AD_MOD ad_t operator +(const ad_t& a, const realT& b)
{
	ad_t r;
	r.v = a.v + b;
	ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, a.AD);
	return r;
}

AD_TEMPL AD_MOD ad_t operator +(const int& a, const ad_t& b)
{
	ad_t r;
	r.v = a + b.v;
	ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, b.AD);
	return r;
}

AD_TEMPL AD_MOD ad_t operator +(const realT& a, const ad_t& b)
{
	ad_t r;
	r.v = a + b.v;
	ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, b.AD);
	return r;
}

///////////////////////////////////   -     //////
AD_TEMPL AD_MOD ad_t operator -(const ad_t& a)
{
	ad_t r;
	r.v = - a.v;
	ns::ad_v_helper<realT, ND, NV, ns::ad_assign_neg<realT, ND>>::unroll(r.AD, a.AD);
	return r;
}

AD_TEMPL AD_MOD ad_t operator -(const ad_t& a, const ad_t& b)
{
	ad_t r;
	r.v = a.v - b.v;
	ns::ad_v_helper<realT, ND, NV, ns::ad_sub<realT, ND>>::unroll(r.AD, a.AD, b.AD);
	return r;
}

AD_TEMPL AD_MOD ad_t operator -(const ad_t& a, const int& b)
{
	ad_t r;
	r.v = a.v - b;
	ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, a.AD);
	return r;
}

AD_TEMPL AD_MOD ad_t operator -(const ad_t& a, const realT& b)
{
	ad_t r;
	r.v = a.v - b;
	ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, a.AD);
	return r;
}

AD_TEMPL AD_MOD ad_t operator -(const int& a, const ad_t& b)
{
	ad_t r;
	r.v = a - b.v;
	ns::ad_v_helper<realT, ND, NV, ns::ad_assign_neg<realT, ND>>::unroll(r.AD, b.AD);
	return r;
}

AD_TEMPL AD_MOD ad_t operator -(const realT& a, const ad_t& b)
{
	ad_t r;
	r.v = a - b.v;
	ns::ad_v_helper<realT, ND, NV, ns::ad_assign_neg<realT, ND>>::unroll(r.AD, b.AD);
	return r;
}

///////////////////////////////////   *     //////
AD_TEMPL AD_MOD ad_t operator *(const ad_t& a, const ad_t& b)
{
	ad_t r;
	r.v = a.v * b.v;
	ns::ad_v_helper<realT, ND, NV, ns::ad_mul<realT, ND>>::unroll(r.AD, a.AD, b.AD, a.v, b.v);
	return r;
}

AD_TEMPL AD_MOD ad_t operator *(const ad_t& a, const int& b)
{
	ad_t r;
	r.v = a.v * b;
	ns::ad_v_helper<realT, ND, NV, ns::ad_mul<realT, ND>>::unroll(r.AD, a.AD, b);
	return r;
}

AD_TEMPL AD_MOD ad_t operator *(const ad_t& a, const realT& b)
{
	ad_t r;
	r.v = a.v * b;
	ns::ad_v_helper<realT, ND, NV, ns::ad_mul<realT, ND>>::unroll(r.AD, a.AD, b);
	return r;
}

AD_TEMPL AD_MOD ad_t operator *(const int& a, const ad_t& b)
{
	ad_t r;
	r.v = a * b.v;
	ns::ad_v_helper<realT, ND, NV, ns::ad_mul<realT, ND>>::unroll(r.AD, b.AD, a);
	return r;
}

AD_TEMPL AD_MOD ad_t operator *(const realT& a, const ad_t& b)
{
	ad_t r;
	r.v = a * b.v;
	ns::ad_v_helper<realT, ND, NV, ns::ad_mul<realT, ND>>::unroll(r.AD, b.AD, a);
	return r;
}


///////////////////////////////////////////   /       //////////////////////
AD_TEMPL AD_MOD ad_t operator /(const ad_t& a, const ad_t& b)
{
	ad_t r;
	realT recip = (realT)1.0 / b.v;
	r.v = a.v * recip;
	ns::ad_v_helper<realT, ND, NV, ns::ad_div<realT, ND>>::unroll(r.AD, a.AD, b.AD, recip, r.v);
	return r;
}

AD_TEMPL AD_MOD ad_t operator /(const ad_t& a, const int& b)
{
	ad_t r;
	r.v = a.v / b;
	ns::ad_v_helper<realT, ND, NV, ns::ad_div<realT, ND>>::unroll(r.AD, a.AD, b);
	return r;
}

AD_TEMPL AD_MOD ad_t operator /(const ad_t& a, const realT& b)
{
	ad_t r;
	r.v = a.v / b;
	ns::ad_v_helper<realT, ND, NV, ns::ad_div<realT, ND>>::unroll(r.AD, a.AD, b);
	return r;
}

AD_TEMPL AD_MOD ad_t operator /(const int& a, const ad_t& b)
{
	ad_t r;
	r.v = a / b.v;
	ns::ad_v_helper<realT, ND, NV, ns::ad_div<realT, ND>>::unroll(r.AD, r.v, b.AD);
	return r;
}

AD_TEMPL AD_MOD ad_t operator /(const realT& a, const ad_t& b)
{
	ad_t r;
	r.v = a / b.v;
	ns::ad_v_helper<realT, ND, NV, ns::ad_div<realT, ND>>::unroll(r.AD, r.v, b.AD);
	return r;
}
