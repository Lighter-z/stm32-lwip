#include "LwipHttp.h"

#include "lwip/opt.h"
#include "lwip/sys.h"
#include "lwip/api.h"
#include "lwip/sockets.h"

#if USE_HTTP

static const char http_html_hdr[] = "HTTP/1.1 200 OK\r\nContent-type: text/html\r\n\r\n";

static const char http_index_html[] = "<html><head><title>Congrats!</title></head>\
                                       <body><h1 align=\"center\">Hello World!</h1>\
                                       <h2 align=\"center\">Welcome to Fire lwIP HTTP Server!</h1>\
                                       <p align=\"center\">This is a small test page, served by httpserver-netconn.</p>\
                                       <p align=\"center\"><a href=\"http://www.firebbs.cn/forum.php/\"> <font size=\"6\"> Ò°»ðµç×ÓÂÛÌ³ </font> </a></p>\
                                       <a href=\"http://www.firebbs.cn/forum.php/\">\
                                       <p align=\"center\"><img src=\"http://www.firebbs.cn/data/attachment/portal/201806/05/163015rhz7mbgbt0zfujzh.jpg\" /></a>\
                                       </body></html>";


#define HTTP_SERVER_PRO 8
#define HTTP_STK_SIZE   300
OS_STK HTTP_TASK_STK[HTTP_STK_SIZE];

char recv_data[1024];



static void LwipHttpThread(void *param) {
  OS_CPU_SR cpu_sr;
  int sock = -1, connected;
  struct sockaddr_in server_addr, client_addr;
  socklen_t sin_size;
  int recv_len;
  
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if(sock < 0) {
//    printf("sock error \r\n"); 
  }
  
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(HTTP_PORT);
  memset(&(server_addr.sin_zero), 0, sizeof(server_addr.sin_zero));
  
  if(bind(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
//    printf("bing failed \r\n"); 
    if(sock > 0) {
      closesocket(sock);
    } 
  }
  
  if(listen(sock, 5) == 1) {
//    printf("listern error \r\n"); 
    if(sock > 0) {
      closesocket(sock);
    } 
  }
  
  while(1) {
    sin_size = sizeof(struct sockaddr_in);
    connected = accept(sock, (struct sockaddr *)&client_addr, &sin_size);

//    printf("new client connected from (%s, %d)\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
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
//      printf("recv %d len data \r\n", recv_len); 
      
      if (recv_len>=5 && 
          recv_data[0]=='G' && 
          recv_data[1]=='E' &&
          recv_data[2]=='T' &&
          recv_data[3]==' ' &&
          recv_data[4]=='/' ) {
          write(connected, http_html_hdr, sizeof(http_html_hdr));
          write(connected, http_index_html, sizeof(http_index_html));
        }
    }
    if(connected >= 0) {
      closesocket(connected);
    }
    connected = -1;
  } 
}

INT8U LwipHttpThreadInit(void) {
  INT8U res;
  OS_CPU_SR cpu_sr;
  
  OS_ENTER_CRITICAL();
  
  res = OSTaskCreate(LwipHttpThread, (void *)0, (OS_STK *)&HTTP_TASK_STK[HTTP_STK_SIZE - 1], HTTP_SERVER_PRO);
  
  OS_EXIT_CRITICAL();
  
}

#endif
