/* usrIperf3.c - iperf3 configlette */

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
