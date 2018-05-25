#  vxworks.mak - for iperf3
#
#Copyright (c) 2016-2017, Wind River Systems, Inc.
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
# modification history
# -------------------- 
# 28sep17,chm  fix an build error when RTNET_RTP is not added
# 25sep17,chm  added llvm support
# 06oct16,chm  licensed
#

include $(WIND_USR_MK)/defs.vsbvars.mk

RTP_BASE_DIR = iperf3

EXE= iperf3.vxe

OBJS = iperf3.o

# Add user space network libraries

ADDED_LIBS += -liperf3 -lnet

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
ifeq ($(TOOL),llvm)
LD_EXEC_FLAGS += -u rtnetStackEnable
else
LD_EXEC_FLAGS += -Wl,-urtnetStackEnable
endif
endif

#
# this code is 3rd party.  Suppress all compiler warnings
#
CC_WARNINGS = $(CC_WARNINGS_NONE)
