#ifndef __STEP_H__
#include "stdint.h"

void stepper_turn(int tim, float angle, float subdivide, uint8_t dir);
void STEP1_turn_CW(int times);

#endif