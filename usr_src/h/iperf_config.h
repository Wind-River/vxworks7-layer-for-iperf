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

/* src/iperf_config.h.  Generated from iperf_config.h.in by configure.  */
/* src/iperf_config.h.in.  Generated from configure.ac by autoheader.  */

/* Define to 1 if you have the `cpuset_setaffinity' function. */
/* #undef HAVE_CPUSET_SETAFFINITY */

/* Have CPU affinity support. */
/* #undef HAVE_CPU_AFFINITY */

/* Define to 1 if you have the <dlfcn.h> header file. */
/* #undef HAVE_DLFCN_H */

/* Have IPv6 flowlabel support. */
#define HAVE_FLOWLABEL 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the <memory.h> header file. */
/* #undef HAVE_MEMORY_H */

/* Define to 1 if you have the <netinet/sctp.h> header file. */
/* #undef HAVE_NETINET_SCTP_H */

/* Define to 1 if you have the `sched_setaffinity' function. */
/* #undef HAVE_SCHED_SETAFFINITY */

/* Have SCTP support. */
/* #undef HAVE_SCTP */

/* Define to 1 if you have the `sendfile' function. */
/* #undef HAVE_SENDFILE */

/* Have SO_MAX_PACING_RATE sockopt. */
/* #undef HAVE_SO_MAX_PACING_RATE */

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
/* #undef HAVE_STRINGS_H */

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if the system has the type `struct sctp_assoc_value'. */
/* #undef HAVE_STRUCT_SCTP_ASSOC_VALUE */

/* Define to 1 if you have the <sys/socket.h> header file. */
#define HAVE_SYS_SOCKET_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Have TCP_CONGESTION sockopt. */
/* #undef HAVE_TCP_CONGESTION */

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#define LT_OBJDIR ".libs/"

/* Name of package */
#define PACKAGE "iperf"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "https://github.com/esnet/iperf"

/* Define to the full name of this package. */
#define PACKAGE_NAME "iperf"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "iperf 3.1"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "iperf"

/* Define to the home page for this package. */
#define PACKAGE_URL "http://software.es.net/iperf/"

/* Define to the version of this package. */
#define PACKAGE_VERSION "3.1"

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Version number of package */
#define VERSION "3.1"

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

#include <sockLib.h>
extern int h_errno;
const char *hstrerror(int err);


#define FP_ZERO		0
#define FP_NORMAL	1
#define fpclassify(__x) ((__x) == 0 ? FP_ZERO : FP_NORMAL)
#define isnormal(__x)   1
