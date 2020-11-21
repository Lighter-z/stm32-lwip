#include "LwipServer.h"

#include "lwip/opt.h"
#include "lwip/sys.h"
#include "lwip/api.h"

#if USE_TCP_SERVER

#define TCP_SERVER_PRIO    8
#define TCP_SERVER_STK_SIZE  300
OS_STK TCP_SERVER_TASK_STK[TCP_SERVER_STK_SIZE];

static void LwipServerThread(void *param) {
  OS_CPU_SR cpu_sr;
  struct netconn *conn, *new_conn;
  err_t err;
  LWIP_UNUSED_ARG(param);
  
  conn = netconn_new(NETCONN_TCP);
  netconn_bind(conn, IP_ADDR_ANY, TCP_SERVER_PORT);
  netconn_listen(conn);
//  conn->recv_timeout = 10;    //³¬Ê±Ê±¼ä
  printf("tcp server thread");
  
  while(1) {
    err = netconn_accept(conn, &new_conn);
    if(err == ERR_OK) {
      struct netbuf *net_buf;
      void *data;
      u16_t len;
//      new_conn->recv_timeout = 10;
      while((err = netconn_recv(new_conn, &net_buf)) == ERR_OK) {
        OS_ENTER_CRITICAL();
        do{
          netbuf_data(net_buf, &data, &len);
          err = netconn_write(new_conn, data, len, NETCONN_COPY);
          if(err != ERR_OK) {
            printf("netconn_write :error \"%s \" \r\n", lwip_strerr(err));
          }
        }while(netbuf_next(net_buf) >= 0);
        OS_ENTER_CRITICAL();
        netbuf_delete(net_buf);
      }
      netconn_close(new_conn);
      netconn_delete(new_conn);
    }
  }
  
  
}


INT8U LwipServerThreadInit(void) {
  INT8U res;
  OS_CPU_SR cpu_sr;
  
  OS_ENTER_CRITICAL();
  
  res = OSTaskCreate(LwipServerThread, (void *)0, (OS_STK *)&TCP_SERVER_TASK_STK[TCP_SERVER_STK_SIZE - 1], TCP_SERVER_PRIO);
  
  OS_EXIT_CRITICAL();
  
  return res;
}


#endif
