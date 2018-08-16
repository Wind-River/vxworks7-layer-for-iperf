/* netdb.h - server entries and the like for routed/rip */

/* Copyright 1996-2007, 2012-2014, 2018 Wind River Systems, Inc. */

/*-
 * Copyright (c) 1980, 1983, 1988, 1993
 *	The Regents of the University of California.  All rights reserved.
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
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
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
 *      @(#)netdb.h	8.1 (Berkeley) 6/2/93
 *      From: Id: netdb.h,v 8.9 1996/11/19 08:39:29 vixie Exp $
 * $FreeBSD: src/include/netdb.h,v 1.14.2.5 2001/08/29 08:46:51 alfred Exp $
 * -
 * Portions Copyright (c) 1993 by Digital Equipment Corporation.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies, and that
 * the name of Digital Equipment Corporation not be used in advertising or
 * publicity pertaining to distribution of the document or software without
 * specific, written prior permission.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND DIGITAL EQUIPMENT CORP. DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS.   IN NO EVENT SHALL DIGITAL EQUIPMENT
 * CORPORATION BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE.
 * -
 * --Copyright--
 */

/*
modification history
--------------------
12dec13,dlk  Change value of AI_NUMERICSERV to agree with IP_AI_NUMERICSERV.
09jan12,h_x  Move extern "C" after last header file include.
12feb07,dlk  Added prototypes for rtpGetaddrinfoInit() and
             rtpGetnameinfoInit().
05oct06,kch  Removed h_ttl member from struct hostent for IPNet
             compatibility.
06jul05,vvv  fixed build errors
29jun05,vvv  added getaddrinfo(), getnameinfo(), freeaddrinfo() and
             gai_strerror() for RFC3493
28jun05,vvv  restored v4mapped
13may05,vvv  merged from kame-20050404-freebsd411
20nov03,niq  Remove copyright_wrs.h file inclusion
05nov03,cdw  Removal of unnecessary _KERNEL guards.
04nov03,rlm  Ran batch header path update for header re-org.
03nov03,rlm  Removed wrn/coreip/ prefix from #includes for header re-org.
06aug03,nee  Accordion Base6 merge from ACCORDION_BASE6_MERGE_BASELINE
             label
10jun03,vvv  include netVersion.h
12dec01,hgo  add support of flag AI_V4MAPPED for getaddrinfo()
20sep01,hgo  extensions for IPv6 support
19aug97,jag  Added the field h_ttl to the structure hostent.
29apr97,jag  fixed include define and added C++ linkage.  Changed field
             names of struc netnet to avoid conflict with i960 macros.
24feb97,jag  changed comment.
26nov96,gnn  created from BSD4.4 routed
*/

#ifndef __INCnetdbh
#define __INCnetdbh

#include <sys/socket.h>    /* for socklen_t */

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Structures returned by network data base library.  All addresses are
 * supplied in host order, and returned in network order (suitable for
 * use in system calls).
 */
struct	hostent {
	char	*h_name;	/* official name of host */
	char	**h_aliases;	/* alias list */
	int	h_addrtype;	/* host address type */
	int	h_length;	/* length of address */
	char	**h_addr_list;	/* list of addresses from name server */
#define	h_addr	h_addr_list[0]	/* address, for backward compatiblity */
};

/*
 * Assumption here is that a network number
 * fits in an unsigned long -- probably a poor one.
 */
struct	netent {
	char	       *  nName;	/* official name of net */
	char	       ** nAliases;	/* alias list */
	int		  nAddrtype;	/* net address type */
	unsigned long	  nNet;		/* network # */
};

struct	servent {
	char	*s_name;	/* official service name */
	char	**s_aliases;	/* alias list */
	int	s_port;		/* port # */
	char	*s_proto;	/* protocol to use */
};

struct	protoent {
	char	*p_name;	/* official protocol name */
	char	**p_aliases;	/* alias list */
	int	p_proto;	/* protocol # */
};

struct addrinfo 
    {
    int     ai_flags;           /* AI_PASSIVE, AI_CANONNAME, AI_NUMERICHOST */
    int     ai_family;          /* PF_xxx */
    int     ai_socktype;        /* SOCK_xxx */
    int     ai_protocol;        /* 0 or IPPROTO_xxx for IPv4 and IPv6 */
    size_t  ai_addrlen;         /* length of ai_addr */
    char   *ai_canonname;       /* canonical name for hostname */
    struct sockaddr *ai_addr;   /* binary address */
    struct addrinfo *ai_next;   /* next structure in linked list */
    };

/*
 * Error return codes from getaddrinfo()
 */
/* #define	EAI_ADDRFAMILY	 1	(obsoleted) */
#define	EAI_AGAIN	 2	/* temporary failure in name resolution */
#define	EAI_BADFLAGS	 3	/* invalid value for ai_flags */
#define	EAI_FAIL	 4	/* non-recoverable failure in name resolution */
#define	EAI_FAMILY	 5	/* ai_family not supported */
#define	EAI_MEMORY	 6	/* memory allocation failure */
/* #define	EAI_NODATA	 7	(obsoleted) */
#define	EAI_NONAME	 8	/* hostname nor servname provided, or not known */
#define	EAI_SERVICE	 9	/* servname not supported for ai_socktype */
#define	EAI_SOCKTYPE	10	/* ai_socktype not supported */
#define	EAI_SYSTEM	11	/* system error returned in errno */
#define	EAI_BADHINTS	12	/* Invalid value for hints */
#define	EAI_PROTOCOL	13	/* Resolved protocol is unknown */
#define	EAI_OVERFLOW	14	/* Argument buffer overflow */
#define	EAI_MAX		15

/*
 * Flag values for getaddrinfo()
 */
#define AI_PASSIVE      0x00000001 /* get address to use bind() */
#define AI_CANONNAME    0x00000002 /* fill ai_canonname */
#define AI_NUMERICHOST  0x00000004 /* prevent name resolution */
#define AI_NUMERICSERV  0x00000008 /* prevent service resolution */
#define AI_ALL          0x00000100 /* IPv6 and IPv4-mapped (with AI_V4MAPPED) */
#define AI_V4MAPPED_CFG 0x00000200 /* accept IPv4-mapped if kernel supports */
#define AI_ADDRCONFIG   0x00000400 /* only if any address is assigned */
#define AI_V4MAPPED     0x00000800 /* accept IPv4-mapped IPv6 address */

/* valid flags for getaddrinfo (not a standard def, apps should not use it) */

#define AI_MASK \
    (AI_PASSIVE | AI_CANONNAME | AI_NUMERICHOST | AI_NUMERICSERV | \
     AI_ADDRCONFIG | AI_ALL | AI_V4MAPPED_CFG | AI_V4MAPPED)

/* special recommended flags for getipnodebyname */
#define	AI_DEFAULT	AI_V4MAPPED_CFG | AI_ADDRCONFIG

/*
 * Constants for getnameinfo()
 */
#define	NI_MAXHOST	1025
#define	NI_MAXSERV	32

/*
 * Flag values for getnameinfo()
 */
#define	NI_NOFQDN	0x00000001
#define	NI_NUMERICHOST	0x00000002
#define	NI_NAMEREQD	0x00000004
#define	NI_NUMERICSERV	0x00000008
#define	NI_DGRAM	0x00000010
#if 0 /* obsolete */
#define NI_WITHSCOPEID	0x00000020
#endif
#define NI_NUMERICSCOPE	0x00000040

/*
 * Scope delimit character
 */
#define	SCOPE_DELIMITER	'%'

/*
 * Error return codes from res_query.c
 */

#define	HOST_NOT_FOUND	1 /* Authoritative Answer Host not found */
#define	TRY_AGAIN	2 /* Non-Authoritive Host not found, or SERVERFAIL */
#define	NO_RECOVERY	3 /* Non recoverable errors, FORMERR, REFUSED, NOTIMP */
#define	NO_DATA		4 /* Valid name, no data record of requested type */
#define	NO_ADDRESS	NO_DATA		/* no address, look for MX record */

#ifdef __cplusplus
}
#endif

#endif /* __INCnetdbh */
