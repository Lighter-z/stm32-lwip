#ifndef _LWIP_CLIENT_H
#define _LWIP_CLIENT_H

#include "includes.h"



#define USE_TCP_CLIENT    0
#define USE_NETCONN_TCP_CLIENT 1
#define USE_SOCKET_TCP_CLIENT  0

#define REMOTE_PORT				8087	//����Զ��������IP��ַ

INT8U LwipClientThreadInit(void);

#endif
