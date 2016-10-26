/* endian.h - minimal endian library header file for iperf3 on VxWorks */

/*
 * Copyright (C) 2016 Wind River Systems, Inc.
 *
 * The right to copy, distribute, modify, or otherwise make use
 * of this software may be licensed only pursuant to the terms
 * of an applicable Wind River license agreement.
 */

/*
modification history
--------------------
31aug16,kjn  written
*/

#ifndef __INCendianh
#define __INCendianh

/* includes */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* defines */

#ifndef BYTE_ORDER
# if _BYTE_ORDER == _LITTLE_ENDIAN
#  define BYTE_ORDER LITTLE_ENDIAN
# elif _BYTE_ORDER == _BIG_ENDIAN
#  define BYTE_ORDER BIG_ENDIAN
# else
#  error "don't know byte order"
# endif
#endif

/* typedefs */

/* function declarations */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __INCendianh */
