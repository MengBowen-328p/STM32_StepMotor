#ifndef __STEP_H__
#include "stdint.h"

void stepper_turn(int tim, float angle, float subdivide, uint8_t dir);
void STEP1_turn_CW(int times);  //步进电机1正转
void SETP1_turn_CCW(int times); //步进电机1反转

#endif