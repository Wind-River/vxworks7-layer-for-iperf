/* iperf3.c - VxWorks iperf3 entry point */

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
10sep16,chm  written
*/

/*
DESCRIPTION
This module is an example of the Wind River Systems C coding convetions.
...
INCLUDE FILES: [N/A]
*/

/* includes */

#include <string.h>
#include <stdlib.h>

/* defines */

/* typedefs */

/* globals */

int iperf3Entry (int argc, char * argv[]);

/* locals */

/* forward declarations */

/*******************************************************************************
*
* main - C-interpreter entrypoit for iperf3
*
* TCP and UDP bandwidth benchmark
*
* RETURNS: 0 if successful, or -1 otherwise
*
* ERRNO: N/A
*/

int main
    (
    int	   argc,	/** number of arguments */
    char * argv[]	/** array of arguments */
    )
    {
	int    ret;

    ret = iperf3Entry (argc, argv);

    return ret;
    }
