/* wrappers.h - wrapper functions required to build iperf for VxWorks */

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
