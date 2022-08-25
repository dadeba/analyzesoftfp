# 1 "multf3.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "multf3.c"
# 31 "multf3.c"
# 1 "soft-fp.h" 1
# 42 "soft-fp.h"
# 1 "../config/i386/sfp-machine.h" 1







typedef int __gcc_CMPtype __attribute__ ((mode (__libgcc_cmp_return__)));



# 1 "../config/i386/64/sfp-machine.h" 1





typedef int TItype __attribute__ ((mode (TI)));
typedef unsigned int UTItype __attribute__ ((mode (TI)));
# 13 "../config/i386/sfp-machine.h" 2
# 56 "../config/i386/sfp-machine.h"
void __sfp_handle_exceptions (int);
# 43 "soft-fp.h" 2
# 317 "soft-fp.h"
# 1 "op-1.h" 1
# 318 "soft-fp.h" 2
# 1 "op-2.h" 1
# 319 "soft-fp.h" 2
# 1 "op-4.h" 1
# 320 "soft-fp.h" 2
# 1 "op-8.h" 1
# 321 "soft-fp.h" 2
# 1 "op-common.h" 1
# 322 "soft-fp.h" 2





typedef int QItype __attribute__ ((mode (QI)));
typedef int SItype __attribute__ ((mode (SI)));
typedef int DItype __attribute__ ((mode (DI)));
typedef unsigned int UQItype __attribute__ ((mode (QI)));
typedef unsigned int USItype __attribute__ ((mode (SI)));
typedef unsigned int UDItype __attribute__ ((mode (DI)));



typedef USItype UHWtype;
# 350 "soft-fp.h"
# 1 "../../include/longlong.h" 1
# 60 "../../include/longlong.h"
extern const UQItype __clz_tab[256] ;
# 351 "soft-fp.h" 2
# 32 "multf3.c" 2
# 1 "quad.h" 1
# 72 "quad.h"
typedef float TFtype __attribute__ ((mode (TF)));
# 203 "quad.h"
union _FP_UNION_Q
{
  TFtype flt ;
  struct
  {
    unsigned long long a, b;
  } longs;
  struct
  {






    unsigned long long frac0 : 64;
    unsigned long long frac1 : 113 - (((unsigned long long) 1 << (113 -1) % 64) != 0) - 64;
    unsigned exp : 15;
    unsigned sign : 1;

  } bits;
};
# 33 "multf3.c" 2

TFtype
__multf3 (TFtype a, TFtype b)
{
  int _fex = 0; unsigned int _fcw __attribute__ ((unused)) = 0;;
  long long A_c __attribute__ ((unused)) ; long long A_s __attribute__ ((unused)) ; long long A_e __attribute__ ((unused)) ; unsigned long long A_f0 , A_f1 ;
  long long B_c __attribute__ ((unused)) ; long long B_s __attribute__ ((unused)) ; long long B_e __attribute__ ((unused)) ; unsigned long long B_f0 , B_f1 ;
  long long R_c __attribute__ ((unused)) ; long long R_s __attribute__ ((unused)) ; long long R_e __attribute__ ((unused)) ; unsigned long long R_f0 , R_f1 ;
  TFtype r;

  do { __asm__ __volatile__ ("%vstmxcsr\t%0" : "=m" (_fcw)); } while (0);
  do { do { union _FP_UNION_Q _FP_UNPACK_RAW_2_flo; _FP_UNPACK_RAW_2_flo.flt = ((a)); A_f0 = _FP_UNPACK_RAW_2_flo.bits.frac0; A_f1 = _FP_UNPACK_RAW_2_flo.bits.frac1; A_e = _FP_UNPACK_RAW_2_flo.bits.exp; A_s = _FP_UNPACK_RAW_2_flo.bits.sign; } while (0); do { switch (A_e) { default: (A_f1) |= ((unsigned long long) 1 << (113 -1) % 64); (void) (((3) < 64) ? ({ if (__builtin_constant_p (3) && (3) == 1) { A_f1 = A_f1 + A_f1 + (((signed long long) (A_f0)) < 0); A_f0 += A_f0; } else { A_f1 = A_f1 << (3) | A_f0 >> (64 - (3)); A_f0 <<= (3); } 0; }) : ({ A_f1 = A_f0 << ((3) - 64); A_f0 = 0; })); A_e -= 16383; A_c = 0; break; case 0: if (((A_f1 | A_f0) == 0)) A_c = 1; else if (0) { A_c = 1; (A_f0 = 0, A_f1 = 0); _fex |= (0x02); } else { long long _FP_UNPACK_CANONICAL_shift; do { if (A_f1) do { _Static_assert (((sizeof (unsigned long long) == sizeof (unsigned int) || (sizeof (unsigned long long) == sizeof (unsigned long)) || (sizeof (unsigned long long) == sizeof (unsigned long long)))), "_FP_W_TYPE size unsupported for clz"); if (sizeof (unsigned long long) == sizeof (unsigned int)) ((_FP_UNPACK_CANONICAL_shift)) = __builtin_clz (A_f1); else if (sizeof (unsigned long long) == sizeof (unsigned long)) ((_FP_UNPACK_CANONICAL_shift)) = __builtin_clzl (A_f1); else ((_FP_UNPACK_CANONICAL_shift)) = __builtin_clzll (A_f1); } while (0); else { do { _Static_assert (((sizeof (unsigned long long) == sizeof (unsigned int) || (sizeof (unsigned long long) == sizeof (unsigned long)) || (sizeof (unsigned long long) == sizeof (unsigned long long)))), "_FP_W_TYPE size unsupported for clz"); if (sizeof (unsigned long long) == sizeof (unsigned int)) ((_FP_UNPACK_CANONICAL_shift)) = __builtin_clz (A_f0); else if (sizeof (unsigned long long) == sizeof (unsigned long)) ((_FP_UNPACK_CANONICAL_shift)) = __builtin_clzl (A_f0); else ((_FP_UNPACK_CANONICAL_shift)) = __builtin_clzll (A_f0); } while (0); (_FP_UNPACK_CANONICAL_shift) += 64; } } while (0); _FP_UNPACK_CANONICAL_shift -= ((2*64) - 113); (void) ((((_FP_UNPACK_CANONICAL_shift + 3)) < 64) ? ({ if (__builtin_constant_p ((_FP_UNPACK_CANONICAL_shift + 3)) && ((_FP_UNPACK_CANONICAL_shift + 3)) == 1) { A_f1 = A_f1 + A_f1 + (((signed long long) (A_f0)) < 0); A_f0 += A_f0; } else { A_f1 = A_f1 << ((_FP_UNPACK_CANONICAL_shift + 3)) | A_f0 >> (64 - ((_FP_UNPACK_CANONICAL_shift + 3))); A_f0 <<= ((_FP_UNPACK_CANONICAL_shift + 3)); } 0; }) : ({ A_f1 = A_f0 << (((_FP_UNPACK_CANONICAL_shift + 3)) - 64); A_f0 = 0; })); A_e -= (16383 - 1 + _FP_UNPACK_CANONICAL_shift); A_c = 0; _fex |= (0x02); } break; case 32767: if (((A_f1 | A_f0) == 0)) A_c = 2; else { A_c = 3; if (((0) ? ((A_f1) & ((unsigned long long) 1 << (113 -2) % 64)) : !((A_f1) & ((unsigned long long) 1 << (113 -2) % 64)))) _fex |= (0x01 | 0); } break; } } while (0); } while (0);
  do { do { union _FP_UNION_Q _FP_UNPACK_RAW_2_flo; _FP_UNPACK_RAW_2_flo.flt = ((b)); B_f0 = _FP_UNPACK_RAW_2_flo.bits.frac0; B_f1 = _FP_UNPACK_RAW_2_flo.bits.frac1; B_e = _FP_UNPACK_RAW_2_flo.bits.exp; B_s = _FP_UNPACK_RAW_2_flo.bits.sign; } while (0); do { switch (B_e) { default: (B_f1) |= ((unsigned long long) 1 << (113 -1) % 64); (void) (((3) < 64) ? ({ if (__builtin_constant_p (3) && (3) == 1) { B_f1 = B_f1 + B_f1 + (((signed long long) (B_f0)) < 0); B_f0 += B_f0; } else { B_f1 = B_f1 << (3) | B_f0 >> (64 - (3)); B_f0 <<= (3); } 0; }) : ({ B_f1 = B_f0 << ((3) - 64); B_f0 = 0; })); B_e -= 16383; B_c = 0; break; case 0: if (((B_f1 | B_f0) == 0)) B_c = 1; else if (0) { B_c = 1; (B_f0 = 0, B_f1 = 0); _fex |= (0x02); } else { long long _FP_UNPACK_CANONICAL_shift; do { if (B_f1) do { _Static_assert (((sizeof (unsigned long long) == sizeof (unsigned int) || (sizeof (unsigned long long) == sizeof (unsigned long)) || (sizeof (unsigned long long) == sizeof (unsigned long long)))), "_FP_W_TYPE size unsupported for clz"); if (sizeof (unsigned long long) == sizeof (unsigned int)) ((_FP_UNPACK_CANONICAL_shift)) = __builtin_clz (B_f1); else if (sizeof (unsigned long long) == sizeof (unsigned long)) ((_FP_UNPACK_CANONICAL_shift)) = __builtin_clzl (B_f1); else ((_FP_UNPACK_CANONICAL_shift)) = __builtin_clzll (B_f1); } while (0); else { do { _Static_assert (((sizeof (unsigned long long) == sizeof (unsigned int) || (sizeof (unsigned long long) == sizeof (unsigned long)) || (sizeof (unsigned long long) == sizeof (unsigned long long)))), "_FP_W_TYPE size unsupported for clz"); if (sizeof (unsigned long long) == sizeof (unsigned int)) ((_FP_UNPACK_CANONICAL_shift)) = __builtin_clz (B_f0); else if (sizeof (unsigned long long) == sizeof (unsigned long)) ((_FP_UNPACK_CANONICAL_shift)) = __builtin_clzl (B_f0); else ((_FP_UNPACK_CANONICAL_shift)) = __builtin_clzll (B_f0); } while (0); (_FP_UNPACK_CANONICAL_shift) += 64; } } while (0); _FP_UNPACK_CANONICAL_shift -= ((2*64) - 113); (void) ((((_FP_UNPACK_CANONICAL_shift + 3)) < 64) ? ({ if (__builtin_constant_p ((_FP_UNPACK_CANONICAL_shift + 3)) && ((_FP_UNPACK_CANONICAL_shift + 3)) == 1) { B_f1 = B_f1 + B_f1 + (((signed long long) (B_f0)) < 0); B_f0 += B_f0; } else { B_f1 = B_f1 << ((_FP_UNPACK_CANONICAL_shift + 3)) | B_f0 >> (64 - ((_FP_UNPACK_CANONICAL_shift + 3))); B_f0 <<= ((_FP_UNPACK_CANONICAL_shift + 3)); } 0; }) : ({ B_f1 = B_f0 << (((_FP_UNPACK_CANONICAL_shift + 3)) - 64); B_f0 = 0; })); B_e -= (16383 - 1 + _FP_UNPACK_CANONICAL_shift); B_c = 0; _fex |= (0x02); } break; case 32767: if (((B_f1 | B_f0) == 0)) B_c = 2; else { B_c = 3; if (((0) ? ((B_f1) & ((unsigned long long) 1 << (113 -2) % 64)) : !((B_f1) & ((unsigned long long) 1 << (113 -2) % 64)))) _fex |= (0x01 | 0); } break; } } while (0); } while (0);
  do { R_s = A_s ^ B_s; R_e = A_e + B_e + 1; switch ((((A_c) << 2) | (B_c))) { case (((0) << 2) | (0)): R_c = 0; do { unsigned long long _FP_MUL_MEAT_2_wide_z_f[4]; do { unsigned long long _FP_MUL_MEAT_DW_2_wide_b_f0 , _FP_MUL_MEAT_DW_2_wide_b_f1 ; unsigned long long _FP_MUL_MEAT_DW_2_wide_c_f0 , _FP_MUL_MEAT_DW_2_wide_c_f1 ; __asm__ ("mul{q} %3" : "=a" ((UDItype) ((_FP_MUL_MEAT_2_wide_z_f[0]))), "=d" ((UDItype) ((_FP_MUL_MEAT_2_wide_z_f[1]))) : "%0" ((UDItype) (A_f0)), "rm" ((UDItype) (B_f0))); __asm__ ("mul{q} %3" : "=a" ((UDItype) (_FP_MUL_MEAT_DW_2_wide_b_f0)), "=d" ((UDItype) (_FP_MUL_MEAT_DW_2_wide_b_f1)) : "%0" ((UDItype) (A_f0)), "rm" ((UDItype) (B_f1))); __asm__ ("mul{q} %3" : "=a" ((UDItype) (_FP_MUL_MEAT_DW_2_wide_c_f0)), "=d" ((UDItype) (_FP_MUL_MEAT_DW_2_wide_c_f1)) : "%0" ((UDItype) (A_f1)), "rm" ((UDItype) (B_f0))); __asm__ ("mul{q} %3" : "=a" ((UDItype) ((_FP_MUL_MEAT_2_wide_z_f[2]))), "=d" ((UDItype) ((_FP_MUL_MEAT_2_wide_z_f[3]))) : "%0" ((UDItype) (A_f1)), "rm" ((UDItype) (B_f1))); do { unsigned long long __FP_FRAC_ADD_3_c1, __FP_FRAC_ADD_3_c2; (_FP_MUL_MEAT_2_wide_z_f[1]) = _FP_MUL_MEAT_DW_2_wide_b_f0 + (_FP_MUL_MEAT_2_wide_z_f[1]); __FP_FRAC_ADD_3_c1 = (_FP_MUL_MEAT_2_wide_z_f[1]) < _FP_MUL_MEAT_DW_2_wide_b_f0; (_FP_MUL_MEAT_2_wide_z_f[2]) = _FP_MUL_MEAT_DW_2_wide_b_f1 + (_FP_MUL_MEAT_2_wide_z_f[2]); __FP_FRAC_ADD_3_c2 = (_FP_MUL_MEAT_2_wide_z_f[2]) < _FP_MUL_MEAT_DW_2_wide_b_f1; (_FP_MUL_MEAT_2_wide_z_f[2]) += __FP_FRAC_ADD_3_c1; __FP_FRAC_ADD_3_c2 |= (_FP_MUL_MEAT_2_wide_z_f[2]) < __FP_FRAC_ADD_3_c1; (_FP_MUL_MEAT_2_wide_z_f[3]) = 0 + (_FP_MUL_MEAT_2_wide_z_f[3]) + __FP_FRAC_ADD_3_c2; } while (0); do { unsigned long long __FP_FRAC_ADD_3_c1, __FP_FRAC_ADD_3_c2; (_FP_MUL_MEAT_2_wide_z_f[1]) = _FP_MUL_MEAT_DW_2_wide_c_f0 + (_FP_MUL_MEAT_2_wide_z_f[1]); __FP_FRAC_ADD_3_c1 = (_FP_MUL_MEAT_2_wide_z_f[1]) < _FP_MUL_MEAT_DW_2_wide_c_f0; (_FP_MUL_MEAT_2_wide_z_f[2]) = _FP_MUL_MEAT_DW_2_wide_c_f1 + (_FP_MUL_MEAT_2_wide_z_f[2]); __FP_FRAC_ADD_3_c2 = (_FP_MUL_MEAT_2_wide_z_f[2]) < _FP_MUL_MEAT_DW_2_wide_c_f1; (_FP_MUL_MEAT_2_wide_z_f[2]) += __FP_FRAC_ADD_3_c1; __FP_FRAC_ADD_3_c2 |= (_FP_MUL_MEAT_2_wide_z_f[2]) < __FP_FRAC_ADD_3_c1; (_FP_MUL_MEAT_2_wide_z_f[3]) = 0 + (_FP_MUL_MEAT_2_wide_z_f[3]) + __FP_FRAC_ADD_3_c2; } while (0); } while (0); do { int _FP_FRAC_SRS_4_sticky; do { long long _FP_FRAC_SRST_4_up, _FP_FRAC_SRST_4_down; long long _FP_FRAC_SRST_4_skip, _FP_FRAC_SRST_4_i; unsigned long long _FP_FRAC_SRST_4_s; _FP_FRAC_SRST_4_skip = ((((3 + 113))-1)) / 64; _FP_FRAC_SRST_4_down = ((((3 + 113))-1)) % 64; _FP_FRAC_SRST_4_up = 64 - _FP_FRAC_SRST_4_down; for (_FP_FRAC_SRST_4_s = _FP_FRAC_SRST_4_i = 0; _FP_FRAC_SRST_4_i < _FP_FRAC_SRST_4_skip; ++_FP_FRAC_SRST_4_i) _FP_FRAC_SRST_4_s |= _FP_MUL_MEAT_2_wide_z_f[_FP_FRAC_SRST_4_i]; if (!_FP_FRAC_SRST_4_down) for (_FP_FRAC_SRST_4_i = 0; _FP_FRAC_SRST_4_i <= 3-_FP_FRAC_SRST_4_skip; ++_FP_FRAC_SRST_4_i) _FP_MUL_MEAT_2_wide_z_f[_FP_FRAC_SRST_4_i] = _FP_MUL_MEAT_2_wide_z_f[_FP_FRAC_SRST_4_i+_FP_FRAC_SRST_4_skip]; else { _FP_FRAC_SRST_4_s |= _FP_MUL_MEAT_2_wide_z_f[_FP_FRAC_SRST_4_i] << _FP_FRAC_SRST_4_up; for (_FP_FRAC_SRST_4_i = 0; _FP_FRAC_SRST_4_i < 3-_FP_FRAC_SRST_4_skip; ++_FP_FRAC_SRST_4_i) _FP_MUL_MEAT_2_wide_z_f[_FP_FRAC_SRST_4_i] = ((_FP_MUL_MEAT_2_wide_z_f[_FP_FRAC_SRST_4_i+_FP_FRAC_SRST_4_skip] >> _FP_FRAC_SRST_4_down) | (_FP_MUL_MEAT_2_wide_z_f[_FP_FRAC_SRST_4_i+_FP_FRAC_SRST_4_skip+1] << _FP_FRAC_SRST_4_up)); _FP_MUL_MEAT_2_wide_z_f[_FP_FRAC_SRST_4_i++] = _FP_MUL_MEAT_2_wide_z_f[3] >> _FP_FRAC_SRST_4_down; } for (; _FP_FRAC_SRST_4_i < 4; ++_FP_FRAC_SRST_4_i) _FP_MUL_MEAT_2_wide_z_f[_FP_FRAC_SRST_4_i] = 0; _FP_FRAC_SRS_4_sticky = (_FP_FRAC_SRST_4_s != 0); } while (0); _FP_MUL_MEAT_2_wide_z_f[0] |= _FP_FRAC_SRS_4_sticky; } while (0); R_f0 = (_FP_MUL_MEAT_2_wide_z_f[0]); R_f1 = (_FP_MUL_MEAT_2_wide_z_f[1]); } while (0); if (((R_f1) & ((unsigned long long) 1 << ((3 + 113) % 64)))) (void) (((1) < 64) ? ({ R_f0 = (R_f1 << (64 - (1)) | R_f0 >> (1) | (__builtin_constant_p (1) && (1) == 1 ? R_f0 & 1 : (R_f0 << (64 - (1))) != 0)); R_f1 >>= (1); }) : ({ R_f0 = (R_f1 >> ((1) - 64) | ((((1) == 64 ? 0 : (R_f1 << (2*64 - (1)))) | R_f0) != 0)); R_f1 = 0; })); else R_e--; break; case (((3) << 2) | (3)): do { if ((A_f1 > B_f1 || (A_f1 == B_f1 && A_f0 > B_f0)) || ((A_f1 == B_f1 && A_f0 == B_f0) && ('*' == '+' || '*' == '*'))) { R_s = A_s; (R_f0 = A_f0, R_f1 = A_f1); } else { R_s = B_s; (R_f0 = B_f0, R_f1 = B_f1); } R_c = 3; } while (0); break; case (((3) << 2) | (0)): case (((3) << 2) | (2)): case (((3) << 2) | (1)): R_s = A_s; case (((2) << 2) | (2)): case (((2) << 2) | (0)): case (((1) << 2) | (0)): case (((1) << 2) | (1)): (R_f0 = A_f0, R_f1 = A_f1); R_c = A_c; break; case (((0) << 2) | (3)): case (((2) << 2) | (3)): case (((1) << 2) | (3)): R_s = B_s; case (((0) << 2) | (2)): case (((0) << 2) | (1)): (R_f0 = B_f0, R_f1 = B_f1); R_c = B_c; break; case (((2) << 2) | (1)): case (((1) << 2) | (2)): R_s = 1; R_c = 3; (R_f0 = 0, R_f1 = ((unsigned long long) 1 << (113 -2) % 64)); _fex |= (0x01 | 0); break; default: __builtin_unreachable (); } } while (0);
  do { do { switch (R_c) { case 0: R_e += 16383; if (R_e > 0) { do { if ((R_f0) & 7) { _fex |= (0x20); switch ((_fcw & 0x6000)) { case 0: do { if (((R_f0) & 15) != ((unsigned long long) 1 << 2)) __asm__ ("add{q} {%5,%1|%1,%5}\n\tadc{q} {%3,%0|%0,%3}" : "=r" ((UDItype) (R_f1)), "=&r" ((UDItype) (R_f0)) : "%0" ((UDItype) (R_f1)), "rme" ((UDItype) (0)), "%1" ((UDItype) (R_f0)), "rme" ((UDItype) (((unsigned long long) 1 << 2)))); } while (0); break; case 0x6000: (void) 0; break; case 0x4000: do { if (!R_s && ((R_f0) & 7)) __asm__ ("add{q} {%5,%1|%1,%5}\n\tadc{q} {%3,%0|%0,%3}" : "=r" ((UDItype) (R_f1)), "=&r" ((UDItype) (R_f0)) : "%0" ((UDItype) (R_f1)), "rme" ((UDItype) (0)), "%1" ((UDItype) (R_f0)), "rme" ((UDItype) (((unsigned long long) 1 << 3)))); } while (0); break; case 0x2000: do { if (R_s && ((R_f0) & 7)) __asm__ ("add{q} {%5,%1|%1,%5}\n\tadc{q} {%3,%0|%0,%3}" : "=r" ((UDItype) (R_f1)), "=&r" ((UDItype) (R_f0)) : "%0" ((UDItype) (R_f1)), "rme" ((UDItype) (0)), "%1" ((UDItype) (R_f0)), "rme" ((UDItype) (((unsigned long long) 1 << 3)))); } while (0); break; } } } while (0); if (((R_f1) & ((unsigned long long) 1 << ((3 + 113) % 64)))) { ((R_f1) &= ~((unsigned long long) 1 << ((3 + 113) % 64))); R_e++; } (void) (((3) < 64) ? ({ R_f0 = R_f0 >> (3) | R_f1 << (64 - (3)); R_f1 >>= (3); }) : ({ R_f0 = R_f1 >> ((3) - 64); R_f1 = 0; })); if (R_e >= 32767) { switch ((_fcw & 0x6000)) { case 0: R_c = 2; break; case 0x4000: if (!R_s) R_c = 2; break; case 0x2000: if (R_s) R_c = 2; break; } if (R_c == 2) { R_e = 32767; (R_f0 = 0, R_f1 = 0); } else { R_e = 32767 - 1; (R_f0 = (~(signed long long) 0), R_f1 = (~(signed long long) 0)); } _fex |= (0x08); _fex |= (0x20); } } else { int _FP_PACK_CANONICAL_is_tiny = 1; if (1 && R_e == 0) { long long _FP_PACK_CANONICAL_T_c __attribute__ ((unused)) ; long long _FP_PACK_CANONICAL_T_s __attribute__ ((unused)) ; long long _FP_PACK_CANONICAL_T_e __attribute__ ((unused)) ; unsigned long long _FP_PACK_CANONICAL_T_f0 , _FP_PACK_CANONICAL_T_f1 ; (_FP_PACK_CANONICAL_T_f0 = R_f0, _FP_PACK_CANONICAL_T_f1 = R_f1); _FP_PACK_CANONICAL_T_s = R_s; _FP_PACK_CANONICAL_T_e = R_e; do { if ((_FP_PACK_CANONICAL_T_f0) & 7) { _fex |= (0x20); switch ((_fcw & 0x6000)) { case 0: do { if (((_FP_PACK_CANONICAL_T_f0) & 15) != ((unsigned long long) 1 << 2)) __asm__ ("add{q} {%5,%1|%1,%5}\n\tadc{q} {%3,%0|%0,%3}" : "=r" ((UDItype) (_FP_PACK_CANONICAL_T_f1)), "=&r" ((UDItype) (_FP_PACK_CANONICAL_T_f0)) : "%0" ((UDItype) (_FP_PACK_CANONICAL_T_f1)), "rme" ((UDItype) (0)), "%1" ((UDItype) (_FP_PACK_CANONICAL_T_f0)), "rme" ((UDItype) (((unsigned long long) 1 << 2)))); } while (0); break; case 0x6000: (void) 0; break; case 0x4000: do { if (!_FP_PACK_CANONICAL_T_s && ((_FP_PACK_CANONICAL_T_f0) & 7)) __asm__ ("add{q} {%5,%1|%1,%5}\n\tadc{q} {%3,%0|%0,%3}" : "=r" ((UDItype) (_FP_PACK_CANONICAL_T_f1)), "=&r" ((UDItype) (_FP_PACK_CANONICAL_T_f0)) : "%0" ((UDItype) (_FP_PACK_CANONICAL_T_f1)), "rme" ((UDItype) (0)), "%1" ((UDItype) (_FP_PACK_CANONICAL_T_f0)), "rme" ((UDItype) (((unsigned long long) 1 << 3)))); } while (0); break; case 0x2000: do { if (_FP_PACK_CANONICAL_T_s && ((_FP_PACK_CANONICAL_T_f0) & 7)) __asm__ ("add{q} {%5,%1|%1,%5}\n\tadc{q} {%3,%0|%0,%3}" : "=r" ((UDItype) (_FP_PACK_CANONICAL_T_f1)), "=&r" ((UDItype) (_FP_PACK_CANONICAL_T_f0)) : "%0" ((UDItype) (_FP_PACK_CANONICAL_T_f1)), "rme" ((UDItype) (0)), "%1" ((UDItype) (_FP_PACK_CANONICAL_T_f0)), "rme" ((UDItype) (((unsigned long long) 1 << 3)))); } while (0); break; } } } while (0); if (((_FP_PACK_CANONICAL_T_f1) & ((unsigned long long) 1 << ((3 + 113) % 64)))) _FP_PACK_CANONICAL_is_tiny = 0; } R_e = -R_e + 1; if (R_e <= (3 + 113)) { (void) (((R_e) < 64) ? ({ R_f0 = (R_f1 << (64 - (R_e)) | R_f0 >> (R_e) | (__builtin_constant_p (R_e) && (R_e) == 1 ? R_f0 & 1 : (R_f0 << (64 - (R_e))) != 0)); R_f1 >>= (R_e); }) : ({ R_f0 = (R_f1 >> ((R_e) - 64) | ((((R_e) == 64 ? 0 : (R_f1 << (2*64 - (R_e)))) | R_f0) != 0)); R_f1 = 0; })); do { if ((R_f0) & 7) { _fex |= (0x20); switch ((_fcw & 0x6000)) { case 0: do { if (((R_f0) & 15) != ((unsigned long long) 1 << 2)) __asm__ ("add{q} {%5,%1|%1,%5}\n\tadc{q} {%3,%0|%0,%3}" : "=r" ((UDItype) (R_f1)), "=&r" ((UDItype) (R_f0)) : "%0" ((UDItype) (R_f1)), "rme" ((UDItype) (0)), "%1" ((UDItype) (R_f0)), "rme" ((UDItype) (((unsigned long long) 1 << 2)))); } while (0); break; case 0x6000: (void) 0; break; case 0x4000: do { if (!R_s && ((R_f0) & 7)) __asm__ ("add{q} {%5,%1|%1,%5}\n\tadc{q} {%3,%0|%0,%3}" : "=r" ((UDItype) (R_f1)), "=&r" ((UDItype) (R_f0)) : "%0" ((UDItype) (R_f1)), "rme" ((UDItype) (0)), "%1" ((UDItype) (R_f0)), "rme" ((UDItype) (((unsigned long long) 1 << 3)))); } while (0); break; case 0x2000: do { if (R_s && ((R_f0) & 7)) __asm__ ("add{q} {%5,%1|%1,%5}\n\tadc{q} {%3,%0|%0,%3}" : "=r" ((UDItype) (R_f1)), "=&r" ((UDItype) (R_f0)) : "%0" ((UDItype) (R_f1)), "rme" ((UDItype) (0)), "%1" ((UDItype) (R_f0)), "rme" ((UDItype) (((unsigned long long) 1 << 3)))); } while (0); break; } } } while (0); if ((R_f1) & (((unsigned long long) 1 << ((3 + 113) % 64)) >> 1)) { R_e = 1; (R_f0 = 0, R_f1 = 0); _fex |= (0x20); } else { R_e = 0; (void) (((3) < 64) ? ({ R_f0 = R_f0 >> (3) | R_f1 << (64 - (3)); R_f1 >>= (3); }) : ({ R_f0 = R_f1 >> ((3) - 64); R_f1 = 0; })); } if (_FP_PACK_CANONICAL_is_tiny && (((_fex) & 0x20) || (((~_fcw >> 7) & (0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20)) & 0x10))) _fex |= (0x10); } else { R_e = 0; if (!((R_f1 | R_f0) == 0)) { (R_f0 = 1, R_f1 = 0); do { if ((R_f0) & 7) { _fex |= (0x20); switch ((_fcw & 0x6000)) { case 0: do { if (((R_f0) & 15) != ((unsigned long long) 1 << 2)) __asm__ ("add{q} {%5,%1|%1,%5}\n\tadc{q} {%3,%0|%0,%3}" : "=r" ((UDItype) (R_f1)), "=&r" ((UDItype) (R_f0)) : "%0" ((UDItype) (R_f1)), "rme" ((UDItype) (0)), "%1" ((UDItype) (R_f0)), "rme" ((UDItype) (((unsigned long long) 1 << 2)))); } while (0); break; case 0x6000: (void) 0; break; case 0x4000: do { if (!R_s && ((R_f0) & 7)) __asm__ ("add{q} {%5,%1|%1,%5}\n\tadc{q} {%3,%0|%0,%3}" : "=r" ((UDItype) (R_f1)), "=&r" ((UDItype) (R_f0)) : "%0" ((UDItype) (R_f1)), "rme" ((UDItype) (0)), "%1" ((UDItype) (R_f0)), "rme" ((UDItype) (((unsigned long long) 1 << 3)))); } while (0); break; case 0x2000: do { if (R_s && ((R_f0) & 7)) __asm__ ("add{q} {%5,%1|%1,%5}\n\tadc{q} {%3,%0|%0,%3}" : "=r" ((UDItype) (R_f1)), "=&r" ((UDItype) (R_f0)) : "%0" ((UDItype) (R_f1)), "rme" ((UDItype) (0)), "%1" ((UDItype) (R_f0)), "rme" ((UDItype) (((unsigned long long) 1 << 3)))); } while (0); break; } } } while (0); (R_f0) >>= (3); } _fex |= (0x10); } } break; case 1: R_e = 0; (R_f0 = 0, R_f1 = 0); break; case 2: R_e = 32767; (R_f0 = 0, R_f1 = 0); break; case 3: R_e = 32767; if (!1) { (R_f0 = 0, R_f1 = ((unsigned long long) 1 << (113 -2) % 64)); R_s = 1; } else do { if (0) { (R_f1) &= ((unsigned long long) 1 << (113 -2) % 64) - 1; if (((R_f1 | R_f0) == 0)) { R_s = 1; (R_f0 = 0, R_f1 = ((unsigned long long) 1 << (113 -2) % 64)); } } else (R_f1) |= ((unsigned long long) 1 << (113 -2) % 64); } while (0); break; } } while (0); do { union _FP_UNION_Q _FP_PACK_RAW_2_flo; _FP_PACK_RAW_2_flo.bits.frac0 = R_f0; _FP_PACK_RAW_2_flo.bits.frac1 = R_f1; _FP_PACK_RAW_2_flo.bits.exp = R_e; _FP_PACK_RAW_2_flo.bits.sign = R_s; ((r)) = _FP_PACK_RAW_2_flo.flt; } while (0); } while (0);
  do { if (__builtin_expect (_fex, 0)) __sfp_handle_exceptions (_fex); } while (0);

  return r;
}
