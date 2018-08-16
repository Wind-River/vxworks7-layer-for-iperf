/* udp.h - udp header file */

/* Copyright 2001-2003, 2012, 2018 Wind River Systems, Inc. */

/*
 * Copyright (c) 1982, 1986, 1993
 *  The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *  This product includes software developed by the University of
 *  California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *  @(#)udp.h   8.1 (Berkeley) 6/10/93
 * $FreeBSD: src/sys/netinet/udp.h,v 1.7 1999/08/28 00:49:34 peter Exp $
 */

/*
modification history
--------------------
31jul18,chm  move udp.h from COREIP to NET_BASE (V7NET-1658)
09jan12,h_x  Move extern "C" after last header file include.
20nov03,niq  Remove copyright_wrs.h file inclusion
05nov03,cdw  Removal of unnecessary _KERNEL guards.
04nov03,rlm  Ran batch header path update for header re-org.
03nov03,rlm  Removed wrn/coreip/ prefix from #includes for header re-org.
10jun03,vvv  include netVersion.h
10sep02,hsh  add c++ protection
24aug01,hsh  Created from BSD 4.3
*/


#ifndef _NETINET_UDP_H_
#define _NETINET_UDP_H_


#ifdef __cplusplus
extern "C" {
#endif

/*
 * Udp protocol header.
 * Per RFC 768, September, 1981.
 */
struct udphdr {
    u_short uh_sport;       /* source port */
    u_short uh_dport;       /* destination port */
    u_short uh_ulen;        /* udp length */
    u_short uh_sum;         /* udp checksum */
};

/* UDPLite socket options, level IPPROTO_UDPLITE */
#define UDPLITE_SEND_CSCOV   10 /* Number of octets that must be
                                   covered by the checksum.
                                    0  = all octets
                                    8  = only header
                                   >8 = header plus part of
                                        payload */


#ifdef __cplusplus
}
#endif

#endif
