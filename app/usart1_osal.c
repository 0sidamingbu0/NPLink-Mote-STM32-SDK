//------------------------------------------------------------------------
// $Id
//
// Copyright (C), 2015-, DS IOT Team Information Co.,Ltd,All Rights Reserved
//
// FileName: usart1_osal.c
//
// Author: 
//
// Version: 
//
// Date: 
//
// Description: ��Ҫ���������豸
//
//
// Function List:
//
// History:
//--------------------------------------------------------------------------


/* Includes ------------------------------------------------------------------*/
#include <string.h>
#include <stdio.h>
#include "uart_board.h"
#include "error.h"
#include "osal.h"
#include "delay.h"
#include "at.h"
#include "usart1_osal.h"
#include "LoraMac_osal.h"

/* Private typedef -----------------------------------------------------------*/
#define USART1_MONITOR_DEBUG
#ifdef  USART1_MONITOR_DEBUG
#define USART1_MONITOR_debug(FORMAT, ARG...)   debug(FORMAT, ##ARG)
#else
#define USART1_MONITOR_debug(FORMAT, ARG...)
#endif

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
#define USART1_DATA_ID 0x0001
#define RECV_USART1_PACKET 0x0002
/* Private variables ---------------------------------------------------------*/

u8 USART1_taskID; //����1���ݼ������ID

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/**
*@Description: Mote�ڵ��ش���1���������ʼ��
*@param: [in]: task_id -- ����ID
*@      [out]: NONE
*@return: NONE
*@others: Parameter validation checking performs in the caller
*/
void Usart1_Init(u8 task_id)
{
		USART1_taskID = task_id;
		osal_set_event(USART1_taskID, RECV_USART1_PACKET);
}

/**
*@Description: Mote�ڵ��ش���1��������
*@param: [in]: task_id -- ����ID
*@             events -- ��������е��¼�
*@      [out]: NONE
*@return: NONE
*@others: Parameter validation checking performs in the caller
*/
u16 Usart1_ProcessEvent( u8 task_id, u16 events )
{
	if(events & RECV_USART1_PACKET)
	{
		HAL_UART_ReceiveString();
		osal_start_timerEx(USART1_taskID, RECV_USART1_PACKET, 300);

		return (events ^ RECV_USART1_PACKET);
	}

	return 0 ; 
}


