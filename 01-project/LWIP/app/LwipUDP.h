#ifndef _LWIP_UDP__H_
#define _LWIP_UDP__H_

#include "includes.h"

#define USE_UDP    0

#define USE_UDP_NETCONN 0
#define USE_UDP_SOCKET  1

#define UDP_LOCAL_PORT 8089

INT8U LwipUDPThreadInit(void);

#endif
