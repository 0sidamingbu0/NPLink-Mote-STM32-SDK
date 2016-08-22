//------------------------------------------------------------------------
// $Id
//
// Copyright (C), 2015-, IOT Team Information Co.,Ltd,All Rights Reserved
//
// FileName: usart1_osal.h
//
// Author: 
//
// Version: 1.0
//
// Date: 
//
// Description: 
//
//
// Function List:
//
// History:
//--------------------------------------------------------------------------
#include "uart_board.h"

#ifndef USART1_OSAL_H
#define USART1_OSAL_H

/**
*@Description: gateway������ش���1���������ʼ��
*@param: [in]: task_id -- ����ID
*@      [out]: NONE
*@return: NONE
*@others: Parameter validation checking performs in the caller
*/
void Usart1_Init(u8 task_id);

/**
*@Description: gateway������ش���1��������,��������Ӧ����
*@param: [in]: task_id -- ����ID
*@             events -- ��������е��¼�
*@      [out]: NONE
*@return: NONE
*@others: Parameter validation checking performs in the caller
*/
u16 Usart1_ProcessEvent( u8 task_id, u16 events );

/**
*@Description: �������ݵĴ�����
*@param: [in]: data -- ָ��������ݵ�ָ��
*@             data_len -- �������ݵĳ���
*@      [out]: NONE
*@return: NONE
*@others: Parameter validation checking performs in the caller
*/
void deal_receive_date( uint8_t * data , int32_t data_len );

#endif

