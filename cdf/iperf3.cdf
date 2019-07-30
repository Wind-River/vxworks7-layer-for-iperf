/* iperf3.cdf - iperf3 network benchmark tool configuration file */

/*
Copyright (c) 2016, 2019 Wind River Systems, Inc.

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
29jul19,chm  update to iperf version to 3.7
30aut16,kjn  created
*/

Component INCLUDE_IPERF3 {
        NAME            iperf3 network benchmark tool
        SYNOPSIS        iperf3 is a TCP, UDP, and SCTP network bandwidth measurement tool
        MODULES         vxiperf3.o
        LINK_SYMS       iperf3
        REQUIRES        INCLUDE_SOCKLIB INCLUDE_GETOPT INCLUDE_RTP INCLUDE_DEV_URANDOM
        _CHILDREN       FOLDER_NETWORK
}

Component INCLUDE_IPERF3_CMD {
        NAME            iperf3 network benchmark tool shell command
        SYNOPSIS        iperf3 is a TCP, UDP, and SCTP network bandwidth measurement tool
        CONFIGLETTES    usrIperf3.c
        INIT_RTN        usrIperf3CmdInit ();
        PROTOTYPE       IMPORT void usrIperf3CmdInit (void);
        _INIT_ORDER     usrShellCmdInit
        REQUIRES        INCLUDE_SOCKLIB INCLUDE_GETOPT INCLUDE_SHELL_INTERP_CMD INCLUDE_DEV_URANDOM
        _CHILDREN       FOLDER_NETWORK
}
