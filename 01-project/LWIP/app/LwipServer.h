#ifndef _LWIP_SERVER__H_
#define _LWIP_SERVER__H_

#include "includes.h"

#define USE_TCP_SERVER 1
#define USE_NETCONN_TCP_SERVER 0
#define USE_SOCKET_TCP_SERVER  1
#define TCP_SERVER_PORT 8087

INT8U LwipServerThreadInit(void);
  
#endif
