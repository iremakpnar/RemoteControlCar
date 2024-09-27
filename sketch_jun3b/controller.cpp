#include <Arduino.h>
#include "timer1.h"
#include "controller.h"
#include "uzakliksnsr.h"


char motorQueue;
char motorDone;
char cmd;
char son_islem;


void controllerKurulum(void){
  motorQueue=0;
  motorDone=0;
  son_islem=0;
  cmd=0;


  pinMode(sol_ileri, OUTPUT);
  pinMode(sol_geri, OUTPUT);
  pinMode(sag_ileri,OUTPUT);
  pinMode(sag_geri,OUTPUT);
}

void controllerDongu(void){
  if(motorDone==1){
    return;
  }
  if(motorQueue==0){
    dur();
    motorQueue++;
  }
  else if(motorQueue<2){
    if(cmd == btnIleri){
      ileri();
      son_islem=1;
    }
    else if(cmd == btnGeri){
      geri();
      son_islem=2;
    }
    else if(cmd == btnSol){
      sol();
      son_islem=3;
    }
    else if(cmd == btnSag){
      sag();
      son_islem=4;
    }
    else if(cmd== btnDur){
      dur();
      son_islem=0;
    }
    motorQueue++;
    motorDone=1;
  }
}



void motorCmd(char iCmd){
  cmd=iCmd;
  if(keyPresed){
   return;
  }
  switch(cmd){
    case btnIleri : 
      motorQueue=0;
      motorDone=0;
      break;
    case btnGeri: 
      motorQueue=0;
      motorDone=0;
      break;
    case btnSol : 
      motorQueue=0;
      motorDone=0;
      break;
    case btnSag : 
      motorQueue=0;
      motorDone=0;
      break;
  }
}
void ileri(){
  digitalWrite(sol_ileri, 1);
  digitalWrite(sol_geri, 0);
  digitalWrite(sag_ileri, 1);
  digitalWrite(sag_geri, 0);
  analogWrite(sol_hiz, 255);
  analogWrite(sag_hiz, 255);
  }

void geri(){
  digitalWrite(sol_ileri, 0);
  digitalWrite(sol_geri, 1);
  digitalWrite(sag_ileri, 0);
  digitalWrite(sag_geri, 1);
  analogWrite(sol_hiz, 255);
  analogWrite(sag_hiz, 255);
}

void sag(){
  digitalWrite(sol_ileri, 0);
  digitalWrite(sol_geri, 1);
  digitalWrite(sag_ileri, 1);
  digitalWrite(sag_geri, 0);
  analogWrite(sol_hiz, 255);
  analogWrite(sag_hiz, 150);
}

void sol(){
  digitalWrite(sol_ileri, 1);
  digitalWrite(sol_geri, 0);
  digitalWrite(sag_ileri, 0);
  digitalWrite(sag_geri, 1);
  analogWrite(sol_hiz, 255);
  analogWrite(sag_hiz, 255);
}


void dur(){
  digitalWrite(sol_ileri, 0);
  digitalWrite(sol_geri, 0);
  digitalWrite(sag_ileri, 0);
  digitalWrite(sag_geri, 0);
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
