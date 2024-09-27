#ifndef UZAKLIKSNSR_H_
#define UZAKLIKSNSR_H_

#define buzzerPin 4
#define echoPin 5
#define trigPin 6

extern int maximumRange;
extern int minimumRange;
extern int olcum; 
extern int maxRange;
extern int minRange;
extern long duration;
extern long distance;
extern int dly;
extern int dly_cntr;
extern int melodi_step;
extern int meloditimer_flag;
extern int melodi_active;

extern void uzaklikKurulum(void);
extern void sensorDongu(void);
extern int mesafe(int maxRange, int minRange);
extern void melodi(void);
#endif