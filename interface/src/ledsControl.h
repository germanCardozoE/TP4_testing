/**
  ******************************************************************************
  * File Name         : timerControl.c
  * Description       : This file define the ledsControl functions and defines
  ******************************************************************************
  * @autor            : Germ�n E. Cardozo
  * @date             : 03/06/2021
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
#include "definesGral.h"

typedef struct{
	uint32_t periodoMseg;    //periodo de titileo
	uint32_t myMseg;			   //contador interno para titileo
	void (* ledON)(); 
	void (* ledOff)();
}led_t;


/*****************************************
**********  ENCENDIDO DE LEDS  ***********
*****************************************/

//Prende el led de refrigerador seleccionado
void led_refriOn(uint8_t);

//Prende el led de freezer seleccionado
void led_freezerOn(uint8_t);

//Prende el led de refrigerador 8�
void led_r8On(void);

//Prende el led de refrigerador 6�
void led_r6On(void);

//Prende el led de refrigerador 4�
void led_r4On(void);

//Prende el led de refrigerador 2�
void led_r2On(void);

//Prende el led de refrigerador 0�
void led_r0On(void);

//Prende el led de freezer -24�
void led_f24On(void);

//Prende el led de freezer -22�
void led_f22On(void);

//Prende el led de freezer -20�
void led_f20On(void);

//Prende el led de freezer -18�
void led_f18On(void);

//Prende el led de freezer -16�
void led_f16On(void);

//Prende todos los leds de refrigerador
void led_allROn(void);

//Prende todos los leds de freezer
void led_allFOn(void);

//Prende todos los leds
void led_allOn(void);

//Prende el led de fast freezing
void led_ffOn(void);

//Prende el led de alarma
void led_alarmOn(void);


/*****************************************
**********  APAGADO DE LEDS **************
*****************************************/


//Apaga el led de refrigerador 8�
void led_r8Off(void);

//Apaga el led de refrigerador 6�
void led_r6Off(void);

//Apaga el led de refrigerador 4�
void led_r4Off(void);

//Apaga el led de refrigerador 2�
void led_r2Off(void);

//Apaga el led de refrigerador 0�
void led_r0Off(void);

//Apaga el led de freezer -24�
void led_f24Off(void);

//Apaga el led de freezer -22�
void led_f22Off(void);

//Apaga el led de freezer -20�
void led_f20Off(void);

//Apaga el led de freezer -18�
void led_f18Off(void);

//Apaga el led de freezer -16�
void led_f16Off(void);

//Apaga el led de fast freezing
void led_ffOff(void);

//Apaga el led de alarma
void led_alarmOff(void);

//Apaga todos los leds de refrigerador
void led_allROff(void);

//Apaga todos los leds de freezer
void led_allFOff(void);

//Apaga todos los leds
void led_allOff(void);


//----------FIN--------------
