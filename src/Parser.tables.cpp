/*
 * Parser.tables.cpp
 *
 *  Created on: 26.10.2014
 *      Author: mueller
 */

#include "Parser.h"

// MUST BE ORDERED!
const Parser::opInfo Parser::operatorMap[] =
{	{ "!",  Eval::lNOT }
,	{ "!=", Eval::NE }
,	{ "%",  Eval::MOD }
,	{ "&",  Eval::AND }
,	{ "&&", Eval::lAND }
,	{ "(",  Eval::BRO }
,	{ ")",  Eval::BRC }
,	{ "*",  Eval::MUL }
,	{ "**", Eval::POW }
,	{ "+",  Eval::ADD } // also unary NOP
,	{ "-",  Eval::SUB } // also unary NEG
,	{ "/",  Eval::DIV }
,	{ "<",  Eval::LT }
,	{ "<<", Eval::ASL }
,	{ "<<<",Eval::SHL }
,	{ "<=", Eval::LE }
,	{ "==", Eval::EQ }
,	{ ">",  Eval::GT }
,	{ ">=", Eval::GE }
,	{ ">>", Eval::ASR }
,	{ ">>>",Eval::SHR }
,	{ "^",  Eval::XOR }
,	{ "^^", Eval::lXOR }
,	{ "|",  Eval::OR }
,	{ "||", Eval::lOR }
,	{ "~",  Eval::NOT }
};

// MUST BE ORDERED!
const Parser::regEntry Parser::regMap[] =
{	{ "elem_num",     { 38, R_RDA  } }
,	{ "exp",          { 54, R_WRAB } }
,	{ "interrupt",    { 38, R_WRAB } }
,	{ "irq",          { 38, R_WRAB } }
,	{ "log",          { 55, R_WRAB } }
,	{ "ms_mask",      { 42, R_RWA  } }
,	{ "mutex",        { 51, R_RWAB } }
,	{ "mutex_acq",    { 51, R_RDAB } }
,	{ "mutex_rel",    { 51, R_WRAB } }
,	{ "qpu_num",      { 38, R_RDB  } }
,	{ "r0",           { 32, R_WRAB } }
,	{ "r1",           { 33, R_WRAB } }
,	{ "r2",           { 34, R_WRAB } }
,	{ "r3",           { 35, R_WRAB } }
,	{ "r4",           { 36, R_WRAB } }
,	{ "r5",           { 37, R_AB   } }
,	{ "r5quad",       { 37, R_WRA  } }
,	{ "r5rep",        { 37, R_WRB  } }
,	{ "ra0",          { 0,  R_RWA  } }
,	{ "ra1",          { 1,  R_RWA  } }
,	{ "ra10",         { 10, R_RWA  } }
,	{ "ra11",         { 11, R_RWA  } }
,	{ "ra12",         { 12, R_RWA  } }
,	{ "ra13",         { 13, R_RWA  } }
,	{ "ra14",         { 14, R_RWA  } }
,	{ "ra15",         { 15, R_RWA  } }
,	{ "ra16",         { 16, R_RWA  } }
,	{ "ra17",         { 17, R_RWA  } }
,	{ "ra18",         { 18, R_RWA  } }
,	{ "ra19",         { 19, R_RWA  } }
,	{ "ra2",          { 2,  R_RWA  } }
,	{ "ra20",         { 20, R_RWA  } }
,	{ "ra21",         { 21, R_RWA  } }
,	{ "ra22",         { 22, R_RWA  } }
,	{ "ra23",         { 23, R_RWA  } }
,	{ "ra24",         { 24, R_RWA  } }
,	{ "ra25",         { 25, R_RWA  } }
,	{ "ra26",         { 26, R_RWA  } }
,	{ "ra27",         { 27, R_RWA  } }
,	{ "ra28",         { 28, R_RWA  } }
,	{ "ra29",         { 29, R_RWA  } }
,	{ "ra3",          { 3,  R_RWA  } }
,	{ "ra30",         { 30, R_RWA  } }
,	{ "ra31",         { 31, R_RWA  } }
,	{ "ra4",          { 4,  R_RWA  } }
,	{ "ra5",          { 5,  R_RWA  } }
,	{ "ra6",          { 6,  R_RWA  } }
,	{ "ra7",          { 7,  R_RWA  } }
,	{ "ra8",          { 8,  R_RWA  } }
,	{ "ra9",          { 9,  R_RWA  } }
,	{ "rb0",          { 0,  R_RWB  } }
,	{ "rb1",          { 1,  R_RWB  } }
,	{ "rb10",         { 10, R_RWB  } }
,	{ "rb11",         { 11, R_RWB  } }
,	{ "rb12",         { 12, R_RWB  } }
,	{ "rb13",         { 13, R_RWB  } }
,	{ "rb14",         { 14, R_RWB  } }
,	{ "rb15",         { 15, R_RWB  } }
,	{ "rb16",         { 16, R_RWB  } }
,	{ "rb17",         { 17, R_RWB  } }
,	{ "rb18",         { 18, R_RWB  } }
,	{ "rb19",         { 19, R_RWB  } }
,	{ "rb2",          { 2,  R_RWB  } }
,	{ "rb20",         { 20, R_RWB  } }
,	{ "rb21",         { 21, R_RWB  } }
,	{ "rb22",         { 22, R_RWB  } }
,	{ "rb23",         { 23, R_RWB  } }
,	{ "rb24",         { 24, R_RWB  } }
,	{ "rb25",         { 25, R_RWB  } }
,	{ "rb26",         { 26, R_RWB  } }
,	{ "rb27",         { 27, R_RWB  } }
,	{ "rb28",         { 28, R_RWB  } }
,	{ "rb29",         { 29, R_RWB  } }
,	{ "rb3",          { 3,  R_RWB  } }
,	{ "rb30",         { 30, R_RWB  } }
,	{ "rb31",         { 31, R_RWB  } }
,	{ "rb4",          { 4,  R_RWB  } }
,	{ "rb5",          { 5,  R_RWB  } }
,	{ "rb6",          { 6,  R_RWB  } }
,	{ "rb7",          { 7,  R_RWB  } }
,	{ "rb8",          { 8,  R_RWB  } }
,	{ "rb9",          { 9,  R_RWB  } }
,	{ "recip",        { 52, R_WRAB } }
,	{ "recipsqrt",    { 53, R_WRAB } }
,	{ "rev_flag",     { 42, R_RWB  } }
,	{ "sacq0",        { 0,  R_SACQ } }
,	{ "sacq1",        { 1,  R_SACQ } }
,	{ "sacq10",       { 10, R_SACQ } }
,	{ "sacq11",       { 11, R_SACQ } }
,	{ "sacq12",       { 12, R_SACQ } }
,	{ "sacq13",       { 13, R_SACQ } }
,	{ "sacq14",       { 14, R_SACQ } }
,	{ "sacq15",       { 15, R_SACQ } }
,	{ "sacq2",        { 2,  R_SACQ } }
,	{ "sacq3",        { 3,  R_SACQ } }
,	{ "sacq4",        { 4,  R_SACQ } }
,	{ "sacq5",        { 5,  R_SACQ } }
,	{ "sacq6",        { 6,  R_SACQ } }
,	{ "sacq7",        { 7,  R_SACQ } }
,	{ "sacq8",        { 8,  R_SACQ } }
,	{ "sacq9",        { 9,  R_SACQ } }
,	{ "srel0",        { 0,  R_SREL } }
,	{ "srel1",        { 1,  R_SREL } }
,	{ "srel10",       { 10, R_SREL } }
,	{ "srel11",       { 11, R_SREL } }
,	{ "srel12",       { 12, R_SREL } }
,	{ "srel13",       { 13, R_SREL } }
,	{ "srel14",       { 14, R_SREL } }
,	{ "srel15",       { 15, R_SREL } }
,	{ "srel2",        { 2,  R_SREL } }
,	{ "srel3",        { 3,  R_SREL } }
,	{ "srel4",        { 4,  R_SREL } }
,	{ "srel5",        { 5,  R_SREL } }
,	{ "srel6",        { 6,  R_SREL } }
,	{ "srel7",        { 7,  R_SREL } }
,	{ "srel8",        { 8,  R_SREL } }
,	{ "srel9",        { 9,  R_SREL } }
,	{ "stencil",      { 43, R_WRAB } }
,	{ "t0b",          { 59, R_WRAB } }
,	{ "t0r",          { 58, R_WRAB } }
,	{ "t0s",          { 56, R_WRAB } }
,	{ "t0t",          { 57, R_WRAB } }
,	{ "t1b",          { 63, R_WRAB } }
,	{ "t1r",          { 62, R_WRAB } }
,	{ "t1s",          { 60, R_WRAB } }
,	{ "t1t",          { 61, R_WRAB } }
,	{ "tlbam",        { 47, R_WRAB } }
,	{ "tlbc",         { 46, R_WRAB } }
,	{ "tlbm",         { 45, R_WRAB } }
,	{ "tlbz",         { 44, R_WRAB } }
,	{ "tmurs",        { 36, R_WRAB } }
,	{ "unif",         { 32, R_RDAB } }
,	{ "unif_addr",    { 40, R_WRA  } }
,	{ "unif_addr_rel",{ 40, R_WRB  } }
,	{ "vary",         { 35, R_RDAB } }
,	{ "vpm",          { 48, R_RWAB } }
,	{ "vr_addr",      { 50, R_WRA  } }
,	{ "vr_busy",      { 49, R_RDA  } }
,	{ "vr_setup",     { 49, R_WRA  } }
,	{ "vr_wait",      { 50, R_RDA  } }
,	{ "vw_addr",      { 50, R_WRB  } }
,	{ "vw_busy",      { 49, R_RDB  } }
,	{ "vw_setup",     { 49, R_WRB  } }
,	{ "vw_wait",      { 50, R_RDB  } }
,	{ "x_coord",      { 41, R_RWA  } }
,	{ "y_coord",      { 41, R_RWB  } }
};
const reg_t Parser::regNOP = { 39, R_WRAB };

const Parser::smiEntry Parser::smiMap[] =
{	{ 0x00000000,  0, Inst::A_XOR }
,	{ 0x00000000,  0, Inst::M_V8SUBS }
,	{ 0x00000001,  1, Inst::A_OR }
,	{ 0x00000001, 32, Inst::A_FTOI }
,	{ 0x00000001, 30, Inst::A_NOT }
,	{ 0x00000001,  1, Inst::M_V8MIN }
,	{ 0x00000002,  2, Inst::A_OR }
,	{ 0x00000002, 33, Inst::A_FTOI }
,	{ 0x00000002,  1, Inst::A_ADD }
,	{ 0x00000002, 29, Inst::A_NOT }
,	{ 0x00000002,  2, Inst::M_V8MIN }
,	{ 0x00000003,  3, Inst::A_OR }
,	{ 0x00000003, 28, Inst::A_NOT }
,	{ 0x00000003,  3, Inst::M_V8MIN }
,	{ 0x00000004,  4, Inst::A_OR }
,	{ 0x00000004,  2, Inst::A_ADD }
,	{ 0x00000004, 34, Inst::A_FTOI }
,	{ 0x00000004, 27, Inst::A_NOT }
,	{ 0x00000004,  4, Inst::M_V8MIN }
,	{ 0x00000004,  2, Inst::M_MUL24 }
,	{ 0x00000005,  5, Inst::A_OR }
,	{ 0x00000005, 26, Inst::A_NOT }
,	{ 0x00000005,  5, Inst::M_V8MIN }
,	{ 0x00000006,  6, Inst::A_OR }
,	{ 0x00000006,  3, Inst::A_ADD }
,	{ 0x00000006, 25, Inst::A_NOT }
,	{ 0x00000006,  6, Inst::M_V8MIN }
,	{ 0x00000007,  7, Inst::A_OR }
,	{ 0x00000007, 24, Inst::A_NOT }
,	{ 0x00000007,  7, Inst::M_V8MIN }
,	{ 0x00000008,  8, Inst::A_OR }
,	{ 0x00000008,  4, Inst::A_ADD }
,	{ 0x00000008,  2, Inst::A_SHL }
,	{ 0x00000008, 35, Inst::A_FTOI }
,	{ 0x00000008, 23, Inst::A_NOT }
,	{ 0x00000008,  8, Inst::M_V8MIN }
,	{ 0x00000009,  9, Inst::A_OR }
,	{ 0x00000009, 22, Inst::A_NOT }
,	{ 0x00000009,  9, Inst::M_V8MIN }
,	{ 0x00000009,  3, Inst::M_MUL24 }
,	{ 0x0000000a, 10, Inst::A_OR }
,	{ 0x0000000a,  5, Inst::A_ADD }
,	{ 0x0000000a, 21, Inst::A_NOT }
,	{ 0x0000000a, 10, Inst::M_V8MIN }
,	{ 0x0000000b, 11, Inst::A_OR }
,	{ 0x0000000b, 20, Inst::A_NOT }
,	{ 0x0000000b, 11, Inst::M_V8MIN }
,	{ 0x0000000c, 12, Inst::A_OR }
,	{ 0x0000000c,  6, Inst::A_ADD }
,	{ 0x0000000c, 19, Inst::A_NOT }
,	{ 0x0000000c, 12, Inst::M_V8MIN }
,	{ 0x0000000d, 13, Inst::A_OR }
,	{ 0x0000000d, 18, Inst::A_NOT }
,	{ 0x0000000d, 13, Inst::M_V8MIN }
,	{ 0x0000000e, 14, Inst::A_OR }
,	{ 0x0000000e,  7, Inst::A_ADD }
,	{ 0x0000000e, 17, Inst::A_NOT }
,	{ 0x0000000e, 14, Inst::M_V8MIN }
,	{ 0x0000000f, 15, Inst::A_OR }
,	{ 0x0000000f, 16, Inst::A_NOT }
,	{ 0x0000000f, 15, Inst::M_V8MIN }
,	{ 0x00000010,  8, Inst::A_ADD } // 16
,	{ 0x00000010,  4, Inst::M_MUL24 }
,	{ 0x00000010, 36, Inst::A_FTOI }
,	{ 0x00000012,  9, Inst::A_ADD } // 18
,	{ 0x00000014, 10, Inst::A_ADD } // 20
,	{ 0x00000016, 11, Inst::A_ADD } // 22
,	{ 0x00000018, 12, Inst::A_ADD } // 24
,	{ 0x00000018,  3, Inst::A_SHL }
,	{ 0x00000019,  5, Inst::M_MUL24 } // 25
,	{ 0x0000001a, 13, Inst::A_ADD } // 26
,	{ 0x0000001c, 14, Inst::A_ADD } // 28
,	{ 0x0000001e, 15, Inst::A_ADD } // 30
,	{ 0x00000020, 37, Inst::A_FTOI } // 32
,	{ 0x00000020,  4, Inst::A_SHL }
,	{ 0x00000024,  6, Inst::M_MUL24 } // 36
,	{ 0x00000031,  7, Inst::M_MUL24 } // 49
,	{ 0x00000040, 38, Inst::A_FTOI } // 64
,	{ 0x00000040,  8, Inst::M_MUL24 }
,	{ 0x00000051,  9, Inst::M_MUL24 } // 81
,	{ 0x00000064, 10, Inst::M_MUL24 } // 100
,	{ 0x00000079, 11, Inst::M_MUL24 } // 121
,	{ 0x00000080, 39, Inst::A_FTOI } // 128
,	{ 0x00000090, 12, Inst::M_MUL24 } // 144
,	{ 0x000000a0,  5, Inst::A_SHL } // 160
,	{ 0x000000a8, 13, Inst::M_MUL24 } // 169
,	{ 0x000000c4, 14, Inst::M_MUL24 } // 196
,	{ 0x000000e1, 15, Inst::M_MUL24 } // 225
,	{ 0x00000180,  6, Inst::A_SHL } // 384
,	{ 0x00000380,  7, Inst::A_SHL } // 896
,	{ 0x00000800,  8, Inst::A_SHL } // 2048
,	{ 0x00001200,  9, Inst::A_SHL } // 4608
,	{ 0x00002800, 10, Inst::A_SHL } // 10240
,	{ 0x00005800, 11, Inst::A_SHL } // 22528
,	{ 0x0000c000, 12, Inst::A_SHL } // 49152
,	{ 0x0001a000, 13, Inst::A_SHL } // 106496
,	{ 0x0001e000, 15, Inst::A_ROR }
,	{ 0x00038000, 14, Inst::A_SHL } // 229376
,	{ 0x00068000, 13, Inst::A_ROR } // 425984
,	{ 0x00078000, 15, Inst::A_SHL } // 491520
,	{ 0x000c0000, 12, Inst::A_ROR } // 786432
,	{ 0x00160000, 11, Inst::A_ROR }
,	{ 0x00280000, 10, Inst::A_ROR }
,	{ 0x00480000,  9, Inst::A_ROR }
,	{ 0x08000000,  8, Inst::A_ROR }
,	{ 0x0e000000,  7, Inst::A_ROR }
,	{ 0x18000000,  6, Inst::A_ROR }
,	{ 0x28000000,  5, Inst::A_ROR }
,	{ 0x39800000, 40, Inst::M_FMUL }
,	{ 0x3a800000, 41, Inst::M_FMUL }
,	{ 0x3b800000, 42, Inst::M_FMUL }
,	{ 0x3c800000, 43, Inst::M_FMUL }
,	{ 0x3b800000, 40, Inst::A_OR }   // .00390625
,	{ 0x3b800000, 40, Inst::M_V8MIN }
,	{ 0x3b800000, 44, Inst::M_FMUL }
,	{ 0x3c000000, 41, Inst::A_OR }   // .0078125
,	{ 0x3c000000, 40, Inst::A_FADD }
,	{ 0x3c000000, 41, Inst::M_V8MIN }
,	{ 0x3c800000, 42, Inst::A_OR }   // .015625
,	{ 0x3c800000, 41, Inst::A_FADD }
,	{ 0x3c800000, 42, Inst::M_V8MIN }
,	{ 0x3c800000, 45, Inst::M_FMUL }
,	{ 0x3d000000, 43, Inst::A_OR }   // .03125
,	{ 0x3d000000, 42, Inst::A_FADD }
,	{ 0x3d000000, 43, Inst::M_V8MIN }
,	{ 0x3d800000, 44, Inst::A_OR }   // .0625
,	{ 0x3d800000, 43, Inst::A_FADD }
,	{ 0x3d800000, 44, Inst::M_V8MIN }
,	{ 0x3d800000, 46, Inst::M_FMUL }
,	{ 0x3e000000, 45, Inst::A_OR }   // .125
,	{ 0x3e000000, 44, Inst::A_FADD }
,	{ 0x3e000000, 45, Inst::M_V8MIN }
,	{ 0x3e800000, 46, Inst::A_OR }   // .25
,	{ 0x3e800000, 45, Inst::A_FADD }
,	{ 0x3e800000, 46, Inst::M_V8MIN }
,	{ 0x3e800000, 47, Inst::M_FMUL }
,	{ 0x3f000000, 47, Inst::A_OR }   // .5
,	{ 0x3f000000, 46, Inst::A_FADD }
,	{ 0x3f000000, 47, Inst::M_V8MIN }
,	{ 0x3f800000, 32, Inst::A_OR }   // 1.0
,	{ 0x3f800000,  1, Inst::A_ITOF }
,	{ 0x3f800000, 47, Inst::A_FADD }
,	{ 0x3f800000, 32, Inst::M_V8MIN }
,	{ 0x40000000, 33, Inst::A_OR }   // 2.0
,	{ 0x40000000,  2, Inst::A_ITOF }
,	{ 0x40000000, 32, Inst::A_FADD }
,	{ 0x40000000,  4, Inst::A_ROR }
,	{ 0x40000000, 33, Inst::M_V8MIN }
,	{ 0x40400000,  3, Inst::A_ITOF } // 3.0
,	{ 0x40800000, 34, Inst::A_OR }   // 4.0
,	{ 0x40800000,  4, Inst::A_ITOF }
,	{ 0x40800000, 33, Inst::A_FADD }
,	{ 0x40800000, 34, Inst::M_V8MIN }
,	{ 0x40a00000,  5, Inst::A_ITOF } // 5.0
,	{ 0x40c00000,  6, Inst::A_ITOF } // 6.0
,	{ 0x40e00000,  7, Inst::A_ITOF } // 7.0
,	{ 0x41000000, 35, Inst::A_OR }   // 8.0
,	{ 0x41000000,  8, Inst::A_ITOF }
,	{ 0x41000000, 34, Inst::A_FADD }
,	{ 0x41000000, 35, Inst::M_V8MIN }
,	{ 0x41100000,  9, Inst::A_ITOF } // 9.0
,	{ 0x41200000, 10, Inst::A_ITOF } // 10.0
,	{ 0x41300000, 11, Inst::A_ITOF } // 11.0
,	{ 0x41400000, 12, Inst::A_ITOF } // 12.0
,	{ 0x41500000, 13, Inst::A_ITOF } // 13.0
,	{ 0x41600000, 14, Inst::A_ITOF } // 14.0
,	{ 0x41700000, 15, Inst::A_ITOF } // 15.0
,	{ 0x41800000, 36, Inst::A_OR }   // 16.0
,	{ 0x41800000, 35, Inst::A_FADD }
,	{ 0x41800000, 36, Inst::M_V8MIN }
,	{ 0x41800000, 34, Inst::M_FMUL }
,	{ 0x42000000, 37, Inst::A_OR }   // 32.0
,	{ 0x42000000, 36, Inst::A_FADD }
,	{ 0x42000000, 37, Inst::M_V8MIN }
,	{ 0x42800000, 38, Inst::A_OR }   // 64.0
,	{ 0x42800000, 37, Inst::A_FADD }
,	{ 0x42800000, 38, Inst::M_V8MIN }
,	{ 0x42800000, 35, Inst::M_FMUL }
,	{ 0x43000000, 39, Inst::A_OR }   // 128.0
,	{ 0x43000000, 38, Inst::A_FADD }
,	{ 0x43000000, 39, Inst::M_V8MIN }
,	{ 0x43800000, 39, Inst::A_FADD } // 256.0
,	{ 0x43800000, 36, Inst::M_FMUL }
,	{ 0x44800000, 37, Inst::M_FMUL } // 1024.0
,	{ 0x45800000, 38, Inst::M_FMUL } // 4096.0
,	{ 0x46800000, 39, Inst::M_FMUL } // 16384.0
,	{ 0x4e6e0000, 40, Inst::A_ITOF }
,	{ 0x4e700000, 41, Inst::A_ITOF }
,	{ 0x4e720000, 42, Inst::A_ITOF }
,	{ 0x4e740000, 43, Inst::A_ITOF }
,	{ 0x4e760000, 44, Inst::A_ITOF }
,	{ 0x4e780000, 45, Inst::A_ITOF }
,	{ 0x4e7a0000, 46, Inst::A_ITOF }
,	{ 0x4e7c0000, 47, Inst::A_ITOF }
,	{ 0x4e7e0000, 32, Inst::A_ITOF }
,	{ 0x4e800000, 33, Inst::A_ITOF }
,	{ 0x4e810000, 34, Inst::A_ITOF }
,	{ 0x4e820000, 35, Inst::A_ITOF }
,	{ 0x4e830000, 36, Inst::A_ITOF }
,	{ 0x4e840000, 37, Inst::A_ITOF }
,	{ 0x4e850000, 38, Inst::A_ITOF }
,	{ 0x4e860000, 39, Inst::A_ITOF }
,	{ 0x60000000,  3, Inst::A_ROR }
,	{ 0x76ff0000, 40, Inst::M_V8ADDS }
,	{ 0x76ff0000, 40, Inst::A_V8ADDS }
,	{ 0x77000000, 40, Inst::A_ADD }
,	{ 0x78000000, 41, Inst::M_V8ADDS }
,	{ 0x78000000, 41, Inst::A_ADD }
,	{ 0x78ff0000, 42, Inst::M_V8ADDS }
,	{ 0x78ff0000, 42, Inst::A_V8ADDS }
,	{ 0x79000000, 42, Inst::A_ADD }
,	{ 0x7a000000, 43, Inst::M_V8ADDS }
,	{ 0x7a000000, 43, Inst::A_ADD }
,	{ 0x7aff0000, 44, Inst::M_V8ADDS }
,	{ 0x7aff0000, 44, Inst::A_V8ADDS }
,	{ 0x7b000000, 44, Inst::A_ADD }
,	{ 0x7c000000, 45, Inst::M_V8ADDS }
,	{ 0x7c000000, 45, Inst::A_ADD }
,	{ 0x7cff0000, 46, Inst::M_V8ADDS }
,	{ 0x7cff0000, 46, Inst::A_V8ADDS }
,	{ 0x7d000000, 46, Inst::A_ADD }
,	{ 0x7e000000, 47, Inst::M_V8ADDS }
,	{ 0x7e000000, 47, Inst::A_ADD }
,	{ 0x7eff0000, 32, Inst::M_V8ADDS }
,	{ 0x7eff0000, 32, Inst::A_V8ADDS }
,	{ 0x7f000000, 32, Inst::A_ADD }
,	{ 0x80000000,  1, Inst::A_ROR } // INT_MIN
,	{ 0x80000000, 33, Inst::M_V8ADDS }
,	{ 0x80000000, 33, Inst::A_ADD }
,	{ 0x80ff0000, 34, Inst::M_V8ADDS }
,	{ 0x80ff0000, 34, Inst::A_V8ADDS }
,	{ 0x81000000, 34, Inst::A_ADD }
,	{ 0x82000000, 35, Inst::M_V8ADDS }
,	{ 0x82000000, 35, Inst::A_ADD }
,	{ 0x82ff0000, 36, Inst::M_V8ADDS }
,	{ 0x82ff0000, 36, Inst::A_V8ADDS }
,	{ 0x83000000, 36, Inst::A_ADD }
,	{ 0x84000000, 37, Inst::M_V8ADDS }
,	{ 0x84000000, 37, Inst::A_ADD }
,	{ 0x84ff0000, 38, Inst::M_V8ADDS }
,	{ 0x84ff0000, 38, Inst::A_V8ADDS }
,	{ 0x85000000, 38, Inst::A_ADD }
,	{ 0x86000000, 39, Inst::M_V8ADDS }
,	{ 0x86000000, 39, Inst::A_ADD }
,	{ 0xbcffffff, 39, Inst::A_NOT }
,	{ 0xbd7fffff, 38, Inst::A_NOT }
,	{ 0xbdffffff, 37, Inst::A_NOT }
,	{ 0xbe7fffff, 36, Inst::A_NOT }
,	{ 0xbeffffff, 35, Inst::A_NOT }
,	{ 0xbf7fffff, 34, Inst::A_NOT }
,	{ 0xbf800000, 29, Inst::A_ITOF } // -1.0
,	{ 0xbfffffff, 33, Inst::A_NOT }
,	{ 0xc0000000, 30, Inst::A_ITOF } // -2.0
,	{ 0xc0400000, 29, Inst::A_ITOF } // -3.0
,	{ 0xc07fffff, 32, Inst::A_NOT }
,	{ 0xc0800000, 28, Inst::A_ITOF } // -4.0
,	{ 0xc0a00000, 27, Inst::A_ITOF } // -5.0
,	{ 0xc0c00000, 26, Inst::A_ITOF } // -6.0
,	{ 0xc0e00000, 25, Inst::A_ITOF } // -7.0
,	{ 0xc0ffffff, 47, Inst::A_NOT }
,	{ 0xc1000000, 24, Inst::A_ITOF } // -8.0
,	{ 0xc1100000, 23, Inst::A_ITOF } // -9.0
,	{ 0xc1200000, 22, Inst::A_ITOF } // -10.0
,	{ 0xc1300000, 21, Inst::A_ITOF } // -11.0
,	{ 0xc1400000, 20, Inst::A_ITOF } // -12.0
,	{ 0xc1500000, 19, Inst::A_ITOF } // -13.0
,	{ 0xc1600000, 18, Inst::A_ITOF } // -14.0
,	{ 0xc1700000, 17, Inst::A_ITOF } // -15.0
,	{ 0xc17fffff, 46, Inst::A_NOT }
,	{ 0xc1800000, 16, Inst::A_ITOF } // -16.0
,	{ 0xc1ffffff, 45, Inst::A_NOT } // ~-32.0
,	{ 0xc27fffff, 44, Inst::A_NOT }
,	{ 0xc2ffffff, 43, Inst::A_NOT }
,	{ 0xc37fffff, 42, Inst::A_NOT }
,	{ 0xc3ffffff, 41, Inst::A_NOT }
,	{ 0xc47fffff, 40, Inst::A_NOT }
,	{ 0xffffffe0, 16, Inst::A_ADD } // -32
,	{ 0xffffffe2, 17, Inst::A_ADD } // -30
,	{ 0xffffffe4, 18, Inst::A_ADD } // -28
,	{ 0xffffffe6, 19, Inst::A_ADD } // -26
,	{ 0xffffffe8, 20, Inst::A_ADD } // -24
,	{ 0xffffffea, 21, Inst::A_ADD } // -22
,	{ 0xffffffec, 22, Inst::A_ADD } // -20
,	{ 0xffffffee, 23, Inst::A_ADD } // -18
,	{ 0xfffffff0, 16, Inst::A_OR }  // -16
,	{ 0xfffffff0, 24, Inst::A_ADD }
,	{ 0xfffffff0, 15, Inst::A_NOT }
,	{ 0xfffffff0, 16, Inst::M_V8MIN }
,	{ 0xfffffff1, 17, Inst::A_OR }  // -15
,	{ 0xfffffff1, 17, Inst::M_V8MIN }
,	{ 0xfffffff1, 14, Inst::A_NOT }
,	{ 0xfffffff2, 18, Inst::A_OR }  // -14
,	{ 0xfffffff2, 25, Inst::A_ADD }
,	{ 0xfffffff2, 13, Inst::A_NOT }
,	{ 0xfffffff2, 18, Inst::M_V8MIN }
,	{ 0xfffffff3, 19, Inst::A_OR }  // -13
,	{ 0xfffffff3, 12, Inst::A_NOT }
,	{ 0xfffffff3, 19, Inst::M_V8MIN }
,	{ 0xfffffff4, 20, Inst::A_OR }  // -12
,	{ 0xfffffff4, 26, Inst::A_ADD }
,	{ 0xfffffff4, 11, Inst::A_NOT }
,	{ 0xfffffff4, 20, Inst::M_V8MIN }
,	{ 0xfffffff5, 21, Inst::A_OR }  // -11
,	{ 0xfffffff5, 10, Inst::A_NOT }
,	{ 0xfffffff5, 21, Inst::M_V8MIN }
,	{ 0xfffffff6, 22, Inst::A_OR }  // -10
,	{ 0xfffffff6, 27, Inst::A_ADD }
,	{ 0xfffffff6,  9, Inst::A_NOT }
,	{ 0xfffffff6, 22, Inst::M_V8MIN }
,	{ 0xfffffff7, 23, Inst::A_OR }  // -9
,	{ 0xfffffff7,  8, Inst::A_NOT }
,	{ 0xfffffff7, 23, Inst::M_V8MIN }
,	{ 0xfffffff8, 24, Inst::A_OR }  // -8
,	{ 0xfffffff8, 28, Inst::A_ADD }
,	{ 0xfffffff8,  7, Inst::A_NOT }
,	{ 0xfffffff8, 24, Inst::M_V8MIN }
,	{ 0xfffffff9, 25, Inst::A_OR }  // -7
,	{ 0xfffffff9,  6, Inst::A_NOT }
,	{ 0xfffffff9, 25, Inst::M_V8MIN }
,	{ 0xfffffffa, 26, Inst::A_OR }  // -6
,	{ 0xfffffffa, 29, Inst::A_ADD }
,	{ 0xfffffffa,  5, Inst::A_NOT }
,	{ 0xfffffffa, 26, Inst::M_V8MIN }
,	{ 0xfffffffb, 27, Inst::A_OR }  // -5
,	{ 0xfffffffb,  4, Inst::A_NOT }
,	{ 0xfffffffb, 27, Inst::M_V8MIN }
,	{ 0xfffffffc, 28, Inst::A_OR }  // -4
,	{ 0xfffffffc, 30, Inst::A_ADD }
,	{ 0xfffffffc,  3, Inst::A_NOT }
,	{ 0xfffffffc, 28, Inst::M_V8MIN }
,	{ 0xfffffffd, 29, Inst::A_OR }  // -3
,	{ 0xfffffffd,  2, Inst::A_NOT }
,	{ 0xfffffffd, 29, Inst::M_V8MIN }
,	{ 0xfffffffe, 30, Inst::A_OR }  // -2
,	{ 0xfffffffe, 31, Inst::A_ADD }
,	{ 0xfffffffe,  1, Inst::A_NOT }
,	{ 0xfffffffe, 30, Inst::M_V8MIN }
,	{ 0xffffffff, 31, Inst::A_OR }  // -1
,	{ 0xffffffff,  0, Inst::A_NOT }
,	{ 0xffffffff, 31, Inst::M_V8MIN }
,	{ 0,           0, Inst::A_NOP } // dummy entry for termination
};

/// Map with opcode tokens, must be ordered.
const Parser::opEntry<8> Parser::opcodeMap[] =
{	{"add",    &Parser::assembleADD,  Inst::A_ADD }
,	{"and",    &Parser::assembleADD,  Inst::A_AND }
,	{"asr",    &Parser::assembleADD,  Inst::A_ASR }
,	{"bpkt",   &Parser::assembleSIG,  Inst::S_BREAK }
,	{"bra",    &Parser::assembleBRANCH, false }
,	{"break",  &Parser::assembleSIG,  Inst::S_BREAK }
,	{"brr",    &Parser::assembleBRANCH, true }
,	{"clz",    &Parser::assembleADD,  Inst::A_CLZ }
,	{"fadd",   &Parser::assembleADD,  Inst::A_FADD }
,	{"fmax",   &Parser::assembleADD,  Inst::A_FMAX }
,	{"fmaxabs",&Parser::assembleADD,  Inst::A_FMAXABS }
,	{"fmin",   &Parser::assembleADD,  Inst::A_FMIN }
,	{"fminabs",&Parser::assembleADD,  Inst::A_FMINABS }
,	{"fmul",   &Parser::assembleMUL,  Inst::M_FMUL }
,	{"fsub",   &Parser::assembleADD,  Inst::A_FSUB }
,	{"ftoi",   &Parser::assembleADD,  Inst::A_FTOI }
,	{"itof",   &Parser::assembleADD,  Inst::A_ITOF }
,	{"ldaltlb",&Parser::assembleSIG,  Inst::S_LOADAM }
,	{"ldcend", &Parser::assembleSIG,  Inst::S_LDCEND }
,	{"ldcoend",&Parser::assembleSIG,  Inst::S_LDCEND }
,	{"ldcotlb",&Parser::assembleSIG,  Inst::S_LOADC }
,	{"ldcvtlb",&Parser::assembleSIG,  Inst::S_LOADCV }
,	{"ldi",    &Parser::assembleMOV,  Inst::L_LDI }
,	{"ldipes", &Parser::assembleMOV,  Inst::L_PES }
,	{"ldipeu", &Parser::assembleMOV,  Inst::L_PEU }
,	{"ldtmu0", &Parser::assembleSIG,  Inst::S_LDTMU0 }
,	{"ldtmu1", &Parser::assembleSIG,  Inst::S_LDTMU1 }
,	{"loadam", &Parser::assembleSIG,  Inst::S_LOADAM }
,	{"loadc",  &Parser::assembleSIG,  Inst::S_LOADC }
,	{"loadcv", &Parser::assembleSIG,  Inst::S_LOADCV }
,	{"lswitch",&Parser::assembleSIG,  Inst::S_LTHRSW }
,	{"lthrsw", &Parser::assembleSIG,  Inst::S_LTHRSW }
,	{"max",    &Parser::assembleADD,  Inst::A_MAX }
,	{"min",    &Parser::assembleADD,  Inst::A_MIN }
,	{"mov",    &Parser::assembleMOV,  -1 }
,	{"mul24",  &Parser::assembleMUL,  Inst::M_MUL24 }
,	{"nop",    &Parser::assembleADD,  Inst::A_NOP } // alternative M_NOP
,	{"not",    &Parser::assembleADD,  Inst::A_NOT }
,	{"or",     &Parser::assembleADD,  Inst::A_OR }
,	{"ror",    &Parser::assembleADD,  Inst::A_ROR }
,	{"sacq",   &Parser::assembleSEMA, 1 }
,	{"sbdone", &Parser::assembleSIG,  Inst::S_SBDONE }
,	{"sbwait", &Parser::assembleSIG,  Inst::S_SBWAIT }
//,	{"sema",   &Parser::assembleSEMA, -1 } // other syntax
,	{"shl",    &Parser::assembleADD,  Inst::A_SHL }
,	{"shr",    &Parser::assembleADD,  Inst::A_SHR }
,	{"srel",   &Parser::assembleSEMA, 0 }
,	{"sub",    &Parser::assembleADD,  Inst::A_SUB }
,	{"tend",   &Parser::assembleSIG,  Inst::S_THREND }
,	{"thrend", &Parser::assembleSIG,  Inst::S_THREND }
,	{"thrsw",  &Parser::assembleSIG,  Inst::S_THRSW }
,	{"tswitch",&Parser::assembleSIG,  Inst::S_THRSW }
,	{"unlscb", &Parser::assembleSIG,  Inst::S_SBDONE }
,	{"v8max",  &Parser::assembleMUL,  Inst::M_V8MAX }
,	{"v8min",  &Parser::assembleMUL,  Inst::M_V8MIN }
,	{"v8muld", &Parser::assembleMUL,  Inst::M_V8MULD }
,	{"v8adds", &Parser::assembleADD,  Inst::A_V8ADDS } // alternative M_V8ADDS
,	{"v8subs", &Parser::assembleADD,  Inst::A_V8SUBS } // alternative M_V8SUBS
,	{"waitscb",&Parser::assembleSIG,  Inst::S_SBWAIT }
};

const Parser::opExtEntry Parser::extMap[] =
{	{ "16a",            &Parser::addPack,   Inst::P_16a,    E_DST }
,	{ "16a",            &Parser::addUnpack, Inst::U_16a,    E_SRC }
,	{ "16aclamp",       &Parser::addPack,   Inst::P_16aS,   E_DST }
,	{ "16as",           &Parser::addPack,   Inst::P_16aS,   E_DST }
,	{ "16b",            &Parser::addPack,   Inst::P_16b,    E_DST }
,	{ "16b",            &Parser::addUnpack, Inst::U_16b,    E_SRC }
,	{ "16bclamp",       &Parser::addPack,   Inst::P_16bS,   E_DST }
,	{ "16bs",           &Parser::addPack,   Inst::P_16bS,   E_DST }
,	{ "32",             &Parser::addPack,   Inst::P_32,     E_DST } // NOP
,	{ "32",             &Parser::addUnpack, Inst::U_32,     E_SRC } // NOP
,	{ "32clamp",        &Parser::addPack,   Inst::P_32S,    E_DST }
,	{ "32s",            &Parser::addPack,   Inst::P_32S,    E_DST }
,	{ "8abcd",          &Parser::addPack,   Inst::P_8abcd,  E_DST }
,	{ "8abcds",         &Parser::addPack,   Inst::P_8abcdS, E_DST }
,	{ "8ddupe",         &Parser::addPack,   Inst::P_8abcd,  E_DST }
,	{ "8ddupeclamp",    &Parser::addPack,   Inst::P_8abcdS, E_DST }
,	{ "8a",             &Parser::addPack,   Inst::P_8a,     E_DST }
,	{ "8a",             &Parser::addUnpack, Inst::U_8a,     E_SRC }
,	{ "8aclamp",        &Parser::addPack,   Inst::P_8aS,    E_DST }
,	{ "8as",            &Parser::addPack,   Inst::P_8aS,    E_DST }
,	{ "8b",             &Parser::addPack,   Inst::P_8b,     E_DST }
,	{ "8b",             &Parser::addUnpack, Inst::U_8b,     E_SRC }
,	{ "8bclamp",        &Parser::addPack,   Inst::P_8bS,    E_DST }
,	{ "8bs",            &Parser::addPack,   Inst::P_8bS,    E_DST }
,	{ "8c",             &Parser::addPack,   Inst::P_8c,     E_DST }
,	{ "8c",             &Parser::addUnpack, Inst::U_8c,     E_SRC }
,	{ "8cclamp",        &Parser::addPack,   Inst::P_8cS,    E_DST }
,	{ "8cs",            &Parser::addPack,   Inst::P_8cS,    E_DST }
,	{ "8d",             &Parser::addPack,   Inst::P_8d,     E_DST }
,	{ "8d",             &Parser::addUnpack, Inst::U_8d,     E_SRC }
,	{ "8dclamp",        &Parser::addPack,   Inst::P_8dS,    E_DST }
,	{ "8ddupe",         &Parser::addUnpack, Inst::U_8dr,    E_SRC }
,	{ "8dr",            &Parser::addUnpack, Inst::U_8dr,    E_SRC }
,	{ "8ds",            &Parser::addPack,   Inst::P_8dS,    E_DST }
,	{ "16a",            &Parser::addPack,   Inst::P_16a,    E_DST }
,	{ "16aclamp",       &Parser::addPack,   Inst::P_16aS,   E_DST }
,	{ "16as",           &Parser::addPack,   Inst::P_16aS,   E_DST }
,	{ "16b",            &Parser::addPack,   Inst::P_16b,    E_DST }
,	{ "16bclamp",       &Parser::addPack,   Inst::P_16bS,   E_DST }
,	{ "16bs",           &Parser::addPack,   Inst::P_16bS,   E_DST }
,	{ "allc",           &Parser::addCond,   Inst::B_ALLC,   E_OP }
,	{ "allcc",          &Parser::addCond,   Inst::B_ALLNC,  E_OP }
,	{ "allcs",          &Parser::addCond,   Inst::B_ALLC,   E_OP }
,	{ "alln",           &Parser::addCond,   Inst::B_ALLN,   E_OP }
,	{ "allnc",          &Parser::addCond,   Inst::B_ALLNC,  E_OP }
,	{ "allnn",          &Parser::addCond,   Inst::B_ALLNN,  E_OP }
,	{ "allnz",          &Parser::addCond,   Inst::B_ALLNZ,  E_OP }
,	{ "allz",           &Parser::addCond,   Inst::B_ALLZ,   E_OP }
,	{ "anyc",           &Parser::addCond,   Inst::B_ANYC,   E_OP }
,	{ "anycc",          &Parser::addCond,   Inst::B_ANYNC,  E_OP }
,	{ "anycs",          &Parser::addCond,   Inst::B_ANYC,   E_OP }
,	{ "anyn",           &Parser::addCond,   Inst::B_ANYN,   E_OP }
,	{ "anync",          &Parser::addCond,   Inst::B_ANYNC,  E_OP }
,	{ "anynn",          &Parser::addCond,   Inst::B_ANYNN,  E_OP }
,	{ "anynz",          &Parser::addCond,   Inst::B_ANYNZ,  E_OP }
,	{ "anyz",           &Parser::addCond,   Inst::B_ANYZ,   E_OP }
,	{ "ifc",            &Parser::addIf,     Inst::C_CS,     E_DSTOP }
,	{ "ifcc",           &Parser::addIf,     Inst::C_CC,     E_DSTOP }
,	{ "ifcs",           &Parser::addIf,     Inst::C_CS,     E_DSTOP }
,	{ "ifn",            &Parser::addIf,     Inst::C_NS,     E_DSTOP }
,	{ "ifnc",           &Parser::addIf,     Inst::C_NC,     E_DSTOP }
,	{ "ifns",           &Parser::addIf,     Inst::C_NS,     E_DSTOP }
,	{ "ifnz",           &Parser::addIf,     Inst::C_ZC,     E_DSTOP }
,	{ "ifz",            &Parser::addIf,     Inst::C_ZS,     E_DSTOP }
,	{ "ifzc",           &Parser::addIf,     Inst::C_ZC,     E_DSTOP }
,	{ "ifzs",           &Parser::addIf,     Inst::C_ZS,     E_DSTOP }
,	{ "never",          &Parser::addIf,     Inst::C_NEVER,  E_DSTOP }
,	{ "pack16a",        &Parser::addPack,   Inst::P_16a,    E_DSTOP }
,	{ "pack16aclamp",   &Parser::addPack,   Inst::P_16aS,   E_DSTOP }
,	{ "pack16as",       &Parser::addPack,   Inst::P_16aS,   E_DSTOP }
,	{ "pack16b",        &Parser::addPack,   Inst::P_16b,    E_DSTOP }
,	{ "pack16bclamp",   &Parser::addPack,   Inst::P_16bS,   E_DSTOP }
,	{ "pack16bs",       &Parser::addPack,   Inst::P_16bS,   E_DSTOP }
,	{ "pack32",         &Parser::addPack,   Inst::P_32,     E_DSTOP } // NOP
,	{ "pack32clamp",    &Parser::addPack,   Inst::P_32S,    E_DSTOP }
,	{ "pack32s",        &Parser::addPack,   Inst::P_32S,    E_DSTOP }
,	{ "pack8abcd",      &Parser::addPack,   Inst::P_8abcd,  E_DSTOP }
,	{ "pack8abcds",     &Parser::addPack,   Inst::P_8abcdS, E_DSTOP }
,	{ "pack8ddupe",     &Parser::addPack,   Inst::P_8abcd,  E_DSTOP }
,	{ "pack8ddupeclamp",&Parser::addPack,   Inst::P_8abcdS, E_DSTOP }
,	{ "pack8a",         &Parser::addPack,   Inst::P_8a,     E_DSTOP }
,	{ "pack8aclamp",    &Parser::addPack,   Inst::P_8aS,    E_DSTOP }
,	{ "pack8as",        &Parser::addPack,   Inst::P_8aS,    E_DSTOP }
,	{ "pack8b",         &Parser::addPack,   Inst::P_8b,     E_DSTOP }
,	{ "pack8bclamp",    &Parser::addPack,   Inst::P_8bS,    E_DSTOP }
,	{ "pack8bs",        &Parser::addPack,   Inst::P_8bS,    E_DSTOP }
,	{ "pack8c",         &Parser::addPack,   Inst::P_8c,     E_DSTOP }
,	{ "pack8cclamp",    &Parser::addPack,   Inst::P_8cS,    E_DSTOP }
,	{ "pack8cs",        &Parser::addPack,   Inst::P_8cS,    E_DSTOP }
,	{ "pack8d",         &Parser::addPack,   Inst::P_8d,     E_DSTOP }
,	{ "pack8dclamp",    &Parser::addPack,   Inst::P_8dS,    E_DSTOP }
,	{ "pack8ds",        &Parser::addPack,   Inst::P_8dS,    E_DSTOP }
,	{ "rot",            &Parser::addRot,    0,              E_DSTOP }
,	{ "setf",           &Parser::addSetF,   0,              E_OP }
,	{ "unpack16a",      &Parser::addUnpack, Inst::U_16a,    E_SRCOP }
,	{ "unpack16b",      &Parser::addUnpack, Inst::U_16b,    E_SRCOP }
,	{ "unpack32",       &Parser::addUnpack, Inst::U_32,     E_SRCOP } // NOP
,	{ "unpack8ddupe",   &Parser::addUnpack, Inst::U_8dr,    E_SRCOP }
,	{ "unpack8dr",      &Parser::addUnpack, Inst::U_8dr,    E_SRCOP }
,	{ "unpack8a",       &Parser::addUnpack, Inst::U_8a,     E_SRCOP }
,	{ "unpack8b",       &Parser::addUnpack, Inst::U_8b,     E_SRCOP }
,	{ "unpack8c",       &Parser::addUnpack, Inst::U_8c,     E_SRCOP }
,	{ "unpack8d",       &Parser::addUnpack, Inst::U_8d,     E_SRCOP }
};

const Parser::opEntry<8> Parser::directiveMap[] =
{	{ "const",   &Parser::parseSET,   2 }
,	{ "else",    &Parser::parseELSE }
,	{ "endif",   &Parser::parseENDIF }
,	{ "endm",    &Parser::endMACRO }
,	{ "endr",    &Parser::endREP }
,	{ "equ",     &Parser::parseSET,   0 }
,	{ "func",    &Parser::defineFUNC }
,	{ "if",      &Parser::parseIF }
,	{ "include", &Parser::doINCLUDE }
,	{ "lconst",  &Parser::parseSET,   3 }
,	{ "lset",    &Parser::parseSET,   1 }
,	{ "lunset",  &Parser::parseUNSET, 1 }
,	{ "macro",   &Parser::beginMACRO }
,	{ "rep",     &Parser::beginREP }
,	{ "set",     &Parser::parseSET,   0 }
,	{ "unset",   &Parser::parseUNSET, 0 }
};