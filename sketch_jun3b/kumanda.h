/*
#ifndef KUMANDA_H_
#define KUMANDA_H_

#define irPin 2
#define sol_ileri 7
#define sol_geri 8 
#define sol_hiz 9
#define sag_ileri 12
#define sag_geri 10
#define sag_hiz 11

#define CHN 0xE318261B
#define CH 0x511DBB
#define CHP 0xEE886D7F
#define PREV 0x52A3D41F
#define NEXT 0xFF02FD
#define PLAYPAUSE 0x20FE4DBB
#define VOLN 0xF076C13B
#define VOLP 0xA3C8EDDB
#define EQ 0xE5CFBD7F
#define BTN0 0xC101E57B
#define BTN100 0xFF9867
#define BTN200 0xF0C41643
#define BTN1 0xFF30CF
#define BTN2 0xFF18E7
#define BTN3 0x6182021B
#define BTN4 0x8C22657B
#define BTN5 0x488F3CBB
#define BTN6 0x449E79F
#define BTN7 0x32C6FDF7
#define BTN8 0xFF4AB5
#define BTN9 0x3EC3FC1B

extern char motorQueue;
extern char motorDone;
extern int motorlar_hiz;
extern char son_islem;
extern char cmd;


extern void irKurulum(void);
extern void irDongu(void);
extern void motorCmd(char iCmd);
extern void sag();
extern void sol();
extern void ileri();
extern void geri();
extern void dur();
extern void hiz_azalt();
extern void hiz_artir();
extern void son_isleme_devam_et();
#endif


/*
#ifndef IRREMOTE_H_
#define IRREMOTE_H_

#define irPin 2

#define CHN 0xE318261B
#define CH 0x511DBB
#define CHP 0xEE886D7F
#define PREV 0x52A3D41F
#define NEXT 0xFF02FD
#define PLAYPAUSE 0x20FE4DBB
#define VOLN 0xF076C13B
#define VOLP 0xA3C8EDDB
#define EQ 0xE5CFBD7F
#define BTN0 0xC101E57B
#define BTN100 0xFF9867
#define BTN200 0xF0C41643
#define BTN1 0xFF30CF
#define BTN2 0xFF18E7
#define BTN3 0x6182021B
#define BTN4 0x8C22657B
#define BTN5 0x488F3CBB
#define BTN6 0x449E79F
#define BTN7 0x32C6FDF7
#define BTN8 0xFF4AB5
#define BTN9 0x3EC3FC1B

extern void irKurulum(void);
extern void irDongu(void);

#endif
*/