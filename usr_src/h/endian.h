/* endian.h - minimal endian library header file for iperf3 on VxWorks */

/*
Copyright (c) 2016, Wind River Systems, Inc.

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
