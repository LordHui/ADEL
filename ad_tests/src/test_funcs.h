#pragma once

#define DEF_FUNC(sname, body) \
struct sname \
{ \
	template<typename realT> static realT func(realT x) { return body; } \
	static const char* name() { return #body; } \
};

#define DEF_FUNC2(sname, body1, body2) \
struct sname \
{ \
	template<typename realT> static realT func_fwd(realT x) { return body1; } \
	template<typename realT> static realT func_rev(realT x) { return body2; } \
	static const char* name() { return #sname; } \
};


DEF_FUNC(F0, x);
DEF_FUNC(F1, x+x-x);
DEF_FUNC(F2, -2+(2+((x+2)-2)));
DEF_FUNC(F3, (2*x)/2);
DEF_FUNC(F4, (x*x)/x);
DEF_FUNC(F5, sqrt(x*x));
DEF_FUNC(F6, sqrt(pow(x,2)));
DEF_FUNC(F7, log(exp(x)));
DEF_FUNC(F8, pow(pow(x,2),.5));
DEF_FUNC(F9, pow(pow(x,3),1.0/3.0));
DEF_FUNC(F10, atan(tan(x)));
DEF_FUNC(F11, (-x)*((realT)-1.0));
DEF_FUNC(F12, acos(cos(x)));

DEF_FUNC2(FSIN, asin(x), sin(x));
DEF_FUNC2(FCOS, acos(x), cos(x));
DEF_FUNC2(FLOG, exp(x), log(x));


#undef DEF_FUNC2
#undef DEF_FUNC

