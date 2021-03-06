#include "LwipClient.h"

#include "lwip/opt.h"
#include "lwip/sys.h"
#include "lwip/api.h" 
#include "lwip/sockets.h"

#include "lwip_comm.h" 

#if USE_TCP_CLIENT

//TCP客户端任务
#define TCP_CLIENT_PRIO		8
//任务堆栈大小
#define TCP_CLIENT_STK_SIZE	300
//任务堆栈
OS_STK TCP_CLIENT_TASK_STK[TCP_CLIENT_STK_SIZE];

#if USE_NETCONN_TCP_CLIENT

static void LwipClientThread(void *param) {
  OS_CPU_SR cpu_sr;
  struct netconn *conn = NULL;
  int ret = 0;
  ip4_addr_t ipaddr;
  
  uint8_t send_buf[]= "This is a TCP Client test...\n";
  
  while(1) {
    conn = netconn_new(NETCONN_TCP);
    if(conn == NULL) {
      printf("create conn failed!\n");
      OSTimeDlyHMSM(0,0,0,10);  //延时10ms
      continue;
    }
    
    IP4_ADDR(&ipaddr, lwipdev.remoteip[0], lwipdev.remoteip[1], lwipdev.remoteip[2], lwipdev.remoteip[3]);
    printf("目地IP地址:%d.%d.%d.%d \t 端口号:%d\r\n",      \
       lwipdev.remoteip[0], lwipdev.remoteip[1], lwipdev.remoteip[2], lwipdev.remoteip[3], REMOTE_PORT);
    
    ret = netconn_connect(conn, &ipaddr, REMOTE_PORT);
    if(ret == -1) {
      printf("Connect failed!\n");
      netconn_close(conn);
      OSTimeDlyHMSM(0,0,0,10);
      continue;
    }
    
    printf("Connect to server successful!\n");
    
    while(1) {
      ret = netconn_write(conn,send_buf,sizeof(send_buf),0);
      OSTimeDlyHMSM(0,0,0,1000);  //延时1000ms
    }
  }
  
}
#elif USE_SOCKET_TCP_CLIENT 

#define IP_ADDR   "192.168.1.22"

static void LwipClientThread(void *param) {
  OS_CPU_SR cpu_sr;
  
  int sock = -1;
  struct sockaddr_in client_addr;
  
  uint8_t send_buf[] = "tcp client socket test ....\r\n";

  while(1) {
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock <= 0) {
      printf("Socket error \r\n");
      OSTimeDlyHMSM(0,0,0,10);
      continue;
    }
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = inet_addr(IP_ADDR);
    client_addr.sin_port = htons(REMOTE_PORT);
    memset(&(client_addr.sin_zero), 0, sizeof(client_addr.sin_zero));
    
    if(connect(sock, (struct sockaddr *)&client_addr, sizeof(struct sockaddr)) == -1) {
      printf("connect failed ! \r\n");
      closesocket(sock);
      OSTimeDlyHMSM(0,0,0,10);
      continue;
    }
    
    printf("connect server success ! \r\n");
    
    while(1) {
      if(write(sock, send_buf, sizeof(send_buf)) < 0) {
        break;
      }
      OSTimeDlyHMSM(0,0,0,10);
    }
    closesocket(sock);
  }
}

#endif

INT8U LwipClientThreadInit(void) {
  INT8U res;
  OS_CPU_SR cpu_sr;
  
  OS_ENTER_CRITICAL();    //关中断
  
  res = OSTaskCreate(LwipClientThread, (void *)0, (OS_STK*)&TCP_CLIENT_TASK_STK[TCP_CLIENT_STK_SIZE-1], TCP_CLIENT_PRIO);
  
  OS_EXIT_CRITICAL();
  
}

#endif

