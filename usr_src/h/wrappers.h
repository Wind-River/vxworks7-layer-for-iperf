/* wrappers.h - wrapper functions required to build iperf for VxWorks */

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

#ifndef __INCwrappersh
#define __INCwrappersh

/* includes */

#include <bootLib.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sysLib.h>
#include <taskLib.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* defines */

#define getpid 		(int)taskIdSelf

#define DUMMY_FD	99

extern char * sysBootLine;

/* typedefs */

/* function declarations */

/*******************************************************************************
*
* srandom - seed pseudo-random number generator
*
* Wrapper function
*
* RETURNS: N/A
*/

_WRS_INLINE void srandom
    (
    unsigned int seed
    )
    {
    srand (seed);
    }

/*******************************************************************************
*
* random - generate pseudo-random number
*
* Wrapper function
*
* RETURNS: Pseudo random number
*
* ERRNO: N/A
*/

_WRS_INLINE long int random (void)
    {
    return rand();
    }

/*******************************************************************************
*
* mkstemp - create a temporary file
*
* Wrapper function
*
* RETURNS: file handle to temporary file, or -1 if error
*
* ERRNO: N/A
*/

_WRS_INLINE int mkstemp
    (
    char * template
    )
    {
    return DUMMY_FD;
    }

/*******************************************************************************
*
* gethostname - get host name
*
* Wrapper function
*
* RETURNS: Always 0
*
* ERRNO: N/A
*/

_WRS_INLINE int gethostname
    (
    char * name,
    size_t len
    )
    {
    BOOT_PARAMS p;

    (void)bootStringToStruct (sysBootLine, &p);
    strncpy (name, p.targetName, len - 1);
    name[len - 1] = '\0';

    return 0;
    }

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __INCwrappersh */
