/*
(C)2015 NPLink

Description: MAC layer osal interface.

License: Revised BSD License, see LICENSE.TXT file include in the project

Maintainer: Robxr
*/
#ifndef LORAMAC_OSAL_H
#define  LORAMAC_OSAL_H

/* Includes ------------------------------------------------------------------*/
#include <stdbool.h>
#include <timer.h>
/* Macros -------------------------------------------------------------*/
//loraMAC system msg types
#define TXDONE 							1//�������
#define RXDONE 							2//�������
#define TXREQUEST						3//��������
#define TXERR_STATUS    		4//���ʹ����Ҳ����ŵ�
#define TXTIMEOUT						5//���ͳ�ʱ
#define NETJOINREQUEST			6//��������
#define NETJOINOK			  	  7//�ɹ���������
#define NETJOINFAIL			    8//��������ʧ��

//LORAMACʱ�¼�����
#define  LORAMAC_LOWPOWER_MODE   0x0001 
#define  LORAMAC_NET_JION        0x0002 

/* Typedefs -----------------------------------------------------------*/
typedef struct loraMAC_msg
{
	uint8   msgID;//��ϢID��
	uint8   msgLen;//��Ϣ����
	uint16  frame_no ;//�������к�
  int16_t msgRxRssi;//�����ź�ǿ��
	int8_t  msgRxSnr;//���������
  int8_t  tx_packet_status;//�������ݰ�״̬
  uint8   reserve;//�����ֽ�
	uint8   msgData[256];//��Ϣ����payload,���64�ֽ�
}loraMAC_msg_t;


/* Variables -----------------------------------------------------------*/
extern bool g_lora_mac_adr_switch ;
extern uint8_t IsTxConfirmed;
extern uint8_t NwkSKey[16];
extern uint8_t AppSKey[16];
extern uint8_t AppKey[16];
extern uint8_t DevEui[8];
extern uint8_t AppEui[8];

extern u8 LoraMAC_taskID;
extern u8	mode;
extern TimerEvent_t JoinReqTimer;

/* function prototypes -----------------------------------------------*/
//MAC�����ʼ������
void LoRaMAC_Init(u8 task_id);
//MAC������Ϣ������
u8 LoRaMAC_GetRxSolt(void);
u16  LoRaMAC_ProcessEvent( u8 task_id, u16 events );
void LoRaMac_SetChannelsTxPower( u8 txPower );
void LoRaMAC_SetOtaaJoinNet( u8 otaajoinnet );
void LoRa_SetDifFrq( u32 frq );

#endif
