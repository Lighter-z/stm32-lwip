#include "LwipUDP.h"

#include "lwip/opt.h"
#include "lwip/api.h"
#include "lwip/sys.h"
#include "lwip/sockets.h"

#include "lwip_comm.h" 

#if USE_UDP

#define UDP_PRIO      8
#define UDP_STK_SIZE  300
OS_STK UDP_TASK_STK[UDP_STK_SIZE];

#if USE_UDP_NETCONN

//回显实验
static void LwipUDPThread(void *param) {
  struct netconn *conn = NULL;
  struct netbuf *buf;
  char buffer[4096];
  
  err_t err;
  LWIP_UNUSED_ARG(param);
  
  conn = netconn_new(NETCONN_UDP);
  if(conn == NULL) {
    printf("create conn failed!\n");
  }
  
  err = netconn_bind(conn, IP_ADDR_ANY, UDP_LOCAL_PORT);
  
  if(err == ERR_OK) {
    printf("netconn bind ok!\n");
    while(1) {
      err = netconn_recv(conn, &buf);
      if (err == ERR_OK) {
        /*  no need netconn_connect here, since the netbuf contains the address */
        if(netbuf_copy(buf, buffer, sizeof(buffer)) != buf->p->tot_len) {
          LWIP_DEBUGF(LWIP_DBG_ON, ("netbuf_copy failed\n"));
          printf("netbuf_copy failed\n");
        } else {
          buffer[buf->p->tot_len] = '\0';
          err = netconn_send(conn, buf);
          if(err != ERR_OK) {
            LWIP_DEBUGF(LWIP_DBG_ON, ("netconn_send failed: %d\n", (int)err));
          } else {
            LWIP_DEBUGF(LWIP_DBG_ON, ("got %s\n", buffer));
            printf(" send ok \r\n");
          }
        }
        netbuf_delete(buf);
      }
    }
  } 
}

#elif USE_UDP_SOCKET

char recv_data[1024];

static void LwipUDPThread(void *param) {
  int sock = -1;
  struct sockaddr_in udp_addr, ser_addr;
  int recv_len;
  socklen_t addrlen;
  
  sock = socket(AF_INET, SOCK_DGRAM, 0);
  if(sock < 0) {
    printf("socket error! \r\n"); 
  }
  
  udp_addr.sin_family = AF_INET;
  udp_addr.sin_addr.s_addr = INADDR_ANY;
  udp_addr.sin_port = htons(UDP_LOCAL_PORT);
  memset(&(udp_addr.sin_zero), 0, sizeof(udp_addr.sin_zero));
  
  if(bind(sock, (struct sockaddr *)&udp_addr, sizeof(struct sockaddr)) == -1) {
    printf("binf error \r\n");
    if(sock >= 0) {
      closesocket(sock);
    }
  }
  while(1) {
    //以下三个都可以
//    recv_len = recvfrom(sock, recv_data, sizeof(recv_data), 0, (struct sockaddr *)&ser_addr, &addrlen);
//    recv_len = read(sock, recv_data, sizeof(recv_data));
    recv_len = recv(sock, recv_data, sizeof(recv_data), 0);
    printf("recv form %s \r\n", inet_ntoa(ser_addr.sin_addr));
    printf("recv %s \r\n", recv_data);
    sendto(sock, recv_data, sizeof(recv_data), 0, (struct sockaddr *)&ser_addr, addrlen);
  }
}

#endif

INT8U LwipUDPThreadInit(void) {
  INT8U res;
  OS_CPU_SR cpu_sr;
  
  OS_ENTER_CRITICAL();
 
  res = OSTaskCreate(LwipUDPThread, (void *)0, (OS_STK*)&UDP_TASK_STK[UDP_STK_SIZE - 1], UDP_PRIO);
  
  OS_EXIT_CRITICAL();
  return res;
}

#endif
