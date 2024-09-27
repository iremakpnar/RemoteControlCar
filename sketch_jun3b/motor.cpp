/*
#include <Arduino.h>
#include "motor.h"

char motorQueue;
char motorDone;
int motorlar_hiz;
char cmd;
char son_islem;

void Initmotor(void){
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
}

void motorTask(void){
  if(motorDone==1){
    return;
  }
  if(motorQueue==0){
    dur();
    motorQueue++;
  }
  else if(motorQueue<2){
    if(cmd=='w'){
      ileri();
      son_islem= 1;
    }
    else if(cmd == 's'){
      geri();
      son_islem =2;
    }

    else if(cmd=='a'){
      sol();
      son_islem=3;
    }

    else if(cmd =='d'){
      sag();
      son_islem=4;
    }

    else if(cmd=='q'){                //  BU KOD İF DONGUSU DISINDA MI YAZILMALI ?
      if(motorlar_hiz>50)
          motorlar_hiz-=50;
      else
          motorlar_hiz=50;
     
      // motorlar_hiz = motorlar_hiz-25;
      // if(motorlar_hiz<0){
      //   motorlar_hiz=0;
      // }

      analogWrite(sol_hiz, motorlar_hiz);
      analogWrite(sag_hiz, motorlar_hiz);
    }

    else if(cmd=='x'){
      dur();
    }

    else if(cmd=='e'){                //  BU KOD İF DONGUSU DISINDA MI YAZILMALI ?
        if(motorlar_hiz<250)
          motorlar_hiz+=50;
        else
          motorlar_hiz=250;

      // motorlar_hiz = motorlar_hiz+25;
      // if(motorlar_hiz > 255){
      //   motorlar_hiz=255;
      // }
      
      analogWrite(sol_hiz, motorlar_hiz);
      analogWrite(sag_hiz, motorlar_hiz);
    }
    motorQueue++;
    motorDone=1;
  }
}

void motorCmd(char iCmd){
  cmd=iCmd;
  switch(cmd){
    case 'e': 
      motorQueue=1;
      motorDone=0;
      break;
    case 'w': 
      motorQueue=0;
      motorDone=0;
      break;
    case 's': 
      motorQueue=0;
      motorDone=0;
      break;
    case 'a': 
      motorQueue=0;
      motorDone=0;
      break;
    case 'd': 
      motorQueue=0;
      motorDone=0;
      break;
    case 'q': 
      motorQueue=1;
      motorDone=0;
      break;
    case 'x': 
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

void son_isleme_devam_et(){
  if(son_islem==1){
    ileri();
  }
  else if(son_islem==2){
    geri();
  }
  else if(son_islem==3){
    sol();
  }
  else if(son_islem==4){
    sag();
  }
}

*/