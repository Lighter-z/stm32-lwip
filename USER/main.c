//#include "led.h"
//#include "delay.h"
//#include "key.h"
//#include "sys.h"
//#include "lcd.h"
//#include "usart.h"	
//#include "timer.h"
//#include "sram.h"
//#include "malloc.h"
//#include "string.h"
//#include "usmart.h"	
//#include "dm9000.h"
//#include "lwip/netif.h"
//#include "lwip_comm.h"
//#include "lwipopts.h"
//#include "includes.h"
///************************************************
// ALIENTEK战舰STM32开发板LWIP实验
// LWIP无操作系统移植
// 技术支持：www.openedv.com
// 淘宝店铺：http://eboard.taobao.com 
// 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
// 广州市星翼电子科技有限公司  
// 作者：正点原子 @ALIENTEK
//************************************************/

////在LCD上显示地址信息
////mode:1 显示DHCP获取到的地址
////	  其他 显示静态地址
//void show_address(u8 mode)
//{
//	u8 buf[30];
//	if(mode==1)
//	{
//		sprintf((char*)buf,"MAC    :%d.%d.%d.%d.%d.%d",lwipdev.mac[0],lwipdev.mac[1],lwipdev.mac[2],lwipdev.mac[3],lwipdev.mac[4],lwipdev.mac[5]);//打印MAC地址
//		LCD_ShowString(30,130,210,16,16,buf); 
//		sprintf((char*)buf,"DHCP IP:%d.%d.%d.%d",lwipdev.ip[0],lwipdev.ip[1],lwipdev.ip[2],lwipdev.ip[3]);						//打印动态IP地址
//		LCD_ShowString(30,150,210,16,16,buf); 
//		sprintf((char*)buf,"DHCP GW:%d.%d.%d.%d",lwipdev.gateway[0],lwipdev.gateway[1],lwipdev.gateway[2],lwipdev.gateway[3]);	//打印网关地址
//		LCD_ShowString(30,170,210,16,16,buf); 
//		sprintf((char*)buf,"DHCP IP:%d.%d.%d.%d",lwipdev.netmask[0],lwipdev.netmask[1],lwipdev.netmask[2],lwipdev.netmask[3]);	//打印子网掩码地址
//		LCD_ShowString(30,190,210,16,16,buf); 
//	}
//	else 
//	{
//		sprintf((char*)buf,"MAC      :%d.%d.%d.%d.%d.%d",lwipdev.mac[0],lwipdev.mac[1],lwipdev.mac[2],lwipdev.mac[3],lwipdev.mac[4],lwipdev.mac[5]);//打印MAC地址
//		LCD_ShowString(30,130,210,16,16,buf); 
//		sprintf((char*)buf,"Static IP:%d.%d.%d.%d",lwipdev.ip[0],lwipdev.ip[1],lwipdev.ip[2],lwipdev.ip[3]);						//打印动态IP地址
//		LCD_ShowString(30,150,210,16,16,buf); 
//		sprintf((char*)buf,"Static GW:%d.%d.%d.%d",lwipdev.gateway[0],lwipdev.gateway[1],lwipdev.gateway[2],lwipdev.gateway[3]);	//打印网关地址
//		LCD_ShowString(30,170,210,16,16,buf); 
//		sprintf((char*)buf,"Static IP:%d.%d.%d.%d",lwipdev.netmask[0],lwipdev.netmask[1],lwipdev.netmask[2],lwipdev.netmask[3]);	//打印子网掩码地址
//		LCD_ShowString(30,190,210,16,16,buf); 
//	}	
//}

//#if 0
// int main(void)
// {	 
//	u32 i;
//	delay_init();	    	//延时函数初始化	  
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 	//设置NVIC中断分组2:2位抢占优先级，2位响应优先级
//	uart_init(115200);	 	//串口初始化为115200
// 	LED_Init();			    //LED端口初始化
//	LCD_Init();				//初始化LCD
//	KEY_Init();	 			//初始化按键
//	TIM3_Int_Init(1000,719);//定时器3频率为100hz
// 	usmart_dev.init(72);	//初始化USMART		
// 	FSMC_SRAM_Init();		//初始化外部SRAM
//	my_mem_init(SRAMIN);	//初始化内部内存池
//	my_mem_init(SRAMEX);	//初始化外部内存池
//	POINT_COLOR = RED; 		
//	LCD_ShowString(30,30,200,16,16,"WARSHIP STM32F103");
//	LCD_ShowString(30,50,200,16,16,"Ethernet lwIP Test");
//	LCD_ShowString(30,70,200,16,16,"ATOM@ALIENTEK");
//	LCD_ShowString(30,90,200,16,16,"2015/3/20"); 			    
//	while(lwip_comm_init()) //lwip初始化
//	{
//		LCD_ShowString(30,110,200,20,16,"LWIP Init Falied!");
//		delay_ms(1200);
//		LCD_Fill(30,110,230,130,WHITE); //清除显示
//		LCD_ShowString(30,110,200,16,16,"Retrying...");  
//	}
//	LCD_ShowString(30,110,200,20,16,"LWIP Init Success!");
// 	LCD_ShowString(30,130,200,16,16,"DHCP IP configing...");
//#if LWIP_DHCP   //使用DHCP
//	while((lwipdev.dhcpstatus!=2)&&(lwipdev.dhcpstatus!=0XFF))//等待DHCP获取成功/超时溢出
//	{
//		lwip_periodic_handle();	//LWIP内核需要定时处理的函数
//		lwip_pkt_handle();
//	}
//#endif
//	show_address(lwipdev.dhcpstatus);	//显示地址信息
//  	while(1)
//	{	
//		lwip_periodic_handle();	//LWIP内核需要定时处理的函数
//		lwip_pkt_handle();
//		i++;
//		if(i==50000)
//		{
//			LED0=~LED0;
//			i=0;
//		}
//	}
//}
//#else

//#define START_TASK_PRIO    10
//#define START_STK_SIZE     64
//OS_STK START_TASK_STK[START_STK_SIZE];

//#define LED0_TASK_PRIO     7
//#define LED0_STK_SIZE      64
//OS_STK LED0_TASK_STK[LED0_STK_SIZE];

//#define LED1_TASK_PRIO     6
//#define LED1_STK_SIZE      64
//OS_STK LED1_TASK_STK[LED1_STK_SIZE];


//void led0_task(void *pdata) {
//  while(1) {
//    LED0 = 0;
//    delay_ms(80);
//    LED0 = 1;
//    delay_ms(900);
//  }
//}

//void led1_task(void *pdata) {
//  while(1) {
//    LED1 = 0;
//    delay_ms(300);
//    LED1 = 1;
//    delay_ms(300);
//  }
//}

//void start_task(void *pdata) {
//  OS_CPU_SR cpu_sr = 0;
//  
//  OS_ENTER_CRITICAL();
//  
//  OSTaskCreate(led0_task, (void *)0, (OS_STK*)&LED0_TASK_STK[LED0_STK_SIZE-1], LED0_TASK_PRIO);
//  OSTaskCreate(led1_task, (void *)0, (OS_STK*)&LED1_TASK_STK[LED1_STK_SIZE-1], LED1_TASK_PRIO);
//  
//  OSTaskSuspend(START_TASK_PRIO);	//挂起起始任务.
//  OS_EXIT_CRITICAL();
//  
//}

//int main(void) {
//  
//  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
//	delay_init();	    //延时函数初始化	  
//	LED_Init();		  	//初始化与LED连接的硬件接口
//  
//  OSInit();
//  OSTaskCreate(start_task, (void *)0, (OS_STK*)&START_TASK_STK[START_STK_SIZE-1], START_TASK_PRIO);
//  OSStart();
//  return 0;
//}


//#endif
//http://www.armbbs.cn/forum.php?mod=viewthread&tid=93665
//https://www.jianshu.com/p/7c8b4ecfebc7
//https://www.jianshu.com/p/deabeb6a6bf4
//7.修改具体文件
//sys.h第108行#define LWIP_COMPAT_MUTEX 0改为#define LWIP_COMPAT_MUTEX 0。
#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"	
#include "timer.h"
#include "sram.h"
#include "malloc.h"
#include "string.h"
#include "usmart.h"	
#include "dm9000.h"
#include "lwip/netif.h"
#include "lwip_comm.h"
#include "lwipopts.h"
#include "includes.h"
/************************************************
 ALIENTEK战舰STM32开发板LWIP实验
 LWIP+UCOS操作系统移植实验
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/

//LED任务
//任务优先级
#define LED_TASK_PRIO		9
//任务堆栈大小
#define LED_STK_SIZE		64
//任务堆栈
OS_STK	LED_TASK_STK[LED_STK_SIZE];
//任务函数
void led_task(void *pdata);  

//在LCD上显示地址信息任务
//任务优先级
#define DISPLAY_TASK_PRIO	10
//任务堆栈大小
#define DISPLAY_STK_SIZE	128
//任务堆栈
OS_STK	DISPLAY_TASK_STK[DISPLAY_STK_SIZE];
//任务函数
void display_task(void *pdata);

//START任务
//任务优先级
#define START_TASK_PRIO		11
//任务堆栈大小
#define START_STK_SIZE		128
//任务堆栈
OS_STK START_TASK_STK[START_STK_SIZE];
//任务函数
void start_task(void *pdata); 
//在LCD上显示地址信息
//mode:1 显示DHCP获取到的地址
//	  其他 显示静态地址
void show_address(u8 mode)
{
	u8 buf[30];
	if(mode==2)
	{
		sprintf((char*)buf,"DHCP IP :%d.%d.%d.%d",lwipdev.ip[0],lwipdev.ip[1],lwipdev.ip[2],lwipdev.ip[3]);						//打印动态IP地址
		LCD_ShowString(30,130,210,16,16,buf); 
		sprintf((char*)buf,"DHCP GW :%d.%d.%d.%d",lwipdev.gateway[0],lwipdev.gateway[1],lwipdev.gateway[2],lwipdev.gateway[3]);	//打印网关地址
		LCD_ShowString(30,150,210,16,16,buf); 
		sprintf((char*)buf,"NET MASK:%d.%d.%d.%d",lwipdev.netmask[0],lwipdev.netmask[1],lwipdev.netmask[2],lwipdev.netmask[3]);	//打印子网掩码地址
		LCD_ShowString(30,170,210,16,16,buf); 
	}
	else 
	{
		sprintf((char*)buf,"Static IP:%d.%d.%d.%d",lwipdev.ip[0],lwipdev.ip[1],lwipdev.ip[2],lwipdev.ip[3]);						//打印动态IP地址
		LCD_ShowString(30,130,210,16,16,buf); 
		sprintf((char*)buf,"Static GW:%d.%d.%d.%d",lwipdev.gateway[0],lwipdev.gateway[1],lwipdev.gateway[2],lwipdev.gateway[3]);	//打印网关地址
		LCD_ShowString(30,150,210,16,16,buf); 
		sprintf((char*)buf,"NET MASK:%d.%d.%d.%d",lwipdev.netmask[0],lwipdev.netmask[1],lwipdev.netmask[2],lwipdev.netmask[3]);	//打印子网掩码地址
		LCD_ShowString(30,170,210,16,16,buf); 
	}	
}


int main(void)
{	 
	delay_init();	    	//延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	//设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 	//串口初始化为115200
 	LED_Init();			    //LED端口初始化
	LCD_Init();				//初始化LCD
	KEY_Init();	 			//初始化按键
 	usmart_dev.init(72);	//初始化USMART		
 	FSMC_SRAM_Init();		//初始化外部SRAM
	my_mem_init(SRAMIN);		//初始化内部内存池
	my_mem_init(SRAMEX);		//初始化外部内存池
	POINT_COLOR = RED; 		
	LCD_ShowString(30,30,200,16,16,"WARSHIP STM32F103");
	LCD_ShowString(30,50,200,16,16,"LWIP+UCOS Test");
	LCD_ShowString(30,70,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(30,90,200,20,16,"2015/3/21");	
	POINT_COLOR = BLUE; 	//蓝色字体
	 
	OSInit();				//UCOS初始化
	while(lwip_comm_init()) //lwip初始化
	{
		LCD_ShowString(30,110,200,20,16,"Lwip Init failed!"); 	//lwip初始化失败
		delay_ms(500);
		LCD_Fill(30,110,230,150,WHITE);
		delay_ms(500);
	}
	LCD_ShowString(30,110,200,20,16,"Lwip Init Success!"); 		//lwip初始化成功
	OSTaskCreate(start_task,(void*)0,(OS_STK*)&START_TASK_STK[START_STK_SIZE-1],START_TASK_PRIO);
	OSStart(); //开启UCOS
}
 
//start任务
void start_task(void *pdata)
{
	OS_CPU_SR cpu_sr;
	pdata = pdata ;
	
	OSStatInit();  			//初始化统计任务
	OS_ENTER_CRITICAL();  	//关中断
	OSTaskCreate(led_task,(void*)0,(OS_STK*)&LED_TASK_STK[LED_STK_SIZE-1],LED_TASK_PRIO); 	//创建LED任务
	OSTaskCreate(display_task,(void*)0,(OS_STK*)&DISPLAY_TASK_STK[DISPLAY_STK_SIZE-1],DISPLAY_TASK_PRIO); //显示任务
	OSTaskSuspend(OS_PRIO_SELF); //挂起start_task任务
	OS_EXIT_CRITICAL();  //开中断
}

//显示地址等信息
void display_task(void *pdata)
{
	while(1)
	{ 
#if LWIP_DHCP									//当开启DHCP的时候
		if(lwipdev.dhcpstatus != 0) 			//开启DHCP
		{
			show_address(lwipdev.dhcpstatus );	//显示地址信息
			OSTaskSuspend(OS_PRIO_SELF); 		//显示完地址信息后挂起自身任务
		}
#else
		show_address(0); 						//显示静态地址
		OSTaskSuspend(OS_PRIO_SELF); 			//显示完地址信息后挂起自身任务
#endif //LWIP_DHCP
		OSTimeDlyHMSM(0,0,0,100);
	}
}

//led任务
void led_task(void *pdata)
{
	while(1)
	{
		LED0 = !LED0;
		OSTimeDlyHMSM(0,0,0,500);  //延时500ms
 	}
}

