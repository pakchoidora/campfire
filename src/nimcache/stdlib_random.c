/* Generated by Nim Compiler v0.17.0 */
/*   (c) 2017 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: MacOSX, amd64, clang */
/* Command for C compiler:
   clang -c  -w  -I/usr/local/Cellar/nim/0.17.0/nim/lib -o /Users/pakchoi/Workspace/campfire/src/nimcache/stdlib_random.o /Users/pakchoi/Workspace/campfire/src/nimcache/stdlib_random.c */
#define NIM_NEW_MANGLING_RULES
#define NIM_INTBITS 64

#include "nimbase.h"
#include <string.h>
#include <time.h>
#undef linux
#undef near
typedef struct RandomGenState_zKRAkOHolLe9c9cWgp3swUJg RandomGenState_zKRAkOHolLe9c9cWgp3swUJg;
struct  RandomGenState_zKRAkOHolLe9c9cWgp3swUJg  {
NU64 a0;
NU64 a1;
};
typedef NU64 TY_NzKR9bw29cLPrd712Xt6Liiw[2];
N_NIMCALL(NU64, rotl_YUrTkztAwPd2iMVoSj9bYBw)(NU64 x, NU64 k);
static N_INLINE(void, nimFrame)(TFrame* s);
N_NOINLINE(void, stackOverflow_II46IjNZztN9bmbxUD8dt8g)(void);
static N_INLINE(void, popFrame)(void);
N_NIMCALL(NU64, next_XD15WiThqxScuoeOixQIfg)(RandomGenState_zKRAkOHolLe9c9cWgp3swUJg* s);
N_NIMCALL(void, skipRandomNumbers_0eGvnPvcp2KgIHO7rfoxng)(RandomGenState_zKRAkOHolLe9c9cWgp3swUJg* s);
static N_INLINE(NI, chckRange)(NI i, NI a, NI b);
N_NOINLINE(void, raiseRangeError)(NI64 val);
static N_INLINE(NI, addInt)(NI a, NI b);
N_NOINLINE(void, raiseOverflow)(void);
N_NIMCALL(NI, random_F1qFFP53BvbP4L65Kn9bG1w)(NI max);
N_NIMCALL(NF, random_ysAjdvfIGCDnzC8BoWsOAw)(NF max);
N_NIMCALL(void, randomize_gyxuLD9a9bDAOjH46GlrA9aDQ)(NI seed);
N_NIMCALL(void, randomize_RtUZt2O8eA6Y5pFWOsdgjg)(void);
N_NIMCALL(time_t, getTime_Ft5FFURWITtb9aR6Hjpq6UQ)(void);
RandomGenState_zKRAkOHolLe9c9cWgp3swUJg state_4atHrcHUZPts5LqH9bzbl0w;
extern TFrame* framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw;
NIM_CONST TY_NzKR9bw29cLPrd712Xt6Liiw helper_cbo2WAcymPI9ccL5RtkWE1w = {13739361407582206667ULL,
15594563132006766882ULL}
;

static N_INLINE(void, nimFrame)(TFrame* s) {
	NI T1_;
	T1_ = (NI)0;
	{
		if (!(framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw == NIM_NIL)) goto LA4_;
		T1_ = ((NI) 0);
	}
	goto LA2_;
	LA4_: ;
	{
		T1_ = ((NI) ((NI16)((*framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw).calldepth + ((NI16) 1))));
	}
	LA2_: ;
	(*s).calldepth = ((NI16) (T1_));
	(*s).prev = framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw;
	framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw = s;
	{
		if (!((*s).calldepth == ((NI16) 2000))) goto LA9_;
		stackOverflow_II46IjNZztN9bmbxUD8dt8g();
	}
	LA9_: ;
}

static N_INLINE(void, popFrame)(void) {
	framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw = (*framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw).prev;
}

N_NIMCALL(NU64, rotl_YUrTkztAwPd2iMVoSj9bYBw)(NU64 x, NU64 k) {
	NU64 result;
	nimfr_("rotl", "random.nim")
	result = (NU64)0;
	nimln_(44, "random.nim");
	result = (NU64)((NU64)((NU64)(x) << (NU64)(k)) | (NU64)((NU64)(x) >> (NU64)((NU64)((NU64)(64ULL) - (NU64)(k)))));
	popFrame();
	return result;
}

N_NIMCALL(NU64, next_XD15WiThqxScuoeOixQIfg)(RandomGenState_zKRAkOHolLe9c9cWgp3swUJg* s) {
	NU64 result;
	NU64 s0;
	NU64 s1;
	NU64 T1_;
	nimfr_("next", "random.nim")
	result = (NU64)0;
	nimln_(47, "random.nim");
	s0 = (*s).a0;
	nimln_(48, "random.nim");
	s1 = (*s).a1;
	nimln_(49, "random.nim");
	result = (NU64)((NU64)(s0) + (NU64)(s1));
	nimln_(50, "random.nim");
	s1 = (NU64)(s1 ^ s0);
	nimln_(51, "random.nim");
	T1_ = (NU64)0;
	T1_ = rotl_YUrTkztAwPd2iMVoSj9bYBw(s0, 55ULL);
	(*s).a0 = (NU64)((NU64)(T1_ ^ s1) ^ (NU64)((NU64)(s1) << (NU64)(((NI) 14))));
	nimln_(52, "random.nim");
	(*s).a1 = rotl_YUrTkztAwPd2iMVoSj9bYBw(s1, 36ULL);
	popFrame();
	return result;
}

static N_INLINE(NI, chckRange)(NI i, NI a, NI b) {
	NI result;
{	result = (NI)0;
	{
		NIM_BOOL T3_;
		T3_ = (NIM_BOOL)0;
		T3_ = (a <= i);
		if (!(T3_)) goto LA4_;
		T3_ = (i <= b);
		LA4_: ;
		if (!T3_) goto LA5_;
		result = i;
		goto BeforeRet_;
	}
	goto LA1_;
	LA5_: ;
	{
		raiseRangeError(((NI64) (i)));
	}
	LA1_: ;
	}BeforeRet_: ;
	return result;
}

static N_INLINE(NI, addInt)(NI a, NI b) {
	NI result;
{	result = (NI)0;
	result = (NI)((NU64)(a) + (NU64)(b));
	{
		NIM_BOOL T3_;
		T3_ = (NIM_BOOL)0;
		T3_ = (((NI) 0) <= (NI)(result ^ a));
		if (T3_) goto LA4_;
		T3_ = (((NI) 0) <= (NI)(result ^ b));
		LA4_: ;
		if (!T3_) goto LA5_;
		goto BeforeRet_;
	}
	LA5_: ;
	raiseOverflow();
	}BeforeRet_: ;
	return result;
}

N_NIMCALL(void, skipRandomNumbers_0eGvnPvcp2KgIHO7rfoxng)(RandomGenState_zKRAkOHolLe9c9cWgp3swUJg* s) {
	NU64 s0;
	NU64 s1;
	nimfr_("skipRandomNumbers", "random.nim")
	nimln_(63, "random.nim");
	s0 = 0ULL;
	nimln_(64, "random.nim");
	s1 = 0ULL;
	{
		NI i;
		NI res;
		i = (NI)0;
		nimln_(1955, "system.nim");
		res = ((NI) 0);
		{
			nimln_(1956, "system.nim");
			while (1) {
				NI TM_AIKkgex03Z1j45JceakCTA_3;
				if (!(res <= ((NI) 1))) goto LA3;
				nimln_(1957, "system.nim");
				i = ((NI)chckRange(res, ((NI) 0), ((NI) 1)));
				{
					NI b;
					NI i_2;
					b = (NI)0;
					nimln_(3772, "system.nim");
					i_2 = ((NI) 0);
					{
						nimln_(3773, "system.nim");
						while (1) {
							NU64 T11_;
							NI TM_AIKkgex03Z1j45JceakCTA_2;
							if (!(i_2 < ((NI) 64))) goto LA6;
							nimln_(3774, "system.nim");
							b = i_2;
							nimln_(67, "random.nim");
							{
								nimln_(363, "system.nim");
								nimln_(67, "random.nim");
								if (!!(((NU64)(helper_cbo2WAcymPI9ccL5RtkWE1w[(i)- 0] & (NU64)((NU64)(1ULL) << (NU64)(((NU64) (b))))) == ((NI) 0)))) goto LA9_;
								nimln_(68, "random.nim");
								s0 = (NU64)(s0 ^ (*s).a0);
								nimln_(69, "random.nim");
								s1 = (NU64)(s1 ^ (*s).a1);
							}
							LA9_: ;
							nimln_(70, "random.nim");
							T11_ = (NU64)0;
							T11_ = next_XD15WiThqxScuoeOixQIfg(s);
							nimln_(3775, "system.nim");
							TM_AIKkgex03Z1j45JceakCTA_2 = addInt(i_2, ((NI) 1));
							i_2 = (NI)(TM_AIKkgex03Z1j45JceakCTA_2);
						} LA6: ;
					}
				}
				nimln_(1976, "system.nim");
				TM_AIKkgex03Z1j45JceakCTA_3 = addInt(res, ((NI) 1));
				res = (NI)(TM_AIKkgex03Z1j45JceakCTA_3);
			} LA3: ;
		}
	}
	nimln_(71, "random.nim");
	(*s).a0 = s0;
	nimln_(72, "random.nim");
	(*s).a1 = s1;
	popFrame();
}

N_NIMCALL(NI, random_F1qFFP53BvbP4L65Kn9bG1w)(NI max) {
	NI result;
	nimfr_("random", "random.nim")
{	result = (NI)0;
	{
		nimln_(79, "random.nim");
		while (1) {
			NU64 x;
			nimln_(80, "random.nim");
			x = next_XD15WiThqxScuoeOixQIfg((&state_4atHrcHUZPts5LqH9bzbl0w));
			nimln_(81, "random.nim");
			{
				if (!((NU64)(x) < (NU64)((NU64)((NU64)(18446744073709551615ULL) - (NU64)((NU64)((NU64)(18446744073709551615ULL) % (NU64)(((NU64) (max))))))))) goto LA5_;
				nimln_(82, "random.nim");
				result = ((NI) ((NU64)((NU64)(x) % (NU64)(((NU64) (max))))));
				goto BeforeRet_;
			}
			LA5_: ;
		}
	}
	}BeforeRet_: ;
	popFrame();
	return result;
}

N_NIMCALL(NF, random_ysAjdvfIGCDnzC8BoWsOAw)(NF max) {
	NF result;
	NU64 x;
	NU64 u;
	union { NU64 source; NF dest; } LOC1;
	nimfr_("random", "random.nim")
	result = (NF)0;
	nimln_(89, "random.nim");
	x = next_XD15WiThqxScuoeOixQIfg((&state_4atHrcHUZPts5LqH9bzbl0w));
	nimln_(93, "random.nim");
	u = (NU64)(4607182418800017408ULL | (NU64)((NU64)(x) >> (NU64)(12ULL)));
	nimln_(94, "random.nim");
	LOC1.source = u;
	result = ((NF)(((NF)(LOC1.dest) - (NF)(1.0000000000000000e+00))) * (NF)(max));
	popFrame();
	return result;
}

N_NIMCALL(void, randomize_gyxuLD9a9bDAOjH46GlrA9aDQ)(NI seed) {
	NU64 T1_;
	nimfr_("randomize", "random.nim")
	nimln_(106, "random.nim");
	state_4atHrcHUZPts5LqH9bzbl0w.a0 = ((NU64) ((NI)((NU64)(seed) >> (NU64)(((NI) 16)))));
	nimln_(107, "random.nim");
	state_4atHrcHUZPts5LqH9bzbl0w.a1 = ((NU64) ((NI)(seed & ((NI) 65535))));
	nimln_(108, "random.nim");
	T1_ = (NU64)0;
	T1_ = next_XD15WiThqxScuoeOixQIfg((&state_4atHrcHUZPts5LqH9bzbl0w));
	popFrame();
}

N_NIMCALL(void, randomize_RtUZt2O8eA6Y5pFWOsdgjg)(void) {
	time_t T1_;
	nimfr_("randomize", "random.nim")
	nimln_(126, "random.nim");
	T1_ = (time_t)0;
	T1_ = getTime_Ft5FFURWITtb9aR6Hjpq6UQ();
	randomize_gyxuLD9a9bDAOjH46GlrA9aDQ(T1_);
	popFrame();
}
NIM_EXTERNC N_NOINLINE(void, stdlib_randomInit000)(void) {
	RandomGenState_zKRAkOHolLe9c9cWgp3swUJg T1_;
	nimfr_("random", "random.nim")
	nimln_(39, "random.nim");
	memset((void*)(&T1_), 0, sizeof(T1_));
	T1_.a0 = 7616934476015405061ULL;
	T1_.a1 = 15122295919272093642ULL;
	state_4atHrcHUZPts5LqH9bzbl0w = T1_;
	popFrame();
}

NIM_EXTERNC N_NOINLINE(void, stdlib_randomDatInit000)(void) {
}

