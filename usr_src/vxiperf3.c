/* vxiperf.c - stub functions required by iperf on VxWorks */

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

/*
DESCRIPTION
This module contains stubs of things required by iperf3 but is not present in
standard VxWorks.

INCLUDE FILES: iperf_config.h
*/

/* includes */

#include <iperf_config.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wrappers.h>

/* defines */

/* typedefs */

/* globals */

int h_errno;

/* locals */

static jmp_buf iperfAbortJmpBuf;

/* forward declarations */

int iperf3Main (int argc, char * argv[]);

/*******************************************************************************
*
* hstrerror - host error minimal implementation
*
* Host error minimal implementation
*
* RETURNS: String representation of error
*
* ERRNO: N/A
*/

const char * hstrerror
    (
    int err
    )
    {
    static char errStr[10];

    snprintf (errStr, sizeof errStr, "%d", err);
    return errStr;
    }

/*******************************************************************************
*
* iperf3Exit - go back to abort point set in iperf3_entry()
*
* This routine aborts back into iperf3_entry()
*
* RETURNS: N/A
*
* ERRNO: N/A
*/

void iperf3Exit
    (
    int code
    )
    {
    longjmp (iperfAbortJmpBuf, code);
    }

/*******************************************************************************
*
* iperf3Unlink - dummy file unlink
*
* This routine is a stub for unlink
*
* RETURNS: Always 0
*
* ERRNO: N/A
*/

int iperf3Unlink
    (
    const char *path
    )
    {
    return 0;
    }

/*******************************************************************************
*
* iperf3Ftruncate - dummy file truncate
*
* This routine is a stub for ftruncate
*
* RETURNS: Always 0
*
* ERRNO: N/A
*/

int iperf3Ftruncate
    (
    int fd,
    off_t length
    )
    {
    return 0;
    }

/*******************************************************************************
*
* iperf3Mmap - allocates memory
*
* This routine allocates a chunk of memory, close enough for an anonymous
* mmap() for iperf3 to work.
*
* RETURNS: a chunk of memory
*
* ERRNO: N/A
*/

void * iperf3Mmap
    (
    void *addr,
    size_t length,
    int prot,
    int flags,
    int fd,
    off_t offset
    )
    {
    if (fd != DUMMY_FD)
        {
        fprintf (stderr, "unexpected FD passed to mmap in iperf3\n");
        iperf3Exit (1);
        }

    return calloc (1, length);
    }

/*******************************************************************************
*
* iperf3Munmap - free memory allocated by iperf3_mmap()
*
* This routine free memory allocated by iperf3_mmap()
*
* RETURNS: Always 0
*
* ERRNO: N/A
*/

int iperf3Munmap
    (
    void * addr,
    size_t length
    )
    {
    free (addr);
    return 0;
    }

/*******************************************************************************
*
* iperf3Fcntl - set non-blocking status of a socket
*
* Set non-blocking status of a socket
*
* RETURNS: 0 if successful, -1 otherwise
*
* ERRNO: N/A
*/

int iperf3Fcntl
    (
    int fd,
    int cmd,
    ...
    )
    {
    int nonblocking;
    va_list valist;

    if (cmd == F_GETFL)
        {
        return 0;
        }

    va_start (valist, cmd);
    nonblocking = va_arg (valist, int);
    va_end (valist);

    nonblocking = !!(nonblocking & O_NONBLOCK);
    return ioctl (fd, FIONBIO, &nonblocking);
    }

/*******************************************************************************
*
* daemon - run this thread in the background
*
* Turn calling thread into a deamon
*
* RETURNS: Always 0
*
* ERRNO: N/A
*/

int daemon
    (
    int nochrdir,
    int noclose
    )
    {
    fprintf (stderr, "Iperf daemon is not supported, do 'sp iperf3,\"ARGS\"' to mimic that\n");
    iperf3Exit (1);
    return 0;
    }

/*******************************************************************************
*
* iperf3Entry - create an abort point and call iperf3
*
* This routine create an abort point and call iperf3
*
* RETURNS: 0 if success, error code otherwise
*
* ERRNO: N/A
*/

int iperf3Entry (int argc, char * argv[])
    {
    int ret = setjmp (iperfAbortJmpBuf);

    if (ret != 0)
        {
        return ret;
        }

    optind = 1;
    return iperf3Main (argc, argv);
    }

/*******************************************************************************
*
* iperf3 - C-interpreter entrypoit for iperf3
*
* TCP and UDP bandwidth benchmark
*
* RETURNS: 0 if successful, or -1 otherwise
*
* ERRNO: N/A
*/

int iperf3(const char * args)
    {
    int    argc = 0;
    char * argv[20];
    char * saveptr;
    char * arg;
    char * args_cpy;
    int    ret;

    if (args == NULL)
        {
        args_cpy = strdup ("-h");
        }
    else
        {
        args_cpy = strdup (args);
        }

    if (args_cpy == NULL)
        {
        return -1;
        }

    argv[argc++] = "iperf3";
    for (arg = strtok_r (args_cpy, " ", &saveptr);
         arg != NULL;
         arg = strtok_r (NULL, " ", &saveptr))
        {
        argv[argc++] = arg;
        }
    argv[argc] = NULL;

    ret = iperf3Entry (argc, argv);
    free (args_cpy);

    return ret;
    }
