/*
 * File:   pwm.c
 * Author: fatma
 *
 * Created on 04 Ekim 2019 Cuma, 21:26
 */


#include <xc.h>
#include "pwm.h"
#define _XTAL_FREQ 4000000
#define TMR2PRESCALER  4

long freq = 1;
static double Pwm_Call_Duty(){
    
    return (_XTAL_FREQ/(freq*TMR2PRESCALER));
    
    
}
void Pwm1_Start(){
    //PWM Mode ON
   CCP1CONbits.CCP1M3=1;
   CCP1CONbits.CCP1M2=1;
 //kosullu derleme sat?rlar?yla kod kolaylasti  
#if TMR2PRESCALER ==1
   T2CKPS0=0;
   T2CKPS1=0;
#elif TMR2PRESCALER==4
   T2CKPS0=1;
   T2CKPS1=0;
#elif TMR2PRESCALER==16
   T2CKPS0=0;
   T2CKPS1=1;
#endif
   
   
   //timer settings
   T2CONbits.TMR2ON=1;
   TRISCbits.TRISC2=0;  //C?K?S AYARLAND?
}

void Pwm1_Duty(uint16_t duty){
    if(duty < 1024){
        duty=(double)duty/1023*Pwm_Call_Duty();
        CCP1X=duty&2;  //birinci bitini al
        CCP1Y=duty&1;  
        CCPR1L=duty>>2;
    
    }    
        
}
//PWM Period Frequency
void Pwm1_Init(long frequency){
    PR2=((_XTAL_FREQ)/(frequency*4*TMR2PRESCALER));
    freq=frequency;
    
}