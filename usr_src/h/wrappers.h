/* wrappers.h - wrapper functions required to build iperf for VxWorks */

/*
Copyright (c) 2016, 2018 Wind River Systems, Inc.

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
23jul18,chm  fix V7TST-1125
27mar18,wjf  modify for conflict of gethostname (V7TST-1026)
31aug16,kjn  written
*/

#ifndef __INCwrappersh
#define __INCwrappersh

/* includes */

#include <bootLib.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sysLib.h>
#include <taskLib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "netdb.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* defines */

#define getpid 		(int)taskIdSelf

#define DUMMY_FD	99

extern int h_errno;

/* typedefs */

/* function declarations */

/*******************************************************************************
*
* srandom - seed pseudo-random number generator
*
* Wrapper function
*
* RETURNS: N/A
*/

_WRS_INLINE void srandom
    (
    unsigned int seed
    )
    {
    srand (seed);
    }

/*******************************************************************************
*
* random - generate pseudo-random number
*
* Wrapper function
*
* RETURNS: Pseudo random number
*
* ERRNO: N/A
*/

_WRS_INLINE long int random (void)
    {
    return rand();
    }

/*******************************************************************************
*
* mkstemp - create a temporary file
*
* Wrapper function
*
* RETURNS: file handle to temporary file, or -1 if error
*
* ERRNO: N/A
*/

_WRS_INLINE int mkstemp
    (
    char * template
    )
    {
    return DUMMY_FD;
    }

_WRS_INLINE int
is_integer(s)
    const char *s;
{
    if (*s == '-' || *s == '+')
	s++;
    if (*s < '0' || '9' < *s)
	return 0;

    s++;
    while ('0' <= *s && *s <= '9')
	s++;

    return (*s == '\0');
}

/*
 * Return 1 if the string `s' represents an IPv4 address.
 * Unlike inet_addr(), it doesn't permit malformed nortation such
 * as "192.168".
 */
_WRS_INLINE int
is_address(s)
    const char *s;
{
    const static char delimiters[] = {'.', '.', '.', '\0'};
    int i, j;
    int octet;

    for (i = 0; i < 4; i++) {
	if (*s == '0' && *(s + 1) != delimiters[i])
	    return 0;
	for (j = 0, octet = 0; '0' <= *s && *s <= '9' && j < 3; s++, j++)
	    octet = octet * 10 + (*s - '0');
	if (j == 0 || octet > 255 || *s != delimiters[i])
	    return 0;
	s++;
    }

    return 1;
}	
	
_WRS_INLINE struct hostent *gethostbyname(char *name)
	{
	struct hostent *host1;
	h_errno = 0;					/* we are always successful!!! */
	host1 = (struct hostent *) malloc (sizeof(struct hostent));
	host1->h_name = name;
	host1->h_addrtype = AF_INET;
	host1->h_aliases = name;
	host1->h_length = 4;
	host1->h_addr_list[0] = NULL;
	host1->h_addr_list[1] = NULL;
	return host1;
	}

_WRS_INLINE struct hostent *gethostbyaddr(char *name, int size, int addr_type)
	{
	struct hostent *host1;
	h_errno = 0;  /* we are always successful!!! */
	host1 = (struct hostent *) malloc (sizeof(struct hostent));
	host1->h_name = name;
	host1->h_addrtype = AF_INET;
	host1->h_aliases = name;
	host1->h_length = 4;
	host1->h_addr_list = NULL;
	return host1;
	}

_WRS_INLINE struct servent *getservbyname (char *name, char *type)
	{
	struct servent *serv1;
	serv1 = (struct servent *) malloc (sizeof(struct servent));
	serv1->s_name = "iperf";      /* official service name */
	serv1->s_aliases = NULL;	/* alias list */
	serv1->s_port = 123;		/* port # */
	serv1->s_proto = "udp";     /* protocol to use */
	return serv1;
	}	

_WRS_INLINE void freeaddrinfo(struct addrinfo *ai)
{
    struct addrinfo *next_ai;

    while (ai != NULL) {
	if (ai->ai_canonname != NULL)
	    free(ai->ai_canonname);
	if (ai->ai_addr != NULL)
	    free(ai->ai_addr);
	next_ai = ai->ai_next;
	free(ai);
	ai = next_ai;
    }
}
	
_WRS_INLINE int getaddrinfo(const char *nodename, const char *servname, const struct addrinfo *hints, struct addrinfo **res)
{
    struct addrinfo *new_res;
    struct sockaddr_in *sa_in;
    struct sockaddr_in6 *sa_in6;	
    struct in_addr addr;	
    struct in6_addr addr6;	
    int port;
    int saved_h_errno;
    int result = 0;
    const char *ifname = NULL;
	
    /*
     * Default hints for getaddrinfo().
     */
    static struct addrinfo default_hints = {
        0, PF_UNSPEC, 0, 0, 0, NULL, NULL, NULL
    };	
	
    saved_h_errno = h_errno = 0;

    if (nodename == NULL) {
	    result = EAI_NONAME;
	    goto end;
    }

    if (hints != NULL) {
	if (hints->ai_family != PF_INET && hints->ai_family != PF_INET6 && hints->ai_family != PF_UNSPEC) {
	    result = EAI_FAMILY;
	    goto end;
	}
	
	if (hints->ai_socktype != SOCK_DGRAM
	    && hints->ai_socktype != SOCK_STREAM
	    && hints->ai_socktype != 0) {
	    result = EAI_SOCKTYPE;
	    goto end;
	}
    } else {
	hints = &default_hints;
    }

    if (servname != NULL) {
	    if (is_integer(servname))
	        port = htons(atoi(servname));
    } else {
	    port = htons(0);
    }
    
	new_res = (struct addrinfo *)malloc(sizeof(struct addrinfo));
	if (new_res == NULL) {
	    result = EAI_MEMORY;
	    goto end;
	}  
	
	memset(new_res, 0, sizeof(struct addrinfo));
	
    if (hints->ai_family == AF_INET || hints->ai_family == AF_UNSPEC){
    	new_res->ai_family = AF_INET;
    }else {
    	new_res->ai_family = AF_INET6;	
    }

	new_res->ai_socktype = hints->ai_socktype;
	new_res->ai_protocol = hints->ai_protocol;
	new_res->ai_addr = malloc(sizeof(char)*28);
	if (new_res->ai_addr == NULL){
        free(new_res);
        result = EAI_MEMORY;
        goto end;		
	}		
	new_res->ai_addrlen = 28;
	new_res->ai_canonname = NULL;
	new_res->ai_next = NULL;    
    
    if (new_res->ai_family == AF_INET){
        if(inet_pton(AF_INET, nodename, (void *)&addr) != 1){
	        free(new_res->ai_addr); 
	        free(new_res);
    	    result = EAI_FAIL;
    	    goto end;
		}
	}

    if (new_res->ai_family == AF_INET6){
        if(inet_pton(AF_INET6, nodename, (void *)&addr6) != 1){
	        free(new_res->ai_addr);         	
	        free(new_res);        	
	        result = EAI_FAIL;
	        goto end;	
		}
	}
    
	if (new_res->ai_family == AF_INET){
	    sa_in = (struct sockaddr_in *)new_res->ai_addr;
	    sa_in->sin_family = AF_INET;
	    sa_in->sin_port = port;
	    memcpy(&sa_in->sin_addr, &addr, sizeof(struct in_addr));
		new_res->ai_addrlen = sizeof(struct sockaddr_in);		
	}

	if (new_res->ai_family == AF_INET6){	
	    sa_in6 = (struct sockaddr_in6 *)new_res->ai_addr;
	    sa_in6->sin6_family = AF_INET6;
	    sa_in6->sin6_port = port;
	    sa_in6->sin6_flowinfo = 0;
	    sa_in6->sin6_scope_id = 0;
	    memcpy(&sa_in6->sin6_addr, &addr6, sizeof(struct in6_addr));
		new_res->ai_addrlen = sizeof(struct sockaddr_in6);	
		
		ifname = strchr(nodename, '%');		
        if (ifname != NULL && *ifname++ != '\0'){
            char * endp = NULL;

            sa_in6->sin6_scope_id = if_nametoindex ((const char *) ifname);

            if (sa_in6->sin6_scope_id == 0 && isdigit (*ifname))
            	sa_in6->sin6_scope_id = strtoul (ifname, &endp, 0);

            if (sa_in6->sin6_scope_id == 0){
    	        free(new_res->ai_addr);         	
    	        free(new_res);        	
    	        result = EAI_FAIL;
    	        goto end;
            }
        }				
	}		

    *res = new_res;   

  end:
    h_errno = saved_h_errno;

    return result;
}
	
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __INCwrappersh */
