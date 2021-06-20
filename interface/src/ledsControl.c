/**
  ******************************************************************************
  * @file    ledsControl.c
  * @brief   Rutinas para el manejo de los leds.
  ******************************************************************************
  * @attention
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
#include "ledsControl.h"

led_t leds[LED_CANTIDAD];


//Vector de funciones para prender los leds del refrigerador
    void (*led_refriSelect[]) (void) = {
					led_r8On, led_r6On, led_r4On,led_r2On,led_r0On};
 
//Vector de funciones para prender los leds del freezer
    void (*led_freezerSelect[]) (void) = {
					led_f16On, led_f18On, led_f20On,led_f22On,led_f24On};

					
/*****************************************
**********  ENCENDIDO DE LEDS  ***********					
*****************************************/
					
/************************************************************************	
		@brief 	led_refriOn: Prende el led de refrigerador seleccionado
		@param 	uint8_t nivel: indica led a prender
		@return none.
************************************************************************/
void led_refriOn(uint8_t nivel)
{
	led_refriSelect[nivel]();
}


/************************************************************************	
		@brief 	led_freezerOn: Prende el led de freezer seleccionado
		@param 	uint8_t nivel: indica led a prender
		@return none.
************************************************************************/
void led_freezerOn(uint8_t nivel)
{
	led_freezerSelect[nivel]();
}


/************************************************************************	
		@brief 	led_r8On: Prende el led de refrigerador 8�
		@param 	none.
		@return none.
************************************************************************/
void led_r8On(void)
{
	TRIO1_ON 
	COMA_OFF
}


/************************************************************************	
		@brief 	led_r6On:	Prende el led de refrigerador 6�
		@param 	none.
		@return none.
************************************************************************/
void led_r6On(void)
{
	TRIO1_ON 
	COMB_OFF 
}


/************************************************************************	
		@brief 	led_r4On:	Prende el led de refrigerador 4�
		@param 	none.
		@return none.
************************************************************************/
void led_r4On(void)
{
	TRIO1_ON 
	COMC_OFF
}


/************************************************************************	
		@brief 	led_r2On:	Prende el led de refrigerador 2�
		@param 	none.
		@return none.
************************************************************************/
void led_r2On(void)
{
	TRIO2_ON 
	COMA_OFF 
}


/************************************************************************	
		@brief 	led_r0On:	Prende el led de refrigerador 0�
		@param 	none.
		@return none.
************************************************************************/
void led_r0On(void)
{
	TRIO2_ON 
	COMB_OFF
}


/************************************************************************	
		@brief 	led_f24On:	Prende el led de freezer -24�
		@param 	none.
		@return none.
************************************************************************/
void led_f24On(void)
{
	TRIO4_ON 
	COMC_OFF 
}


/************************************************************************	
		@brief 	led_f22On:	Prende el led de freezer -22�
		@param 	none.
		@return none.
************************************************************************/
void led_f22On(void)
{
	TRIO3_ON 
	COMC_OFF 
}


/************************************************************************	
		@brief 	led_f20On:	Prende el led de freezer -20�
		@param 	none.
		@return none.
************************************************************************/
void led_f20On(void)
{
	TRIO3_ON 
	COMB_OFF
}


/************************************************************************	
		@brief 	led_f18On:	Prende el led de freezer -18�
		@param 	none.
		@return none.
************************************************************************/
void led_f18On(void)
{
	TRIO3_ON 
	COMA_OFF
}


/************************************************************************	
		@brief 	led_f16On:	Prende el led de freezer -16�
		@param 	none.
		@return none.
************************************************************************/
void led_f16On(void)
{
	TRIO2_ON 
	COMC_OFF 
}
	

/************************************************************************	
		@brief 	led_ffOn: Prende el led de fast freezing
		@param 	none.
		@return none.
************************************************************************/
void led_ffOn(void)
{
	TRIO4_ON 
	COMA_OFF
}


/************************************************************************	
		@brief 	led_alarmOn: Prende el led de alarma
		@param 	none.
		@return none.
************************************************************************/
void led_alarmOn(void)
{
	TRIO4_ON 
	COMB_OFF
}


/************************************************************************	
		@brief 	led_allROn: Prende todos los led del refrigerador
		@param 	none.
		@return none.
************************************************************************/
void led_allROn(void);


/************************************************************************	
		@brief 	led_allFOn: Prende todos los led del freezer
		@param 	none.
		@return none.
************************************************************************/
void led_allFOn(void);


/************************************************************************	
		@brief 	led_allOn: Prende todos los leds
		@param 	none.
		@return none.
************************************************************************/
void led_allOn(void);


/*****************************************
**********  APAGADO DE LEDS **************
*****************************************/



/************************************************************************	
		@brief 	led_r8Off: Apaga el led de refrigerador 8�
		@param 	none.
		@return none.
************************************************************************/
void led_r8Off(void);


/************************************************************************	
		@brief 	led_r6Off: Apaga el led de refrigerador 6�
		@param 	none.
		@return none.
************************************************************************/
void led_r6Off(void);


/************************************************************************	
		@brief 	led_r4Off: Apaga el led de refrigerador 4�
		@param 	none.
		@return none.
************************************************************************/
void led_r4Off(void);


/************************************************************************	
		@brief 	led_r2Off: Apaga el led de refrigerador 2�
		@param 	none.
		@return none.
************************************************************************/
void led_r2Off(void);


/************************************************************************	
		@brief 	led_r0Off: Apaga el led de refrigerador 0�
		@param 	none.
		@return none.
************************************************************************/
void led_r0Off(void);


/************************************************************************	
		@brief 	led_f24Off: Apaga el led de freezer -24�
		@param 	none.
		@return none.
************************************************************************/
void led_f24Off(void);

/************************************************************************	
		@brief 	led_f22Off: Apaga el led de freezer -22�
		@param 	none.
		@return none.
************************************************************************/
void led_f22Off(void);

/************************************************************************	
		@brief 	led_f20Off: Apaga el led de freezer -20�
		@param 	none.
		@return none.
************************************************************************/
void led_f20Off(void);

/************************************************************************	
		@brief 	led_f18Off: Apaga el led de freezer -18�
		@param 	none.
		@return none.
************************************************************************/
void led_f18Off(void);

/************************************************************************	
		@brief 	led_f16Off: Apaga el led de freezer -16�
		@param 	none.
		@return none.
************************************************************************/
void led_f16Off(void);

/************************************************************************	
		@brief 	led_allROff: Apaga los led de refrigerador
		@param 	none.
		@return none.
************************************************************************/
void led_allROff(void);

/************************************************************************	
		@brief 	led_allFOff: Apaga los led de freezer
		@param 	none.
		@return none.
************************************************************************/
void led_allFOff(void);

/************************************************************************	
		@brief 	led_allOff: Apaga todos los leds
		@param 	none.
		@return none.
************************************************************************/
void led_allOff(void)
{
	TRIO4_OFF 
	TRIO3_OFF 
	TRIO2_OFF 
	TRIO1_OFF 
	COMA_ON 
	COMB_ON 
	COMC_ON 
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
