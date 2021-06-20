//=====  INCLUDES  ============//
#include "unity.h"
#include "interfazControl.h"
#include "mock_teclasControl.h"
#include "mock_ledsControl.h"
//#include "MocktimerControl.h"


//=====  END OF INCLUDES  =====//


//=====  DEFINES  =============//
//=====  END OF DEFINES  ======//


//=====  VARIABLES  ===========//
  static uint8_t *nivR, *nivF;
  static bool_t *ffX;

//=====  END OF VARIABLES  ====//


//=====  FUNCTIONS  ===========//

void setUp(void){
}


//
void tearDown(void) {
}


// se verifica maxima cantidad de leds a prender (4)
void test_interfaz_setMaxCont_4ledsOn(void){
   static uint8_t alarma,val;
   static uint8_t FF; 
   alarma=1;
   FF=1;
      
   TEST_ASSERT_EQUAL_HEX8(4,interfaz_setMaxCont(alarma, FF) );
 }

// se verifica minima cantidad de leds a prender (2)
void test_interfaz_setMaxCont_2ledsOn(void){
   static uint8_t alarma,val;
   static uint8_t FF; 
   alarma=0;
   FF=0;
      
   TEST_ASSERT_EQUAL_HEX8(2,interfaz_setMaxCont(alarma, FF) );
 }

 // se verifica cantidad de leds a prender con un solo flag activo (3)
void test_interfaz_setMaxCont_3ledsOn(void){
   static uint8_t alarma,val;
   static uint8_t FF; 
   alarma=0;
   FF=1;
      
   TEST_ASSERT_EQUAL_HEX8(3,interfaz_setMaxCont(alarma, FF) );
 }


// corrobora la funcion que devuelve el estado del delay de lectura de teclas
void test_interfaz_getDelayTeclas(void){
  interfaz_init(); //al inicializar delayTeclas se pone en FALSE
  led_allFOn_Ignore();
  TEST_ASSERT_EQUAL(FALSE, interfaz_getDelayTeclas() );
 }



//lee tecla de Frio maximo pulsada
 /*la funcion no retorna y no recibe parametros
   pero internamenta modifica valores de variables locales a interfazControl.c
   como lo testeo???*/
void test_interfaz_leeTeclas(void){
  uint8_t nivR2=0,nivF2=0;
  bool_t ffX2=FALSE;

  //lee si hay teclas pulsadas 
  interfaz_leeTeclas(nivR2,nivF2,ffX2);
  tecla_FF_IgnoreAndReturn(TRUE);
  tecla_nivelR_IgnoreAndReturn(FALSE);
  tecla_nivelF_IgnoreAndReturn(FALSE);
  
  //ACA NECESITARIA OBTENER EL VALOR DE Las VARIABLES QUE VAN COMO PARAMETRO


  TEST_ASSERT_EQUAL(TRUE,ffX2);
  
}



//=====  END OF FUNCTIONS  ====//
//=====  END OF FILE  =========//