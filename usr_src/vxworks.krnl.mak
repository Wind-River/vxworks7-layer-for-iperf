#  vxworks.krnl.mak - for iperf3
#
# Copyright 2016, Wind River Systems, Inc.
#
#  This file is released under the terms of the license contained
#  in the accompanying file  LICENSE_NOTICES.txt
#
#  modification history
#  --------------------
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
	   tcp_window_size.o  \
	   timer.o  \
	   units.o
	   
include $(WIND_KRNL_MK)/rules.library.mk
