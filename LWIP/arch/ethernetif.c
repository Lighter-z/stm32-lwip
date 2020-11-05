#include "lwip_comm.h" 
#include "lwip/opt.h"
#include "lwip/mem.h"
#include "lwip/memp.h"
#include "lwip/timeouts.h"
#include "netif/ethernet.h"
#include "netif/etharp.h"
#include "lwip/ethip6.h"
#include "ethernetif.h"
#include "dm9000.h"

#include "string.h"  

extern OS_EVENT* dm9000input;		//DM9000���������ź���

/* Define those to better describe your network interface. */
#define IFNAME0 'e'
#define IFNAME1 'n'

struct ethernetif {
	struct eth_addr *ethaddr;
/* Add whatever per-interface state that is needed here. */
};

//��ethernetif_init()�������ڳ�ʼ��Ӳ��
//netif:�����ṹ��ָ�� 
//����ֵ:ERR_OK,����
//       ����,ʧ��
static err_t low_level_init(struct netif *netif)
{
	netif->hwaddr_len = ETHARP_HWADDR_LEN; //����MAC��ַ����,Ϊ6���ֽ�
	//��ʼ��MAC��ַ,����ʲô��ַ���û��Լ�����,���ǲ����������������豸MAC��ַ�ظ�
	netif->hwaddr[0]=lwipdev.mac[0]; 
	netif->hwaddr[1]=lwipdev.mac[1]; 
	netif->hwaddr[2]=lwipdev.mac[2];
	netif->hwaddr[3]=lwipdev.mac[3];
	netif->hwaddr[4]=lwipdev.mac[4];
	netif->hwaddr[5]=lwipdev.mac[5];
	netif->mtu=1500; //��������䵥Ԫ,����������㲥��ARP����
	netif->flags = NETIF_FLAG_BROADCAST|NETIF_FLAG_ETHARP|NETIF_FLAG_LINK_UP;		
	return ERR_OK;
} 
//���ڷ������ݰ�����ײ㺯��(lwipͨ��netif->linkoutputָ��ú���)
//netif:�����ṹ��ָ��
//p:pbuf���ݽṹ��ָ��
//����ֵ:ERR_OK,��������
//       ERR_MEM,����ʧ��
static err_t low_level_output(struct netif *netif, struct pbuf *p)
{
	DM9000_SendPacket(p);
	return ERR_OK;
}  
///���ڽ������ݰ�����ײ㺯��
//neitif:�����ṹ��ָ��
//����ֵ:pbuf���ݽṹ��ָ��
static struct pbuf * low_level_input(struct netif *netif)
{  
	struct pbuf *p;
	p=DM9000_Receive_Packet();
	return p;
}
//������������(lwipֱ�ӵ���)
//netif:�����ṹ��ָ��
//����ֵ:ERR_OK,��������
//       ERR_MEM,����ʧ��
//err_t ethernetif_input(struct netif *netif)
//{
//	err_t err;
//	struct pbuf *p;
//	p=low_level_input(netif);   //����low_level_input������������
//	if(p==NULL) return ERR_MEM;
//	err=netif->input(p, netif); //����netif�ṹ���е�input�ֶ�(һ������)���������ݰ�
//	if(err!=ERR_OK)
//	{
//		LWIP_DEBUGF(NETIF_DEBUG,("ethernetif_input: IP input error\n"));
//		pbuf_free(p);
//		p = NULL;
//	} 
//	return err;
//} 
err_t ethernetif_input(struct netif *netif)
{
	INT8U _err;
	err_t err;
	struct pbuf *p;
	while(1)
	{
		OSSemPend(dm9000input,0,&_err);		//�����ź���
		if(_err == OS_ERR_NONE)
		{
			while(1)
			{
				p=low_level_input(netif);   //����low_level_input������������
				if(p!=NULL)
				{
					err=netif->input(p, netif); //����netif�ṹ���е�input�ֶ�(һ������)���������ݰ�
					if(err!=ERR_OK)
					{
						LWIP_DEBUGF(NETIF_DEBUG,("ethernetif_input: IP input error\n"));
						pbuf_free(p);
						p = NULL;
					} 
				}else break; 
			}
		}
	}
} 

//ʹ��low_level_init()��������ʼ������
//netif:�����ṹ��ָ��
//����ֵ:ERR_OK,����
//       ����,ʧ��
err_t ethernetif_init(struct netif *netif) {
  struct ethernetif *ethernetif;
  
//	LWIP_ASSERT("netif!=NULL",(netif!=NULL));
  
  ethernetif = mem_malloc(sizeof(ethernetif));
  
  if(ethernetif == NULL) {
    printf("ethernetif_init: out of memory\n");
    return ERR_MEM;
  }
  
  LWIP_ASSERT("netif!=NULL",(netif!=NULL));
  
#if LWIP_NETIF_HOSTNAME			//LWIP_NETIF_HOSTNAME 
	netif->hostname="lwip";  	//��ʼ������
#endif 
  netif->state = ethernetif;
	netif->name[0]=IFNAME0; 	//��ʼ������netif��name�ֶ�
	netif->name[1]=IFNAME1; 	//���ļ��ⶨ�����ﲻ�ù��ľ���ֵ
  
//	netif->output=etharp_output;//IP�㷢�����ݰ�����
//	netif->linkoutput=low_level_output;//ARPģ�鷢�����ݰ�����
//	low_level_init(netif); 		//�ײ�Ӳ����ʼ������
  
#if LWIP_IPV4
#if LWIP_ARP || LWIP_ETHERNET
#if LWIP_ARP
  netif->output = etharp_output;    //IP�㷢�����ݰ�����
#else
  /* The user should write ist own code in low_level_output_arp_off function */
  netif->output = low_level_output_arp_off;
#endif /* LWIP_ARP */
#endif /* LWIP_ARP || LWIP_ETHERNET */
#endif /* LWIP_IPV4 */
 
#if LWIP_IPV6
  netif->output_ip6 = ethip6_output;
#endif /* LWIP_IPV6 */

  netif->linkoutput=low_level_output;//ARPģ�鷢�����ݰ�����
  
  low_level_init(netif);           //�ײ�Ӳ����ʼ������
  ethernetif->ethaddr = (struct eth_addr *) &(netif->hwaddr[0]);

	return ERR_OK;
}















