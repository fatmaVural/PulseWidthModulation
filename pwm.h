/* 
 * File:   pwm.h
 * Author: fatma
 *
 * Created on 04 Ekim 2019 Cuma, 21:26
 */

#ifndef PWM_H
#define	PWM_H

#include <stdint.h>
void Pwm1_Start();
void Pwm1_Duty(uint16_t duty );
void Pwm1_Init(long frequency);
#endif	/* PWM_H */

