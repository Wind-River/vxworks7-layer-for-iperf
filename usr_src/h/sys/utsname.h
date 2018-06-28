/* utsname.h - kernel information library header file */

/*
Copyright (c) 2016, Wind River Systems, Inc.

Redistribution and use in source and binary forms, with or without modification, are
permitted provided that the following conditions are met:

1) Redistributions of source code must retain the above copyright notice, this list of 
conditions and the following disclaimer.
2) Redistributions in binary form must reproduce the above copyright notice, this list 
of conditions and the following disclaimer in the documentation and/or other materials 
provided with the distribution.
3) Neither the name of Wind River Systems nor the names of its contributors may be
used to endorse or promote products derived from this software without specific
prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"AND ANY EXPRESS 
OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THEIMPLIED WARRANTIES OF MERCHANTABILITY
AND FITNESS FOR A PARTICULAR PURPOSEARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
CONTRIBUTORS BELIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS ORSERVICES; LOSS OF USE, 
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVERCAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
OF THEUSE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/*
modification history
--------------------
31aug16,kjn  written
*/

#ifndef __INCutsnameh
#define __INCutsnameh

/* includes */

#include <string.h>

#include "../wrappers.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* defines */

#define RUSAGE_SELF	0
#define RUSAGE_CHILDREN	1
#define RUSAGE_THREAD	2

#ifdef _WRS_CONFIG_CORE_VERSION
#define _WRS_CONFIG_CORE_KERNEL_VERSION _WRS_CONFIG_CORE_VERSION
#endif

/* typedefs */

struct rusage
    {
    struct timeval ru_utime; /* user CPU time used */
    struct timeval ru_stime; /* system CPU time used */
    long   ru_maxrss;        /* maximum resident set size */
    long   ru_ixrss;         /* integral shared memory size */
    long   ru_idrss;         /* integral unshared data size */
    long   ru_isrss;         /* integral unshared stack size */
    long   ru_minflt;        /* page reclaims (soft page faults) */
    long   ru_majflt;        /* page faults (hard page faults) */
    long   ru_nswap;         /* swaps */
    long   ru_inblock;       /* block input operations */
    long   ru_oublock;       /* block output operations */
    long   ru_msgsnd;        /* IPC messages sent */
    long   ru_msgrcv;        /* IPC messages received */
    long   ru_nsignals;      /* signals received */
    long   ru_nvcsw;         /* voluntary context switches */
    long   ru_nivcsw;        /* involuntary context switches */
    };

struct utsname
    {
    char sysname[8];   /* Operating system name, will be "VxWorks" */
    char nodename[BOOT_HOST_LEN]; /* Name within "some implementation-defined
                          network" */
    char release[16];  /* Operating system release, */
                       /* _WRS_CONFIG_CORE_KERNEL_VERSION */
    char version[2];   /* Operating system version, will be "7" */
    char machine[16];  /* Hardware identifier */
    };

/* function declarations */

/*******************************************************************************
*
* getrusage - get resource usage
*
* Wrapper function, does nothing more than set all valus to zero
*
* RETURNS: Always 0
*
* ERRNO: N/A
*/

_WRS_INLINE int getrusage
    (
    int who,
    struct rusage * usage
    )
    {
    memset (usage, 0, sizeof *usage);
    return 0;
    }

/*******************************************************************************
*
* uname - get system version information
*
* Wrapper function
*
* RETURNS: Always 0
*
* ERRNO: N/A
*/

_WRS_INLINE int uname(struct utsname *name)
    {
    BOOT_PARAMS p;

    (void)bootStringToStruct (sysBootLine, &p);

    strcpy (name->sysname, "VxWorks");
    strcpy (name->nodename, p.targetName);
    strcpy (name->release, _WRS_CONFIG_CORE_KERNEL_VERSION);
    strcpy (name->version, "7");
    strcpy (name->machine, "");
    return 0;
    }

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __INCutsnameh */
