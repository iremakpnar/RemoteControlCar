/*
#include <IRRemoteControl.h>
#include <IRRemoteControlInt.h>
#include <IRremote.h>
#include <Arduino.h>
#include "kumanda.h"

char motorQueue;
char motorDone;
int motorlar_hiz;
char cmd;
char son_islem;

IRrecv irrecv(irPin);
decode_results results;

void irKurulum(){
  motorQueue=0;
  motorDone=0;
  motorlar_hiz=255;
  son_islem=0;
  cmd=0;
  pinMode(sol_ileri, OUTPUT);
  pinMode(sol_geri, OUTPUT);
  pinMode(sol_hiz, OUTPUT);
  pinMode(sag_ileri,OUTPUT);
  pinMode(sag_geri,OUTPUT);
  pinMode(sag_hiz,OUTPUT);

  digitalWrite(sol_ileri, LOW);
  digitalWrite(sol_geri, LOW);
  digitalWrite(sag_ileri, LOW);
  digitalWrite(sag_geri, LOW);
  digitalWrite(sol_hiz, LOW);
  digitalWrite(sag_hiz, LOW);

  irrecv.enableIRIn();
}

void irDongu(){
  if(motorDone==1){
    return;
  }
  if(motorQueue==0){
    dur();
    motorQueue++;
  }
  else if(motorQueue<2){

    if(irrecv.decode(&results)){

      if(results.value == BTN2){
        ileri();
        son_islem=1;
      }
      else if(results.value == BTN8){
        geri();
        son_islem=2;
      }
      else if(results.value == BTN4){
        sol();
        son_islem=3;
      }
      else if(results.value == BTN6){
        sag();
        son_islem=4;
      }
      else if(results.value == BTN0){
        dur();
        
      }
      else if(results.value == VOLN){
        if(motorlar_hiz>75){
          motorlar_hiz = motorlar_hiz - 25;
        }
        else{
          motorlar_hiz = 75;
        }
      }
      else if(results.value == VOLP){
        if(motorlar_hiz<255){
          motorlar_hiz = motorlar_hiz + 25;
        }
        else{
          motorlar_hiz= 255;
        }
      }
    }
    motorQueue++;
    motorDone=1;
  }
}


void motorCmd(char iCmd){
  cmd=iCmd;
  switch(cmd){
    case VOLP: 
      motorQueue=1;
      motorDone=0;
      break;
    case BTN2 : 
      motorQueue=0;
      motorDone=0;
      break;
    case BTN8 : 
      motorQueue=0;
      motorDone=0;
      break;
    case BTN4 : 
      motorQueue=0;
      motorDone=0;
      break;
    case BTN6 : 
      motorQueue=0;
      motorDone=0;
      break;
    case VOLN : 
      motorQueue=1;
      motorDone=0;
      break;
    case BTN0 : 
      motorQueue=1;
      motorDone=0;
      break;
  }
}

void ileri(){
  digitalWrite(sol_ileri,1);
  digitalWrite(sag_ileri,1);
  digitalWrite(sol_geri,0);
  digitalWrite(sag_geri,0);
  analogWrite(sol_hiz, motorlar_hiz);
  analogWrite(sag_hiz, motorlar_hiz);
}

void geri(){
  digitalWrite(sol_geri,1);
  digitalWrite(sag_geri,1);
  digitalWrite(sol_ileri,0);
  digitalWrite(sag_ileri,0);
  analogWrite(sol_hiz, motorlar_hiz);
  analogWrite(sag_hiz, motorlar_hiz);
}

void sag(){
  digitalWrite(sol_geri, 1);
  digitalWrite(sag_geri, 0);
  digitalWrite(sol_ileri, 0);
  digitalWrite(sag_ileri, 1);
  analogWrite(sol_hiz, motorlar_hiz);
  analogWrite(sag_hiz, motorlar_hiz);
}

void sol(){
  digitalWrite(sol_geri, 0);
  digitalWrite(sag_geri, 1);
  digitalWrite(sol_ileri, 1);
  digitalWrite(sag_ileri, 0);
  analogWrite(sol_hiz, motorlar_hiz);
  analogWrite(sag_hiz, motorlar_hiz);
}

void dur(){
  digitalWrite(sol_geri, 0);
  digitalWrite(sag_geri, 0);
  digitalWrite(sol_ileri, 0);
  digitalWrite(sag_ileri, 0);
  analogWrite(sol_hiz, 0);
  analogWrite(sag_hiz, 0);
}



/*

IRrecv irrecv(irPin);
decode_results results;

void irKurulum(){
  irrecv.enableIRIn();
}

void irDongu(){
  if(irrecv.decode(&results)){

    if(results.value == BTN2){
      ileri();
      son_islem=1;
    }
    else if(results.value == BTN8){
      geri();
      son_islem=2;
    }
    else if(results.value == BTN4){
      sol();
      son_islem=3;
    }
    else if(results.value == BTN6){
      sag();
      son_islem=4;
    }
    else if(results.value == BTN0){
      dur();
      
    }
    else if(results.value == VOLN){
      if(motorlar_hiz>75){
        motorlar_hiz = motorlar_hiz - 25;
      }
      else{
        motorlar_hiz = 75;
      }
    }
    else if(results.value == VOLP){
      if(motorlar_hiz<255){
        motorlar_hiz = motorlar_hiz + 25;
      }
      else{
        motorlar_hiz= 255;
      }
    }
  }
}
*/