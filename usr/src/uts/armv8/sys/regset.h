/*
 * This file and its contents are supplied under the terms of the
 * Common Development and Distribution License ("CDDL"), version 1.0.
 * You may only use this file in accordance with the terms of version
 * 1.0 of the CDDL.
 *
 * A full copy of the text of the CDDL should have accompanied this
 * source.  A copy of the CDDL is also available via the Internet at
 * http://www.illumos.org/license/CDDL.
 */

/*
 * Copyright 2013 (c) Joyent, Inc.  All rights reserved.
 */

#ifndef _SYS_REGSET_H
#define	_SYS_REGSET_H

/*
 * ARM register definitions.
 * XXX I cannot find an ABI which defines these in the arm world. As such we are
 * just going to roll our own. I realize that's a bit janky, but I'm not sure
 * what else there really is to do.
 */
/*
 * XXX This totally punts on floating point.
 */

#include <sys/feature_tests.h>

#if !defined(_ASM)
#include <sys/types.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(_XPG4_2) || defined(__EXTENSIONS__)

/*
 * XXX
 * Our portable aliases usually refer to REG_R0 and REG_R1. However, R0 and R1
 * are what ARM calls its general purpose registesr. To help work aorund this
 * fact, we ourselves define the register numbers to be REG_ARM_<reg> instead of
 * the traditional REG_<reg>
 */

/*
 * Aarch64 defines registers r0-30
 */
#ifdef __aarch64__
#define	REG_ARM_R0	0
#define	REG_ARM_R1	1
#define	REG_ARM_R2	2
#define	REG_ARM_R3	3
#define	REG_ARM_R4	4
#define	REG_ARM_R5	5
#define	REG_ARM_R6	6
#define	REG_ARM_R7	7
#define	REG_ARM_R8	8
#define	REG_ARM_R9	9
#define	REG_ARM_R10	10
#define	REG_ARM_R11	11
#define	REG_ARM_R12	12
#define	REG_ARM_R13	13
#define	REG_ARM_R14	14
#define	REG_ARM_R15	15
#define	REG_ARM_R16	16 /* aka IP0 */
#define	REG_ARM_R17	17 /* aka IP1 */
#define	REG_ARM_R18	18
#define	REG_ARM_R19	19
#define	REG_ARM_R20	20
#define	REG_ARM_R21	21
#define	REG_ARM_R22	22
#define	REG_ARM_R23	23
#define	REG_ARM_R24	24
#define	REG_ARM_R25	25
#define	REG_ARM_R26	26
#define	REG_ARM_R27	27
#define	REG_ARM_R28	28
#define	REG_ARM_R29	29 /* aka LR */
#define	REG_ARM_R30	30 /* aka FP */
	/* XXX: i thnk the following are right */
#define	REG_ARM_SP	31
#define	REG_ARM_PC	32
// #define	REG_ARM_CPSR	33
#else
#error "port aarch32"
#endif /* __aarch64__ */

/* Portable Aliases */
#ifdef __aarch64__
#define	REG_PC	REG_ARM_PC
#define	REG_SP	REG_ARM_SP
#define	REG_FP	REG_ARM_R30
// #define	REG_PS	REG_ARM_CPSR
#define	REG_R0	REG_ARM_R0
#define	REG_R1	REG_ARM_R1
#else
#error "port aarch32"
#endif /* __aarch64__ */

#endif	/* !defined(_XPG4_2) || defined(__EXTENSIONS__) */

/*
 * A gregset_t is defined as an array type for compatibility with the reference
 * source. This is important due to differences in the way the C language
 * treats arrays and structures as parameters.
 */
#ifdef __aarch64__
#define	_NGREG	33
#else
#error "port aarch32"
#endif

#if !defined(_XPG4_2) || defined(__EXTENSIONS__)
#define	NGREG	_NGREG
#endif	/* !defined(_XPG4_2) || defined(__EXTENSIONS__) */

#if !defined(_ASM)

typedef long	greg_t;
typedef greg_t	gregset_t[_NGREG];

/*
 * Floating point definitions
 * XXX Fix these later
 */
typedef struct fpu {
	#ifdef __aarch64__
	/*
	 * XXX There are 32 128-bit registers in AARCH64, v0-v31, so we store
	 * these as the low and high halves of the arrays... this is prob
	 * not how we want to do it
	 */
	uint64_t f_fpregs_lo[32];
	uint64_t f_fpregs_hi[32];

	uint32_t f_fpcr; /* FP Control Register */
	uint32_t f_fpsr; /* FP Status Register */
	#else
	#error "port aarch32"
	#endif
} fpregset_t;

#if !defined(_XPG4_2) || defined(__EXTENSIONS__)

typedef struct {
	gregset_t	gregs;	/* General register set */
} mcontext_t;

#endif	/* _ASM */
#endif	/* !defined(_XPG4_2) || defined(__EXTENSIONS__) */

#if defined(_XPG4_2) && !defined(__EXTENSIONS__) && !defined(_ASM)

/*
 * The following is here for UNIX 95 compliance (XPG Issue 4, Version 2
 * System Interfaces and Headers). The structures included here are identical
 * to those visible elsewhere in this header except that the structure
 * element names have been changed in accordance with the X/Open namespace
 * rules.  Specifically, depending on the name and scope, the names have
 * been prepended with a single or double underscore (_ or __).  See the
 * structure definitions in the non-X/Open namespace for more detailed
 * comments describing each of these structures.
 */

typedef struct {
	gregset_t	__gregs;	/* General register set */
} mcontext_t;

#endif /* _XPG4_2 && !__EXTENSIONS__ && !_ASM */

#ifdef __cplusplus
}
#endif

#endif /* _SYS_REGSET_H */
