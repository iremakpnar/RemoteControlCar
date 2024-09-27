#ifndef TIMER1_H_
#define TIMER1_H_
#define TRUE 1
#define FALSE 0
extern int timctr_10ms, timctr_100ms, timctr_500ms, timctr_1000ms;
extern char flag_10ms, flag_100ms, flag_500ms, flag_1000ms, keyPresed;
extern void InitializeTimer1(void);
#endif
