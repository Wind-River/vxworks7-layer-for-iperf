# Makefile - iperf3 kernel layer makefile
#
# Copyright 2016 Wind River Systems, Inc.
#
# The right to copy, distribute, modify or otherwise make use
# of this software may be licensed only pursuant to the terms
# of an applicable Wind River license agreement.
#
# modification history
# --------------------
# 30aug16,kjn  created
#

PRE_BUILD_DIRS = usr_src
BUILD_DIRS = usr_src
POSTBUILD_USRLIB_DIRS = usr_src
POSTBUILD_RTP_DIRS = usr_src

POST_NOBUILD_CDFDIRS = cdf
POST_NOBUILD_CFGDIRS = configlette

include $(WIND_KRNL_MK)/rules.layers.mk
