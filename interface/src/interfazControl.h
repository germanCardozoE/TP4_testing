/**
  ******************************************************************************
  * File Name         : interfazControl.c
  * Description       : Este archivo tiene los defines para la interfaz
  ******************************************************************************
  * @autor            : Germ�n E. Cardozo
  * @date             : 03/06/2021
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
#include "definesGral.h"


#define DEFAULT_LED_ON 2 // cantidad de leds prendidos por defecto.


//retorna cuantos leds se deben prender 2,3 o 4
uint8_t interfaz_setMaxCont(uint8_t, bool_t);

//setea valores iniciales
void interfaz_init(void);

//control geenral de interfaz
void interfaz_control(uint8_t * ,uint8_t * ,bool_t * ,uint8_t *);

//lectura de los pulsadores
void interfaz_leeTeclas(uint8_t *,uint8_t *,bool_t *);

//habilita lectura de teclas
void interfaz_teclasDelayOn(void);

//deshabilita lectura de teclas
void interfaz_teclasDelayOff(void);

//devuelve el estado del delay de lectura de teclas
bool_t interfaz_getDelayTeclas(void);

//escritura de los leds acorde a los niveles,FF y alarma
void interfaz_escribeLeds(uint8_t ,uint8_t,bool_t,uint8_t);	

//elige como prende el indicador de alarma
uint8_t interfaz_alarmOnSelection(uint8_t);

//--------------- FIN DE ARCHIVO ---------------------------
