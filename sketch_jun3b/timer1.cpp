#include "HardwareSerial.h"
#include <Arduino.h>

//#include "motor.h"
#include "timer1.h"
#include "uzakliksnsr.h"
#include "controller.h"


int timctr_10ms, timctr_100ms, timctr_500ms, timctr_1000ms, btnCtr;
char flag_10ms, flag_100ms, flag_500ms, flag_1000ms, btnFlag, keyPresed;
char komut = 0;


ISR(TIMER1_OVF_vect)
{
  TCNT1 = 49535; // Timer Preloading
  // Handle The Timer Overflow Interrupt
  //...
  if(timctr_10ms>=10){
    flag_10ms = TRUE;
    timctr_10ms=0;
    if(Serial.available() > 0){
      komut = Serial.read();
      Serial.write(komut);
    } 
    if(komut == 0x31 ){
      motorCmd(btnIleri); 
      btnCtr=0;
      keyPresed = 1;
    }
    
    else if(komut == 0x32){
      motorCmd(btnGeri); 
      btnCtr=0;
      keyPresed = 1;
    }

    else if(komut == 0x33){
      motorCmd(btnSol);
      btnCtr=0;
      keyPresed = 1;
    }

    else if(komut == 0x34){
      motorCmd(btnSag); 
      btnCtr=0;
      keyPresed = 1;
    }

    else if(komut== 0x35){
      motorCmd(btnDur);
      btnCtr=0;
      keyPresed = 1;
    }
    else{
      keyPresed = 0;
      if(motorDone && btnFlag){
        dur();
        btnFlag=0;
       // Serial.println("t");
      }
    } 
    komut = 0;
  } 
 
  if(timctr_100ms>=100){
    flag_100ms = TRUE;
    timctr_100ms=0;
  }
  if(timctr_500ms>=500){
    flag_500ms =TRUE;
    timctr_500ms=0;
  } 
  if(timctr_1000ms>=1000){
    flag_1000ms =TRUE;
    timctr_1000ms=0;
  }
  if(dly_cntr>dly){
    meloditimer_flag = TRUE;
    dly_cntr=0;
    melodi_step++;
    if(melodi_step>2){
      melodi_step=0;
    }
  }
  if(btnCtr > 300){
    btnFlag = TRUE;
    btnCtr=0;
  }


  btnCtr++;
  dly_cntr++;
  timctr_10ms++; 
  timctr_100ms++; 
  timctr_500ms++;
  timctr_1000ms++;
}


void InitializeTimer1(void)
{
  timctr_10ms=timctr_100ms=timctr_500ms=timctr_1000ms=0;
  flag_10ms= flag_100ms=flag_500ms=flag_1000ms=0;

  TCCR1A = 0;           // Init Timer1A
  TCCR1B = 0;           // Init Timer1B
  TCCR1B |= B00000001;  // Prescaler = 8
  TCNT1 = 49535;        // Timer Preloading
  TIMSK1 |= B00000001;  // Enable Timer Overflow Interrupt
}


