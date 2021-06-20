/**
  ******************************************************************************
  * @file    interfazControl.c
  * @brief   Rutinas para el manejo de las teclas y los leds.
  ******************************************************************************
  * @attention
  *
	* <h2><center>LEO_FAST, LEO_REFRI y LEO_FREEZER definidas en definesRefri.h
	*	</center></h2>
	*
  * <h2><center>&copy; Copyright (c) 2021 Electrostd.
  * All rights reserved.</center></h2>
  ******************************************************************************
  * @autor  Germ�n E. Cardozo
  ******************************************************************************
  * @date   2021/06/03
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "interfazControl.h"

#include "teclasControl.h"
#include "ledsControl.h"
//#include "MocktimerControl.h"



static bool_t delayTeclas;



/************************************************************************	
		@brief 	interfaz_setMaxCont: establece el valor maximo de secuencia						
		@param 	uint8_t alar, bool_t ff2 : indicadores de FF y de alarma
		@return vMax: valor maximo modificado
************************************************************************/
uint8_t interfaz_setMaxCont(uint8_t alar, bool_t ff2)
{
		uint8_t vMax=DEFAULT_LED_ON;
		if(alar!=ALARMA_NO_HAY && ff2!=0)
		{
				vMax+=2;	
		}
		else if(alar!=ALARMA_NO_HAY || ff2!=0)
		{
			vMax+=1;
		}
		
		return vMax;
}


/************************************************************************	
		@brief 	interfaz_setMaxCont: establece el valor maximo de secuencia						
		@param 	uint8_t alar, bool_t ff2 : indicadores de FF y de alarma
		@return vMax: valor maximo modificado
************************************************************************/
void interfaz_init(void)
{
	delayTeclas=FALSE;
	void led_allOff(void);

	
}

/************************************************************************	
		@brief 	interfaz_getDelayTeclas: retorna el estado de delayTeclas
		@param 	none.
		@return bool_t delayTeclas: estado de delayTeclas
************************************************************************/
bool_t interfaz_getDelayTeclas(void)
{
	return delayTeclas;
}



/************************************************************************	
		@brief 	interfaz_control: controla si debe leer teclas o 
						escribir leds
		@param 	none.
		@return none.
************************************************************************/
/*void interfaz_control(uint8_t *nivR,uint8_t *nivF,bool_t *ffX,uint8_t *alarmX)
{
	//chequea si debe leer las teclas, de lo contrario escribe los leds
	if(delayTeclas==FALSE)
	{
		interfaz_leeTeclas(nivR,nivF,ffX);
		delayTeclas=TRUE;
	}
	else
	{			

		interfaz_escribeLeds(*nivR, *nivF, *ffX, *alarmX);
	}
}
*/

/************************************************************************
************************   MANEJO DE LEDS   *****************************
************************************************************************/

/************************************************************************	
		@brief 	interfaz_escribeLeds: prende de a un led por vez acorde a 
						los flags de nivel, de FF y de alarma
		@param 	nivel de Refri, nivel de Freezer, alarma y frio rapido
		@return none.
************************************************************************/
/*void interfaz_escribeLeds(uint8_t nR,uint8_t nF,bool_t fast,uint8_t alarX)
{
	static uint8_t secuenciadorLeds; //variable usada para secuenciar los leds
	uint8_t valorMax; //indica cual es el valor maximo de la secuencia 2, 3, 4
	
	//se establece valor maximo de la secuencia si hay alarma y/o FF
	valorMax=interfaz_setMaxCont(alarX, fast);
	
	//borro los leds encendidos
	led_allOff();
	
	//prende de a un led por vez
	switch(secuenciadorLeds)
	{
		case 0:
				led_refriOn(nR);
				break;
		case 1:
				led_freezerOn(nF);
				break;
		case 2:
				if(fast==TRUE)
						led_ffOn();
				else
						//salta a subrutina que decide como prender el led de alarma
						interfaz_alarmOnSelection(alarX);
		case 3:	
			   //salta a subrutina que decide como prender el led de alarma
				interfaz_alarmOnSelection(alarX);
				break;
		default: //cuarto led a prender
				secuenciadorLeds=0;
				break;
	}
			
	//cambia el valor del secuenciador para prender otro led
	secuenciadorLeds++;
	if(secuenciadorLeds>=valorMax)
		secuenciadorLeds=0;
	
}
*/
/************************************************************************
************************  MANEJO DE TECLAS  *****************************
************************************************************************/


/************************************************************************	
		@brief 	interfaz_control: lee las teclas 
		@param 	none.
		@return none.
************************************************************************/
void interfaz_leeTeclas(uint8_t *nivR,uint8_t *nivF,bool_t *ffX)
{
		if(tecla_FF())
		{
				if(*ffX==TRUE)
					*ffX=FALSE;
				else
					*ffX=TRUE;
		}
			
		if(tecla_nivelR())
		{
				(*nivR)++;
				if(*nivR>=CANT_NIV_R)
					*nivR=0;		
		}
		
		if(tecla_nivelF())
		{
				(*nivF)++;
				if(*nivF>=CANT_NIV_F)
					*nivF=0;	
		}
}


/************************************************************************	
		@brief 	interfaz_teclasDelayOn deshabilita la lectura de teclas
		@param 	none.
		@return none.
************************************************************************/
void interfaz_teclasDelayOn(void)
{
	delayTeclas=TRUE;
}


/************************************************************************	
		@brief 	interfaz_teclasDelayOff deshabilita la lectura de teclas
		@param 	none.
		@return none.
************************************************************************/
void interfaz_teclasDelayOff(void)
{
	delayTeclas=FALSE;
}



/************************************************************************
**************************  MANEJO DE LEDS  *****************************
************************************************************************/



/************************************************************************	
		@brief 	interfaz_alarmOnSelection: maquina de estados para el titileo 
						del led alarma.
		@param 	uint8_t numberOfBlinks: Numero de titileos durante el PeriodOn.
		@param 	uint8_t periodOn: tiempo en segundos en los cuales ocurren 
						los titileos.
		@param 	uint8_t periodOff: tiempo apagado entre secuencia de titileos.
		@return none.
************************************************************************/
/*void interfaz_alarmBlinky(uint8_t numerOfBlinks, uint8_t periodOn, uint8_t periodOff )
{
	static bool_t startBlink;		//varible que permite reiniciar la secuencia
	static uint32_t onTime;			//carga el tiempo que el led parpadera
	static uint32_t offTime;     //carga el tiempo total de la secuencia
	static uint32_t frecuency;  //frecuencia de parpadeo
	static bool_t blinkyStatus; //permite intercambiar entre encendido y apagado para lograr el titileo
	static bool_t blinkyFlag;   //asegura que no ingres al if ma de una vez por miliseg
	
	//startBlink sera TRUE cuando deba reinicair la secuencia
	if(startBlink==TRUE)
	{
		//evita que reingrese a este if
		startBlink=FALSE;
		
		//cargo tiempo en el que ocurriran los titileos
		onTime=periodOn*1000;
		
		//cargo tiempo muerto luego de los titileos
		offTime=onTime+(periodOff*1000);
		
		if(numerOfBlinks!=0)
			//calculo cada cuantos milisegundo habra una titileo
			frecuency=(onTime)/(2*numerOfBlinks);
			
		//reseto el contador de alarma para nueva seceuncia
		timer_clrMsegAlarma();
	}
	
	if(timer_getMsegAlarma() < onTime)
	{
		if(numerOfBlinks!=0)
		{
			if(timer_getMsegAlarma()%frecuency==0)
			{
				if(blinkyFlag==TRUE)
				{			
					blinkyStatus= !(blinkyStatus);
					blinkyFlag=FALSE;
				}
			}
			else
				blinkyFlag=TRUE;
			
			if(blinkyStatus==TRUE)
			{
				//prende el led de alarma
				led_alarmOn();
			}
			else
			{
				//apaga el led de alarma
				//led_alarmOff();
			}
		}
		else
		{
			//si numero de blink =0 queda prendido todo el onTime
			led_alarmOn();
		}
	}
	else if(timer_getMsegAlarma() < offTime)
	{
				//apaga el led de alarma
				//led_alarmOff();
		
			blinkyStatus=TRUE;
	}
	else
	{
		//reinicio secuencia
		startBlink=TRUE;
	}
}
*/


/************************************************************************	
		@brief 	interfaz_alarmOnSelection: maquina de estados para el titileo 
						del led alarma
		@param 	uint8_t alarm: Numero de alarma
		@return retorna el mismo valor de alarma a menos que el numero 
						recibido este fuera de rango, en ese caso, resetea la alarma
************************************************************************/
/*uint8_t interfaz_alarmOnSelection(uint8_t alar)
{
	

	switch(alar)
	{
		case ALARMA_NO_HAY:
			
			//apaga el led de alarma
			//led_alarmOff()
			break;
		
		case ALARMA_TESTEO_MANUAL:
			
			//interfaz_alarmBlinky(numerOfBlinks, periodOn, periodOff )
			interfaz_alarmBlinky(8, 1, 3 );	
			break;
		
		case ALARMA_TESTEO_AUTOMATICO:
			
			interfaz_alarmBlinky(0, 1, 1 );	
			break;
		
		case ALARMA_SENSOR_AMB_CORTO:
			
			interfaz_alarmBlinky(1, 4, 5 );		
			break;
		
		case ALARMA_SENSOR_EVA_CORTO:
			
			interfaz_alarmBlinky(2, 4, 5 );		
			break;
		
		case ALARMA_SENSOR_REF_CORTO:
		
			interfaz_alarmBlinky(3, 4, 5 );	
			break;
		
		case ALARMA_PUERTA_ABIERTA:
			
			interfaz_alarmBlinky(2, 2, 2 );	
			break;
		
		case ALARMA_PUERTA_ABIERTA_PLUS:
			
			interfaz_alarmBlinky(2, 2, 4 );	
			break;
		
		case ALARMA_SENSOR_AMB_ABIERTO:
		
			interfaz_alarmBlinky(4, 4, 5 );
			break;
		
		case ALARMA_SENSOR_EVA_ABIERTO:
		
			interfaz_alarmBlinky(5, 4, 5 );	
			break;
		
		case ALARMA_SENSOR_REF_ABIERTO:
		
			interfaz_alarmBlinky(6, 4, 5 );	
			break;
		
		default:
		
			alar= ALARMA_NO_HAY;
			break;		
	}

	return alar;
}
*/


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
