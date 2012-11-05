#pragma once

#include "adt_define.h"
#include "adt_helper.h"
#include "adt_ops.h"

template<typename realT, int ND, int NV>
struct ad_taylor_var_t
{
	typedef realT BaseT;

	realT v;
	ns::ad_holder<realT, ND, NV> AD;

	AD_MOD ad_taylor_var_t() { }

    AD_MOD realT get(const int& direction, const int& degree) const
	{
		return AD.V[direction-1].D[degree-1];
	}

    AD_MOD void set(const int& direction, const int& degree, const realT& value)
	{
		AD.V[direction-1].D[degree-1] = value;
	}

    AD_MOD ad_taylor_var_t(const ad_t& r)
	{
		v = r.v;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(AD, r.AD);
	}

    AD_MOD ad_taylor_var_t(const double& r)
	{
		v = r;
		const realT zero = 0;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(AD, zero);
	}

    AD_MOD ad_taylor_var_t(const float& r)
	{
		v = r;
		const realT zero = 0;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(AD, zero);
	}

    AD_MOD ad_taylor_var_t(const int& r)
	{
		v = r;
		const realT zero = 0;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(AD, zero);
	}

    AD_MOD const ad_t& operator =(const ad_t& r)
	{
		v = r.v;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(AD, r.AD);
		return *this;
	}

    AD_MOD volatile ad_t& operator=(const volatile ad_t& r) volatile
	{
		v = r.v;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(AD, r.AD);
		return *this;
	}

    AD_MOD const ad_t& operator =(const double& r)
	{
		v = r;
		const realT zero = 0;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(AD, zero);
		return *this;
	}

    AD_MOD ad_t& operator =(const int& r)
	{
		v = r;
		const realT zero = 0;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(AD, zero);
		return *this;
	}

    AD_MOD const ad_t& operator =(const float& r)
	{
		v = r;
		const realT zero = 0;
		ns::ad_v_helper<realT, ND, NV, ns::ad_assign<realT, ND>>::unroll(AD, zero);
		return *this;
	}

	////////////////////////////////////////    +=    ///////////////////////////////////////

    AD_MOD ad_t& operator +=(const ad_t& b)
	{
		v += b.v;
		ns::ad_v_helper<realT, ND, NV, ns::ad_inc<realT, ND>>::unroll(AD, b.AD);
		return *this;
	}

    AD_MOD volatile ad_t& operator+=(const volatile ad_t& b) volatile
	{
		v += b.v;
		ns::ad_v_helper<realT, ND, NV, ns::ad_inc<realT, ND>>::unroll(AD, b.AD);
		return *this;
	}

    AD_MOD ad_t& operator +=(const int& b)
	{
		v += b;
		return *this;
	}

    AD_MOD ad_t& operator +=(const realT& b)
	{
		v += b;
		return *this;
	}

	////////////////////////////////////////    -=    ///////////////////////////////////////

    AD_MOD ad_t& operator -=(const ad_t& b)
	{
		v -= b.v;
		ns::ad_v_helper<realT, ND, NV, ns::ad_dec<realT, ND>>::unroll(AD, b.AD);
		return *this;
	}

    AD_MOD volatile ad_t& operator-=(const volatile ad_t& b) volatile
	{
		v -= b.v;
		ns::ad_v_helper<realT, ND, NV, ns::ad_dec<realT, ND>>::unroll(AD, b.AD);
		return *this;
	}

    AD_MOD ad_t& operator -=(const int& b)
	{
		v -= b;
		return *this;
	}

    AD_MOD ad_t& operator -=(const realT& b)
	{
		v -= b;
		return *this;
	}

};

