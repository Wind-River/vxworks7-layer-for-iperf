/* iperf3.cdf - iperf3 network benchmark tool configuration file */

/* Copyright 2016 Wind River Systems, Inc. */

/*
modification history
--------------------
30aut16,kjn  created
*/

Component INCLUDE_IPERF3 {
        NAME            iperf3 network benchmark tool
        SYNOPSIS        iperf3 is a TCP, UDP, and SCTP network bandwidth measurement tool
        MODULES         vxiperf3.o
        LINK_SYMS       iperf3
        REQUIRES        INCLUDE_SOCKLIB INCLUDE_GETOPT INCLUDE_GETADDRINFO INCLUDE_RTP
        _CHILDREN       FOLDER_NET_L5_APPLICATIONS
}

Component INCLUDE_IPERF3_CMD {
        NAME            iperf3 network benchmark tool shell command
        SYNOPSIS        iperf3 is a TCP, UDP, and SCTP network bandwidth measurement tool
        CONFIGLETTES    usrIperf3.c
        INIT_RTN        usrIperf3CmdInit ();
        PROTOTYPE       IMPORT void usrIperf3CmdInit (void);
        _INIT_ORDER     usrShellCmdInit
        REQUIRES        INCLUDE_SOCKLIB INCLUDE_GETOPT INCLUDE_SHELL_INTERP_CMD
        _CHILDREN       FOLDER_NET_L5_APPLICATIONS
}
