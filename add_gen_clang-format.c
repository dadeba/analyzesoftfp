# 1 "addtf3.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "addtf3.c"
# 31 "addtf3.c"
# 1 "soft-fp.h" 1
# 42 "soft-fp.h"
# 1 "../config/i386/sfp-machine.h" 1

typedef int __gcc_CMPtype __attribute__((mode(__libgcc_cmp_return__)));

# 1 "../config/i386/64/sfp-machine.h" 1

typedef int TItype __attribute__((mode(TI)));
typedef unsigned int UTItype __attribute__((mode(TI)));
# 13 "../config/i386/sfp-machine.h" 2
# 56 "../config/i386/sfp-machine.h"
void __sfp_handle_exceptions(int);
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

typedef int QItype __attribute__((mode(QI)));
typedef int SItype __attribute__((mode(SI)));
typedef int DItype __attribute__((mode(DI)));
typedef unsigned int UQItype __attribute__((mode(QI)));
typedef unsigned int USItype __attribute__((mode(SI)));
typedef unsigned int UDItype __attribute__((mode(DI)));

typedef USItype UHWtype;
# 350 "soft-fp.h"
# 1 "../../include/longlong.h" 1
# 60 "../../include/longlong.h"
extern const UQItype __clz_tab[256];
# 351 "soft-fp.h" 2
# 32 "addtf3.c" 2
# 1 "quad.h" 1
# 72 "quad.h"
typedef float TFtype __attribute__((mode(TF)));
# 203 "quad.h"
union _FP_UNION_Q {
    TFtype flt;
    struct {
        unsigned long long a, b;
    } longs;
    struct {

        unsigned long long frac0 : 64;
        unsigned long long frac1 : 113 - (((unsigned long long)1 << (113 - 1) % 64) != 0) - 64;
        unsigned exp : 15;
        unsigned sign : 1;

    } bits;
};
# 33 "addtf3.c" 2

TFtype __addtf3(TFtype a, TFtype b) {
    int _fex = 0;
    unsigned int _fcw __attribute__((unused)) = 0;
    ;
    long long A_c __attribute__((unused));
    long long A_s __attribute__((unused));
    long long A_e __attribute__((unused));
    unsigned long long A_f0, A_f1;
    long long B_c __attribute__((unused));
    long long B_s __attribute__((unused));
    long long B_e __attribute__((unused));
    unsigned long long B_f0, B_f1;
    long long R_c __attribute__((unused));
    long long R_s __attribute__((unused));
    long long R_e __attribute__((unused));
    unsigned long long R_f0, R_f1;
    TFtype r;

    do {
        __asm__ __volatile__("%vstmxcsr\t%0" : "=m"(_fcw));
    } while (0);
    do {
        do {
            union _FP_UNION_Q _FP_UNPACK_RAW_2_flo;
            _FP_UNPACK_RAW_2_flo.flt = ((a));
            A_f0 = _FP_UNPACK_RAW_2_flo.bits.frac0;
            A_f1 = _FP_UNPACK_RAW_2_flo.bits.frac1;
            A_e = _FP_UNPACK_RAW_2_flo.bits.exp;
            A_s = _FP_UNPACK_RAW_2_flo.bits.sign;
        } while (0);
        (void)(((3) < 64) ? ({
            if (__builtin_constant_p(3) && (3) == 1) {
                A_f1 = A_f1 + A_f1 + (((signed long long)(A_f0)) < 0);
                A_f0 += A_f0;
            } else {
                A_f1 = A_f1 << (3) | A_f0 >> (64 - (3));
                A_f0 <<= (3);
            }
            0;
        })
                          : ({
                                A_f1 = A_f0 << ((3) - 64);
                                A_f0 = 0;
                            }));
    } while (0);
    do {
        do {
            union _FP_UNION_Q _FP_UNPACK_RAW_2_flo;
            _FP_UNPACK_RAW_2_flo.flt = ((b));
            B_f0 = _FP_UNPACK_RAW_2_flo.bits.frac0;
            B_f1 = _FP_UNPACK_RAW_2_flo.bits.frac1;
            B_e = _FP_UNPACK_RAW_2_flo.bits.exp;
            B_s = _FP_UNPACK_RAW_2_flo.bits.sign;
        } while (0);
        (void)(((3) < 64) ? ({
            if (__builtin_constant_p(3) && (3) == 1) {
                B_f1 = B_f1 + B_f1 + (((signed long long)(B_f0)) < 0);
                B_f0 += B_f0;
            } else {
                B_f1 = B_f1 << (3) | B_f0 >> (64 - (3));
                B_f0 <<= (3);
            }
            0;
        })
                          : ({
                                B_f1 = B_f0 << ((3) - 64);
                                B_f0 = 0;
                            }));
    } while (0);
    do {
        do {
            if (0 && A_e == 0 && !((A_f1 | A_f0) == 0)) {
                (A_f0 = 0, A_f1 = 0);
                _fex |= (0x02);
            }
        } while (0);
        do {
            if (0 && B_e == 0 && !((B_f1 | B_f0) == 0)) {
                (B_f0 = 0, B_f1 = 0);
                _fex |= (0x02);
            }
        } while (0);
        if (A_s == B_s) {
            __label__ add1, add2, add3, add_done;
            R_s = A_s;
            int _FP_ADD_INTERNAL_ediff = A_e - B_e;
            if (_FP_ADD_INTERNAL_ediff > 0) {
                R_e = A_e;
                if (B_e == 0) {
                    if (((B_f1 | B_f0) == 0)) {
                        do {
                            if (A_e == 32767 && !((A_f1 | A_f0) == 0) && ((0) ? ((A_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64)) : !((A_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64))))
                                _fex |= (0x01 | 0);
                        } while (0);
                        (R_f0 = A_f0, R_f1 = A_f1);
                        goto add_done;
                    } else {
                        _fex |= (0x02);
                        _FP_ADD_INTERNAL_ediff--;
                        if (_FP_ADD_INTERNAL_ediff == 0) {
                            __asm__("add{q} {%5,%1|%1,%5}\n\tadc{q} {%3,%0|%0,%3}" : "=r"((UDItype)(R_f1)), "=&r"((UDItype)(R_f0)) : "%0"((UDItype)(A_f1)), "rme"((UDItype)(B_f1)), "%1"((UDItype)(A_f0)), "rme"((UDItype)(B_f0)));
                            goto add3;
                        }
                        if (A_e == 32767) {
                            do {
                                if (A_e == 32767 && !((A_f1 | A_f0) == 0) && ((0) ? ((A_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64)) : !((A_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64))))
                                    _fex |= (0x01 | 0);
                            } while (0);
                            (R_f0 = A_f0, R_f1 = A_f1);
                            goto add_done;
                        }
                        goto add1;
                    }
                } else if (A_e == 32767) {
                    do {
                        if (A_e == 32767 && !((A_f1 | A_f0) == 0) && ((0) ? ((A_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64)) : !((A_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64))))
                            _fex |= (0x01 | 0);
                    } while (0);
                    (R_f0 = A_f0, R_f1 = A_f1);
                    goto add_done;
                }
                (B_f1) |= ((unsigned long long)1 << (113 - 1 + 3) % 64);
            add1:
                if (_FP_ADD_INTERNAL_ediff <= (3 + 113))
                    (void)(((_FP_ADD_INTERNAL_ediff) < 64) ? ({
                        B_f0 = (B_f1 << (64 - (_FP_ADD_INTERNAL_ediff)) | B_f0 >> (_FP_ADD_INTERNAL_ediff) | (__builtin_constant_p(_FP_ADD_INTERNAL_ediff) && (_FP_ADD_INTERNAL_ediff) == 1 ? B_f0 & 1 : (B_f0 << (64 - (_FP_ADD_INTERNAL_ediff))) != 0));
                        B_f1 >>= (_FP_ADD_INTERNAL_ediff);
                    })
                                                           : ({
                                                                 B_f0 = (B_f1 >> ((_FP_ADD_INTERNAL_ediff)-64) | ((((_FP_ADD_INTERNAL_ediff) == 64 ? 0 : (B_f1 << (2 * 64 - (_FP_ADD_INTERNAL_ediff)))) | B_f0) != 0));
                                                                 B_f1 = 0;
                                                             }));
                else if (!((B_f1 | B_f0) == 0))
                    (B_f0 = 1, B_f1 = 0);
                __asm__("add{q} {%5,%1|%1,%5}\n\tadc{q} {%3,%0|%0,%3}" : "=r"((UDItype)(R_f1)), "=&r"((UDItype)(R_f0)) : "%0"((UDItype)(A_f1)), "rme"((UDItype)(B_f1)), "%1"((UDItype)(A_f0)), "rme"((UDItype)(B_f0)));
            } else if (_FP_ADD_INTERNAL_ediff < 0) {
                _FP_ADD_INTERNAL_ediff = -_FP_ADD_INTERNAL_ediff;
                R_e = B_e;
                if (A_e == 0) {
                    if (((A_f1 | A_f0) == 0)) {
                        do {
                            if (B_e == 32767 && !((B_f1 | B_f0) == 0) && ((0) ? ((B_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64)) : !((B_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64))))
                                _fex |= (0x01 | 0);
                        } while (0);
                        (R_f0 = B_f0, R_f1 = B_f1);
                        goto add_done;
                    } else {
                        _fex |= (0x02);
                        _FP_ADD_INTERNAL_ediff--;
                        if (_FP_ADD_INTERNAL_ediff == 0) {
                            __asm__("add{q} {%5,%1|%1,%5}\n\tadc{q} {%3,%0|%0,%3}" : "=r"((UDItype)(R_f1)), "=&r"((UDItype)(R_f0)) : "%0"((UDItype)(B_f1)), "rme"((UDItype)(A_f1)), "%1"((UDItype)(B_f0)), "rme"((UDItype)(A_f0)));
                            goto add3;
                        }
                        if (B_e == 32767) {
                            do {
                                if (B_e == 32767 && !((B_f1 | B_f0) == 0) && ((0) ? ((B_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64)) : !((B_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64))))
                                    _fex |= (0x01 | 0);
                            } while (0);
                            (R_f0 = B_f0, R_f1 = B_f1);
                            goto add_done;
                        }
                        goto add2;
                    }
                } else if (B_e == 32767) {
                    do {
                        if (B_e == 32767 && !((B_f1 | B_f0) == 0) && ((0) ? ((B_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64)) : !((B_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64))))
                            _fex |= (0x01 | 0);
                    } while (0);
                    (R_f0 = B_f0, R_f1 = B_f1);
                    goto add_done;
                }
                (A_f1) |= ((unsigned long long)1 << (113 - 1 + 3) % 64);
            add2:
                if (_FP_ADD_INTERNAL_ediff <= (3 + 113))
                    (void)(((_FP_ADD_INTERNAL_ediff) < 64) ? ({
                        A_f0 = (A_f1 << (64 - (_FP_ADD_INTERNAL_ediff)) | A_f0 >> (_FP_ADD_INTERNAL_ediff) | (__builtin_constant_p(_FP_ADD_INTERNAL_ediff) && (_FP_ADD_INTERNAL_ediff) == 1 ? A_f0 & 1 : (A_f0 << (64 - (_FP_ADD_INTERNAL_ediff))) != 0));
                        A_f1 >>= (_FP_ADD_INTERNAL_ediff);
                    })
                                                           : ({
                                                                 A_f0 = (A_f1 >> ((_FP_ADD_INTERNAL_ediff)-64) | ((((_FP_ADD_INTERNAL_ediff) == 64 ? 0 : (A_f1 << (2 * 64 - (_FP_ADD_INTERNAL_ediff)))) | A_f0) != 0));
                                                                 A_f1 = 0;
                                                             }));
                else if (!((A_f1 | A_f0) == 0))
                    (A_f0 = 1, A_f1 = 0);
                __asm__("add{q} {%5,%1|%1,%5}\n\tadc{q} {%3,%0|%0,%3}" : "=r"((UDItype)(R_f1)), "=&r"((UDItype)(R_f0)) : "%0"((UDItype)(B_f1)), "rme"((UDItype)(A_f1)), "%1"((UDItype)(B_f0)), "rme"((UDItype)(A_f0)));
            } else {
                if (!(((A_e + 1) & 32767) > 1)) {
                    if (A_e == 0) {
                        R_e = 0;
                        if (((A_f1 | A_f0) == 0)) {
                            if (!((B_f1 | B_f0) == 0))
                                _fex |= (0x02);
                            (R_f0 = B_f0, R_f1 = B_f1);
                            goto add_done;
                        } else if (((B_f1 | B_f0) == 0)) {
                            _fex |= (0x02);
                            (R_f0 = A_f0, R_f1 = A_f1);
                            goto add_done;
                        } else {
                            _fex |= (0x02);
                            __asm__("add{q} {%5,%1|%1,%5}\n\tadc{q} {%3,%0|%0,%3}" : "=r"((UDItype)(R_f1)), "=&r"((UDItype)(R_f0)) : "%0"((UDItype)(A_f1)), "rme"((UDItype)(B_f1)), "%1"((UDItype)(A_f0)), "rme"((UDItype)(B_f0)));
                            if ((R_f1) & ((unsigned long long)1 << (113 - 1 + 3) % 64)) {
                                (R_f1) &= ~(unsigned long long)((unsigned long long)1 << (113 - 1 + 3) % 64);
                                R_e = 1;
                            }
                            goto add_done;
                        }
                    } else {
                        do {
                            if (A_e == 32767 && !((A_f1 | A_f0) == 0) && ((0) ? ((A_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64)) : !((A_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64))))
                                _fex |= (0x01 | 0);
                        } while (0);
                        do {
                            if (B_e == 32767 && !((B_f1 | B_f0) == 0) && ((0) ? ((B_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64)) : !((B_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64))))
                                _fex |= (0x01 | 0);
                        } while (0);
                        R_e = 32767;
                        if (((A_f1 | A_f0) == 0))
                            (R_f0 = B_f0, R_f1 = B_f1);
                        else if (((B_f1 | B_f0) == 0))
                            (R_f0 = A_f0, R_f1 = A_f1);
                        else
                            do {
                                (void)(((3) < 64) ? ({
                                    A_f0 = A_f0 >> (3) | A_f1 << (64 - (3));
                                    A_f1 >>= (3);
                                })
                                                  : ({
                                                        A_f0 = A_f1 >> ((3) - 64);
                                                        A_f1 = 0;
                                                    }));
                                (void)(((3) < 64) ? ({
                                    B_f0 = B_f0 >> (3) | B_f1 << (64 - (3));
                                    B_f1 >>= (3);
                                })
                                                  : ({
                                                        B_f0 = B_f1 >> ((3) - 64);
                                                        B_f1 = 0;
                                                    }));
                                do {
                                    if ((A_f1 > B_f1 || (A_f1 == B_f1 && A_f0 > B_f0)) || ((A_f1 == B_f1 && A_f0 == B_f0) && ('+' == '+' || '+' == '*'))) {
                                        R_s = A_s;
                                        (R_f0 = A_f0, R_f1 = A_f1);
                                    } else {
                                        R_s = B_s;
                                        (R_f0 = B_f0, R_f1 = B_f1);
                                    }
                                    R_c = 3;
                                } while (0);
                                (void)(((3) < 64) ? ({
                                    if (__builtin_constant_p(3) && (3) == 1) {
                                        R_f1 = R_f1 + R_f1 + (((signed long long)(R_f0)) < 0);
                                        R_f0 += R_f0;
                                    } else {
                                        R_f1 = R_f1 << (3) | R_f0 >> (64 - (3));
                                        R_f0 <<= (3);
                                    }
                                    0;
                                })
                                                  : ({
                                                        R_f1 = R_f0 << ((3) - 64);
                                                        R_f0 = 0;
                                                    }));
                            } while (0);
                        goto add_done;
                    }
                }
                __asm__("add{q} {%5,%1|%1,%5}\n\tadc{q} {%3,%0|%0,%3}" : "=r"((UDItype)(R_f1)), "=&r"((UDItype)(R_f0)) : "%0"((UDItype)(A_f1)), "rme"((UDItype)(B_f1)), "%1"((UDItype)(A_f0)), "rme"((UDItype)(B_f0)));
                R_e = A_e + 1;
                (void)(((1) < 64) ? ({
                    R_f0 = (R_f1 << (64 - (1)) | R_f0 >> (1) | (__builtin_constant_p(1) && (1) == 1 ? R_f0 & 1 : (R_f0 << (64 - (1))) != 0));
                    R_f1 >>= (1);
                })
                                  : ({
                                        R_f0 = (R_f1 >> ((1) - 64) | ((((1) == 64 ? 0 : (R_f1 << (2 * 64 - (1)))) | R_f0) != 0));
                                        R_f1 = 0;
                                    }));
                if (R_e == 32767)
                    do {
                        if ((_fcw & 0x6000) == 0 || ((_fcw & 0x6000) == 0x4000 && !R_s) || ((_fcw & 0x6000) == 0x2000 && R_s)) {
                            R_e = 32767;
                            (R_f0 = 0, R_f1 = 0);
                        } else {
                            R_e = 32767 - 1;
                            (R_f0 = (~(signed long long)0), R_f1 = (~(signed long long)0));
                        }
                        _fex |= (0x20);
                        _fex |= (0x08);
                    } while (0);
                goto add_done;
            }
        add3:
            if ((R_f1) & ((unsigned long long)1 << (113 - 1 + 3) % 64)) {
                (R_f1) &= ~(unsigned long long)((unsigned long long)1 << (113 - 1 + 3) % 64);
                R_e++;
                (void)(((1) < 64) ? ({
                    R_f0 = (R_f1 << (64 - (1)) | R_f0 >> (1) | (__builtin_constant_p(1) && (1) == 1 ? R_f0 & 1 : (R_f0 << (64 - (1))) != 0));
                    R_f1 >>= (1);
                })
                                  : ({
                                        R_f0 = (R_f1 >> ((1) - 64) | ((((1) == 64 ? 0 : (R_f1 << (2 * 64 - (1)))) | R_f0) != 0));
                                        R_f1 = 0;
                                    }));
                if (R_e == 32767)
                    do {
                        if ((_fcw & 0x6000) == 0 || ((_fcw & 0x6000) == 0x4000 && !R_s) || ((_fcw & 0x6000) == 0x2000 && R_s)) {
                            R_e = 32767;
                            (R_f0 = 0, R_f1 = 0);
                        } else {
                            R_e = 32767 - 1;
                            (R_f0 = (~(signed long long)0), R_f1 = (~(signed long long)0));
                        }
                        _fex |= (0x20);
                        _fex |= (0x08);
                    } while (0);
            }
        add_done:;
        } else {
            __label__ sub1, sub2, sub3, norm, sub_done;
            int _FP_ADD_INTERNAL_ediff = A_e - B_e;
            if (_FP_ADD_INTERNAL_ediff > 0) {
                R_e = A_e;
                R_s = A_s;
                if (B_e == 0) {
                    if (((B_f1 | B_f0) == 0)) {
                        do {
                            if (A_e == 32767 && !((A_f1 | A_f0) == 0) && ((0) ? ((A_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64)) : !((A_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64))))
                                _fex |= (0x01 | 0);
                        } while (0);
                        (R_f0 = A_f0, R_f1 = A_f1);
                        goto sub_done;
                    } else {
                        _fex |= (0x02);
                        _FP_ADD_INTERNAL_ediff--;
                        if (_FP_ADD_INTERNAL_ediff == 0) {
                            __asm__("sub{q} {%5,%1|%1,%5}\n\tsbb{q} {%3,%0|%0,%3}" : "=r"((UDItype)(R_f1)), "=&r"((UDItype)(R_f0)) : "0"((UDItype)(A_f1)), "rme"((UDItype)(B_f1)), "1"((UDItype)(A_f0)), "rme"((UDItype)(B_f0)));
                            goto sub3;
                        }
                        if (A_e == 32767) {
                            do {
                                if (A_e == 32767 && !((A_f1 | A_f0) == 0) && ((0) ? ((A_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64)) : !((A_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64))))
                                    _fex |= (0x01 | 0);
                            } while (0);
                            (R_f0 = A_f0, R_f1 = A_f1);
                            goto sub_done;
                        }
                        goto sub1;
                    }
                } else if (A_e == 32767) {
                    do {
                        if (A_e == 32767 && !((A_f1 | A_f0) == 0) && ((0) ? ((A_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64)) : !((A_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64))))
                            _fex |= (0x01 | 0);
                    } while (0);
                    (R_f0 = A_f0, R_f1 = A_f1);
                    goto sub_done;
                }
                (B_f1) |= ((unsigned long long)1 << (113 - 1 + 3) % 64);
            sub1:
                if (_FP_ADD_INTERNAL_ediff <= (3 + 113))
                    (void)(((_FP_ADD_INTERNAL_ediff) < 64) ? ({
                        B_f0 = (B_f1 << (64 - (_FP_ADD_INTERNAL_ediff)) | B_f0 >> (_FP_ADD_INTERNAL_ediff) | (__builtin_constant_p(_FP_ADD_INTERNAL_ediff) && (_FP_ADD_INTERNAL_ediff) == 1 ? B_f0 & 1 : (B_f0 << (64 - (_FP_ADD_INTERNAL_ediff))) != 0));
                        B_f1 >>= (_FP_ADD_INTERNAL_ediff);
                    })
                                                           : ({
                                                                 B_f0 = (B_f1 >> ((_FP_ADD_INTERNAL_ediff)-64) | ((((_FP_ADD_INTERNAL_ediff) == 64 ? 0 : (B_f1 << (2 * 64 - (_FP_ADD_INTERNAL_ediff)))) | B_f0) != 0));
                                                                 B_f1 = 0;
                                                             }));
                else if (!((B_f1 | B_f0) == 0))
                    (B_f0 = 1, B_f1 = 0);
                __asm__("sub{q} {%5,%1|%1,%5}\n\tsbb{q} {%3,%0|%0,%3}" : "=r"((UDItype)(R_f1)), "=&r"((UDItype)(R_f0)) : "0"((UDItype)(A_f1)), "rme"((UDItype)(B_f1)), "1"((UDItype)(A_f0)), "rme"((UDItype)(B_f0)));
            } else if (_FP_ADD_INTERNAL_ediff < 0) {
                _FP_ADD_INTERNAL_ediff = -_FP_ADD_INTERNAL_ediff;
                R_e = B_e;
                R_s = B_s;
                if (A_e == 0) {
                    if (((A_f1 | A_f0) == 0)) {
                        do {
                            if (B_e == 32767 && !((B_f1 | B_f0) == 0) && ((0) ? ((B_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64)) : !((B_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64))))
                                _fex |= (0x01 | 0);
                        } while (0);
                        (R_f0 = B_f0, R_f1 = B_f1);
                        goto sub_done;
                    } else {
                        _fex |= (0x02);
                        _FP_ADD_INTERNAL_ediff--;
                        if (_FP_ADD_INTERNAL_ediff == 0) {
                            __asm__("sub{q} {%5,%1|%1,%5}\n\tsbb{q} {%3,%0|%0,%3}" : "=r"((UDItype)(R_f1)), "=&r"((UDItype)(R_f0)) : "0"((UDItype)(B_f1)), "rme"((UDItype)(A_f1)), "1"((UDItype)(B_f0)), "rme"((UDItype)(A_f0)));
                            goto sub3;
                        }
                        if (B_e == 32767) {
                            do {
                                if (B_e == 32767 && !((B_f1 | B_f0) == 0) && ((0) ? ((B_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64)) : !((B_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64))))
                                    _fex |= (0x01 | 0);
                            } while (0);
                            (R_f0 = B_f0, R_f1 = B_f1);
                            goto sub_done;
                        }
                        goto sub2;
                    }
                } else if (B_e == 32767) {
                    do {
                        if (B_e == 32767 && !((B_f1 | B_f0) == 0) && ((0) ? ((B_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64)) : !((B_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64))))
                            _fex |= (0x01 | 0);
                    } while (0);
                    (R_f0 = B_f0, R_f1 = B_f1);
                    goto sub_done;
                }
                (A_f1) |= ((unsigned long long)1 << (113 - 1 + 3) % 64);
            sub2:
                if (_FP_ADD_INTERNAL_ediff <= (3 + 113))
                    (void)(((_FP_ADD_INTERNAL_ediff) < 64) ? ({
                        A_f0 = (A_f1 << (64 - (_FP_ADD_INTERNAL_ediff)) | A_f0 >> (_FP_ADD_INTERNAL_ediff) | (__builtin_constant_p(_FP_ADD_INTERNAL_ediff) && (_FP_ADD_INTERNAL_ediff) == 1 ? A_f0 & 1 : (A_f0 << (64 - (_FP_ADD_INTERNAL_ediff))) != 0));
                        A_f1 >>= (_FP_ADD_INTERNAL_ediff);
                    })
                                                           : ({
                                                                 A_f0 = (A_f1 >> ((_FP_ADD_INTERNAL_ediff)-64) | ((((_FP_ADD_INTERNAL_ediff) == 64 ? 0 : (A_f1 << (2 * 64 - (_FP_ADD_INTERNAL_ediff)))) | A_f0) != 0));
                                                                 A_f1 = 0;
                                                             }));
                else if (!((A_f1 | A_f0) == 0))
                    (A_f0 = 1, A_f1 = 0);
                __asm__("sub{q} {%5,%1|%1,%5}\n\tsbb{q} {%3,%0|%0,%3}" : "=r"((UDItype)(R_f1)), "=&r"((UDItype)(R_f0)) : "0"((UDItype)(B_f1)), "rme"((UDItype)(A_f1)), "1"((UDItype)(B_f0)), "rme"((UDItype)(A_f0)));
            } else {
                if (!(((A_e + 1) & 32767) > 1)) {
                    if (A_e == 0) {
                        R_e = 0;
                        if (((A_f1 | A_f0) == 0)) {
                            (R_f0 = B_f0, R_f1 = B_f1);
                            if (((B_f1 | B_f0) == 0))
                                R_s = ((_fcw & 0x6000) == 0x2000);
                            else {
                                _fex |= (0x02);
                                R_s = B_s;
                            }
                            goto sub_done;
                        } else if (((B_f1 | B_f0) == 0)) {
                            _fex |= (0x02);
                            (R_f0 = A_f0, R_f1 = A_f1);
                            R_s = A_s;
                            goto sub_done;
                        } else {
                            _fex |= (0x02);
                            __asm__("sub{q} {%5,%1|%1,%5}\n\tsbb{q} {%3,%0|%0,%3}" : "=r"((UDItype)(R_f1)), "=&r"((UDItype)(R_f0)) : "0"((UDItype)(A_f1)), "rme"((UDItype)(B_f1)), "1"((UDItype)(A_f0)), "rme"((UDItype)(B_f0)));
                            R_s = A_s;
                            if ((R_f1) & ((unsigned long long)1 << (113 - 1 + 3) % 64)) {
                                __asm__("sub{q} {%5,%1|%1,%5}\n\tsbb{q} {%3,%0|%0,%3}" : "=r"((UDItype)(R_f1)), "=&r"((UDItype)(R_f0)) : "0"((UDItype)(B_f1)), "rme"((UDItype)(A_f1)), "1"((UDItype)(B_f0)), "rme"((UDItype)(A_f0)));
                                R_s = B_s;
                            } else if (((R_f1 | R_f0) == 0))
                                R_s = ((_fcw & 0x6000) == 0x2000);
                            goto sub_done;
                        }
                    } else {
                        do {
                            if (A_e == 32767 && !((A_f1 | A_f0) == 0) && ((0) ? ((A_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64)) : !((A_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64))))
                                _fex |= (0x01 | 0);
                        } while (0);
                        do {
                            if (B_e == 32767 && !((B_f1 | B_f0) == 0) && ((0) ? ((B_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64)) : !((B_f1) & ((unsigned long long)1 << (113 - 2 + 3) % 64))))
                                _fex |= (0x01 | 0);
                        } while (0);
                        R_e = 32767;
                        if (((A_f1 | A_f0) == 0)) {
                            if (((B_f1 | B_f0) == 0)) {
                                R_s = 1;
                                (R_f0 = 0, R_f1 = ((unsigned long long)1 << (113 - 2) % 64));
                                (void)(((3) < 64) ? ({
                                    if (__builtin_constant_p(3) && (3) == 1) {
                                        R_f1 = R_f1 + R_f1 + (((signed long long)(R_f0)) < 0);
                                        R_f0 += R_f0;
                                    } else {
                                        R_f1 = R_f1 << (3) | R_f0 >> (64 - (3));
                                        R_f0 <<= (3);
                                    }
                                    0;
                                })
                                                  : ({
                                                        R_f1 = R_f0 << ((3) - 64);
                                                        R_f0 = 0;
                                                    }));
                                _fex |= (0x01 | 0);
                            } else {
                                R_s = B_s;
                                (R_f0 = B_f0, R_f1 = B_f1);
                            }
                        } else {
                            if (((B_f1 | B_f0) == 0)) {
                                R_s = A_s;
                                (R_f0 = A_f0, R_f1 = A_f1);
                            } else {
                                do {
                                    (void)(((3) < 64) ? ({
                                        A_f0 = A_f0 >> (3) | A_f1 << (64 - (3));
                                        A_f1 >>= (3);
                                    })
                                                      : ({
                                                            A_f0 = A_f1 >> ((3) - 64);
                                                            A_f1 = 0;
                                                        }));
                                    (void)(((3) < 64) ? ({
                                        B_f0 = B_f0 >> (3) | B_f1 << (64 - (3));
                                        B_f1 >>= (3);
                                    })
                                                      : ({
                                                            B_f0 = B_f1 >> ((3) - 64);
                                                            B_f1 = 0;
                                                        }));
                                    do {
                                        if ((A_f1 > B_f1 || (A_f1 == B_f1 && A_f0 > B_f0)) || ((A_f1 == B_f1 && A_f0 == B_f0) && ('+' == '+' || '+' == '*'))) {
                                            R_s = A_s;
                                            (R_f0 = A_f0, R_f1 = A_f1);
                                        } else {
                                            R_s = B_s;
                                            (R_f0 = B_f0, R_f1 = B_f1);
                                        }
                                        R_c = 3;
                                    } while (0);
                                    (void)(((3) < 64) ? ({
                                        if (__builtin_constant_p(3) && (3) == 1) {
                                            R_f1 = R_f1 + R_f1 + (((signed long long)(R_f0)) < 0);
                                            R_f0 += R_f0;
                                        } else {
                                            R_f1 = R_f1 << (3) | R_f0 >> (64 - (3));
                                            R_f0 <<= (3);
                                        }
                                        0;
                                    })
                                                      : ({
                                                            R_f1 = R_f0 << ((3) - 64);
                                                            R_f0 = 0;
                                                        }));
                                } while (0);
                            }
                        }
                        goto sub_done;
                    }
                }
                R_e = A_e;
                __asm__("sub{q} {%5,%1|%1,%5}\n\tsbb{q} {%3,%0|%0,%3}" : "=r"((UDItype)(R_f1)), "=&r"((UDItype)(R_f0)) : "0"((UDItype)(A_f1)), "rme"((UDItype)(B_f1)), "1"((UDItype)(A_f0)), "rme"((UDItype)(B_f0)));
                R_s = A_s;
                if ((R_f1) & ((unsigned long long)1 << (113 - 1 + 3) % 64)) {
                    __asm__("sub{q} {%5,%1|%1,%5}\n\tsbb{q} {%3,%0|%0,%3}" : "=r"((UDItype)(R_f1)), "=&r"((UDItype)(R_f0)) : "0"((UDItype)(B_f1)), "rme"((UDItype)(A_f1)), "1"((UDItype)(B_f0)), "rme"((UDItype)(A_f0)));
                    R_s = B_s;
                } else if (((R_f1 | R_f0) == 0)) {
                    R_e = 0;
                    R_s = ((_fcw & 0x6000) == 0x2000);
                    goto sub_done;
                }
                goto norm;
            }
        sub3:
            if ((R_f1) & ((unsigned long long)1 << (113 - 1 + 3) % 64)) {
                int _FP_ADD_INTERNAL_diff;
                (R_f1) &= ((unsigned long long)1 << (113 - 1 + 3) % 64) - 1;
            norm:
                do {
                    if (R_f1)
                        do {
                            _Static_assert(((sizeof(unsigned long long) == sizeof(unsigned int) || (sizeof(unsigned long long) == sizeof(unsigned long)) || (sizeof(unsigned long long) == sizeof(unsigned long long)))), "_FP_W_TYPE size unsupported for clz");
                            if (sizeof(unsigned long long) == sizeof(unsigned int))
                                ((_FP_ADD_INTERNAL_diff)) = __builtin_clz(R_f1);
                            else if (sizeof(unsigned long long) == sizeof(unsigned long))
                                ((_FP_ADD_INTERNAL_diff)) = __builtin_clzl(R_f1);
                            else
                                ((_FP_ADD_INTERNAL_diff)) = __builtin_clzll(R_f1);
                        } while (0);
                    else {
                        do {
                            _Static_assert(((sizeof(unsigned long long) == sizeof(unsigned int) || (sizeof(unsigned long long) == sizeof(unsigned long)) || (sizeof(unsigned long long) == sizeof(unsigned long long)))), "_FP_W_TYPE size unsupported for clz");
                            if (sizeof(unsigned long long) == sizeof(unsigned int))
                                ((_FP_ADD_INTERNAL_diff)) = __builtin_clz(R_f0);
                            else if (sizeof(unsigned long long) == sizeof(unsigned long))
                                ((_FP_ADD_INTERNAL_diff)) = __builtin_clzl(R_f0);
                            else
                                ((_FP_ADD_INTERNAL_diff)) = __builtin_clzll(R_f0);
                        } while (0);
                        (_FP_ADD_INTERNAL_diff) += 64;
                    }
                } while (0);
                _FP_ADD_INTERNAL_diff -= ((2 * 64) - (3 + 113));
                (void)(((_FP_ADD_INTERNAL_diff) < 64) ? ({
                    if (__builtin_constant_p(_FP_ADD_INTERNAL_diff) && (_FP_ADD_INTERNAL_diff) == 1) {
                        R_f1 = R_f1 + R_f1 + (((signed long long)(R_f0)) < 0);
                        R_f0 += R_f0;
                    } else {
                        R_f1 = R_f1 << (_FP_ADD_INTERNAL_diff) | R_f0 >> (64 - (_FP_ADD_INTERNAL_diff));
                        R_f0 <<= (_FP_ADD_INTERNAL_diff);
                    }
                    0;
                })
                                                      : ({
                                                            R_f1 = R_f0 << ((_FP_ADD_INTERNAL_diff)-64);
                                                            R_f0 = 0;
                                                        }));
                if (R_e <= _FP_ADD_INTERNAL_diff) {
                    _FP_ADD_INTERNAL_diff = _FP_ADD_INTERNAL_diff - R_e + 1;
                    (void)(((_FP_ADD_INTERNAL_diff) < 64) ? ({
                        R_f0 = (R_f1 << (64 - (_FP_ADD_INTERNAL_diff)) | R_f0 >> (_FP_ADD_INTERNAL_diff) | (__builtin_constant_p(_FP_ADD_INTERNAL_diff) && (_FP_ADD_INTERNAL_diff) == 1 ? R_f0 & 1 : (R_f0 << (64 - (_FP_ADD_INTERNAL_diff))) != 0));
                        R_f1 >>= (_FP_ADD_INTERNAL_diff);
                    })
                                                          : ({
                                                                R_f0 = (R_f1 >> ((_FP_ADD_INTERNAL_diff)-64) | ((((_FP_ADD_INTERNAL_diff) == 64 ? 0 : (R_f1 << (2 * 64 - (_FP_ADD_INTERNAL_diff)))) | R_f0) != 0));
                                                                R_f1 = 0;
                                                            }));
                    R_e = 0;
                } else {
                    R_e -= _FP_ADD_INTERNAL_diff;
                    (R_f1) &= ~(unsigned long long)((unsigned long long)1 << (113 - 1 + 3) % 64);
                }
            }
        sub_done:;
        }
    } while (0);
    do {
        do {
            int _FP_PACK_SEMIRAW_is_tiny = R_e == 0 && !((R_f1 | R_f0) == 0);
            if (1 && _FP_PACK_SEMIRAW_is_tiny) {
                long long _FP_PACK_SEMIRAW_T_c __attribute__((unused));
                long long _FP_PACK_SEMIRAW_T_s __attribute__((unused));
                long long _FP_PACK_SEMIRAW_T_e __attribute__((unused));
                unsigned long long _FP_PACK_SEMIRAW_T_f0, _FP_PACK_SEMIRAW_T_f1;
                (_FP_PACK_SEMIRAW_T_f0 = R_f0, _FP_PACK_SEMIRAW_T_f1 = R_f1);
                _FP_PACK_SEMIRAW_T_s = R_s;
                _FP_PACK_SEMIRAW_T_e = R_e;
                (void)(((1) < 64) ? ({
                    if (__builtin_constant_p(1) && (1) == 1) {
                        _FP_PACK_SEMIRAW_T_f1 = _FP_PACK_SEMIRAW_T_f1 + _FP_PACK_SEMIRAW_T_f1 + (((signed long long)(_FP_PACK_SEMIRAW_T_f0)) < 0);
                        _FP_PACK_SEMIRAW_T_f0 += _FP_PACK_SEMIRAW_T_f0;
                    } else {
                        _FP_PACK_SEMIRAW_T_f1 = _FP_PACK_SEMIRAW_T_f1 << (1) | _FP_PACK_SEMIRAW_T_f0 >> (64 - (1));
                        _FP_PACK_SEMIRAW_T_f0 <<= (1);
                    }
                    0;
                })
                                  : ({
                                        _FP_PACK_SEMIRAW_T_f1 = _FP_PACK_SEMIRAW_T_f0 << ((1) - 64);
                                        _FP_PACK_SEMIRAW_T_f0 = 0;
                                    }));
                do {
                    if ((_FP_PACK_SEMIRAW_T_f0)&7) {
                        _fex |= (0x20);
                        switch ((_fcw & 0x6000)) {
                        case 0:
                            do {
                                if (((_FP_PACK_SEMIRAW_T_f0)&15) != ((unsigned long long)1 << 2))
                                    __asm__("add{q} {%5,%1|%1,%5}\n\tadc{q} {%3,%0|%0,%3}" : "=r"((UDItype)(_FP_PACK_SEMIRAW_T_f1)), "=&r"((UDItype)(_FP_PACK_SEMIRAW_T_f0)) : "%0"((UDItype)(_FP_PACK_SEMIRAW_T_f1)), "rme"((UDItype)(0)), "%1"((UDItype)(_FP_PACK_SEMIRAW_T_f0)), "rme"((UDItype)(((unsigned long long)1 << 2))));
                            } while (0);
                            break;
                        case 0x6000:
                            (void)0;
                            break;
                        case 0x4000:
                            do {
                                if (!_FP_PACK_SEMIRAW_T_s && ((_FP_PACK_SEMIRAW_T_f0)&7))
                                    __asm__("add{q} {%5,%1|%1,%5}\n\tadc{q} {%3,%0|%0,%3}" : "=r"((UDItype)(_FP_PACK_SEMIRAW_T_f1)), "=&r"((UDItype)(_FP_PACK_SEMIRAW_T_f0)) : "%0"((UDItype)(_FP_PACK_SEMIRAW_T_f1)), "rme"((UDItype)(0)), "%1"((UDItype)(_FP_PACK_SEMIRAW_T_f0)), "rme"((UDItype)(((unsigned long long)1 << 3))));
                            } while (0);
                            break;
                        case 0x2000:
                            do {
                                if (_FP_PACK_SEMIRAW_T_s && ((_FP_PACK_SEMIRAW_T_f0)&7))
                                    __asm__("add{q} {%5,%1|%1,%5}\n\tadc{q} {%3,%0|%0,%3}" : "=r"((UDItype)(_FP_PACK_SEMIRAW_T_f1)), "=&r"((UDItype)(_FP_PACK_SEMIRAW_T_f0)) : "%0"((UDItype)(_FP_PACK_SEMIRAW_T_f1)), "rme"((UDItype)(0)), "%1"((UDItype)(_FP_PACK_SEMIRAW_T_f0)), "rme"((UDItype)(((unsigned long long)1 << 3))));
                            } while (0);
                            break;
                        }
                    }
                } while (0);
                if (((_FP_PACK_SEMIRAW_T_f1) & ((unsigned long long)1 << ((3 + 113) % 64))))
                    _FP_PACK_SEMIRAW_is_tiny = 0;
            }
            do {
                if ((R_f0)&7) {
                    _fex |= (0x20);
                    switch ((_fcw & 0x6000)) {
                    case 0:
                        do {
                            if (((R_f0)&15) != ((unsigned long long)1 << 2))
                                __asm__("add{q} {%5,%1|%1,%5}\n\tadc{q} {%3,%0|%0,%3}" : "=r"((UDItype)(R_f1)), "=&r"((UDItype)(R_f0)) : "%0"((UDItype)(R_f1)), "rme"((UDItype)(0)), "%1"((UDItype)(R_f0)), "rme"((UDItype)(((unsigned long long)1 << 2))));
                        } while (0);
                        break;
                    case 0x6000:
                        (void)0;
                        break;
                    case 0x4000:
                        do {
                            if (!R_s && ((R_f0)&7))
                                __asm__("add{q} {%5,%1|%1,%5}\n\tadc{q} {%3,%0|%0,%3}" : "=r"((UDItype)(R_f1)), "=&r"((UDItype)(R_f0)) : "%0"((UDItype)(R_f1)), "rme"((UDItype)(0)), "%1"((UDItype)(R_f0)), "rme"((UDItype)(((unsigned long long)1 << 3))));
                        } while (0);
                        break;
                    case 0x2000:
                        do {
                            if (R_s && ((R_f0)&7))
                                __asm__("add{q} {%5,%1|%1,%5}\n\tadc{q} {%3,%0|%0,%3}" : "=r"((UDItype)(R_f1)), "=&r"((UDItype)(R_f0)) : "%0"((UDItype)(R_f1)), "rme"((UDItype)(0)), "%1"((UDItype)(R_f0)), "rme"((UDItype)(((unsigned long long)1 << 3))));
                        } while (0);
                        break;
                    }
                }
            } while (0);
            if (_FP_PACK_SEMIRAW_is_tiny) {
                if (((_fex)&0x20) || (((~_fcw >> 7) & (0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20)) & 0x10))
                    _fex |= (0x10);
            }
            if ((R_f1) & (((unsigned long long)1 << ((3 + 113) % 64)) >> 1)) {
                (R_f1) &= ~(((unsigned long long)1 << ((3 + 113) % 64)) >> 1);
                R_e++;
                if (R_e == 32767)
                    do {
                        if ((_fcw & 0x6000) == 0 || ((_fcw & 0x6000) == 0x4000 && !R_s) || ((_fcw & 0x6000) == 0x2000 && R_s)) {
                            R_e = 32767;
                            (R_f0 = 0, R_f1 = 0);
                        } else {
                            R_e = 32767 - 1;
                            (R_f0 = (~(signed long long)0), R_f1 = (~(signed long long)0));
                        }
                        _fex |= (0x20);
                        _fex |= (0x08);
                    } while (0);
            }
            (void)(((3) < 64) ? ({
                R_f0 = R_f0 >> (3) | R_f1 << (64 - (3));
                R_f1 >>= (3);
            })
                              : ({
                                    R_f0 = R_f1 >> ((3) - 64);
                                    R_f1 = 0;
                                }));
            if (R_e == 32767 && !((R_f1 | R_f0) == 0)) {
                if (!1) {
                    (R_f0 = 0, R_f1 = ((unsigned long long)1 << (113 - 2) % 64));
                    R_s = 1;
                } else
                    do {
                        if (0) {
                            (R_f1) &= ((unsigned long long)1 << (113 - 2) % 64) - 1;
                            if (((R_f1 | R_f0) == 0)) {
                                R_s = 1;
                                (R_f0 = 0, R_f1 = ((unsigned long long)1 << (113 - 2) % 64));
                            }
                        } else
                            (R_f1) |= ((unsigned long long)1 << (113 - 2) % 64);
                    } while (0);
            }
        } while (0);
        do {
            union _FP_UNION_Q _FP_PACK_RAW_2_flo;
            _FP_PACK_RAW_2_flo.bits.frac0 = R_f0;
            _FP_PACK_RAW_2_flo.bits.frac1 = R_f1;
            _FP_PACK_RAW_2_flo.bits.exp = R_e;
            _FP_PACK_RAW_2_flo.bits.sign = R_s;
            ((r)) = _FP_PACK_RAW_2_flo.flt;
        } while (0);
    } while (0);
    do {
        if (__builtin_expect(_fex, 0))
            __sfp_handle_exceptions(_fex);
    } while (0);

    return r;
}
