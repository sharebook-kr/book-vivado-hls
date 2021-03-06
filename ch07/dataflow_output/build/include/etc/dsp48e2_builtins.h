// This header file is generated by script. Don't modify it manully

#ifndef _DSP48E2_BUILTINS_H_
#define _DSP48E2_BUILTINS_H_

// Flags 
#define DSP_REGISTER_DEFAULT 0x00000000
#define DSP_REGISTER_A1 0x00000001
#define DSP_REGISTER_A2 0x00000002
#define DSP_REGISTER_B1 0x00000004
#define DSP_REGISTER_B2 0x00000008
#define DSP_REGISTER_D 0x00000010
#define DSP_REGISTER_AD 0x00000020
#define DSP_REGISTER_M 0x00000040
#define DSP_REGISTER_C 0x00000080
#define DSP_REGISTER_P 0x00000100
#define DSP_REGISTER_NO 0x00000200

// DSP builtin wrapper functions

static inline __dsp48_t
__builtin_madd(
    int64_t flags,
    __dsp27_t a,
    __dsp18_t b,
    __dsp48_t c) __attribute__((always_inline));

static inline __dsp48_t
__builtin_msub(
    int64_t flags,
    __dsp27_t a,
    __dsp18_t b,
    __dsp48_t c) __attribute__((always_inline));

static inline __dsp48_t
__builtin_msubed(
    int64_t flags,
    __dsp27_t a,
    __dsp18_t b,
    __dsp48_t c) __attribute__((always_inline));

static inline __dsp48_t
__builtin_simd_4add(
    int64_t flags,
    __dsp48_t a,
    __dsp48_t b) __attribute__((always_inline));

static inline __dsp48_t
__builtin_simd_4sub(
    int64_t flags,
    __dsp48_t a,
    __dsp48_t b) __attribute__((always_inline));

static inline __dsp48_t
__builtin_simd_2add(
    int64_t flags,
    __dsp48_t a,
    __dsp48_t b) __attribute__((always_inline));

static inline __dsp48_t
__builtin_simd_2sub(
    int64_t flags,
    __dsp48_t a,
    __dsp48_t b) __attribute__((always_inline));

static inline __dsp48_t
__builtin_amadd(
    int64_t flags,
    __dsp27_t a,
    __dsp27_t d,
    __dsp18_t b,
    __dsp48_t c) __attribute__((always_inline));

static inline __dsp48_t
__builtin_amsub(
    int64_t flags,
    __dsp27_t a,
    __dsp27_t d,
    __dsp18_t b,
    __dsp48_t c) __attribute__((always_inline));

static inline __dsp48_t
__builtin_square_sub_add(
    int64_t flags,
    __dsp17_t a,
    __dsp17_t d,
    __dsp48_t c) __attribute__((always_inline));

static inline __dsp48_t
__builtin_square_add_subed(
    int64_t flags,
    __dsp17_t a,
    __dsp17_t d,
    __dsp48_t c) __attribute__((always_inline));


#ifdef __HLS_SYN__
// DSP state type
typedef __dsp48_t __xilinx_dsp_state;
#ifdef __cplusplus
extern "C" {
#endif

int64_t __attribute__((bitwidth(48)))
_ssdm_op_DSP( 
    __xilinx_dsp_state *state, // Pass nullptr if we do not do accumulation 
    int32_t func_index,
    int64_t flags,
    int32_t __attribute__((bitwidth(27))) d,
    int32_t __attribute__((bitwidth(30))) a,
    int32_t __attribute__((bitwidth(18))) b,
    int64_t __attribute__((bitwidth(48))) c,
    int32_t __attribute__((bitwidth(30))) acin,
    int32_t __attribute__((bitwidth(18))) bcin,
    int64_t __attribute__((bitwidth(48))) pcin,
    int32_t __attribute__((bitwidth(1))) carrycascin,
    int32_t __attribute__((bitwidth(1))) multsignin,
    int32_t __attribute__((bitwidth(1))) carryin,
    int32_t __attribute__((bitwidth(30)))* acout,
    int32_t __attribute__((bitwidth(18)))* bcout,
    int32_t __attribute__((bitwidth(1)))* multsignout,
    int32_t __attribute__((bitwidth(1)))* carrycasCout,
    int32_t __attribute__((bitwidth(4)))* carryout);

int64_t __attribute__((bitwidth(48)))
_ssdm_op_DSP_AB( 
    __xilinx_dsp_state *state, // Pass nullptr if we do not do accumulation 
    int32_t func_index,
    int64_t flags,
    int64_t __attribute__((bitwidth(48))) ab,
    int64_t __attribute__((bitwidth(48))) c,
    int32_t __attribute__((bitwidth(1))) carryin,
    int32_t __attribute__((bitwidth(30)))* acout,
    int32_t __attribute__((bitwidth(18)))* bcout,
    int32_t __attribute__((bitwidth(4)))* carryout);
#ifdef __cplusplus
}
#endif
#endif
__dsp48_t
__builtin_madd(
    int64_t flags,
    __dsp27_t a,
    __dsp18_t b,
    __dsp48_t c)
{
#ifndef __HLS_SYN__
  return ((__dsp48_t)a) * ((__dsp48_t)b) + c;
#else
  return (int64_t)_ssdm_op_DSP(0, 0, flags, 0, a, b, c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
#endif
}

__dsp48_t
__builtin_msub(
    int64_t flags,
    __dsp27_t a,
    __dsp18_t b,
    __dsp48_t c)
{
#ifndef __HLS_SYN__
  return ((__dsp48_t)a) * ((__dsp48_t)b) - c;
#else
  return (int64_t)_ssdm_op_DSP(0, 1, flags, 0, a, b, c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
#endif
}

__dsp48_t
__builtin_msubed(
    int64_t flags,
    __dsp27_t a,
    __dsp18_t b,
    __dsp48_t c)
{
#ifndef __HLS_SYN__
  return c - ((__dsp48_t)a) * ((__dsp48_t)b);
#else
  return (int64_t)_ssdm_op_DSP(0, 2, flags, 0, a, b, c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
#endif
}

__dsp48_t
__builtin_simd_4add(
    int64_t flags,
    __dsp48_t a,
    __dsp48_t b)
{
#ifndef __HLS_SYN__
  	__dsp48_t a1 = a & 0xFFF;
	__dsp48_t a2 = (a & 0xFFF000) >> 12;
	__dsp48_t a3 = (a & 0xFFF000000) >> 24;
	__dsp48_t a4 = (a & 0xFFF000000000) >> 36;
	__dsp48_t b1 = b & 0xFFF;
	__dsp48_t b2 = (b & 0xFFF000) >> 12;
	__dsp48_t b3 = (b & 0xFFF000000) >> 24;
	__dsp48_t b4 = (b & 0xFFF000000000) >> 36;
	__dsp48_t p1, p2, p3, p4;
	__dsp48_t p;
	p1 = a1 + b1;
	p2 = a2 + b2;
	p3 = a3 + b3;
	p4 = a4 + b4;
	p = ((p4 & 0xFFF) << 36) + ((p3 & 0xFFF) << 24) + ((p2 & 0xFFF) << 12) + (p1 & 0xFFF);
	return p;
#else
  return (int64_t)_ssdm_op_DSP_AB(0, 3, flags, a, b, 0, 0, 0, 0);
#endif
}

__dsp48_t
__builtin_simd_4sub(
    int64_t flags,
    __dsp48_t a,
    __dsp48_t b)
{
#ifndef __HLS_SYN__
  	__dsp48_t a1 = a & 0xFFF;
	__dsp48_t a2 = (a & 0xFFF000) >> 12;
	__dsp48_t a3 = (a & 0xFFF000000) >> 24;
	__dsp48_t a4 = (a & 0xFFF000000000) >> 36;
	__dsp48_t b1 = b & 0xFFF;
	__dsp48_t b2 = (b & 0xFFF000) >> 12;
	__dsp48_t b3 = (b & 0xFFF000000) >> 24;
	__dsp48_t b4 = (b & 0xFFF000000000) >> 36;
	__dsp48_t p1, p2, p3, p4;
	__dsp48_t p;
	p1 = a1 - b1;
	p2 = a2 - b2;
	p3 = a3 - b3;
	p4 = a4 - b4;
	p = ((p4 & 0xFFF) << 36) + ((p3 & 0xFFF) << 24) + ((p2 & 0xFFF) << 12) + (p1 & 0xFFF);
	return p;
#else
  return (int64_t)_ssdm_op_DSP_AB(0, 4, flags, b, a, 0, 0, 0, 0);
#endif
}

__dsp48_t
__builtin_simd_2add(
    int64_t flags,
    __dsp48_t a,
    __dsp48_t b)
{
#ifndef __HLS_SYN__
  	__dsp48_t a1 = a & 0xFFFFFF;
	__dsp48_t a2 = (a & 0xFFFFFF000000) >> 24;
	__dsp48_t b1 = b & 0xFFFFFF;
	__dsp48_t b2 = (b & 0xFFFFFF000000) >> 24;
	__dsp48_t p1, p2;
	__dsp48_t p;
	p1 = a1 + b1;
	p2 = a2 + b2;
	p = ((p2 & 0xFFFFFF) << 24) + (p1 & 0xFFFFFF);
	return p;
#else
  return (int64_t)_ssdm_op_DSP_AB(0, 5, flags, a, b, 0, 0, 0, 0);
#endif
}

__dsp48_t
__builtin_simd_2sub(
    int64_t flags,
    __dsp48_t a,
    __dsp48_t b)
{
#ifndef __HLS_SYN__
  	__dsp48_t a1 = a & 0xFFFFFF;
	__dsp48_t a2 = (a & 0xFFFFFF000000) >> 24;
	__dsp48_t b1 = b & 0xFFFFFF;
	__dsp48_t b2 = (b & 0xFFFFFF000000) >> 24;
	__dsp48_t p1, p2;
	__dsp48_t p;
	p1 = a1 - b1;
	p2 = a2 - b2;
	p = ((p2 & 0xFFFFFF) << 24) + (p1 & 0xFFFFFF);
	return p;
#else
  return (int64_t)_ssdm_op_DSP_AB(0, 6, flags, b, a, 0, 0, 0, 0);
#endif
}

__dsp48_t
__builtin_amadd(
    int64_t flags,
    __dsp27_t a,
    __dsp27_t d,
    __dsp18_t b,
    __dsp48_t c)
{
#ifndef __HLS_SYN__
  return ((__dsp48_t)a + (__dsp48_t)d) * ((__dsp48_t)b) + c;
#else
  return (int64_t)_ssdm_op_DSP(0, 7, flags, d, a, b, c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
#endif
}

__dsp48_t
__builtin_amsub(
    int64_t flags,
    __dsp27_t a,
    __dsp27_t d,
    __dsp18_t b,
    __dsp48_t c)
{
#ifndef __HLS_SYN__
  return ((__dsp48_t)a + (__dsp48_t)d) * ((__dsp48_t)b) - c;
#else
  return (int64_t)_ssdm_op_DSP(0, 8, flags, d, a, b, c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
#endif
}

__dsp48_t
__builtin_square_sub_add(
    int64_t flags,
    __dsp17_t a,
    __dsp17_t d,
    __dsp48_t c)
{
#ifndef __HLS_SYN__
  return ((__dsp48_t)d - (__dsp48_t)a) * ((__dsp48_t)d - (__dsp48_t)a) + c;
#else
  return (int64_t)_ssdm_op_DSP(0, 11, flags, d, a, 0, c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
#endif
}

__dsp48_t
__builtin_square_add_subed(
    int64_t flags,
    __dsp17_t a,
    __dsp17_t d,
    __dsp48_t c)
{
#ifndef __HLS_SYN__
  return c - ((__dsp48_t)d + (__dsp48_t)a) * ((__dsp48_t)d + (__dsp48_t)a);
#else
  return (int64_t)_ssdm_op_DSP(0, 12, flags, d, a, 0, c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
#endif
}

#endif
