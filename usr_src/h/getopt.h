/* getopt.h - minimal getopt library header file */

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

#ifndef __INCgetopth
#define __INCgetopth

/* includes */

#include <unistd.h>

#include "wrappers.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* defines */

#define no_argument		0	/* option does not take an argument */
#define required_argument	1	/* option requires an argument */
#define optional_argument	2	/* option takes an optional argument */

/* typedefs */

struct option
    {
    const char * name;	/* name of long option */
    int has_arg;	/* one of no_argument, required_argument or */
                        /* optional_argument */
    int * flag;		/* if NULL, then getopt_long returns 'val'. Else set */
                        /* to point to a variable holding the argument value */
    int val;		/* value to return from getopt_long() or store into */
                        /* '*flag' if not NULL */
    };

/* function declarations */

/*******************************************************************************
*
* getopt_long - wrapper that just ignores the long options
*
* Wrapper to get iperf to build without long options
*
* RETURNS: same as getopt ()
*
* ERRNO: N/A
*/

_WRS_INLINE int getopt_long
    (
    int 		argc,
    char * const 	argv[],
    const char * 	optstring,
    const struct option * longopts,
    int * 		longindex
    )
    {
    return getopt (argc, argv, optstring);
    }

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __INCgetopth */
