/* Capstone Disassembly Engine */
/* TMS320C64x Backend by Fotis Loukos <me@fotisl.com> 2016 */

#ifndef CAPSTONE_TMS320C64X_H
#define CAPSTONE_TMS320C64X_H

#ifdef __cplusplus
extern "C" {
#endif

//#include <stdint.h>
#include "platform.h"

#ifdef _MSC_VER
#pragma warning(disable:4201)
#endif

typedef enum tms320c64x_op_type {
	TMS320C64X_OP_INVALID = 0, // = CS_OP_INVALID (Uninitialized).
	TMS320C64X_OP_REG, // = CS_OP_REG (Register operand).
	TMS320C64X_OP_IMM, // = CS_OP_IMM (Immediate operand).
	TMS320C64X_OP_MEM, // = CS_OP_MEM (Memory operand).
	TMS320C64X_OP_REGPAIR = 64, // Register pair for double word ops
} tms320c64x_op_type;

typedef enum tms320c64x_mem_disp {
	TMS320C64X_MEM_DISP_INVALID = 0,
	TMS320C64X_MEM_DISP_CONSTANT,
	TMS320C64X_MEM_DISP_REGISTER,
} tms320c64x_mem_disp;

typedef enum tms320c64x_mem_dir {
	TMS320C64X_MEM_DIR_INVALID = 0,
	TMS320C64X_MEM_DIR_FW,
	TMS320C64X_MEM_DIR_BW,
} tms320c64x_mem_dir;

typedef enum tms320c64x_mem_mod {
	TMS320C64X_MEM_MOD_INVALID = 0,
	TMS320C64X_MEM_MOD_NO,
	TMS320C64X_MEM_MOD_PRE,
	TMS320C64X_MEM_MOD_POST,
} tms320c64x_mem_mod;

typedef struct tms320c64x_op_mem {
	unsigned int	base;	// base register
	unsigned int	disp;	// displacement/offset value
	unsigned int	unit;	// unit of base and offset register
	unsigned int	scaled;	// offset scaled
	unsigned int	disptype;	// displacement type
	unsigned int	direction;	// direction
	unsigned int	modify;	// modification
} tms320c64x_op_mem;

typedef struct cs_tms320c64x_op {
	tms320c64x_op_type type;	// operand type
	union {
		unsigned int reg;	// register value for REG operand or first register for REGPAIR operand
		int32_t imm;		// immediate value for IMM operand
		tms320c64x_op_mem mem;		// base/disp value for MEM operand
	};
} cs_tms320c64x_op;

typedef struct cs_tms320c64x {
	uint8_t op_count;
	cs_tms320c64x_op operands[8]; // operands for this instruction.
	struct {
		unsigned int reg;
		unsigned int zero;
	} condition;
	struct {
		unsigned int unit;
		unsigned int side;
		unsigned int crosspath;
	} funit;
	unsigned int parallel;
} cs_tms320c64x;

typedef enum tms320c64x_reg {
	TMS320C64X_REG_INVALID = 0,

	TMS320C64X_REG_AMR,
	TMS320C64X_REG_CSR,
	TMS320C64X_REG_DIER,
	TMS320C64X_REG_DNUM,
	TMS320C64X_REG_ECR,
	TMS320C64X_REG_GFPGFR,
	TMS320C64X_REG_GPLYA,
	TMS320C64X_REG_GPLYB,
	TMS320C64X_REG_ICR,
	TMS320C64X_REG_IER,
	TMS320C64X_REG_IERR,
	TMS320C64X_REG_ILC,
	TMS320C64X_REG_IRP,
	TMS320C64X_REG_ISR,
	TMS320C64X_REG_ISTP,
	TMS320C64X_REG_ITSR,
	TMS320C64X_REG_NRP,
	TMS320C64X_REG_NTSR,
	TMS320C64X_REG_REP,
	TMS320C64X_REG_RILC,
	TMS320C64X_REG_SSR,
	TMS320C64X_REG_TSCH,
	TMS320C64X_REG_TSCL,
	TMS320C64X_REG_TSR,
	TMS320C64X_REG_A0,
	TMS320C64X_REG_A1,
	TMS320C64X_REG_A2,
	TMS320C64X_REG_A3,
	TMS320C64X_REG_A4,
	TMS320C64X_REG_A5,
	TMS320C64X_REG_A6,
	TMS320C64X_REG_A7,
	TMS320C64X_REG_A8,
	TMS320C64X_REG_A9,
	TMS320C64X_REG_A10,
	TMS320C64X_REG_A11,
	TMS320C64X_REG_A12,
	TMS320C64X_REG_A13,
	TMS320C64X_REG_A14,
	TMS320C64X_REG_A15,
	TMS320C64X_REG_A16,
	TMS320C64X_REG_A17,
	TMS320C64X_REG_A18,
	TMS320C64X_REG_A19,
	TMS320C64X_REG_A20,
	TMS320C64X_REG_A21,
	TMS320C64X_REG_A22,
	TMS320C64X_REG_A23,
	TMS320C64X_REG_A24,
	TMS320C64X_REG_A25,
	TMS320C64X_REG_A26,
	TMS320C64X_REG_A27,
	TMS320C64X_REG_A28,
	TMS320C64X_REG_A29,
	TMS320C64X_REG_A30,
	TMS320C64X_REG_A31,
	TMS320C64X_REG_B0,
	TMS320C64X_REG_B1,
	TMS320C64X_REG_B2,
	TMS320C64X_REG_B3,
	TMS320C64X_REG_B4,
	TMS320C64X_REG_B5,
	TMS320C64X_REG_B6,
	TMS320C64X_REG_B7,
	TMS320C64X_REG_B8,
	TMS320C64X_REG_B9,
	TMS320C64X_REG_B10,
	TMS320C64X_REG_B11,
	TMS320C64X_REG_B12,
	TMS320C64X_REG_B13,
	TMS320C64X_REG_B14,
	TMS320C64X_REG_B15,
	TMS320C64X_REG_B16,
	TMS320C64X_REG_B17,
	TMS320C64X_REG_B18,
	TMS320C64X_REG_B19,
	TMS320C64X_REG_B20,
	TMS320C64X_REG_B21,
	TMS320C64X_REG_B22,
	TMS320C64X_REG_B23,
	TMS320C64X_REG_B24,
	TMS320C64X_REG_B25,
	TMS320C64X_REG_B26,
	TMS320C64X_REG_B27,
	TMS320C64X_REG_B28,
	TMS320C64X_REG_B29,
	TMS320C64X_REG_B30,
	TMS320C64X_REG_B31,
	TMS320C64X_REG_PCE1,

	TMS320C64X_REG_ENDING,	// <-- mark the end of the list of registers

	// Alias registers
	TMS320C64X_REG_EFR = TMS320C64X_REG_ECR,
	TMS320C64X_REG_IFR = TMS320C64X_REG_ISR,
} tms320c64x_reg;

typedef enum tms320c64x_insn {
	TMS320C64X_INS_INVALID = 0,

	TMS320C64X_INS_ABS,
	TMS320C64X_INS_ABS2,
	TMS320C64X_INS_ADD,
	TMS320C64X_INS_ADD2,
	TMS320C64X_INS_ADD4,
	TMS320C64X_INS_ADDAB,
	TMS320C64X_INS_ADDAD,
	TMS320C64X_INS_ADDAH,
	TMS320C64X_INS_ADDAW,
	TMS320C64X_INS_ADDK,
	TMS320C64X_INS_ADDKPC,
	TMS320C64X_INS_ADDU,
	TMS320C64X_INS_AND,
	TMS320C64X_INS_ANDN,
	TMS320C64X_INS_AVG2,
	TMS320C64X_INS_AVGU4,
	TMS320C64X_INS_B,
	TMS320C64X_INS_BDEC,
	TMS320C64X_INS_BITC4,
	TMS320C64X_INS_BNOP,
	TMS320C64X_INS_BPOS,
	TMS320C64X_INS_CLR,
	TMS320C64X_INS_CMPEQ,
	TMS320C64X_INS_CMPEQ2,
	TMS320C64X_INS_CMPEQ4,
	TMS320C64X_INS_CMPGT,
	TMS320C64X_INS_CMPGT2,
	TMS320C64X_INS_CMPGTU4,
	TMS320C64X_INS_CMPLT,
	TMS320C64X_INS_CMPLTU,
	TMS320C64X_INS_DEAL,
	TMS320C64X_INS_DOTP2,
	TMS320C64X_INS_DOTPN2,
	TMS320C64X_INS_DOTPNRSU2,
	TMS320C64X_INS_DOTPRSU2,
	TMS320C64X_INS_DOTPSU4,
	TMS320C64X_INS_DOTPU4,
	TMS320C64X_INS_EXT,
	TMS320C64X_INS_EXTU,
	TMS320C64X_INS_GMPGTU,
	TMS320C64X_INS_GMPY4,
	TMS320C64X_INS_LDB,
	TMS320C64X_INS_LDBU,
	TMS320C64X_INS_LDDW,
	TMS320C64X_INS_LDH,
	TMS320C64X_INS_LDHU,
	TMS320C64X_INS_LDNDW,
	TMS320C64X_INS_LDNW,
	TMS320C64X_INS_LDW,
	TMS320C64X_INS_LMBD,
	TMS320C64X_INS_MAX2,
	TMS320C64X_INS_MAXU4,
	TMS320C64X_INS_MIN2,
	TMS320C64X_INS_MINU4,
	TMS320C64X_INS_MPY,
	TMS320C64X_INS_MPY2,
	TMS320C64X_INS_MPYH,
	TMS320C64X_INS_MPYHI,
	TMS320C64X_INS_MPYHIR,
	TMS320C64X_INS_MPYHL,
	TMS320C64X_INS_MPYHLU,
	TMS320C64X_INS_MPYHSLU,
	TMS320C64X_INS_MPYHSU,
	TMS320C64X_INS_MPYHU,
	TMS320C64X_INS_MPYHULS,
	TMS320C64X_INS_MPYHUS,
	TMS320C64X_INS_MPYLH,
	TMS320C64X_INS_MPYLHU,
	TMS320C64X_INS_MPYLI,
	TMS320C64X_INS_MPYLIR,
	TMS320C64X_INS_MPYLSHU,
	TMS320C64X_INS_MPYLUHS,
	TMS320C64X_INS_MPYSU,
	TMS320C64X_INS_MPYSU4,
	TMS320C64X_INS_MPYU,
	TMS320C64X_INS_MPYU4,
	TMS320C64X_INS_MPYUS,
	TMS320C64X_INS_MVC,
	TMS320C64X_INS_MVD,
	TMS320C64X_INS_MVK,
	TMS320C64X_INS_MVKL,
	TMS320C64X_INS_MVKLH,
	TMS320C64X_INS_NOP,
	TMS320C64X_INS_NORM,
	TMS320C64X_INS_OR,
	TMS320C64X_INS_PACK2,
	TMS320C64X_INS_PACKH2,
	TMS320C64X_INS_PACKH4,
	TMS320C64X_INS_PACKHL2,
	TMS320C64X_INS_PACKL4,
	TMS320C64X_INS_PACKLH2,
	TMS320C64X_INS_ROTL,
	TMS320C64X_INS_SADD,
	TMS320C64X_INS_SADD2,
	TMS320C64X_INS_SADDU4,
	TMS320C64X_INS_SADDUS2,
	TMS320C64X_INS_SAT,
	TMS320C64X_INS_SET,
	TMS320C64X_INS_SHFL,
	TMS320C64X_INS_SHL,
	TMS320C64X_INS_SHLMB,
	TMS320C64X_INS_SHR,
	TMS320C64X_INS_SHR2,
	TMS320C64X_INS_SHRMB,
	TMS320C64X_INS_SHRU,
	TMS320C64X_INS_SHRU2,
	TMS320C64X_INS_SMPY,
	TMS320C64X_INS_SMPY2,
	TMS320C64X_INS_SMPYH,
	TMS320C64X_INS_SMPYHL,
	TMS320C64X_INS_SMPYLH,
	TMS320C64X_INS_SPACK2,
	TMS320C64X_INS_SPACKU4,
	TMS320C64X_INS_SSHL,
	TMS320C64X_INS_SSHVL,
	TMS320C64X_INS_SSHVR,
	TMS320C64X_INS_SSUB,
	TMS320C64X_INS_STB,
	TMS320C64X_INS_STDW,
	TMS320C64X_INS_STH,
	TMS320C64X_INS_STNDW,
	TMS320C64X_INS_STNW,
	TMS320C64X_INS_STW,
	TMS320C64X_INS_SUB,
	TMS320C64X_INS_SUB2,
	TMS320C64X_INS_SUB4,
	TMS320C64X_INS_SUBAB,
	TMS320C64X_INS_SUBABS4,
	TMS320C64X_INS_SUBAH,
	TMS320C64X_INS_SUBAW,
	TMS320C64X_INS_SUBC,
	TMS320C64X_INS_SUBU,
	TMS320C64X_INS_SWAP4,
	TMS320C64X_INS_UNPKHU4,
	TMS320C64X_INS_UNPKLU4,
	TMS320C64X_INS_XOR,
	TMS320C64X_INS_XPND2,
	TMS320C64X_INS_XPND4,
	// Aliases
	TMS320C64X_INS_IDLE,
	TMS320C64X_INS_MV,
	TMS320C64X_INS_NEG,
	TMS320C64X_INS_NOT,
	TMS320C64X_INS_SWAP2,
	TMS320C64X_INS_ZERO,

	TMS320C64X_INS_ENDING,   // <-- mark the end of the list of instructions
} tms320c64x_insn;

typedef enum tms320c64x_insn_group {
	TMS320C64X_GRP_INVALID = 0, // = CS_GRP_INVALID

	TMS320C64X_GRP_JUMP,	// = CS_GRP_JUMP

	TMS320C64X_GRP_FUNIT_D = 128,
	TMS320C64X_GRP_FUNIT_L,
	TMS320C64X_GRP_FUNIT_M,
	TMS320C64X_GRP_FUNIT_S,
	TMS320C64X_GRP_FUNIT_NO,

	TMS320C64X_GRP_ENDING,   // <-- mark the end of the list of groups
} tms320c64x_insn_group;

typedef enum tms320c64x_funit {
	TMS320C64X_FUNIT_INVALID = 0,
	TMS320C64X_FUNIT_D,
	TMS320C64X_FUNIT_L,
	TMS320C64X_FUNIT_M,
	TMS320C64X_FUNIT_S,
	TMS320C64X_FUNIT_NO
} tms320c64x_funit;

#ifdef __cplusplus
}
#endif

#endif

