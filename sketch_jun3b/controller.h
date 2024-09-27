
#ifndef CONTROLLER_H_
#define CONTROLLER_H_


#define sol_ileri 7
#define sol_geri 8 
#define sol_hiz 9
#define sag_ileri 11
#define sag_geri 10
#define sag_hiz 12

#define btnIleri 1
#define btnGeri 2
#define btnSag 3
#define btnSol 4
#define btnDur 5

extern char motorQueue;
extern char motorDone;
extern char son_islem;
extern char cmd;


extern void controllerKurulum(void);
extern void controllerDongu(void);
extern void motorCmd(char iCmd);
extern void ileri();
extern void geri();
extern void sag();
extern void sol();
extern void dur();
extern void son_isleme_devam_et();

#endif

