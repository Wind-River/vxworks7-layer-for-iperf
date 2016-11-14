/* getopt.h - minimal getopt library header file */

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
