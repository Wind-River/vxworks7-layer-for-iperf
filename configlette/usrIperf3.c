/* usrIperf3.c - iperf3 configlette */

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
01sep16,kjn  written
*/

/*
DESCRIPTION
This module is the configlette for the iperf3 shell command.

INCLUDE FILES: N/A
*/

/* includes */

#include <shellInterpCmdLib.h>
#include <stdlib.h>
#include <string.h>
#include <taskLib.h>

/* defines */

#define SHELL_CMD_TOPIC "network"
#define IPERF3_CMD_PRIO 100

/* typedefs */

/* globals */

/* locals */

/* forward declarations */

int iperf3Entry (int argc, char * argv[]);

/*******************************************************************************
*
* iperf3Cmd - entry point for iperf shell command
*
* This routine is the iperf3 shell command entry point
*
* RETURNS: 0 if successful, or an error code otherwise
*
* ERRNO: N/A
*/

int iperf3Cmd
    (
    int argc,
    char * argv[]
    )
    {
    int prio;
    int ret = -1;

    if (taskPriorityGet (0, &prio) == OK)
        {
        (void)taskPrioritySet (0, IPERF3_CMD_PRIO);
        ret = iperf3Entry (argc, argv);
        (void)taskPrioritySet (0, prio);
        }

    return ret;
    }

/*******************************************************************************
*
* usrIperf3CmdInit - register iperf3 shell command
*
* This routine register the iperf3 shell command
*
* RETURNS: N/A
*
* ERRNO: N/A
*/

void usrIperf3CmdInit (void)
    {
    static SHELL_CMD cmd;

    memset (&cmd, 0, sizeof cmd);
    cmd.name = "iperf3";
    cmd.func = (FUNCPTR) iperf3Cmd;
    cmd.shortDesc = "Network benchmark tool.";
    cmd.fullDesc = "A tool for performing TCP and UDP network throughput measurements.";
    cmd.synopsis = "iperf3 [-s -B LOCAL_IPADDR | -c REMOTE_IPADDR]";

    (void)shellCmdTopicAdd (SHELL_CMD_TOPIC,
                            "List of the shell commands related to networking");
    (void)shellCmdAdd (SHELL_CMD_TOPIC, &cmd);
    }
