/*
 * XXX This file is a total hack, even worse than our neighbor fake_stubs.c. The
 * entire point of this is to contain data definitions so we can make forward
 * progress through the realm of unix and genunix. Several of these definitions
 * are the wrong storage size. If we are using them for any actual purpose we
 * should stop and reconsider what's going on.
 */

#include <sys/types.h>
#include <sys/clock.h>
#include <sys/kmem.h>
#include <sys/ksynch.h>

int in_sync = 0;
uint_t adj_shift = ADJ_SHIFT;
void *segkp = NULL;
timespec_t panic_hrestime;
int interrupts_unleashed;
void *process_cache;
void *static_arena;
void *proc_pageout;
void *anonhash_lock;
void *panic_thread;
uint64_t total_pages;
hrtime_t panic_hrtime;
void *heap32_arena;
int panic_forced = 0;
pgcnt_t kcage_needfree;
void *ani_free_pool;
void *anon_hash;
unsigned int anon_hash_shift;
size_t anon_hash_size;
kmutex_t anoninfo_lock;
int audit_active = 0;
uint_t availrmem;
uint_t availrmem_initial;
int boot_max_ncpus = -1;
const k_sigset_t cantmask;
clock_t clock_tick_proc_max;
int cluster_bootflags;
uint_t cp_haltset_fanout = 0;
void *cpu_active;
void *cpu_inmotion;
void *cpu_list;
kmutex_t cpu_lock;
void **cpu_seq;
void *devnamesp;
uint_t dump_plat_mincpu_default = 0;
const k_sigset_t fillset;
int free_pages = 1;
pgcnt_t freemem;
kmutex_t freemem_lock;
volatile timestruc_t hrestime;
int64_t hrestime_adj;
const k_sigset_t ignoredefault;
int k_anoninfo;
pgcnt_t kcage_desfree;
pgcnt_t kcage_freemem;
int kcage_on = 0;
int klustsize = 56 * 1024;
int lgrp_alloc_max;
int lgrp_gen;
int lgrp_mem_default_policy = 0;
void *lgrp_table[64];
int max_cpuid = 1;
int max_ncpus = 2;
int maxphys = 56 * 1024;
void *mb_hashtab[64];
void *memsegs;
uintptr_t mod_nodev_ops[8];
void (*mutex_lock_delay)(uint_t);
uint_t (*mutex_lock_backoff)(uint_t);
uintptr_t native_brand;
int ncpus = 1;
int ncpus_online = 1;
int nlgrps;
int nlgrpsmax;
const k_sigset_t nullsmask;
uintptr_t orphanlist;
pgcnt_t pages_locked;
int panic_bootfcn;
char *panic_bootstr = NULL;
int panic_cpu;
int panic_dump;
int panic_sync;
uintptr_t panicargs;
char *volatile panicstr;
void *phys_install;
char *platform_module_list[] = { NULL };
void *proc_fsflush, *proc_init, *proc_sched;
volatile int quiesce_active;
uint_t rctlproc_flags;
uint_t rctlproc_legacy;
uint_t rctlproc_signals;
void *rootvfs;
void *segkmap;
void *segkpm;
int sync_timeleft;
int64_t timedetla;
krwlock_t vfssw_lock;
int64_t timedelta;
disp_lock_t stop_lock;
char panicbuf[8192];
id_t defaultcid;
int nswapped;
int cp_numparts;
int kpreemptpri;
void *cp_list_head;
disp_lock_t swapped_lock, transition_lock;
int cp_default;
