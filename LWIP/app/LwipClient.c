#include "LwipClient.h"

#include "lwip/opt.h"
#include "lwip/sys.h"
#include "lwip/api.h"

#include "lwip_comm.h" 

#if USE_TCP

//TCP�ͻ�������
#define TCP_CLIENT_PRIO		8
//�����ջ��С
#define TCP_CLIENT_STK_SIZE	300
//�����ջ
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
      OSTimeDlyHMSM(0,0,0,10);  //��ʱ10ms
      continue;
    }
    
    IP4_ADDR(&ipaddr, lwipdev.remoteip[0], lwipdev.remoteip[1], lwipdev.remoteip[2], lwipdev.remoteip[3]);
    printf("Ŀ��IP��ַ:%d.%d.%d.%d \t �˿ں�:%d\r\n",      \
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
      OSTimeDlyHMSM(0,0,0,1000);  //��ʱ1000ms
    }
  }
  
}
#elif USE_SOCKET_TCP_CLIENT 

static void LwipClientThread(void *param) {

}

#endif

INT8U LwipClientThreadInit(void) {
  INT8U res;
  OS_CPU_SR cpu_sr;
  
  OS_ENTER_CRITICAL();    //���ж�
  
  res = OSTaskCreate(LwipClientThread, (void *)0, (OS_STK*)&TCP_CLIENT_TASK_STK[TCP_CLIENT_STK_SIZE-1], TCP_CLIENT_PRIO);
  
  OS_EXIT_CRITICAL();
  
}

#endif

