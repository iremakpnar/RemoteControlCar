#include "HardwareSerial.h"
#include <Arduino.h>
#include "uzakliksnsr.h"
#include "controller.h"

int maximumRange;
int minimumRange;
int dly;
int dly_cntr;
int melodi_step;
int meloditimer_flag;
int melodi_active;
int olcum; 
long duration;
long distance;

void uzaklikKurulum(){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  maximumRange=50;
  minimumRange=0;
  melodi_step=0;
  melodi_active=0;
  meloditimer_flag=0;
  dly_cntr=0;
  olcum=0; 
  distance=0;                                            
}


void sensorDongu(){
  olcum = mesafe(maximumRange, minimumRange);
  //Serial.print(olcum);
  //Serial.println();
  if(olcum< maximumRange && olcum> 0){
    melodi_active=1 ;
    dly = olcum*10;
  }
  else{
    melodi_active=0;
    melodi_step=0;
    dly=0;
  }
}

int mesafe(int maxRange, int minRange){

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*563)>>15;

  if(distance >= maxRange || distance <= minRange)
    return 0;
  if (distance < 10 && distance > 0) {
    //dur();
  }
  return distance;
}


void melodi(void){
  if(melodi_active!=1){
    digitalWrite(buzzerPin, LOW);
    return;
  }
  switch (melodi_step){
    case 1:
      digitalWrite(buzzerPin, HIGH);
      break;
    case 2:
      digitalWrite(buzzerPin, LOW);
      break;
  }

}






