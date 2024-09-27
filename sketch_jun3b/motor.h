/*
#ifndef MOTOR_H_
#define MOTOR_H_


#define sol_ileri 7
#define sol_geri 8 
#define sol_hiz 9
#define sag_ileri 12
#define sag_geri 10
#define sag_hiz 11


extern char motorQueue;
extern char motorDone;
extern int motorlar_hiz;
extern char son_islem;
extern char cmd;

extern void Initmotor(void);
extern void motorTask(void);
extern void motorCmd(char iCmd);
extern void sag();
extern void sol();
extern void ileri();
extern void geri();
extern void dur();
extern void son_isleme_devam_et();
#endif
*/