VxWorks® 7 Recipe Layer for iPerf3
===
---

#Overview

iPerf3 is a tool for active measurements of the maximum achievable 
bandwidth on IP networks. It supports tuning of various parameters 
related to timing, buffers and protocols (TCP, UDP, SCTP with IPv4 
and IPv6). For each test it reports the bandwidth, loss, and other 
parameters. 

This layer is an adapter to make standard iPerf3 build and run on
VxWorks. This layer does not contain the iPerf3 source, it only
contains all functions required to allow iPerf3 to build and execute
on top of VxWorks. Use this layer to add the iPerf3 library to your 
kernel or user space, and to build the iPerf3 utility as an RTP.

NOTE: iPerf3 is not part of any VxWorks® product. If you need help, 
use the resources available or contact your Wind River sales representative 
to arrange for consulting services.

#Project License

The source code for this project is provided under the BSD-3-Clause license license. 
Text for the iPerf and other applicable license notices can be found in 
the LICENSE_NOTICES.txt file in the project top level directory. Different 
files may be under different licenses. Each source file should include a 
license notice that designates the licensing terms for the respective file.

#Prerequisite(s)

* Install the Wind River® VxWorks® 7 operating system. And ensure the ***Unix 
  Compatibility layer*** was supported in your release. The layer support for 
  porting third party code to VxWorks.

* Ensure the iPerf3 for C source code is available from the following location:

    https://downloads.es.net/pub/iperf/iperf-$(PKG_VER).tar.gz

* You must have **patch** installed in addition to the regular build support 
  for VxWorks. 

#Building and Using

###Setup

Checkout feature of GitHub to place the contents of this repository 
in your VxWorks® install tree at an appropriate location, for example:

***installDir***/vxworks-7/pkgs/net/app

###VSB

The name of this layer is *IPERF3*. The layer is not included by
default in VSBs, it must be manually added. One example of how to do
this using the *vxprj* command line tool is:

    $ cd VSB_DIR
    $ vxprj vsb add IPERF3
    $ make
    
During the build, the the iPerf3 source is downloaded and placed in the 
VSB directory:

***VSB_DIR***/3pp/IPERF3/iperf-*version*

The source is patched for VxWorks and the RTP and libraries are built 
and placed in the standard locations in the VSB directory tree.

###VIP

Adding *IPERF3* to the VSB will build the *iperf3* library. The library 
is not automatically added to VIP. There are two VIP components for iperf3.

####C-interpreter

The iPerf3 command is made available to the VxWorks C-interpreter via
the *INCLUDE_IPER3* VIP component. It can be added like this

    $ cd VIP_DIR
    $ vxprj component add INCLUDE_IPERF3
    $ make

The iPerf3 command can now be invoked from the VxWorks C-interpreter
like this (no argument will show the help page)

    -> iperf3

It might be convinient to run the iperf3 server in the background, it
can be done with the VxWorks *sp* command (spawn). Spawning an iPerf3
server in the background on all local IPv4 addresses is done like this:

    -> sp iperf3,"-s -B 0.0.0.0"
	
With IPv6 address is done like this:

    -> sp iperf3,"-s -B ::0 -6"
	
or

    -> sp iperf3,"-s -B 2001:db8:21:111:0:0:0:1 -6" 

with a specific Gloable Unicast address	

or

    -> sp iperf3,"-s -B fe80::787a:c0ff:fea8:c878%simnet0 -6" 

with a specific Link Local address	

####Command line shell

The iPerf3 command can also be made available through the VxWorks
command line shell by including the VIP component INCLUDE_IPERF3_CMD

    $ cd VIP_DIR
    $ vxprj component add INCLUDE_IPERF3_CMD
    $ make

The command is added under the "network" topic in the shell and iPerf3
can be run as a client like this

    [vxWorks *]# iperf3 -c 192.168.200.254 -t3
    Connecting to host 192.168.200.254, port 5201
    [  8] local 192.168.200.10 port 58786 connected to 192.168.200.254
    port 5201
    [ ID] Interval           Transfer     Bandwidth
    [  8]   0.00-1.00   sec  20.1 MBytes   169 Mbits/sec
    [  8]   1.00-2.00   sec  20.2 MBytes   169 Mbits/sec
    [  8]   2.00-3.00   sec  20.1 MBytes   169 Mbits/sec
    - - - - - - - - - - - - - - - - - - - - - - - - -
    [ ID] Interval           Transfer     Bandwidth
    [  8]   0.00-3.00   sec  60.4 MBytes   169 Mbits/sec
    sender
    [  8]   0.00-3.00   sec  60.4 MBytes   169 Mbits/sec
    receiver

    iperf Done.
    [vxWorks *]#
	
For IPv6 Link Local address do like this

    [vxWorks *]# iperf3 -c fe80::787a:c0ff:fea8:c878%simnet0 -6
    Connecting to host fe80::787a:c0ff:fea8:c878%simnet0, port 5201
    [  9] local fe80::787a:c0ff:fea8:c882 port 53997 connected to fe80::787a:c0ff:fea8:c878 port 5201
    [ ID] Interval           Transfer     Bandwidth
    [  9]   0.00-1.00   sec  25.4 MBytes   213 Mbits/sec                  
    [  9]   1.00-2.00   sec  27.7 MBytes   233 Mbits/sec                  
    [  9]   2.00-3.00   sec  26.4 MBytes   222 Mbits/sec                  
    [  9]   3.00-4.00   sec  24.8 MBytes   208 Mbits/sec                  
    [  9]   4.00-5.00   sec  27.3 MBytes   229 Mbits/sec                  
    [  9]   5.00-6.00   sec  27.0 MBytes   226 Mbits/sec                  
    [  9]   6.00-7.00   sec  25.7 MBytes   216 Mbits/sec                  
    [  9]   7.00-8.00   sec  22.0 MBytes   185 Mbits/sec                  
    [  9]   8.00-9.00   sec  19.9 MBytes   167 Mbits/sec                  
    [  9]   9.00-10.00  sec  20.3 MBytes   171 Mbits/sec                  
    - - - - - - - - - - - - - - - - - - - - - - - - -
    [ ID] Interval           Transfer     Bandwidth
    [  9]   0.00-10.00  sec   247 MBytes   207 Mbits/sec                  sender
    [  9]   0.00-10.00  sec   247 MBytes   207 Mbits/sec                  receiver

iperf Done.
[vxWorks *]# 

For IPv6 Gloable Unicast address do like this

    [vxWorks *]# iperf3 -c 2001:db8:21:111:0:0:0:1 -6	

#Legal Notices

All product names, logos, and brands are property of their respective owners. All company, 
product and service names used in this software are for identification purposes only. 
Wind River and VxWorks are registered trademarks of Wind River Systems, Inc. UNIX is a 
registered trademark of The Open Group.

Disclaimer of Warranty / No Support: Wind River does not provide support 
and maintenance services for this software, under Wind River’s standard 
Software Support and Maintenance Agreement or otherwise. Unless required 
by applicable law, Wind River provides the software (and each contributor 
provides its contribution) on an “AS IS” BASIS, WITHOUT WARRANTIES OF ANY 
KIND, either express or implied, including, without limitation, any warranties 
of TITLE, NONINFRINGEMENT, MERCHANTABILITY, or FITNESS FOR A PARTICULAR 
PURPOSE. You are solely responsible for determining the appropriateness of 
using or redistributing the software and assume any risks associated with 
your exercise of permissions under the license.
