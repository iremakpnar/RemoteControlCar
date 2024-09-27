#include "timer1.h"
//#include "motor.h"
#include "uzakliksnsr.h"
#include "controller.h"


//#include "kumanda.h"
void setup() {

  Serial.begin(9600);
  InitializeTimer1();
  //Initmotor();
  uzaklikKurulum();
  controllerKurulum();
}

void loop() {
  if(flag_10ms)
  {
    flag_10ms= FALSE; 
    controllerDongu();
    mesafe(maximumRange, minimumRange);
    //motorTask();
    //irDongu();
  }
  if(flag_100ms){
    flag_100ms = FALSE;
    sensorDongu();
  }
  if(flag_500ms){
    flag_500ms =FALSE; 
  }
  if(flag_1000ms){
    flag_1000ms =FALSE;
  }
  if(meloditimer_flag){
    meloditimer_flag =FALSE;
    melodi();
  }
}

