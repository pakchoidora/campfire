/* Generated by Nim Compiler v0.17.0 */
/*   (c) 2017 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: MacOSX, amd64, clang */
/* Command for C compiler:
   clang -c  -w  -I/usr/local/Cellar/nim/0.17.0/nim/lib -o /Users/pakchoi/Workspace/campfire/src/nimcache/sdl2_mixer.o /Users/pakchoi/Workspace/campfire/src/nimcache/sdl2_mixer.c */
#define NIM_NEW_MANGLING_RULES
#define NIM_INTBITS 64

#include "nimbase.h"
#undef linux
#undef near
typedef struct TGenericSeq TGenericSeq;
typedef struct NimStringDesc NimStringDesc;
typedef struct Music_Vn6WD0VwBnoULHVMnyrkwQ Music_Vn6WD0VwBnoULHVMnyrkwQ;
typedef struct Chunk_VX9bcqnrA9c5vzbGkN3CfJcA Chunk_VX9bcqnrA9c5vzbGkN3CfJcA;
typedef struct RWops_CLIyzMHHcrhaNlCqUuM1OA RWops_CLIyzMHHcrhaNlCqUuM1OA;
typedef struct Mem_Y7I9bNHWVNgY3LblplAgArw Mem_Y7I9bNHWVNgY3LblplAgArw;
struct  TGenericSeq  {
NI len;
NI reserved;
};
struct  NimStringDesc  {
  TGenericSeq Sup;
NIM_CHAR data[SEQ_DECL_SIZE];
};
typedef N_CDECL_PTR(int, TY_6DzmQdLg31OmeFUXpotB2g) (int channel, int volume);
typedef N_CDECL_PTR(int, TY_4hSZquf3VZZvlELaYshEWg) (int volume);
typedef N_CDECL_PTR(Music_Vn6WD0VwBnoULHVMnyrkwQ*, TY_687KpSvUN4jGmi75YHgfAA) (NCSTRING file);
typedef N_CDECL_PTR(int, TY_Me6si9aLeR5dK04JjP6ueMw) (Music_Vn6WD0VwBnoULHVMnyrkwQ* music, int loops);
typedef N_CDECL_PTR(int, TY_atHCNHSHP9cHNabrrTFYSZg) (Music_Vn6WD0VwBnoULHVMnyrkwQ* music, int loops, int ms);
typedef N_CDECL_PTR(Chunk_VX9bcqnrA9c5vzbGkN3CfJcA*, TY_7gOrd8YjstY2dDB8bQb69cg) (RWops_CLIyzMHHcrhaNlCqUuM1OA* src, int freesrc);
typedef N_CDECL_PTR(int, TY_aseY2vKVPogzPeFns0J8EQ) (int channel, Chunk_VX9bcqnrA9c5vzbGkN3CfJcA* chunk, int loops, int ticks);
typedef N_CDECL_PTR(int, TY_QfSTmsZTaEEiWuexopQsmQ) (int frequency, NU16 format, int channels, int chunksize);
typedef N_CDECL_PTR(void, TY_ln4kdL5W9bbX4a1xl8nnVXQ) (void);
struct  Music_Vn6WD0VwBnoULHVMnyrkwQ  {
char dummy;
};
struct  Chunk_VX9bcqnrA9c5vzbGkN3CfJcA  {
int allocated;
NU8* abuf;
NU32 alen;
NU8 volume;
};
typedef N_CDECL_PTR(NI64, TY_pv8LHGd6Yei89cd2Rd8hv8g) (RWops_CLIyzMHHcrhaNlCqUuM1OA* context);
typedef N_CDECL_PTR(NI64, TY_0zChuivuFV72gZwz2rUkHA) (RWops_CLIyzMHHcrhaNlCqUuM1OA* context, NI64 offset, int whence);
typedef N_CDECL_PTR(size_t, TY_i5pcx3FBdKHMUS2uvRgvYw) (RWops_CLIyzMHHcrhaNlCqUuM1OA* context, void* destination, size_t size, size_t maxnum);
typedef N_CDECL_PTR(int, TY_LaZp89cSat1m2LqumdMScDw) (RWops_CLIyzMHHcrhaNlCqUuM1OA* context);
struct  Mem_Y7I9bNHWVNgY3LblplAgArw  {
NU8* base;
NU8* here;
NU8* stop;
};
struct  RWops_CLIyzMHHcrhaNlCqUuM1OA  {
TY_pv8LHGd6Yei89cd2Rd8hv8g size;
TY_0zChuivuFV72gZwz2rUkHA seek;
TY_i5pcx3FBdKHMUS2uvRgvYw read;
TY_i5pcx3FBdKHMUS2uvRgvYw write;
TY_LaZp89cSat1m2LqumdMScDw close;
int kind;
Mem_Y7I9bNHWVNgY3LblplAgArw mem;
};
N_NIMCALL(void*, nimLoadLibrary)(NimStringDesc* path);
N_NOINLINE(void, nimLoadLibraryError)(NimStringDesc* path);
N_NIMCALL(void*, nimGetProcAddr)(void* lib, NCSTRING name);
static N_INLINE(void, nimFrame)(TFrame* s);
N_NOINLINE(void, stackOverflow_II46IjNZztN9bmbxUD8dt8g)(void);
static N_INLINE(void, popFrame)(void);
static void* TM_Br69cUFlze53b9aOFOZb6qwQ_2;
TY_6DzmQdLg31OmeFUXpotB2g Dl_406275_;
TY_4hSZquf3VZZvlELaYshEWg Dl_406284_;
TY_687KpSvUN4jGmi75YHgfAA Dl_405881_;
TY_Me6si9aLeR5dK04JjP6ueMw Dl_406242_;
TY_4hSZquf3VZZvlELaYshEWg Dl_406307_;
TY_atHCNHSHP9cHNabrrTFYSZg Dl_406247_;
TY_7gOrd8YjstY2dDB8bQb69cg Dl_405872_;
TY_4hSZquf3VZZvlELaYshEWg Dl_406287_;
TY_aseY2vKVPogzPeFns0J8EQ Dl_406229_;
TY_4hSZquf3VZZvlELaYshEWg Dl_405810_;
TY_QfSTmsZTaEEiWuexopQsmQ Dl_405855_;
TY_ln4kdL5W9bbX4a1xl8nnVXQ Dl_406365_;
extern TFrame* framePtr_HRfVMH3jYeBJz6Q6X9b6Ptw;
STRING_LITERAL(TM_Br69cUFlze53b9aOFOZb6qwQ_4, "libSDL2_mixer.dylib", 19);
STRING_LITERAL(TM_Br69cUFlze53b9aOFOZb6qwQ_5, "libSDL2_mixer.dylib", 19);

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
NIM_EXTERNC N_NOINLINE(void, sdl2_mixerInit000)(void) {
	nimfr_("mixer", "mixer.nim")
	popFrame();
}

NIM_EXTERNC N_NOINLINE(void, sdl2_mixerDatInit000)(void) {
if (!((TM_Br69cUFlze53b9aOFOZb6qwQ_2 = nimLoadLibrary((NimStringDesc*) &TM_Br69cUFlze53b9aOFOZb6qwQ_4))
)) nimLoadLibraryError((NimStringDesc*) &TM_Br69cUFlze53b9aOFOZb6qwQ_5);
	Dl_406275_ = (TY_6DzmQdLg31OmeFUXpotB2g) nimGetProcAddr(TM_Br69cUFlze53b9aOFOZb6qwQ_2, "Mix_Volume");
	Dl_406284_ = (TY_4hSZquf3VZZvlELaYshEWg) nimGetProcAddr(TM_Br69cUFlze53b9aOFOZb6qwQ_2, "Mix_VolumeMusic");
	Dl_405881_ = (TY_687KpSvUN4jGmi75YHgfAA) nimGetProcAddr(TM_Br69cUFlze53b9aOFOZb6qwQ_2, "Mix_LoadMUS");
	Dl_406242_ = (TY_Me6si9aLeR5dK04JjP6ueMw) nimGetProcAddr(TM_Br69cUFlze53b9aOFOZb6qwQ_2, "Mix_PlayMusic");
	Dl_406307_ = (TY_4hSZquf3VZZvlELaYshEWg) nimGetProcAddr(TM_Br69cUFlze53b9aOFOZb6qwQ_2, "Mix_FadeOutMusic");
	Dl_406247_ = (TY_atHCNHSHP9cHNabrrTFYSZg) nimGetProcAddr(TM_Br69cUFlze53b9aOFOZb6qwQ_2, "Mix_FadeInMusic");
	Dl_405872_ = (TY_7gOrd8YjstY2dDB8bQb69cg) nimGetProcAddr(TM_Br69cUFlze53b9aOFOZb6qwQ_2, "Mix_LoadWAV_RW");
	Dl_406287_ = (TY_4hSZquf3VZZvlELaYshEWg) nimGetProcAddr(TM_Br69cUFlze53b9aOFOZb6qwQ_2, "Mix_HaltChannel");
	Dl_406229_ = (TY_aseY2vKVPogzPeFns0J8EQ) nimGetProcAddr(TM_Br69cUFlze53b9aOFOZb6qwQ_2, "Mix_PlayChannelTimed");
	Dl_405810_ = (TY_4hSZquf3VZZvlELaYshEWg) nimGetProcAddr(TM_Br69cUFlze53b9aOFOZb6qwQ_2, "Mix_Init");
	Dl_405855_ = (TY_QfSTmsZTaEEiWuexopQsmQ) nimGetProcAddr(TM_Br69cUFlze53b9aOFOZb6qwQ_2, "Mix_OpenAudio");
	Dl_406365_ = (TY_ln4kdL5W9bbX4a1xl8nnVXQ) nimGetProcAddr(TM_Br69cUFlze53b9aOFOZb6qwQ_2, "Mix_CloseAudio");
}

