#pragma once

namespace ns
{

template<typename realT, int ND>
struct ad_var_holder
{
	realT D[ND];
};

template<typename realT, int ND, int NV>
struct ad_holder
{
	ad_var_holder<realT, ND> V[NV];
};

//////////////////////////////// top-level unroll helpers ad_d_helper ////////////////////////////

template<typename realT, int ND, typename OP, int ID>
struct ad_d_helper
{
	// 1 - arg: ra ca
	AD_MOD static void unroll(ad_var_holder<realT, ND> &result, const ad_var_holder<realT, ND> &da)
	{
		ad_d_helper<realT, ND, OP, ID-1>::unroll(result, da);
		OP::template impl<ID>(result, da);
	}

	// 1 - arg: ra ca (volatile)
	AD_MOD static void unroll(volatile ad_var_holder<realT, ND> &result, const volatile ad_var_holder<realT, ND> &da)
	{
		ad_d_helper<realT, ND, OP, ID-1>::unroll(result, da);
		OP::template impl<ID>(result, da);
	}

	// 1 - arg: ra cf
	template<typename CT>
	AD_MOD static void unroll(ad_var_holder<realT, ND> &result, const CT &a)
	{
		ad_d_helper<realT, ND, OP, ID-1>::template unroll<CT>(result, a);
		OP::template impl<CT, ID>(result, a);
	}

	// 1 - arg: ra cf
	template<typename CT>
	AD_MOD static void unroll(volatile ad_var_holder<realT, ND> &result, const CT &a)
	{
		ad_d_helper<realT, ND, OP, ID-1>::template unroll<CT>(result, a);
		OP::template impl<CT, ID>(result, a);
	}


	// 2 - arg: ra ca ca
	AD_MOD static void unroll(ad_var_holder<realT, ND> &result, const ad_var_holder<realT, ND> &da, const ad_var_holder<realT, ND> &db)
	{
		ad_d_helper<realT, ND, OP, ID-1>::unroll(result, da, db);
		OP::template impl<ID>(result, da, db);
	}

	// 2 - arg: ra ca cf
	template<typename CT>
	AD_MOD static void unroll(ad_var_holder<realT, ND> &result, const ad_var_holder<realT, ND> &da, const CT &b)
	{
		ad_d_helper<realT, ND, OP, ID-1>::unroll(result, da, b);
		OP::template impl<CT, ID>(result, da, b);
	}

	// 2 - arg: ra cf ca
	template<typename CT>
	AD_MOD static void unroll(ad_var_holder<realT, ND> &result, const CT &a, const ad_var_holder<realT, ND> &db)
	{
		ad_d_helper<realT, ND, OP, ID-1>::unroll(result, a, db);
		OP::template impl<CT, ID>(result, a, db);
	}

	// 3 - arg: ra ca ca cf cf
	AD_MOD static void unroll(ad_var_holder<realT, ND> &result, const ad_var_holder<realT, ND> &da, const ad_var_holder<realT, ND> &db, const realT &aa, const realT &bb)
	{
		ad_d_helper<realT, ND, OP, ID-1>::unroll(result, da, db, aa, bb);
		OP::template impl<ID>(result, da, db, aa, bb);
	}

	// 3 - arg: ra ca cf cf (reverse)
	AD_MOD static void unroll_reverse(ad_var_holder<realT, ND> &result, const ad_var_holder<realT, ND> &da, const realT &aa, const realT &bb)
	{
		OP::template impl<ID>(result, da, aa, bb);
		ad_d_helper<realT, ND, OP, ID-1>::unroll_reverse(result, da, aa, bb);
	}

	// 4 - arg: ra ra ca cf
	AD_MOD static void unroll(ad_var_holder<realT, ND> &result, ad_var_holder<realT, ND> &tmp, const ad_var_holder<realT, ND> &da, const realT &b)
	{
		ad_d_helper<realT, ND, OP, ID-1>::unroll(result, tmp, da, b);
		OP::template impl<ID>(result, tmp, da, b);
	}

	// 4 - arg: ra ra ca ca cf
	AD_MOD static void unroll(ad_var_holder<realT, ND> &result, ad_var_holder<realT, ND> &tmp, const ad_var_holder<realT, ND> &da, const ad_var_holder<realT, ND> &db, const realT &b)
	{
		ad_d_helper<realT, ND, OP, ID-1>::unroll(result, tmp, da, db, b);
		OP::template impl<ID>(result, tmp, da, db, b);
	}


	// 5 - arg: ra ra ra ca cf cf
	AD_MOD static void unroll(ad_var_holder<realT, ND> &ra1, ad_var_holder<realT, ND> &ra2, ad_var_holder<realT, ND> &ra3, const ad_var_holder<realT, ND> &ad, const realT &v1, const realT &v2)
	{
		ad_d_helper<realT, ND, OP, ID-1>::unroll(ra1, ra2, ra3, ad, v1, v2);
		OP::template impl<ID>(ra1, ra2, ra3, ad, v1, v2);
	}

	// 5 - arg: ra ra ra ca cf cf cf
	template<typename CT>
	AD_MOD static void unroll(ad_var_holder<realT, ND> &ra1, ad_var_holder<realT, ND> &ra2, ad_var_holder<realT, ND> &ra3, const ad_var_holder<realT, ND> &ad, const realT &v1, const realT &v2, const CT &b)
	{
		ad_d_helper<realT, ND, OP, ID-1>::unroll(ra1, ra2, ra3, ad, v1, v2, b);
		OP::template impl<CT, ID>(ra1, ra2, ra3, ad, v1, v2, b);
	}

};

template<typename realT, int ND, typename OP>
struct ad_d_helper<realT, ND, OP, 0>
{
	// 1 - arg: ra ca
	AD_MOD static void unroll(ad_var_holder<realT, ND> &result, const ad_var_holder<realT, ND> &da)
	{
	}

	// 1 - arg: ra ca (volatile)
	AD_MOD static void unroll(volatile ad_var_holder<realT, ND> &result, const volatile ad_var_holder<realT, ND> &da)
	{
	}

	// 1 - arg: ra cf
	template<typename CT>
	AD_MOD static void unroll(ad_var_holder<realT, ND> &result, const CT &a)
	{
	}

	// 1 - arg: ra cf
	template<typename CT>
	AD_MOD static void unroll(volatile ad_var_holder<realT, ND> &result, const CT &a)
	{
	}


	// 2 - arg: ra ca ca
	AD_MOD static void unroll(ad_var_holder<realT, ND> &result, const ad_var_holder<realT, ND> &da, const ad_var_holder<realT, ND> &db)
	{
	}

	// 2 - arg: ra ca cf
	template<typename CT>
	AD_MOD static void unroll(ad_var_holder<realT, ND> &result, const ad_var_holder<realT, ND> &da, const CT &b)
	{
	}

	// 2 - arg: ra cf ca
	template<typename CT>
	AD_MOD static void unroll(ad_var_holder<realT, ND> &result, const CT &a, const ad_var_holder<realT, ND> &db)
	{
	}

	// 3 - arg: ra ca ca cf cf
	AD_MOD static void unroll(ad_var_holder<realT, ND> &result, const ad_var_holder<realT, ND> &da, const ad_var_holder<realT, ND> &db, const realT &aa, const realT &bb)
	{
	}

	// 3 - arg: ra ca cf cf (reverse)
	AD_MOD static void unroll_reverse(ad_var_holder<realT, ND> &result, const ad_var_holder<realT, ND> &da, const realT &aa, const realT &bb)
	{
	}

	// 4 - arg: ra ra ca cf
	AD_MOD static void unroll(ad_var_holder<realT, ND> &result, ad_var_holder<realT, ND> &tmp, const ad_var_holder<realT, ND> &da, const realT &b)
	{
	}

	// 4 - arg: ra ra ca ca cf
	AD_MOD static void unroll(ad_var_holder<realT, ND> &result, ad_var_holder<realT, ND> &tmp, const ad_var_holder<realT, ND> &da, const ad_var_holder<realT, ND> &db, const realT &b)
	{
	}


	// 5 - arg: ra ra ra ca cf cf
	AD_MOD static void unroll(ad_var_holder<realT, ND> &ra1, ad_var_holder<realT, ND> &ra2, ad_var_holder<realT, ND> &ra3, const ad_var_holder<realT, ND> &ad, const realT &v1, const realT &v2)
	{
	}

	// 5 - arg: ra ra ra ca cf cf cf
	template<typename CT>
	AD_MOD static void unroll(ad_var_holder<realT, ND> &ra1, ad_var_holder<realT, ND> &ra2, ad_var_holder<realT, ND> &ra3, const ad_var_holder<realT, ND> &ad, const realT &v1, const realT &v2, const CT &b)
	{
	}
};

//////////////////////////////// top-level unroll helpers ad_v_helper ////////////////////////////

template<typename realT, int ND, int NV, class OP, int IV = NV>
struct ad_v_helper
{
	// 1 - arg: ra ca
	AD_MOD static void unroll(ad_holder<realT, ND, NV> &result, const ad_holder<realT, ND, NV> &da)
	{
		ad_v_helper<realT, ND, NV, OP, IV-1>::unroll(result, da);
		ad_d_helper<realT, ND, OP, ND>::unroll(result.V[IV-1], da.V[IV-1]);
	}

	// 1 - arg: ra ca (volatile)
	AD_MOD static void unroll(volatile ad_holder<realT, ND, NV> &result, const volatile ad_holder<realT, ND, NV> &da)
	{
		ad_v_helper<realT, ND, NV, OP, IV-1>::unroll(result, da);
		ad_d_helper<realT, ND, OP, ND>::unroll(result.V[IV-1], da.V[IV-1]);
	}

	// 1 - arg: ra cf
	template<typename CT>
	AD_MOD static void unroll(ad_holder<realT, ND, NV> &result, const CT &a)
	{
		ad_v_helper<realT, ND, NV, OP, IV-1>::template unroll<CT>(result, a);
		ad_d_helper<realT, ND, OP, ND>::template unroll<CT>(result.V[IV-1], a);
	}

	// 1 - arg: ra cf (volatile)
	template<typename CT>
	AD_MOD static void unroll(volatile ad_holder<realT, ND, NV> &result, const CT &a)
	{
		ad_v_helper<realT, ND, NV, OP, IV-1>::template unroll<CT>(result, a);
		ad_d_helper<realT, ND, OP, ND>::template unroll<CT>(result.V[IV-1], a);
	}

	// 2 - arg: ra ca ca 
	AD_MOD static void unroll(ad_holder<realT, ND, NV> &result, const ad_holder<realT, ND, NV> &da, const ad_holder<realT, ND, NV> &db)
	{
		ad_v_helper<realT, ND, NV, OP, IV-1>::unroll(result, da, db);
		ad_d_helper<realT, ND, OP, ND>::unroll(result.V[IV-1], da.V[IV-1], db.V[IV-1]);
	}

	// 2 - arg: ra ca cf
	template<typename CT>
	AD_MOD static void unroll(ad_holder<realT, ND, NV> &result, const ad_holder<realT, ND, NV> &da, const CT &b)
	{
		ad_v_helper<realT, ND, NV, OP, IV-1>::unroll(result, da, b);
		ad_d_helper<realT, ND, OP, ND>::unroll(result.V[IV-1], da.V[IV-1], b);
	}

	// 2 - arg: ra cf ca
	template<typename CT>
	AD_MOD static void unroll(ad_holder<realT, ND, NV> &result, const CT &a, const ad_holder<realT, ND, NV> &db)
	{
		ad_v_helper<realT, ND, NV, OP, IV-1>::unroll(result, a, db);
		ad_d_helper<realT, ND, OP, ND>::unroll(result.V[IV-1], a, db.V[IV-1]);
	}


	// 3 - arg: ra ca ca cf cf
	AD_MOD static void unroll(ad_holder<realT, ND, NV> &result, const ad_holder<realT, ND, NV> &da, const ad_holder<realT, ND, NV> &db, const realT &aa, const realT &bb)
	{
		ad_v_helper<realT, ND, NV, OP, IV-1>::unroll(result, da, db, aa, bb);
		ad_d_helper<realT, ND, OP, ND>::unroll(result.V[IV-1], da.V[IV-1], db.V[IV-1], aa, bb);
	}

	// 3 - arg: ra ca cf cf (reverse)
	AD_MOD static void unroll_reverse(ad_holder<realT, ND, NV> &result, const ad_holder<realT, ND, NV> &da, const realT &aa, const realT &bb)
	{
		ad_v_helper<realT, ND, NV, OP, IV-1>::unroll_reverse(result, da, aa, bb);
		ad_d_helper<realT, ND, OP, ND>::unroll_reverse(result.V[IV-1], da.V[IV-1], aa, bb);
	}

	// 4 - arg: ra ta ca cf
	AD_MOD static void unroll(ad_holder<realT, ND, NV> &result, ad_var_holder<realT, ND> &tmp, const ad_holder<realT, ND, NV> &da, const realT &b)
	{
		ad_v_helper<realT, ND, NV, OP, IV-1>::unroll(result, tmp, da, b);
		ad_d_helper<realT, ND, OP, ND>::unroll(result.V[IV-1], tmp, da.V[IV-1], b);
	}

	// 4 - arg: ra ta ca ca cf
	AD_MOD static void unroll(ad_holder<realT, ND, NV> &result, ad_var_holder<realT, ND> &tmp, const ad_holder<realT, ND, NV> &da, const ad_holder<realT, ND, NV> &db, const realT &c)
	{
		ad_v_helper<realT, ND, NV, OP, IV-1>::unroll(result, tmp, da, db, c);
		ad_d_helper<realT, ND, OP, ND>::unroll(result.V[IV-1], tmp, da.V[IV-1], db.V[IV-1], c);
	}


	// 5 - arg: ra ta ta ca cf cf
	AD_MOD static void unroll(ad_holder<realT, ND, NV> &ra, ad_var_holder<realT, ND> &ta1, ad_var_holder<realT, ND> &ta2, const ad_holder<realT, ND, NV> &ca, const realT &v1, const realT &v2)
	{
		ad_v_helper<realT, ND, NV, OP, IV-1>::unroll(ra, ta1, ta2, ca, v1, v2);
		ad_d_helper<realT, ND, OP, ND>::unroll(ra.V[IV-1], ta1, ta2, ca.V[IV-1], v1, v2);
	}

	// 5 - arg: ra ta ta ca cf cf cf
	template<typename CT>
	AD_MOD static void unroll(ad_holder<realT, ND, NV> &ra, ad_var_holder<realT, ND> &ta1, ad_var_holder<realT, ND> &ta2, const ad_holder<realT, ND, NV> &ca, const realT &v1, const realT &v2, const CT &b)
	{
		ad_v_helper<realT, ND, NV, OP, IV-1>::unroll(ra, ta1, ta2, ca, v1, v2, b);
		ad_d_helper<realT, ND, OP, ND>::unroll(ra.V[IV-1], ta1, ta2, ca.V[IV-1], v1, v2, b);
	}

	// 5 - arg: ta ra ta ca cf cf
	AD_MOD static void unroll(ad_var_holder<realT, ND> &ta1, ad_holder<realT, ND, NV> &ra, ad_var_holder<realT, ND> &ta2, const ad_holder<realT, ND, NV> &ca, const realT &v1, const realT &v2)
	{
		ad_v_helper<realT, ND, NV, OP, IV-1>::unroll(ta1, ra, ta2, ca, v1, v2);
		ad_d_helper<realT, ND, OP, ND>::unroll(ta1, ra.V[IV-1], ta2, ca.V[IV-1], v1, v2);
	}

	// 5 - arg: ra ra ta ca cf cf
	AD_MOD static void unroll(ad_holder<realT, ND, NV> &ra1, ad_holder<realT, ND, NV> &ra2, ad_var_holder<realT, ND> &ta2, const ad_holder<realT, ND, NV> &ca, const realT &v1, const realT &v2)
	{
		ad_v_helper<realT, ND, NV, OP, IV-1>::unroll(ra1, ra2, ta2, ca, v1, v2);
		ad_d_helper<realT, ND, OP, ND>::unroll(ra1.V[IV-1], ra2.V[IV-1], ta2, ca.V[IV-1], v1, v2);
	}
};

template<typename realT, int ND, int NV, class OP>
struct ad_v_helper<realT, ND, NV, OP, 0>
{
	// 1 - arg: ra ca
	AD_MOD static void unroll(ad_holder<realT, ND, NV> &result, const ad_holder<realT, ND, NV> &da)
	{
	}

	// 1 - arg: ra ca (volatile)
	AD_MOD static void unroll(volatile ad_holder<realT, ND, NV> &result, const volatile ad_holder<realT, ND, NV> &da)
	{
	}

	// 1 - arg: ra cf
	template<typename CT>
	AD_MOD static void unroll(ad_holder<realT, ND, NV> &result, const CT &a)
	{
	}

	// 1 - arg: ra cf (volatile)
	template<typename CT>
	AD_MOD static void unroll(volatile ad_holder<realT, ND, NV> &result, const CT &a)
	{
	}

	// 2 - arg: ra ca ca 
	AD_MOD static void unroll(ad_holder<realT, ND, NV> &result, const ad_holder<realT, ND, NV> &da, const ad_holder<realT, ND, NV> &db)
	{
	}

	// 2 - arg: ra ca cf
	template<typename CT>
	AD_MOD static void unroll(ad_holder<realT, ND, NV> &result, const ad_holder<realT, ND, NV> &da, const CT &b)
	{
	}

	// 2 - arg: ra cf ca
	template<typename CT>
	AD_MOD static void unroll(ad_holder<realT, ND, NV> &result, const CT &a, const ad_holder<realT, ND, NV> &db)
	{
	}


	// 3 - arg: ra ca ca cf cf
	AD_MOD static void unroll(ad_holder<realT, ND, NV> &result, const ad_holder<realT, ND, NV> &da, const ad_holder<realT, ND, NV> &db, const realT &aa, const realT &bb)
	{
	}

	// 3 - arg: ra ca cf cf (reverse)
	AD_MOD static void unroll_reverse(ad_holder<realT, ND, NV> &result, const ad_holder<realT, ND, NV> &da, const realT &aa, const realT &bb)
	{
	}

	// 4 - arg: ra ta ca cf
	AD_MOD static void unroll(ad_holder<realT, ND, NV> &result, ad_var_holder<realT, ND> &tmp, const ad_holder<realT, ND, NV> &da, const realT &b)
	{
	}

	// 4 - arg: ra ta ca ca cf
	AD_MOD static void unroll(ad_holder<realT, ND, NV> &result, ad_var_holder<realT, ND> &tmp, const ad_holder<realT, ND, NV> &da, const ad_holder<realT, ND, NV> &db, const realT &c)
	{
	}


	// 5 - arg: ra ta ta ca cf cf
	AD_MOD static void unroll(ad_holder<realT, ND, NV> &ra, ad_var_holder<realT, ND> &ta1, ad_var_holder<realT, ND> &ta2, const ad_holder<realT, ND, NV> &ca, const realT &v1, const realT &v2)
	{
	}

	// 5 - arg: ra ta ta ca cf cf cf
	template<typename CT>
	AD_MOD static void unroll(ad_holder<realT, ND, NV> &ra, ad_var_holder<realT, ND> &ta1, ad_var_holder<realT, ND> &ta2, const ad_holder<realT, ND, NV> &ca, const realT &v1, const realT &v2, const CT &b)
	{
	}

	// 5 - arg: ta ra ta ca cf cf
	AD_MOD static void unroll(ad_var_holder<realT, ND> &ta1, ad_holder<realT, ND, NV> &ra, ad_var_holder<realT, ND> &ta2, const ad_holder<realT, ND, NV> &ca, const realT &v1, const realT &v2)
	{
	}

	// 5 - arg: ra ra ta ca cf cf
	AD_MOD static void unroll(ad_holder<realT, ND, NV> &ra1, ad_holder<realT, ND, NV> &ra2, ad_var_holder<realT, ND> &ta2, const ad_holder<realT, ND, NV> &ca, const realT &v1, const realT &v2)
	{
	}
};



}
