#pragma once

#if defined(__host__)
#	define AD_HOST __host__
#else
#	define AD_HOST 
#endif

#if defined(__device__)
#	define AD_DEVICE __device__
#else
#	define AD_DEVICE
#endif

#if defined(__forceinline__)
#	define AD_FORCEINLINE __forceinline__
#else
#	if defined(__GNUC__)
#		define AD_FORCEINLINE __inline__ __attribute__((always_inline))
#	elif defined(_WIN32)
#		define AD_FORCEINLINE inline
#	else
#		error --- !!! UNKNOWN COMPILER
#	endif
#endif

#define AD_MOD AD_HOST AD_DEVICE AD_FORCEINLINE
#define AD_MOD_NOINLINE AD_HOST AD_DEVICE 

#if !defined(PI)
#	define PI  3.141592653589793238462
#endif

#define ns ad_taylor_impl
#define ad_t ad_taylor_var_t<realT, ND, NV>
#define AD_TEMPL template<typename realT, int ND, int NV>




