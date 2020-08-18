/*
 * nvfxmath.h
 *
 * The primary intent of this library is to provide efficient
 * implementations of commonly used S15.16 fixed point math routines.
 * One consequence of this design choice is that macros are used in
 * some places to avoid function call overhead.  This forces the
 * library to be delivered as a header file and a static library.
 */

#if !defined(NVFXMATH_H)
#define NVFXMATH_H

#include <stdlib.h>  /* for labs() prototype */

#ifdef __cplusplus
extern "C" {
#endif

/* no support for 'long long' until MS VC7 */
#if defined(_WIN32) && defined(_WIN32) && (_MSC_VER < 1300)
#define NV_FX_LONGLONG __int64
#else
#define NV_FX_LONGLONG long long
#endif

typedef int NvSFx;

/*
 * NvSFxAbs returns the absolute value of its parameter.  This is currently
 * implemented as a call to labs(), which the compiler will turn into
 * efficient asm.
 */
#define NvSFxAbs(A)   (labs((NvSFx)(A)))

/*
 * NvSFxFloor returns the floor of its parameter.
 */
#define NvSFxFloor(A) ((((NvSFx)(A)) >> 16) << 16)

/*
 * NvSFxCeil returns the ceiling of its parameter.  The result is
 * undefined if input > 7FFF.0000
 */
#define NvSFxCeil(A)  (-NvSFxFloor(-((NvSFx)(A))))

/*
 * NvSFxAdd returns the sum of its parameters.  The result is undefined
 * if sum > 7FFF.FFFF or sum < 8000.0000
 */
#define NvSFxAdd(A,B) (((NvSFx)(A)) + ((NvSFx)(B)))

/*
 * NvSFxSub returns the difference of its parameters.  The result is
 * undefined if difference > 7FFF.FFFF or difference < 8000.0000
 */
#define NvSFxSub(A,B) (((NvSFx)(A)) - ((NvSFx)(B)))

/*
 * NvSFxMul returns the product of its parameters.  The result is
 * undefined if product > 7FFF.FFFF or product < 8000.0000
 */
#define NvSFxMul(A,B) \
((NvSFx)((((NV_FX_LONGLONG)(NvSFx)(A)) * ((NvSFx)(B))) >> 16))

/*
 * NvSFxDot4, NvSFxDot3, and NvSFxDot2 implement four element, three element,
 * and two element dot products, respectively. These macros provide additional
 * accuracy by accumulating the double wide results and doing rounded conversion
 * back to S15.16 format only at the end.
 */
#define NvSFxDot4(a0,b0,a1,b1,a2,b2,a3,b3)             \
(((((((NV_FX_LONGLONG)(a0)) * (b0))   +                \
    (((NV_FX_LONGLONG)(a1)) * (b1)))  +                \
   ((((NV_FX_LONGLONG)(a2)) * (b2))   +                \
    (((NV_FX_LONGLONG)(a3)) * (b3)))) + 0x8000) >> 16)

#define NvSFxDot3(a0,b0,a1,b1,a2,b2)                   \
((((((NV_FX_LONGLONG)(a0)) * (b0))  +                  \
   (((NV_FX_LONGLONG)(a1)) * (b1))  +                  \
   (((NV_FX_LONGLONG)(a2)) * (b2))) + 0x8000) >> 16)

#define NvSFxDot2(a0,b0,a1,b1)                         \
((((((NV_FX_LONGLONG)(a0)) * (b0))  +                  \
   (((NV_FX_LONGLONG)(a1)) * (b1))) + 0x8000) >> 16)

/* 
 * NvSFxPow approximates A^B (where "^" denotes "raised to the power of"). 
 * In general, the result is undefined if A is not a non-zero, non-negative 
 * number. I.e. A must be > 0000.0000. However pow(0,0) is 0001.0000 as 
 * demanded by OpenGL-ES. The result is undefined if pow(A,B) > 7FFF.FFFF.
 * The result is also undefined if log2(A)*B is not in range [8000.0000, 
 * 7FFF.FFFF].
 *
 * While this pow() function works well in many situations (e.g. for
 * lighting), there are numerical shortcomings when it is used as a general
 * purpose pow() function, since significantly reduced accuracy can occur
 * for certain pairs of arguments. Errors up to about 0.5% have been
 * observed. The basic issue when using pow(x,y) = exp(y*log(x)) is that
 * a small error in the logarithm can lead to a massive error in the
 * function value. This effect is more pronounced with a fixed point
 * implementation than a floating-point one.  The worst errors occur when
 * A is a number slightly less than 1, and B is a negative number of
 * fairly large magnitude such that the result is large but does not
 * overflow.
 */
NvSFx NvSFxPow (NvSFx A, NvSFx B);

/* 
 * NvSFxDiv returns the quotient of its arguments.  Division is exact
 * and the result is equal to the quotient of dividend and divisor
 * rounded towards 0, i.e. truncated after 16 fraction bits.  The
 * quotient is undefined if abs(dividend) > (7FFF.FFFF * abs(divisor)).
 * The divisor must satisfy abs(divisor) <= 7FFF.FFFF.
 */
NvSFx NvSFxDiv (NvSFx dividend, NvSFx divisor);

/* 
 * NvSFxRecip returns the reciprocal of its argument.  The reciprocal
 * is exact and the result is equal to the quotient of 1 / divisor 
 * rounded towards 0, i.e. truncated after 16 fraction bits.  The
 * quotient is undefined if abs(dividend) > (7FFF.FFFF * abs(divisor)).
 */
NvSFx NvSFxRecip (NvSFx divisor);

/*
 * NvSFxMod is the fixed-point equivalent of the ANSI-C function fmod(). It 
 * computes dividend - trunc(dividend / divisor) * divisor, where trunc(x) = 
 * (x >= 0.0) ? floor(x) : ceil(x)). The remainder has the same sign as the
 * dividend. The result is undefined if 
 * abs(dividend) > (7FFF.FFFF * abs(divisor)).
 */
NvSFx NvSFxMod(NvSFx dividend, NvSFx divisor);

/* 
 * NvSFxCosD computes an approximation to the cosine of deg, where deg is an
 * angle given in degrees (a full circle having 360 degrees). The input must
 * be >= 0 and less than 360 degrees, i.e. 0000.0000 <= deg <= 0167.FFFF. The
 * function returns 0 for arguments outside this range. The magnitude of the
 * approximation error does not exceed 4/65536 over the entire supported 
 * argument range.
 */ 
NvSFx NvSFxCosD(NvSFx deg);

/* 
 * NvSFxSinD computes an approximation to the sine of deg, where deg is an
 * angle given in degrees (a full circle having 360 degrees). The input must
 * be >= 0 and less than 360 degrees, i.e. 0000.0000 <= deg <= 0167.FFFF. The
 * function returns 0 for arguments outside this range. The magnitude of the
 * approximation error does not exceed 4/65536 over the entire supported 
 * argument range.
 */
NvSFx NvSFxSinD(NvSFx deg);

/* 
 * NvSFxCosDFullRange computes an approximation to the cosine of deg,
 * where deg is an angle given in degrees (a full circle having 360
 * degrees).  The input is allowed to be any fixed point number.  The
 * magnitude of the approximation error does not exceed 4/65536 over
 * the entire supported argument range.
 *
 * This function is slower than NvSFxCosD because it first transforms
 * its parameter to be >= 0 and less than 360 degrees.  As such, this
 * function is provided for convenience and is not recommended for
 * performance sensitive applications.
 */ 
NvSFx NvSFxCosDFullRange (NvSFx deg);

/* 
 * NvSFxSinDFullRange computes an approximation to the sine of deg,
 * where deg is an angle given in degrees (a full circle having 360
 * degrees).  The input is allowed to be any fixed point number.  The
 * magnitude of the approximation error does not exceed 4/65536 over
 * the entire supported argument range.
 *
 * This function is slower than NvSFxSinD because it first transforms
 * its parameter to be >= 0 and less than 360 degrees.  As such, this
 * function is provided for convenience and is not recommended for
 * performance sensitive applications.
 */ 
NvSFx NvSFxSinDFullRange (NvSFx deg);

/*
 * NvSFxSqrt returns the square root of its parameter.  The square root
 * is exact and the result is equal to sqrt (radicand) rounded towards 0,
 * i.e. truncated after 16 fraction bits.  The result is undefined if the
 * radicand does not satisfy 0000.0000 <= radicand < 7FFF.FFFF, i.e. the
 * radicand must be greater than or equal to zero.
 */
NvSFx NvSFxSqrt(NvSFx radicand);

/*
 * NvSFxRecipSqrt computes an approximation to 1/sqrt(radicand). The result is
 * undefined if radicand does not satisfy 0000.0000 < radicand < 7FFF.FFF, i.e
 * the argument must be a non-zero non-negative number. Over the supported
 * argument range all results either match the reference function, or are off
 * by at most +/-1/65536. No larger errors were observed in an exhaustive test.
 */
NvSFx NvSFxRecipSqrt(NvSFx radicand);

/*
 * NvSFxLog2 computes an approximation to the logarithm base 2 of x. The result
 * is undefined if the argument x does not satisfy 0000.0000 < x < 7FFF.FFFF,
 * i.e. argument must be a non-zero non-negative number. Over the supported
 * argument range all results either match the reference function, or are off
 * by at most +/-1/65536. No larger errors were observed in an exhaustive test.
 */
NvSFx NvSFxLog2(NvSFx x);

/*
 * NvSFxPow2 computes an approximation to 2^x. The result is undefined if the 
 * argument x is > 000E.FFFF (about 14.99998). The approximation provides 
 * about 23.5 bits of accuracy. The result is not off by more than +/-2/65536
 * (as compared to a floating-point reference converted to S15.16) if the 
 * argument is less than 0008.2000. The magnitude of the approximation error 
 * increases for larger arguments, but does not exceed 176/65536 over the 
 * entire supported argument range.
 */
NvSFx NvSFxPow2(NvSFx x);

/*
 * NvSFxFloat2Fixed converts the floating-point number f into a S15.16 fixed
 * point number. The result is identical to ((int)(f * 65536.0f + 0.5f)) for
 * f >= 0, and ((int)(f * 65536.0f - 0.5f)) for f < 0. Using this function 
 * avoids floating-point computation which is slow without FPU. The result is 
 * undefined if f does not satisfy -32768.0 < f < 32767.99998.
 */
NvSFx NvSFxFloat2Fixed(float f);

/*
 * NvSFxAtan2D computes an approximation to the principal value of arctangent 
 * of y/x, using the signs of both arguments to determine the quadrant of the
 * return value. The value of the arctangent returned is in degrees (where a
 * full circle comprises 360 degrees) and is in [-180, 180]. Zero is returned 
 * if both arguments are zero. The magnitude of the error should not exceed 
 * 2/65536 (determined by comparing a large number of results to a floating-
 * point reference).
 */
NvSFx NvSFxAtan2D (NvSFx y, NvSFx x);

/*
 * NvSFxAsinD computes an approximation to the principal value of arcsine of 
 * x. The value of the arc sine returned is in degrees (where a full circle 
 * comprises 360 degrees) and is in [-90, 90]. The result is undefined if the 
 * input does not satisfy -1 <= x <= 1. The magnitude of the approximation 
 * error does not exceed 3/65536 over the entire legal argument range.
 */
NvSFx NvSFxAsinD (NvSFx x);

/*
 * NvSFxAcosD computes an approximation to the principal value of arcsine of 
 * x. The value of the arc cosine returned is in degrees (where a full circle 
 * comprises 360 degrees) and is in [-90, 90]. The result is undefined if the 
 * input does not satisfy -1 <= x <= 1. The magnitude of the approximation 
 * error does not exceed 3/65536 over the entire legal argument range.
 */
NvSFx NvSFxAcosD (NvSFx x);

#ifdef __cplusplus
}
#endif

#endif /* NVFXMATH_H */
