#ifndef __CC_H__
#define __CC_H__

#include "stdio.h"

//#include "main.h"

#define LWIP_NO_STDINT_H 1

typedef unsigned   char    u8_t;
typedef signed     char    s8_t;
typedef unsigned   short   u16_t;
typedef signed     short   s16_t;
typedef unsigned   long    u32_t;
typedef signed     long    s32_t;
typedef u32_t mem_ptr_t;
typedef int sys_prot_t;


#define U16_F "hu"
#define S16_F "d"
#define X16_F "hx"
#define U32_F "u"
#define S32_F "d"
#define X32_F "x"
#define SZT_F "uz" 



/* 选择小端模式 */
#define BYTE_ORDER LITTLE_ENDIAN

/* define compiler specific symbols */
#if defined (__ICCARM__)

#define PACK_STRUCT_BEGIN
#define PACK_STRUCT_STRUCT 
#define PACK_STRUCT_END
#define PACK_STRUCT_FIELD(x) x
#define PACK_STRUCT_USE_INCLUDES

#elif defined (__CC_ARM)

#define PACK_STRUCT_BEGIN __packed
#define PACK_STRUCT_STRUCT 
#define PACK_STRUCT_END
#define PACK_STRUCT_FIELD(x) x

#elif defined (__GNUC__)

#define PACK_STRUCT_BEGIN
#define PACK_STRUCT_STRUCT __attribute__ ((__packed__))
#define PACK_STRUCT_END
#define PACK_STRUCT_FIELD(x) x

#elif defined (__TASKING__)

#define PACK_STRUCT_BEGIN
#define PACK_STRUCT_STRUCT
#define PACK_STRUCT_END
#define PACK_STRUCT_FIELD(x) x

#endif


#define LWIP_PLATFORM_ASSERT(x) do {printf(x);}while(0)

extern u32_t sys_now(void);

#endif /* __CC_H__ */
///*
// * Copyright (c) 2001-2003 Swedish Institute of Computer Science.
// * All rights reserved. 
// * 
// * Redistribution and use in source and binary forms, with or without modification, 
// * are permitted provided that the following conditions are met:
// *
// * 1. Redistributions of source code must retain the above copyright notice,
// *    this list of conditions and the following disclaimer.
// * 2. Redistributions in binary form must reproduce the above copyright notice,
// *    this list of conditions and the following disclaimer in the documentation
// *    and/or other materials provided with the distribution.
// * 3. The name of the author may not be used to endorse or promote products
// *    derived from this software without specific prior written permission. 
// *
// * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED 
// * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
// * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT 
// * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
// * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT 
// * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
// * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
// * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
// * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
// * OF SUCH DAMAGE.
// *
// * This file is part of the lwIP TCP/IP stack.
// * 
// * Author: Adam Dunkels <adam@sics.se>
// *
// */
//#ifndef LWIP_ARCH_CC_H
//#define LWIP_ARCH_CC_H

///* see https://sourceforge.net/p/predef/wiki/OperatingSystems/ */
//#if defined __ANDROID__
//#define LWIP_UNIX_ANDROID
//#elif defined __linux__
//#define LWIP_UNIX_LINUX
//#elif defined __APPLE__
//#define LWIP_UNIX_MACH
//#elif defined __OpenBSD__
//#define LWIP_UNIX_OPENBSD
//#elif defined __CYGWIN__
//#define LWIP_UNIX_CYGWIN
//#elif defined __GNU__
//#define LWIP_UNIX_HURD
//#endif

//#define LWIP_TIMEVAL_PRIVATE 0
//#include <sys/time.h>

//#define LWIP_ERRNO_INCLUDE <errno.h>

//#if defined(LWIP_UNIX_LINUX) || defined(LWIP_UNIX_HURD)
//#define LWIP_ERRNO_STDINCLUDE	1
//#endif

//#define LWIP_RAND() ((u32_t)rand())

///* different handling for unit test, normally not needed */
//#ifdef LWIP_NOASSERT_ON_ERROR
//#define LWIP_ERROR(message, expression, handler) do { if (!(expression)) { \
//  handler;}} while(0)
//#endif

//#if defined(LWIP_UNIX_ANDROID) && defined(FD_SET)
//typedef __kernel_fd_set fd_set;
//#endif

//#if defined(LWIP_UNIX_MACH)
///* sys/types.h and signal.h bring in Darwin byte order macros. pull the
//   header here and disable LwIP's version so that apps still can get
//   the macros via LwIP headers and use system headers */
//#include <sys/types.h>
//#define LWIP_DONT_PROVIDE_BYTEORDER_FUNCTIONS
//#endif

//struct sio_status_s;
//typedef struct sio_status_s sio_status_t;
//#define sio_fd_t sio_status_t*
//#define __sio_fd_t_defined

//typedef unsigned int sys_prot_t;

//#endif /* LWIP_ARCH_CC_H */
