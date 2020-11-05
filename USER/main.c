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
// ALIENTEKս��STM32������LWIPʵ��
// LWIP�޲���ϵͳ��ֲ
// ����֧�֣�www.openedv.com
// �Ա����̣�http://eboard.taobao.com 
// ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
// ������������ӿƼ����޹�˾  
// ���ߣ�����ԭ�� @ALIENTEK
//************************************************/

////��LCD����ʾ��ַ��Ϣ
////mode:1 ��ʾDHCP��ȡ���ĵ�ַ
////	  ���� ��ʾ��̬��ַ
//void show_address(u8 mode)
//{
//	u8 buf[30];
//	if(mode==1)
//	{
//		sprintf((char*)buf,"MAC    :%d.%d.%d.%d.%d.%d",lwipdev.mac[0],lwipdev.mac[1],lwipdev.mac[2],lwipdev.mac[3],lwipdev.mac[4],lwipdev.mac[5]);//��ӡMAC��ַ
//		LCD_ShowString(30,130,210,16,16,buf); 
//		sprintf((char*)buf,"DHCP IP:%d.%d.%d.%d",lwipdev.ip[0],lwipdev.ip[1],lwipdev.ip[2],lwipdev.ip[3]);						//��ӡ��̬IP��ַ
//		LCD_ShowString(30,150,210,16,16,buf); 
//		sprintf((char*)buf,"DHCP GW:%d.%d.%d.%d",lwipdev.gateway[0],lwipdev.gateway[1],lwipdev.gateway[2],lwipdev.gateway[3]);	//��ӡ���ص�ַ
//		LCD_ShowString(30,170,210,16,16,buf); 
//		sprintf((char*)buf,"DHCP IP:%d.%d.%d.%d",lwipdev.netmask[0],lwipdev.netmask[1],lwipdev.netmask[2],lwipdev.netmask[3]);	//��ӡ���������ַ
//		LCD_ShowString(30,190,210,16,16,buf); 
//	}
//	else 
//	{
//		sprintf((char*)buf,"MAC      :%d.%d.%d.%d.%d.%d",lwipdev.mac[0],lwipdev.mac[1],lwipdev.mac[2],lwipdev.mac[3],lwipdev.mac[4],lwipdev.mac[5]);//��ӡMAC��ַ
//		LCD_ShowString(30,130,210,16,16,buf); 
//		sprintf((char*)buf,"Static IP:%d.%d.%d.%d",lwipdev.ip[0],lwipdev.ip[1],lwipdev.ip[2],lwipdev.ip[3]);						//��ӡ��̬IP��ַ
//		LCD_ShowString(30,150,210,16,16,buf); 
//		sprintf((char*)buf,"Static GW:%d.%d.%d.%d",lwipdev.gateway[0],lwipdev.gateway[1],lwipdev.gateway[2],lwipdev.gateway[3]);	//��ӡ���ص�ַ
//		LCD_ShowString(30,170,210,16,16,buf); 
//		sprintf((char*)buf,"Static IP:%d.%d.%d.%d",lwipdev.netmask[0],lwipdev.netmask[1],lwipdev.netmask[2],lwipdev.netmask[3]);	//��ӡ���������ַ
//		LCD_ShowString(30,190,210,16,16,buf); 
//	}	
//}

//#if 0
// int main(void)
// {	 
//	u32 i;
//	delay_init();	    	//��ʱ������ʼ��	  
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 	//����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
//	uart_init(115200);	 	//���ڳ�ʼ��Ϊ115200
// 	LED_Init();			    //LED�˿ڳ�ʼ��
//	LCD_Init();				//��ʼ��LCD
//	KEY_Init();	 			//��ʼ������
//	TIM3_Int_Init(1000,719);//��ʱ��3Ƶ��Ϊ100hz
// 	usmart_dev.init(72);	//��ʼ��USMART		
// 	FSMC_SRAM_Init();		//��ʼ���ⲿSRAM
//	my_mem_init(SRAMIN);	//��ʼ���ڲ��ڴ��
//	my_mem_init(SRAMEX);	//��ʼ���ⲿ�ڴ��
//	POINT_COLOR = RED; 		
//	LCD_ShowString(30,30,200,16,16,"WARSHIP STM32F103");
//	LCD_ShowString(30,50,200,16,16,"Ethernet lwIP Test");
//	LCD_ShowString(30,70,200,16,16,"ATOM@ALIENTEK");
//	LCD_ShowString(30,90,200,16,16,"2015/3/20"); 			    
//	while(lwip_comm_init()) //lwip��ʼ��
//	{
//		LCD_ShowString(30,110,200,20,16,"LWIP Init Falied!");
//		delay_ms(1200);
//		LCD_Fill(30,110,230,130,WHITE); //�����ʾ
//		LCD_ShowString(30,110,200,16,16,"Retrying...");  
//	}
//	LCD_ShowString(30,110,200,20,16,"LWIP Init Success!");
// 	LCD_ShowString(30,130,200,16,16,"DHCP IP configing...");
//#if LWIP_DHCP   //ʹ��DHCP
//	while((lwipdev.dhcpstatus!=2)&&(lwipdev.dhcpstatus!=0XFF))//�ȴ�DHCP��ȡ�ɹ�/��ʱ���
//	{
//		lwip_periodic_handle();	//LWIP�ں���Ҫ��ʱ����ĺ���
//		lwip_pkt_handle();
//	}
//#endif
//	show_address(lwipdev.dhcpstatus);	//��ʾ��ַ��Ϣ
//  	while(1)
//	{	
//		lwip_periodic_handle();	//LWIP�ں���Ҫ��ʱ����ĺ���
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
//  OSTaskSuspend(START_TASK_PRIO);	//������ʼ����.
//  OS_EXIT_CRITICAL();
//  
//}

//int main(void) {
//  
//  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
//	delay_init();	    //��ʱ������ʼ��	  
//	LED_Init();		  	//��ʼ����LED���ӵ�Ӳ���ӿ�
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
//7.�޸ľ����ļ�
//sys.h��108��#define LWIP_COMPAT_MUTEX 0��Ϊ#define LWIP_COMPAT_MUTEX 0��
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
 ALIENTEKս��STM32������LWIPʵ��
 LWIP+UCOS����ϵͳ��ֲʵ��
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/

//LED����
//�������ȼ�
#define LED_TASK_PRIO		9
//�����ջ��С
#define LED_STK_SIZE		64
//�����ջ
OS_STK	LED_TASK_STK[LED_STK_SIZE];
//������
void led_task(void *pdata);  

//��LCD����ʾ��ַ��Ϣ����
//�������ȼ�
#define DISPLAY_TASK_PRIO	10
//�����ջ��С
#define DISPLAY_STK_SIZE	128
//�����ջ
OS_STK	DISPLAY_TASK_STK[DISPLAY_STK_SIZE];
//������
void display_task(void *pdata);

//START����
//�������ȼ�
#define START_TASK_PRIO		11
//�����ջ��С
#define START_STK_SIZE		128
//�����ջ
OS_STK START_TASK_STK[START_STK_SIZE];
//������
void start_task(void *pdata); 
//��LCD����ʾ��ַ��Ϣ
//mode:1 ��ʾDHCP��ȡ���ĵ�ַ
//	  ���� ��ʾ��̬��ַ
void show_address(u8 mode)
{
	u8 buf[30];
	if(mode==2)
	{
		sprintf((char*)buf,"DHCP IP :%d.%d.%d.%d",lwipdev.ip[0],lwipdev.ip[1],lwipdev.ip[2],lwipdev.ip[3]);						//��ӡ��̬IP��ַ
		LCD_ShowString(30,130,210,16,16,buf); 
		sprintf((char*)buf,"DHCP GW :%d.%d.%d.%d",lwipdev.gateway[0],lwipdev.gateway[1],lwipdev.gateway[2],lwipdev.gateway[3]);	//��ӡ���ص�ַ
		LCD_ShowString(30,150,210,16,16,buf); 
		sprintf((char*)buf,"NET MASK:%d.%d.%d.%d",lwipdev.netmask[0],lwipdev.netmask[1],lwipdev.netmask[2],lwipdev.netmask[3]);	//��ӡ���������ַ
		LCD_ShowString(30,170,210,16,16,buf); 
	}
	else 
	{
		sprintf((char*)buf,"Static IP:%d.%d.%d.%d",lwipdev.ip[0],lwipdev.ip[1],lwipdev.ip[2],lwipdev.ip[3]);						//��ӡ��̬IP��ַ
		LCD_ShowString(30,130,210,16,16,buf); 
		sprintf((char*)buf,"Static GW:%d.%d.%d.%d",lwipdev.gateway[0],lwipdev.gateway[1],lwipdev.gateway[2],lwipdev.gateway[3]);	//��ӡ���ص�ַ
		LCD_ShowString(30,150,210,16,16,buf); 
		sprintf((char*)buf,"NET MASK:%d.%d.%d.%d",lwipdev.netmask[0],lwipdev.netmask[1],lwipdev.netmask[2],lwipdev.netmask[3]);	//��ӡ���������ַ
		LCD_ShowString(30,170,210,16,16,buf); 
	}	
}


int main(void)
{	 
	delay_init();	    	//��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	//����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 	//���ڳ�ʼ��Ϊ115200
 	LED_Init();			    //LED�˿ڳ�ʼ��
	LCD_Init();				//��ʼ��LCD
	KEY_Init();	 			//��ʼ������
 	usmart_dev.init(72);	//��ʼ��USMART		
 	FSMC_SRAM_Init();		//��ʼ���ⲿSRAM
	my_mem_init(SRAMIN);		//��ʼ���ڲ��ڴ��
	my_mem_init(SRAMEX);		//��ʼ���ⲿ�ڴ��
	POINT_COLOR = RED; 		
	LCD_ShowString(30,30,200,16,16,"WARSHIP STM32F103");
	LCD_ShowString(30,50,200,16,16,"LWIP+UCOS Test");
	LCD_ShowString(30,70,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(30,90,200,20,16,"2015/3/21");	
	POINT_COLOR = BLUE; 	//��ɫ����
	 
	OSInit();				//UCOS��ʼ��
	while(lwip_comm_init()) //lwip��ʼ��
	{
		LCD_ShowString(30,110,200,20,16,"Lwip Init failed!"); 	//lwip��ʼ��ʧ��
		delay_ms(500);
		LCD_Fill(30,110,230,150,WHITE);
		delay_ms(500);
	}
	LCD_ShowString(30,110,200,20,16,"Lwip Init Success!"); 		//lwip��ʼ���ɹ�
	OSTaskCreate(start_task,(void*)0,(OS_STK*)&START_TASK_STK[START_STK_SIZE-1],START_TASK_PRIO);
	OSStart(); //����UCOS
}
 
//start����
void start_task(void *pdata)
{
	OS_CPU_SR cpu_sr;
	pdata = pdata ;
	
	OSStatInit();  			//��ʼ��ͳ������
	OS_ENTER_CRITICAL();  	//���ж�
	OSTaskCreate(led_task,(void*)0,(OS_STK*)&LED_TASK_STK[LED_STK_SIZE-1],LED_TASK_PRIO); 	//����LED����
	OSTaskCreate(display_task,(void*)0,(OS_STK*)&DISPLAY_TASK_STK[DISPLAY_STK_SIZE-1],DISPLAY_TASK_PRIO); //��ʾ����
	OSTaskSuspend(OS_PRIO_SELF); //����start_task����
	OS_EXIT_CRITICAL();  //���ж�
}

//��ʾ��ַ����Ϣ
void display_task(void *pdata)
{
	while(1)
	{ 
#if LWIP_DHCP									//������DHCP��ʱ��
		if(lwipdev.dhcpstatus != 0) 			//����DHCP
		{
			show_address(lwipdev.dhcpstatus );	//��ʾ��ַ��Ϣ
			OSTaskSuspend(OS_PRIO_SELF); 		//��ʾ���ַ��Ϣ�������������
		}
#else
		show_address(0); 						//��ʾ��̬��ַ
		OSTaskSuspend(OS_PRIO_SELF); 			//��ʾ���ַ��Ϣ�������������
#endif //LWIP_DHCP
		OSTimeDlyHMSM(0,0,0,100);
	}
}

//led����
void led_task(void *pdata)
{
	while(1)
	{
		LED0 = !LED0;
		OSTimeDlyHMSM(0,0,0,500);  //��ʱ500ms
 	}
}

