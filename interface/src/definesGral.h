/**
  ******************************************************************************
  * File Name          : definesRefri.c
  * Description        : Este archivo contiene los defines del refrigerador 
	*											 modelo B40
  ******************************************************************************
  * @autor			   	: Germ�n E. Cardozo
  * @date			   		: 16/03/2021
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/

#include "stdint.h"


/* USER DEFINES ------------------------------------------------------------------*/

//================================================
//===  INICIO DE BOOLEANOS  ======================
//================================================
#define bool_t      uint8_t

#define TRUE     	  1
#define FALSE       0

#define PRESSED		  1
#define NOT_PRESSED 0

#define ENCENDIDO	  1
#define APAGADO		  0

#define ABIERTA 1				//puerta
#define CERRADA 0				//puerta

#define ABIERTO 1       //
#define CERRADO 0       //

#define ABRIR 	1
#define CERRAR 	0

#define MAX 1
#define MIN 0



//================================================
//===	 CANTIDAD DE NIVELES  ====================== 
//================================================
#define CANT_NIV_R	5 // cantidad de niveles para el refrigerador
#define CANT_NIV_F	5 // cantidad de niveles para el freezer



//================================================
//===  CORTE Y ARRANQUE DE MOTOR  ================
//================================================
#define MOFF_16    2900 
#define MON_16     2600 

#define MOFF_18    3100 
#define MON_18     2800 

#define MOFF_20    2900 
#define MON_20     2600 

#define MOFF_22    3100 
#define MON_22     2800 

#define MOFF_24    3100 
#define MON_24     2800 



//================================================
//===  APAERTURA Y CIERRE DE DAMPER  =============
//================================================
#define DOFF_0    2900 
#define DON_0     2600 

#define DOFF_2    3100 
#define DON_2     2800 

#define DOFF_4    2900 
#define DON_4     2600 

#define DOFF_6    3100 
#define DON_6     2800 

#define DOFF_8    3100 
#define DON_8     2800 



//================================================
//===  CORTE DE RESISTENCIA  =====================
//================================================
#define RESIST_OFF   1200	//1300 



//================================================
//===  TIEMPOS  ==================================
//================================================
#define TIEMPO_MARCHA 							5 	//[horas]
#define TIEMPO_R_MAX 								23  //[minutos] maximos de R andando
#define TIEMPO_POST_DEFROST 				5 	// [minutos]
#define TIEMPO_ALARMA_PUERTA 				2 	//tiempo en minutos para que salte alarma de puerta
#define ACTUALIZO_ESTADO_TECLAS 		(mseg%250==0) // cada cuantos milisegundos lee las teclas
#define TIME_TEST_IN 								3		//segundos que se presionana las teclas antes de entrar en testeo
#define TIEMPO_ANALIZA_ERROR_SENSOR	2   //demora en minutos para entrar en 'S' si hay error
#define TIEMPO_MINIMO_R							5		//tiempo minimo que activa la R
#define DEMORA_FORZA_POST_R					2		//minutos que tarda el forzador en encender luego del descongelamiento



//================================================
//===  FALLA DE SENSORES  ========================
//================================================
#define NTC_CORTO				300
#define NTC_ABIERTO			3900



//================================================
//===  ALARMAS  ==================================
//================================================
#define ALARMA_NO_HAY 							0 
#define ALARMA_TESTEO_MANUAL 				1
#define ALARMA_TESTEO_AUTOMATICO 		2

#define ALARMA_PUERTA_ABIERTA 			10
#define ALARMA_PUERTA_ABIERTA_PLUS	11

#define ALARMA_SENSOR_AMB_CORTO			20
#define ALARMA_SENSOR_EVA_CORTO 		21
#define ALARMA_SENSOR_REF_CORTO			22

#define ALARMA_SENSOR_AMB_ABIERTO 	23
#define ALARMA_SENSOR_EVA_ABIERTO 	24
#define ALARMA_SENSOR_REF_ABIERTO		125


//================================================
//===  ENTRADAS  =================================
//================================================

#define DAMP_SW 		HAL_GPIO_ReadPin(INT_FLAP_GPIO_Port,INT_FLAP_Pin)
#define PUERTA 			HAL_GPIO_ReadPin(DOOR_GPIO_Port,DOOR_Pin) 
#define LEO_REFRI  	HAL_GPIO_ReadPin(MIC3_GPIO_Port,MIC3_Pin)
#define LEO_FREEZER HAL_GPIO_ReadPin(MIC2_GPIO_Port,MIC2_Pin)
#define LEO_FAST	  HAL_GPIO_ReadPin(MIC1_GPIO_Port,MIC1_Pin)


//================================================
//===  LEDS  =====================================
//================================================
#define TRIO1_ON 	HAL_GPIO_WritePin(TRIO1_GPIO_Port,TRIO1_Pin,GPIO_PIN_SET);
#define TRIO1_OFF	HAL_GPIO_WritePin(TRIO1_GPIO_Port,TRIO1_Pin,GPIO_PIN_RESET);
#define TRIO2_ON 	HAL_GPIO_WritePin(TRIO2_GPIO_Port,TRIO2_Pin,GPIO_PIN_SET);
#define TRIO2_OFF	HAL_GPIO_WritePin(TRIO2_GPIO_Port,TRIO2_Pin,GPIO_PIN_RESET);
#define TRIO3_ON 	HAL_GPIO_WritePin(TRIO3_GPIO_Port,TRIO3_Pin,GPIO_PIN_SET);
#define TRIO3_OFF	HAL_GPIO_WritePin(TRIO3_GPIO_Port,TRIO3_Pin,GPIO_PIN_RESET);
#define TRIO4_ON 	HAL_GPIO_WritePin(TRIO4_GPIO_Port,TRIO4_Pin,GPIO_PIN_SET);
#define TRIO4_OFF	HAL_GPIO_WritePin(TRIO4_GPIO_Port,TRIO4_Pin,GPIO_PIN_RESET);

#define COMA_ON 	HAL_GPIO_WritePin(COM_A_GPIO_Port,COM_A_Pin,GPIO_PIN_SET);
#define COMA_OFF	HAL_GPIO_WritePin(COM_A_GPIO_Port,COM_A_Pin,GPIO_PIN_RESET);
#define COMB_ON 	HAL_GPIO_WritePin(COM_B_GPIO_Port,COM_B_Pin,GPIO_PIN_SET);
#define COMB_OFF	HAL_GPIO_WritePin(COM_B_GPIO_Port,COM_B_Pin,GPIO_PIN_RESET);
#define COMC_ON 	HAL_GPIO_WritePin(COM_C_GPIO_Port,COM_C_Pin,GPIO_PIN_SET);
#define COMC_OFF	HAL_GPIO_WritePin(COM_C_GPIO_Port,COM_C_Pin,GPIO_PIN_RESET);

#define LED_8 				0
#define LED_6 				1
#define LED_4 				2
#define LED_2 				3							
#define LED_0 				4

#define LED_16				5
#define LED_18				6
#define LED_20				7
#define LED_22				8
#define LED_24				9

#define LED_FF				10
#define LED_ALARMA		11					
	
#define LED_CANTIDAD	12
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
