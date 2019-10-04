/*
 * File:   main.c
 * Author: fatma
 *SORU:CCP1 modulü kullan?larak RC2 baca??ndan periyodu 1 milisaniye,duty cycle 0.5 milisaniye olan
 * bir PWM sinyalini al?n?z.
 * Created on 04 Ekim 2019 Cuma, 20:58
 */


#include <xc.h>
#include"configBit.h"
#include "pwm.h"

int main() {
    
    Pwm1_Init(1000);
    Pwm1_Duty(512);
    Pwm1_Start();
    
    while(1){
        
    }
}
