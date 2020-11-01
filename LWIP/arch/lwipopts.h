
#ifndef __LWIPOPTS_H__
#define __LWIPOPTS_H__

#define SYS_LIGHTWEIGHT_PROT    0

//NO_SYS==1:不使用操作系统
#define NO_SYS                  1  //不使用UCOS操作系统

//使用4字节对齐模式
#define MEM_ALIGNMENT           4  

//MEM_SIZE:heap内存的大小,如果在应用中有大量数据发送的话这个值最好设置大一点 
#define MEM_SIZE                10*1024 //内存堆大小

//MEMP_NUM_PBUF:memp结构的pbuf数量,如果应用从ROM或者静态存储区发送大量数据时,这个值应该设置大一点
#define MEMP_NUM_PBUF           10

//MEMP_NUM_UDP_PCB:UDP协议控制块(PCB)数量.每个活动的UDP"连接"需要一个PCB.
#define MEMP_NUM_UDP_PCB        6

//MEMP_NUM_TCP_PCB:同时建立激活的TCP数量
#define MEMP_NUM_TCP_PCB        10

//MEMP_NUM_TCP_PCB_LISTEN:能够监听的TCP连接数量
#define MEMP_NUM_TCP_PCB_LISTEN 6

//MEMP_NUM_TCP_SEG:最多同时在队列中的TCP段数量
#define MEMP_NUM_TCP_SEG        20

//MEMP_NUM_SYS_TIMEOUT:能够同时激活的timeout个数
#define MEMP_NUM_SYS_TIMEOUT    5


/* ---------- Pbuf选项---------- */
//PBUF_POOL_SIZE:pbuf内存池个数. 
#define PBUF_POOL_SIZE          10

//PBUF_POOL_BUFSIZE:每个pbuf内存池大小. 
#define PBUF_POOL_BUFSIZE       1500


/* ---------- TCP选项---------- */
#define LWIP_TCP                1  //为1是使用TCP
#define TCP_TTL                 255//生存时间

/*当TCP的数据段超出队列时的控制位,当设备的内存过小的时候此项应为0*/
#define TCP_QUEUE_OOSEQ         0

//最大TCP分段
#define TCP_MSS                 (1500 - 40)	  //TCP_MSS = (MTU - IP报头大小 - TCP报头大小

//TCP发送缓冲区大小(bytes).
#define TCP_SND_BUF             (4*TCP_MSS)

//TCP_SND_QUEUELEN: TCP发送缓冲区大小(pbuf).这个值最小为(2 * TCP_SND_BUF/TCP_MSS) 
#define TCP_SND_QUEUELEN        (4* TCP_SND_BUF/TCP_MSS)

//TCP发送窗口
#define TCP_WND                 (2*TCP_MSS)


/* ---------- ICMP选项---------- */
#define LWIP_ICMP                 1 //使用ICMP协议

/* ---------- DHCP选项---------- */
//当使用DHCP时此位应该为1,LwIP 0.5.1版本中没有DHCP服务.
#define LWIP_DHCP               0

/* ---------- UDP选项 ---------- */ 
#define LWIP_UDP                1 //使用UDP服务
#define UDP_TTL                 255 //UDP数据包生存时间


/* ---------- Statistics options ---------- */
#define LWIP_STATS 0
#define LWIP_PROVIDE_ERRNO 1


/*
   ----------------------------------------------
   ---------- SequentialAPI选项----------
   ----------------------------------------------
*/

//LWIP_NETCONN==1:使能NETCON函数(要求使用api_lib.c)
#define LWIP_NETCONN                    0

/*
   ------------------------------------
   ---------- Socket API选项----------
   ------------------------------------
*/
//LWIP_SOCKET==1:使能Socket API(要求使用sockets.c)
#define LWIP_SOCKET                     0

#define LWIP_COMPAT_MUTEX               1

#define LWIP_SO_RCVTIMEO                1 //通过定义LWIP_SO_RCVTIMEO使能netconn结构体中recv_timeout,使用recv_timeout可以避免阻塞线程


/*
   ----------------------------------------
   ---------- Lwip调试选项----------
   ----------------------------------------
*/
//#define LWIP_DEBUG                     1 //开启DEBUG选项

#define ICMP_DEBUG                      LWIP_DBG_OFF //开启/关闭ICMPdebug

#endif /* __LWIPOPTS_H__ */


///**
//  ******************************************************************************
//  * @file    lwipopts.h
//  * @author  MCD Application Team
//  * @version V1.1.0
//  * @date    31-July-2013
//  * @brief   lwIP Options Configuration.
//  *          This file is based on Utilities\lwip_v1.4.1\src\include\lwip\opt.h 
//  *          and contains the lwIP configuration for the STM32F4x7 demonstration.
//  ******************************************************************************
//  * @attention
//  *
//  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
//  *
//  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
//  * You may not use this file except in compliance with the License.
//  * You may obtain a copy of the License at:
//  *
//  *        http://www.st.com/software_license_agreement_liberty_v2
//  *
//  * Unless required by applicable law or agreed to in writing, software 
//  * distributed under the License is distributed on an "AS IS" BASIS, 
//  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  * See the License for the specific language governing permissions and
//  * limitations under the License.
//  *
//  ******************************************************************************
//  */

//#ifndef __LWIPOPTS_H__
//#define __LWIPOPTS_H__

///**
// * SYS_LIGHTWEIGHT_PROT==1: if you want inter-task protection for certain
// * critical regions during buffer allocation, deallocation and memory
// * allocation and deallocation.
// */
//#define SYS_LIGHTWEIGHT_PROT    0

///**
// * NO_SYS==1: Provides VERY minimal functionality. Otherwise,
// * use lwIP facilities.
// */
//#define NO_SYS                  1

///**
// * NO_SYS_NO_TIMERS==1: Drop support for sys_timeout when NO_SYS==1
// * Mainly for compatibility to old versions.
// */
//#define NO_SYS_NO_TIMERS        0

///* ---------- Memory options ---------- */
///* MEM_ALIGNMENT: should be set to the alignment of the CPU for which
//   lwIP is compiled. 4 byte alignment -> define MEM_ALIGNMENT to 4, 2
//   byte alignment -> define MEM_ALIGNMENT to 2. */
//#define MEM_ALIGNMENT           4

///* MEM_SIZE: the size of the heap memory. If the application will send
//a lot of data that needs to be copied, this should be set high. */
//#define MEM_SIZE                (10*1024)

///* MEMP_NUM_PBUF: the number of memp struct pbufs. If the application
//   sends a lot of data out of ROM (or other static memory), this
//   should be set high. */
//#define MEMP_NUM_PBUF           50
///* MEMP_NUM_UDP_PCB: the number of UDP protocol control blocks. One
//   per active UDP "connection". */
//#define MEMP_NUM_UDP_PCB        6
///* MEMP_NUM_TCP_PCB: the number of simulatenously active TCP
//   connections. */
//#define MEMP_NUM_TCP_PCB        10
///* MEMP_NUM_TCP_PCB_LISTEN: the number of listening TCP
//   connections. */
//#define MEMP_NUM_TCP_PCB_LISTEN 6
///* MEMP_NUM_TCP_SEG: the number of simultaneously queued TCP
//   segments. */
//#define MEMP_NUM_TCP_SEG        12
///* MEMP_NUM_SYS_TIMEOUT: the number of simulateously active
//   timeouts. */
//#define MEMP_NUM_SYS_TIMEOUT    10


///* ---------- Pbuf options ---------- */
///* PBUF_POOL_SIZE: the number of buffers in the pbuf pool. */
//#define PBUF_POOL_SIZE          20
///* PBUF_POOL_BUFSIZE: the size of each pbuf in the pbuf pool. */
//#define PBUF_POOL_BUFSIZE       500//LWIP_MEM_ALIGN_SIZE(TCP_MSS+40+PBUF_LINK_ENCAPSULATION_HLEN+PBUF_LINK_HLEN)


///* ---------- TCP options ---------- */
//#define LWIP_TCP                1
//#define TCP_TTL                 255

///* Controls if TCP should queue segments that arrive out of
//   order. Define to 0 if your device is low on memory. */
//#define TCP_QUEUE_OOSEQ         0

///* TCP Maximum segment size. */
//#define TCP_MSS                 (1500 - 40)	  /* TCP_MSS = (Ethernet MTU - IP header size - TCP header size) */

///* TCP sender buffer space (bytes). */
//#define TCP_SND_BUF             (4*TCP_MSS)

///*  TCP_SND_QUEUELEN: TCP sender buffer space (pbufs). This must be at least
//  as much as (2 * TCP_SND_BUF/TCP_MSS) for things to work. */

//#define TCP_SND_QUEUELEN        (2 * TCP_SND_BUF/TCP_MSS)

///* TCP receive window. */
//#define TCP_WND                 (2*TCP_MSS)//16000//(12*TCP_MSS)


///* ---------- ICMP options ---------- */
//#define LWIP_ICMP                       1


///* ---------- DHCP options ---------- */
///* Define LWIP_DHCP to 1 if you want DHCP configuration of
//   interfaces. DHCP is not implemented in lwIP 0.5.1, however, so
//   turning this on does currently not work. */
//#define LWIP_DHCP               0


///* ---------- UDP options ---------- */
//#define LWIP_UDP                1
//#define UDP_TTL                 255


///* ---------- Statistics options ---------- */
//#define LWIP_STATS 0
//#define LWIP_PROVIDE_ERRNO 1

///* ---------- link callback options ---------- */
///* LWIP_NETIF_LINK_CALLBACK==1: Support a callback function from an interface
// * whenever the link changes (i.e., link down)
// */
//#define LWIP_NETIF_LINK_CALLBACK        0
///*
//   --------------------------------------
//   ---------- Checksum options ----------
//   --------------------------------------
//*/

///* 
//The STM32F4x7 allows computing and verifying the IP, UDP, TCP and ICMP checksums by hardware:
// - To use this feature let the following define uncommented.
// - To disable it and process by CPU comment the  the checksum.
//*/
//#define CHECKSUM_BY_HARDWARE 


//#ifdef CHECKSUM_BY_HARDWARE
//  /* CHECKSUM_GEN_IP==0: Generate checksums by hardware for outgoing IP packets.*/
//  #define CHECKSUM_GEN_IP                 0
//  /* CHECKSUM_GEN_UDP==0: Generate checksums by hardware for outgoing UDP packets.*/
//  #define CHECKSUM_GEN_UDP                0
//  /* CHECKSUM_GEN_TCP==0: Generate checksums by hardware for outgoing TCP packets.*/
//  #define CHECKSUM_GEN_TCP                0 
//  /* CHECKSUM_CHECK_IP==0: Check checksums by hardware for incoming IP packets.*/
//  #define CHECKSUM_CHECK_IP               0
//  /* CHECKSUM_CHECK_UDP==0: Check checksums by hardware for incoming UDP packets.*/
//  #define CHECKSUM_CHECK_UDP              0
//  /* CHECKSUM_CHECK_TCP==0: Check checksums by hardware for incoming TCP packets.*/
//  #define CHECKSUM_CHECK_TCP              0
//  /* CHECKSUM_CHECK_ICMP==0: Check checksums by hardware for incoming ICMP packets.*/
//  #define CHECKSUM_GEN_ICMP               0
//#else
//  /* CHECKSUM_GEN_IP==1: Generate checksums in software for outgoing IP packets.*/
//  #define CHECKSUM_GEN_IP                 1
//  /* CHECKSUM_GEN_UDP==1: Generate checksums in software for outgoing UDP packets.*/
//  #define CHECKSUM_GEN_UDP                1
//  /* CHECKSUM_GEN_TCP==1: Generate checksums in software for outgoing TCP packets.*/
//  #define CHECKSUM_GEN_TCP                1
//  /* CHECKSUM_CHECK_IP==1: Check checksums in software for incoming IP packets.*/
//  #define CHECKSUM_CHECK_IP               1
//  /* CHECKSUM_CHECK_UDP==1: Check checksums in software for incoming UDP packets.*/
//  #define CHECKSUM_CHECK_UDP              1
//  /* CHECKSUM_CHECK_TCP==1: Check checksums in software for incoming TCP packets.*/
//  #define CHECKSUM_CHECK_TCP              1
//  /* CHECKSUM_CHECK_ICMP==1: Check checksums by hardware for incoming ICMP packets.*/
//  #define CHECKSUM_GEN_ICMP               1
//#endif


///*
//   ----------------------------------------------
//   ---------- Sequential layer options ----------
//   ----------------------------------------------
//*/
///**
// * LWIP_NETCONN==1: Enable Netconn API (require to use api_lib.c)
// */
//#define LWIP_NETCONN                    0

///*
//   ------------------------------------
//   ---------- Socket options ----------
//   ------------------------------------
//*/
///**
// * LWIP_SOCKET==1: Enable Socket API (require to use sockets.c)
// */
//#define LWIP_SOCKET                     0

///*
//   ---------------------------------
//   ---------- OS options ----------
//   ---------------------------------
//*/


////#define DEFAULT_UDP_RECVMBOX_SIZE       10
////#define DEFAULT_TCP_RECVMBOX_SIZE       10
////#define DEFAULT_ACCEPTMBOX_SIZE         10
////#define DEFAULT_THREAD_STACKSIZE        1024


////#define TCPIP_THREAD_NAME              "lwip"
////#define TCPIP_THREAD_STACKSIZE          2048
////#define TCPIP_MBOX_SIZE                 8
////#define TCPIP_THREAD_PRIO               3

//////#define IPERF_SERVER_THREAD_NAME            "iperf_server"
//////#define IPERF_SERVER_THREAD_STACKSIZE        1024
//////#define IPERF_SERVER_THREAD_PRIO             0

//////#define BLOCK_TIME			                250
//////#define BLOCK_TIME_WAITING_FOR_INPUT	( ( portTickType ) 100 )

///*
//   ----------------------------------------
//   ---------- Lwip Debug options ----------
//   ----------------------------------------
//*/
////#define LWIP_DEBUG                      1

//#endif /* __LWIPOPTS_H__ */


/////*
//// * Copyright (c) 2001-2003 Swedish Institute of Computer Science.
//// * All rights reserved. 
//// * 
//// * Redistribution and use in source and binary forms, with or without modification, 
//// * are permitted provided that the following conditions are met:
//// *
//// * 1. Redistributions of source code must retain the above copyright notice,
//// *    this list of conditions and the following disclaimer.
//// * 2. Redistributions in binary form must reproduce the above copyright notice,
//// *    this list of conditions and the following disclaimer in the documentation
//// *    and/or other materials provided with the distribution.
//// * 3. The name of the author may not be used to endorse or promote products
//// *    derived from this software without specific prior written permission. 
//// *
//// * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED 
//// * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
//// * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT 
//// * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
//// * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT 
//// * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
//// * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
//// * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
//// * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
//// * OF SUCH DAMAGE.
//// *
//// * This file is part of the lwIP TCP/IP stack.
//// * 
//// * Author: Adam Dunkels <adam@sics.se>
//// *
//// */
////#ifndef LWIP_LWIPOPTS_H
////#define LWIP_LWIPOPTS_H

////#ifdef LWIP_OPTTEST_FILE
////#include "lwipopts_test.h"
////#else /* LWIP_OPTTEST_FILE */

////#define LWIP_IPV4                  1
////#define LWIP_IPV6                  1

////#define NO_SYS                     0
////#define LWIP_SOCKET                (NO_SYS==0)
////#define LWIP_NETCONN               (NO_SYS==0)
////#define LWIP_NETIF_API             (NO_SYS==0)

////#define LWIP_IGMP                  LWIP_IPV4
////#define LWIP_ICMP                  LWIP_IPV4

////#define LWIP_SNMP                  LWIP_UDP
////#define MIB2_STATS                 LWIP_SNMP
////#ifdef LWIP_HAVE_MBEDTLS
////#define LWIP_SNMP_V3               (LWIP_SNMP)
////#endif

////#define LWIP_DNS                   LWIP_UDP
////#define LWIP_MDNS_RESPONDER        LWIP_UDP

////#define LWIP_NUM_NETIF_CLIENT_DATA (LWIP_MDNS_RESPONDER)

////#define LWIP_HAVE_LOOPIF           1
////#define LWIP_NETIF_LOOPBACK        1
////#define LWIP_LOOPBACK_MAX_PBUFS    10

////#define TCP_LISTEN_BACKLOG         1

////#define LWIP_COMPAT_SOCKETS        1
////#define LWIP_SO_RCVTIMEO           1
////#define LWIP_SO_RCVBUF             1

////#define LWIP_TCPIP_CORE_LOCKING    1

////#define LWIP_NETIF_LINK_CALLBACK        1
////#define LWIP_NETIF_STATUS_CALLBACK      1
////#define LWIP_NETIF_EXT_STATUS_CALLBACK  1

////#ifdef LWIP_DEBUG

////#define LWIP_DBG_MIN_LEVEL         0
////#define PPP_DEBUG                  LWIP_DBG_OFF
////#define MEM_DEBUG                  LWIP_DBG_OFF
////#define MEMP_DEBUG                 LWIP_DBG_OFF
////#define PBUF_DEBUG                 LWIP_DBG_OFF
////#define API_LIB_DEBUG              LWIP_DBG_OFF
////#define API_MSG_DEBUG              LWIP_DBG_OFF
////#define TCPIP_DEBUG                LWIP_DBG_OFF
////#define NETIF_DEBUG                LWIP_DBG_OFF
////#define SOCKETS_DEBUG              LWIP_DBG_OFF
////#define DNS_DEBUG                  LWIP_DBG_OFF
////#define AUTOIP_DEBUG               LWIP_DBG_OFF
////#define DHCP_DEBUG                 LWIP_DBG_OFF
////#define IP_DEBUG                   LWIP_DBG_OFF
////#define IP_REASS_DEBUG             LWIP_DBG_OFF
////#define ICMP_DEBUG                 LWIP_DBG_OFF
////#define IGMP_DEBUG                 LWIP_DBG_OFF
////#define UDP_DEBUG                  LWIP_DBG_OFF
////#define TCP_DEBUG                  LWIP_DBG_OFF
////#define TCP_INPUT_DEBUG            LWIP_DBG_OFF
////#define TCP_OUTPUT_DEBUG           LWIP_DBG_OFF
////#define TCP_RTO_DEBUG              LWIP_DBG_OFF
////#define TCP_CWND_DEBUG             LWIP_DBG_OFF
////#define TCP_WND_DEBUG              LWIP_DBG_OFF
////#define TCP_FR_DEBUG               LWIP_DBG_OFF
////#define TCP_QLEN_DEBUG             LWIP_DBG_OFF
////#define TCP_RST_DEBUG              LWIP_DBG_OFF
////#endif

////#define LWIP_DBG_TYPES_ON         (LWIP_DBG_ON|LWIP_DBG_TRACE|LWIP_DBG_STATE|LWIP_DBG_FRESH|LWIP_DBG_HALT)


/////* ---------- Memory options ---------- */
/////* MEM_ALIGNMENT: should be set to the alignment of the CPU for which
////   lwIP is compiled. 4 byte alignment -> define MEM_ALIGNMENT to 4, 2
////   byte alignment -> define MEM_ALIGNMENT to 2. */
/////* MSVC port: intel processors don't need 4-byte alignment,
////   but are faster that way! */
////#define MEM_ALIGNMENT           4U

/////* MEM_SIZE: the size of the heap memory. If the application will send
////a lot of data that needs to be copied, this should be set high. */
////#define MEM_SIZE               10240

/////* MEMP_NUM_PBUF: the number of memp struct pbufs. If the application
////   sends a lot of data out of ROM (or other static memory), this
////   should be set high. */
////#define MEMP_NUM_PBUF           16
/////* MEMP_NUM_RAW_PCB: the number of UDP protocol control blocks. One
////   per active RAW "connection". */
////#define MEMP_NUM_RAW_PCB        3
/////* MEMP_NUM_UDP_PCB: the number of UDP protocol control blocks. One
////   per active UDP "connection". */
////#define MEMP_NUM_UDP_PCB        4
/////* MEMP_NUM_TCP_PCB: the number of simulatenously active TCP
////   connections. */
////#define MEMP_NUM_TCP_PCB        5
/////* MEMP_NUM_TCP_PCB_LISTEN: the number of listening TCP
////   connections. */
////#define MEMP_NUM_TCP_PCB_LISTEN 8
/////* MEMP_NUM_TCP_SEG: the number of simultaneously queued TCP
////   segments. */
////#define MEMP_NUM_TCP_SEG        16
/////* MEMP_NUM_SYS_TIMEOUT: the number of simulateously active
////   timeouts. */
////#define MEMP_NUM_SYS_TIMEOUT    17

/////* The following four are used only with the sequential API and can be
////   set to 0 if the application only will use the raw API. */
/////* MEMP_NUM_NETBUF: the number of struct netbufs. */
////#define MEMP_NUM_NETBUF         2
/////* MEMP_NUM_NETCONN: the number of struct netconns. */
////#define MEMP_NUM_NETCONN        10
/////* MEMP_NUM_TCPIP_MSG_*: the number of struct tcpip_msg, which is used
////   for sequential API communication and incoming packets. Used in
////   src/api/tcpip.c. */
////#define MEMP_NUM_TCPIP_MSG_API   16
////#define MEMP_NUM_TCPIP_MSG_INPKT 16


/////* ---------- Pbuf options ---------- */
/////* PBUF_POOL_SIZE: the number of buffers in the pbuf pool. */
////#define PBUF_POOL_SIZE          120

/////* PBUF_POOL_BUFSIZE: the size of each pbuf in the pbuf pool. */
////#define PBUF_POOL_BUFSIZE       256

/////** SYS_LIGHTWEIGHT_PROT
//// * define SYS_LIGHTWEIGHT_PROT in lwipopts.h if you want inter-task protection
//// * for certain critical regions during buffer allocation, deallocation and memory
//// * allocation and deallocation.
//// */
////#define SYS_LIGHTWEIGHT_PROT    (NO_SYS==0)


/////* ---------- TCP options ---------- */
////#define LWIP_TCP                1
////#define TCP_TTL                 255

////#define LWIP_ALTCP              (LWIP_TCP)
////#ifdef LWIP_HAVE_MBEDTLS
////#define LWIP_ALTCP_TLS          (LWIP_TCP)
////#define LWIP_ALTCP_TLS_MBEDTLS  (LWIP_TCP)
////#endif


/////* Controls if TCP should queue segments that arrive out of
////   order. Define to 0 if your device is low on memory. */
////#define TCP_QUEUE_OOSEQ         1

/////* TCP Maximum segment size. */
////#define TCP_MSS                 1024

/////* TCP sender buffer space (bytes). */
////#define TCP_SND_BUF             2048

/////* TCP sender buffer space (pbufs). This must be at least = 2 *
////   TCP_SND_BUF/TCP_MSS for things to work. */
////#define TCP_SND_QUEUELEN       (4 * TCP_SND_BUF/TCP_MSS)

/////* TCP writable space (bytes). This must be less than or equal
////   to TCP_SND_BUF. It is the amount of space which must be
////   available in the tcp snd_buf for select to return writable */
////#define TCP_SNDLOWAT           (TCP_SND_BUF/2)

/////* TCP receive window. */
////#define TCP_WND                 (20 * 1024)

/////* Maximum number of retransmissions of data segments. */
////#define TCP_MAXRTX              12

/////* Maximum number of retransmissions of SYN segments. */
////#define TCP_SYNMAXRTX           4


/////* ---------- ARP options ---------- */
////#define LWIP_ARP                1
////#define ARP_TABLE_SIZE          10
////#define ARP_QUEUEING            1


/////* ---------- IP options ---------- */
/////* Define IP_FORWARD to 1 if you wish to have the ability to forward
////   IP packets across network interfaces. If you are going to run lwIP
////   on a device with only one network interface, define this to 0. */
////#define IP_FORWARD              1

/////* IP reassembly and segmentation.These are orthogonal even
//// * if they both deal with IP fragments */
////#define IP_REASSEMBLY           1
////#define IP_REASS_MAX_PBUFS      (10 * ((1500 + PBUF_POOL_BUFSIZE - 1) / PBUF_POOL_BUFSIZE))
////#define MEMP_NUM_REASSDATA      IP_REASS_MAX_PBUFS
////#define IP_FRAG                 1
////#define IPV6_FRAG_COPYHEADER    1

/////* ---------- ICMP options ---------- */
////#define ICMP_TTL                255


/////* ---------- DHCP options ---------- */
/////* Define LWIP_DHCP to 1 if you want DHCP configuration of
////   interfaces. */
////#define LWIP_DHCP               LWIP_UDP

/////* 1 if you want to do an ARP check on the offered address
////   (recommended). */
////#define DHCP_DOES_ARP_CHECK    (LWIP_DHCP)


/////* ---------- AUTOIP options ------- */
////#define LWIP_AUTOIP            (LWIP_DHCP)
////#define LWIP_DHCP_AUTOIP_COOP  (LWIP_DHCP && LWIP_AUTOIP)


/////* ---------- UDP options ---------- */
////#define LWIP_UDP                1
////#define LWIP_UDPLITE            LWIP_UDP
////#define UDP_TTL                 255


/////* ---------- RAW options ---------- */
////#define LWIP_RAW                1


/////* ---------- Statistics options ---------- */

////#define LWIP_STATS              1
////#define LWIP_STATS_DISPLAY      1

////#if LWIP_STATS
////#define LINK_STATS              1
////#define IP_STATS                1
////#define ICMP_STATS              1
////#define IGMP_STATS              1
////#define IPFRAG_STATS            1
////#define UDP_STATS               1
////#define TCP_STATS               1
////#define MEM_STATS               1
////#define MEMP_STATS              1
////#define PBUF_STATS              1
////#define SYS_STATS               1
////#endif /* LWIP_STATS */

/////* ---------- NETBIOS options ---------- */
////#define LWIP_NETBIOS_RESPOND_NAME_QUERY 1

/////* ---------- PPP options ---------- */

////#define PPP_SUPPORT             1      /* Set > 0 for PPP */

////#if PPP_SUPPORT

////#define NUM_PPP                 1      /* Max PPP sessions. */


/////* Select modules to enable.  Ideally these would be set in the makefile but
//// * we're limited by the command line length so you need to modify the settings
//// * in this file.
//// */
////#define PPPOE_SUPPORT           1
////#define PPPOS_SUPPORT           1

////#define PAP_SUPPORT             1      /* Set > 0 for PAP. */
////#define CHAP_SUPPORT            1      /* Set > 0 for CHAP. */
////#define MSCHAP_SUPPORT          0      /* Set > 0 for MSCHAP */
////#define CBCP_SUPPORT            0      /* Set > 0 for CBCP (NOT FUNCTIONAL!) */
////#define CCP_SUPPORT             0      /* Set > 0 for CCP */
////#define VJ_SUPPORT              1      /* Set > 0 for VJ header compression. */
////#define MD5_SUPPORT             1      /* Set > 0 for MD5 (see also CHAP) */

////#endif /* PPP_SUPPORT */

////#endif /* LWIP_OPTTEST_FILE */

/////* The following defines must be done even in OPTTEST mode: */

////#if !defined(NO_SYS) || !NO_SYS /* default is 0 */
////void sys_check_core_locking(void);
////#define LWIP_ASSERT_CORE_LOCKED()  sys_check_core_locking()
////void sys_mark_tcpip_thread(void);
////#define LWIP_MARK_TCPIP_THREAD()   sys_mark_tcpip_thread()

////#if !defined(LWIP_TCPIP_CORE_LOCKING) || LWIP_TCPIP_CORE_LOCKING /* default is 1 */
////void sys_lock_tcpip_core(void);
////#define LOCK_TCPIP_CORE()          sys_lock_tcpip_core()
////void sys_unlock_tcpip_core(void);
////#define UNLOCK_TCPIP_CORE()        sys_unlock_tcpip_core()
////#endif
////#endif

////#endif /* LWIP_LWIPOPTS_H */
