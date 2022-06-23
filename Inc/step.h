#ifndef __STEP_H__
#include "stdint.h"

void stepper_turn(int tim, float angle, float subdivide, uint8_t dir);
void STEP1_turn_CW(int times);  //步进电机1正转
void SETP1_turn_CCW(int times); //步进电机1反转
void STEP2_turn_CW(int times);  //步进电机2正转
void STEP2_turn_CCW(int times); //步进电机2反转
void BUSH_MOTOR_CW(int times);  //刷子电机正转
void BUSH_MOTOR_CCW(int times); //刷子电机反转
void MOVE_MOTOR_CW(int times);  //丝杆电机正转
void MOVE_MOTOR_CCW(int times); //丝杆电机反转



#endif