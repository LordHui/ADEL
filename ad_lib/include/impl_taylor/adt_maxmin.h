#pragma once

#include "adt_define.h"
#include "adt_helper.h"
#include "adt_ops.h"
#include "adt_var.h"

////////////////////////////////////// MAX //////////////////////////////////

AD_TEMPL AD_MOD ad_t max(const ad_t& a, const ad_t& b)
{
	ad_t r;
	if (a.v < b.v)
	{
		r.v = b.v;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, b.AD);
	}
	else
	{
		r.v = a.v;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, a.AD);
	}
	return r;
}

AD_TEMPL AD_MOD ad_t max(const ad_t& a, const int& b)
{
	ad_t r;
	if (a.v < b)
	{
		r.v = b;
		const realT zero = 0;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, zero);
	}
	else
	{
		r.v = a.v;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, a.AD);
	}
	return r;
}

AD_TEMPL AD_MOD ad_t max(const ad_t& a, const realT& b)
{
	ad_t r;
	if (a.v < b)
	{
		r.v = b;
		const realT zero = 0;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, zero);
	}
	else
	{
		r.v = a.v;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, a.AD);
	}
	return r;
}

AD_TEMPL AD_MOD ad_t max(const int& a, const ad_t& b)
{
	ad_t r;
	if (a < b.v)
	{
		r.v = b.v;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, b.AD);
	}
	else
	{
		r.v = a;
		const realT zero = 0;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, zero);
	}
	return r;
}

AD_TEMPL AD_MOD ad_t max(const realT& a, const ad_t& b)
{
	ad_t r;
	if (a < b.v)
	{
		r.v = b.v;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, b.AD);
	}
	else
	{
		r.v = a;
		const realT zero = 0;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, zero);
	}
	return r;
}

//////////////////////////////////////// MIN /////////////////////////////////////////////

AD_TEMPL AD_MOD ad_t min(const ad_t& a, const ad_t& b)
{
	ad_t r;
	if (a.v < b.v)
	{
		r.v = a.v;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, a.AD);
	}
	else
	{
		r.v = b.v;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, b.AD);
	}
	return r;
}

AD_TEMPL AD_MOD ad_t min(const ad_t& a, const int& b)
{
	ad_t r;
	if (a.v < b)
	{
		r.v = a.v;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, a.AD);
	}
	else
	{
		r.v = b;
		const realT zero = 0;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, zero);
	}
	return r;
}

AD_TEMPL AD_MOD ad_t min(const ad_t& a, const realT& b)
{
	ad_t r;
	if (a.v < b)
	{
		r.v = a.v;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, a.AD);
	}
	else
	{
		r.v = b;
		const realT zero = 0;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, zero);
	}
	return r;
}

AD_TEMPL AD_MOD ad_t min(const int& a, const ad_t& b)
{
	ad_t r;
	if (a < b.v)
	{
		r.v = a;
		const realT zero = 0;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, zero);
	}
	else
	{
		r.v = b.v;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, b.AD);
	}
	return r;
}

AD_TEMPL AD_MOD ad_t min(const realT& a, const ad_t& b)
{
	ad_t r;
	if (a < b.v)
	{
		r.v = a;
		const realT zero = 0;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, zero);
	}
	else
	{
		r.v = b.v;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(r.AD, b.AD);
	}
	return r;
}

