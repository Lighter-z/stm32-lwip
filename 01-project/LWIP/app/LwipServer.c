#include "LwipServer.h"

#include "lwip/opt.h"
#include "lwip/sys.h"
#include "lwip/api.h"
#include "lwip/sockets.h"

#if USE_TCP_SERVER 


#define TCP_SERVER_PRIO    8
#define TCP_SERVER_STK_SIZE  300
OS_STK TCP_SERVER_TASK_STK[TCP_SERVER_STK_SIZE];

#if USE_NETCONN_TCP_SERVER

static void LwipServerThread(void *param) {
  OS_CPU_SR cpu_sr;
  struct netconn *conn, *new_conn;
  err_t err;
  LWIP_UNUSED_ARG(param);
  
  conn = netconn_new(NETCONN_TCP);
  netconn_bind(conn, IP_ADDR_ANY, TCP_SERVER_PORT);
  netconn_listen(conn);  
  printf("tcp server thread");
  
  while(1) {
    err = netconn_accept(conn, &new_conn);
    if(err == ERR_OK) {
      struct netbuf *net_buf;
      void *data;
      u16_t len; 
      while((err = netconn_recv(new_conn, &net_buf)) == ERR_OK) { 
        do{
          netbuf_data(net_buf, &data, &len);
          err = netconn_write(new_conn, data, len, NETCONN_COPY);
          if(err != ERR_OK) {
            printf("netconn_write :error \"%s \" \r\n", lwip_strerr(err));
          }
        }while(netbuf_next(net_buf) >= 0); 
        netbuf_delete(net_buf);
      }
      netconn_close(new_conn);
      netconn_delete(new_conn);
    }
  } 
}  

#elif USE_SOCKET_TCP_SERVER

char recv_data[1024];

static void LwipServerThread(void *param) {
  OS_CPU_SR cpu_sr;
  int sock = -1, connected;
  struct sockaddr_in server_addr, client_addr;
  socklen_t sin_size;
  int recv_len;
  
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if(sock < 0) {
    printf("sock error \r\n"); 
  }
  
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(TCP_SERVER_PORT);
  memset(&(server_addr.sin_zero), 0, sizeof(server_addr.sin_zero));
  
  if(bind(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
    printf("bing failed \r\n"); 
    if(sock > 0) {
      closesocket(sock);
    } 
  }
  
  if(listen(sock, 5) == 1) {
    printf("listern error \r\n"); 
    if(sock > 0) {
      closesocket(sock);
    } 
  }
  
  while(1) {
    sin_size = sizeof(struct sockaddr_in);
    connected = accept(sock, (struct sockaddr *)&client_addr, &sin_size);

    printf("new client connected from (%s, %d)\n",
            inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        {
      int flag = 1;
      
      setsockopt(connected,
                 IPPROTO_TCP,     /* set option at TCP level */
                 TCP_NODELAY,     /* name of option */
                 (void *) &flag,  /* the cast is historical cruft */
                 sizeof(int));    /* length of option value */
    }
        
    while(1) {
      recv_len = recv(connected, recv_data, sizeof(recv_data), 0);
      if(recv_len <= 0) {
        break;
      }
      printf("recv %d len data \r\n", recv_len);
      write(connected, recv_data, recv_len);
    }
    if(connected >= 0) {
      closesocket(connected);
    }
    connected = -1;
  } 
}

#endif

INT8U LwipServerThreadInit(void) {
  INT8U res;
  OS_CPU_SR cpu_sr;
  
  OS_ENTER_CRITICAL();
  
  res = OSTaskCreate(LwipServerThread, (void *)0, (OS_STK *)&TCP_SERVER_TASK_STK[TCP_SERVER_STK_SIZE - 1], TCP_SERVER_PRIO);
  
  OS_EXIT_CRITICAL();
  
  return res;
}


#endif
