/* bootLib.h - boot support subroutine library */

/*
 * Copyright (c) 1990-1992,1996-1997,2002-2003,2007, 2009, 2012, 2014-2016
 * Wind River Systems, Inc.
 *
 * The right to copy, distribute, modify or otherwise make use
 * of this software may be licensed only pursuant to the terms
 * of an applicable Wind River license agreement.
 */

/*
modification history
--------------------
18jul90,dnw  written
*/

#ifndef __INCbootLibh
#define __INCbootLibh

#include <vxWorks.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BOOT_DEV_LEN            40      /* max chars in device name */
#define BOOT_HOST_LEN           20      /* max chars in host name */

typedef struct                          /* BOOT_PARAMS */
    {
    char bootDev [BOOT_DEV_LEN];        /* boot device code */
    char hostName [BOOT_HOST_LEN];      /* name of host */
    char targetName [BOOT_HOST_LEN];    /* name of target */
    } BOOT_PARAMS;

/* function declarations */

_WRS_INLINE char *	bootStringToStruct
    (
    char * bootString,
    BOOT_PARAMS * pBootParams
    )
    {
    bzero ((char *) pBootParams, sizeof (*pBootParams));
    return NULL;
    }

#ifdef __cplusplus
}
#endif

#endif /* __INCbootLibh */

