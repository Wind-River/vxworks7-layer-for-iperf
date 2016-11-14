/* iperf3.c - VxWorks iperf3 entry point */

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
