/**
  ******************************************************************************
  * @file    teclasControl.c
  * @brief   Rutinas para el manejo de las teclas.
  ******************************************************************************
  * @attention
  *
	* <h2><center>LEO_FAST, LEO_REFRI y LEO_FREEZER definidas en definesRefri.h
	*	</center></h2>
	*
  * <h2><center>&copy; Copyright (c) 2021 Electrostd.
  * All rights reserved.</center></h2>
  ******************************************************************************
  * @autor  Germán E. Cardozo
  ******************************************************************************
  * @date   2021/06/03
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "teclasControl.h"
#include "timerControl.h"
#include "definesRefri.h"
//#include "gpio.h"



/*****************************************
********  LECTURA DE LAS TECLAS  *********
*****************************************/


/************************************************************************	
		@brief 	tecla_FF: Lectura de tecla de FF
		@param 	none.
		@return estado de tecla de FF.
************************************************************************/
bool_t tecla_FF(void)
{
		if(!LEO_FAST)
		{
	
			return PRESSED;
		}
		else
		{
			//borra el tiempo de tecla presionada
			timer_clrFFPressTime();
			
			return NOT_PRESSED;
		}
}


/************************************************************************	
		@brief 	tecla_nivelR: Lectura de tecla de nivel de refrigerador
		@param 	none.
		@return estado de la tecla de nivel de refrigerador
************************************************************************/
bool_t tecla_nivelR(void)
{
		if(!LEO_REFRI)
			return PRESSED;
		else
		{
			//borra el tiempo de tecla presionada
			timer_clrNivRPressTime();
			
			return NOT_PRESSED;
		}
}


/************************************************************************	
		@brief 	tecla_nivelF: Lectura de tecla de nivel de Freezer
		@param 	none.
		@return estado de la tecla de nivel de freezer
************************************************************************/
bool_t tecla_nivelF(void)
{
		if(!LEO_FREEZER)
			return PRESSED;
		else
		{
			//borra el tiempo de tecla presionada
			timer_clrNivFPressTime();
			return NOT_PRESSED;
		}
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
