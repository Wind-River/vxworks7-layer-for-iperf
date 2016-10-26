/* utsname.h - kernel information library header file */

/*
 * Copyright (C) 2016 Wind River Systems, Inc.
 *
 * The right to copy, distribute, modify, or otherwise make use
 * of this software may be licensed only pursuant to the terms
 * of an applicable Wind River license agreement.
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

char * sysBootLine;

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
