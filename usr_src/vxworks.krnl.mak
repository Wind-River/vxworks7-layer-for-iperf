#  vxworks.krnl.mak - for iperf3
#
#Copyright (c) 2016, 2019 Wind River Systems, Inc.
#
#Redistribution and use in source and binary forms, with or without modification, are
#permitted provided that the following conditions are met:
#
#1) Redistributions of source code must retain the above copyright notice, this list of 
#conditions and the following disclaimer.
#2) Redistributions in binary form must reproduce the above copyright notice, this list 
#of conditions and the following disclaimer in the documentation and/or other materials 
#provided with the distribution.
#3) Neither the name of Wind River Systems nor the names of its contributors may be
#used to endorse or promote products derived from this software without specific
#prior written permission.
#
#THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"AND ANY EXPRESS 
#OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THEIMPLIED WARRANTIES OF MERCHANTABILITY
#AND FITNESS FOR A PARTICULAR PURPOSEARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
#CONTRIBUTORS BELIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
#DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS ORSERVICES; LOSS OF USE, 
#DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVERCAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
#IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
#OF THEUSE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
#  modification history
#  --------------------
#  29jul19,chm  update to iperf version to 3.7
#  06Oct16,chm  written
#

LIB_BASE_NAME = iperf3

include $(WIND_KRNL_MK)/defs.library.mk

# iperf assume C99
ifeq ($(TOOL_FAMILY), diab)
CC_OPTIM += -Xdialect-c99
endif

ifeq ($(TOOL_FAMILY), gnu)
CC_OPTIM += -std=c99
endif

ifeq ($(TOOL_FAMILY), icc)
CC_OPTIM += -std=c99
endif

EXTRA_INCLUDE += -Ih
EXTRA_DEFINE += -Dversion=iperfVersion
EXTRA_DEFINE += -Dmain=iperf3Main
EXTRA_DEFINE += -Dexit=iperf3Exit
EXTRA_DEFINE += -Dunlink=iperf3Unlink
EXTRA_DEFINE += -Dftruncate=iperf3Ftruncate
EXTRA_DEFINE += -Dmmap=iperf3Mmap
EXTRA_DEFINE += -Dmunmap=iperf3Munmap
EXTRA_DEFINE += -Dfcntl=iperf3Fcntl

OBJS = vxiperf3.o  \
       cjson.o  \
       iperf_api.o  \
       iperf_client_api.o  \
       iperf_error.o  \
       iperf_locale.o  \
       iperf_sctp.o  \
       iperf_server_api.o  \
       iperf_tcp.o  \
       iperf_udp.o  \
       iperf_util.o  \
       main.o  \
       net.o  \
       tcp_info.o  \
       timer.o  \
       units.o  \
       dscp.o  \
       iperf_time.o  \
       t_api.o  	   
	   
include $(WIND_KRNL_MK)/rules.library.mk

#
# this code is 3rd party.  Suppress all compiler warnings
#
CC_WARNINGS = $(CC_WARNINGS_NONE)
