#pragma once

#include "adt_define.h"
#include "adt_helper.h"
#include "adt_ops.h"
#include "adt_var.h"


#define GENERATE_COMPARE(op) \
	AD_TEMPL AD_MOD bool operator op(const ad_t& a, const ad_t& b) { return a.v op b.v; } \
	AD_TEMPL AD_MOD bool operator op(const ad_t& a, const int& b) { return a.v op b; } \
	AD_TEMPL AD_MOD bool operator op(const ad_t& a, const realT& b) { return a.v op b; } \
	AD_TEMPL AD_MOD bool operator op(const int& a, const ad_t& b) { return a op b.v; } \
	AD_TEMPL AD_MOD bool operator op(const realT& a, const ad_t& b) { return a op b.v; }

GENERATE_COMPARE(<);
GENERATE_COMPARE(<=);
GENERATE_COMPARE(>);
GENERATE_COMPARE(>=);
GENERATE_COMPARE(==);
GENERATE_COMPARE(!=);

#undef GENERATE_COMPARE

