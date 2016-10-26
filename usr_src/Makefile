# Makefile for iperf3 apps
#
# Copyright (c) 2013,2016 Wind River Systems, Inc.
#
#  This file is released under the terms of the license contained
#  in the accompanying file  LICENSE_NOTICES.txt
#
# modification history
# -------------------- 
# 06oct16,chm  licensed
#

include $(WIND_KRNL_MK)/defs.ver.mk

PKG_URL = https://iperf.fr/download/source/iperf-$(PKG_VER)-source.tar.gz
PKG_NAME = iperf-$(PKG_VER)-source.tar.gz
PKG_FILE_TYPE = unpack

PKG_BUILD_DIR = iperf-$(PKG_VER)/src

PKG_EXTRA_SRC = vxiperf3.c  \
                iperf3.c  \
                h
				
include $(WIND_KRNL_MK)/defs.unix.ports.mk

ifeq "$(BUILDSTAGE)" "POSTBUILD"
PKG_BUILD_TARGETS := iperf3
else
PKG_BUILD_TARGETS := libiperf3
endif 

include $(WIND_KRNL_MK)/rules.unix.ports.mk


