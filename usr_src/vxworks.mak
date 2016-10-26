#  vxworks.mak - for iperf3
#
# Copyright 2016 Wind River Systems, Inc.
#
#  This file is released under the terms of the license contained
#  in the accompanying file LICENSE_NOTICES.txt
#
# modification history
# -------------------- 
# 06oct16,chm  licensed
#

RTP_BASE_DIR = iperf3

EXE= iperf3.vxe

OBJS = iperf3.o

# Add user space network libraries
ADDED_LIBS += -liperf3

ifdef _WRS_CONFIG_RTNET_RTP
ADDED_LIBS += -lnet_base -ljson -lrtnet
endif

ifdef _WRS_CONFIG_VXBUS_USER
ADDED_LIBS += -lvxbus
endif

include $(WIND_USR_MK)/rules.rtp.mk

# Include the network stack. Undefining the rtnetStackEnable symbol
# will force pulling in the constructor when building the RTP.
ifdef _WRS_CONFIG_RTNET_RTP
LD_EXEC_FLAGS += -Wl,-urtnetStackEnable
endif
