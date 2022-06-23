#include "step.h"
#include "gpio.h"

void stepper_turn(int tim, float angle, float subdivide, uint8_t dir)
{
    int n,i;
    n = (int)(angle/(1.9/subdivide));
    if(dir == 'CW')
    {
        HAL_GPIO_WritePin(DIR1_GPIO_Port,DIR1_Pin,GPIO_PIN_SET);
    }
    else if(dir = 'CCW')
    {
        HAL_GPIO_WritePin(DIR1_GPIO_Port,DIR1_Pin,GPIO_PIN_RESET);
    }

    HAL_GPIO_WritePin(EN1_GPIO_Port,EN1_Pin,GPIO_PIN_RESET);

    for(i=0;i<n;i++)
    {
        HAL_GPIO_WritePin(STP1_GPIO_Port,STP1_Pin,GPIO_PIN_SET);
        HAL_Delay(tim/2);
        HAL_GPIO_WritePin(STP1_GPIO_Port,STP1_Pin,GPIO_PIN_RESET);
        HAL_Delay(tim/2);
    }
    HAL_GPIO_WritePin(EN1_GPIO_Port,EN1_Pin,GPIO_PIN_SET);
}
void STEP1_turn_CW(int times)
{
    int i = 0;
    HAL_GPIO_WritePin(EN1_GPIO_Port,EN1_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(DIR1_GPIO_Port,DIR1_Pin,GPIO_PIN_SET);
    for(i=0;i<times;i++)
    {
    HAL_GPIO_WritePin(STP1_GPIO_Port,STP1_Pin,GPIO_PIN_SET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(STP1_GPIO_Port,STP1_Pin,GPIO_PIN_RESET);
    HAL_Delay(1);
    }
}

void SETP1_turn_CCW(int times)
{
    int i = 0;
    HAL_GPIO_WritePin(EN1_GPIO_Port,EN1_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(DIR1_GPIO_Port,DIR1_Pin,GPIO_PIN_RESET);
    for(i=0;i<times;i++)
    {
    HAL_GPIO_WritePin(STP1_GPIO_Port,STP1_Pin,GPIO_PIN_SET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(STP1_GPIO_Port,STP1_Pin,GPIO_PIN_RESET);
    HAL_Delay(1);
    }
}

void STEP2_turn_CW(int times)
{
    int i = 0;
    HAL_GPIO_WritePin(EN2_GPIO_Port,EN2_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(DIR2_GPIO_Port,DIR2_Pin,GPIO_PIN_SET);
    for(i=0;i<times;i++)
    {
        HAL_GPIO_WritePin(STP2_GPIO_Port,STP2_Pin,GPIO_PIN_SET);
        HAL_Delay(1);
        HAL_GPIO_WritePin(STP2_GPIO_Port,STP2_Pin,GPIO_PIN_RESET);
        HAL_Delay(1);
    }
}

void STEP2_turn_CCW(int times)
{
    int i = 0;
    HAL_GPIO_WritePin(EN2_GPIO_Port,EN2_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(DIR2_GPIO_Port,DIR2_Pin,GPIO_PIN_RESET);
    for(i=0;i<times;i++)
    {
        HAL_GPIO_WritePin(STP2_GPIO_Port,STP2_Pin,GPIO_PIN_SET);
        HAL_Delay(1);
        HAL_GPIO_WritePin(STP2_GPIO_Port,STP2_Pin,GPIO_PIN_RESET);
        HAL_Delay(1);
    }
}

void BUSH_MOTOR_CW(int times)
{
    int i = 0;
    for(i=0;i<times;i++)
    {
        HAL_GPIO_WritePin(BRUSH_EN1_GPIO_Port,BRUSH_EN1_Pin,GPIO_PIN_SET);
        HAL_GPIO_WritePin(BRUSH_EN2_GPIO_Port,BRUSH_EN2_Pin,GPIO_PIN_RESET);
    }
    HAL_GPIO_WritePin(BRUSH_EN1_GPIO_Port,BRUSH_EN1_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(BRUSH_EN2_GPIO_Port,BRUSH_EN2_Pin,GPIO_PIN_RESET);
}

void BUSH_MOTOR_CCW(int times)
{
    int i = 0;
    for(i=0;i<times;i++)
    {
        HAL_GPIO_WritePin(BRUSH_EN1_GPIO_Port,BRUSH_EN1_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(BRUSH_EN2_GPIO_Port,BRUSH_EN2_Pin,GPIO_PIN_SET);
    }
    HAL_GPIO_WritePin(BRUSH_EN1_GPIO_Port,BRUSH_EN1_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(BRUSH_EN2_GPIO_Port,BRUSH_EN2_Pin,GPIO_PIN_RESET);
}

void MOVE_MOTOR_CW(int times)
{
    int i=0;
    for(i=0;i<times;i++)
    {
        HAL_GPIO_WritePin(MOVE_EN1_GPIO_Port,MOVE_EN1_Pin,GPIO_PIN_SET);
        HAL_GPIO_WritePin(MOVE_EN2_GPIO_Port,MOVE_EN2_Pin,GPIO_PIN_RESET);
    }
    HAL_GPIO_WritePin(MOVE_EN1_GPIO_Port,MOVE_EN1_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(MOVE_EN2_GPIO_Port,MOVE_EN2_Pin,GPIO_PIN_RESET);
}

void MOVE_MOTOR_CCW(int times)
{
    int i=0;
    for(i=0;i<times;i++)
    {
        HAL_GPIO_WritePin(MOVE_EN1_GPIO_Port,MOVE_EN1_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(MOVE_EN2_GPIO_Port,MOVE_EN2_Pin,GPIO_PIN_SET);
    }
    HAL_GPIO_WritePin(MOVE_EN1_GPIO_Port,MOVE_EN1_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(MOVE_EN2_GPIO_Port,MOVE_EN2_Pin,GPIO_PIN_RESET);
}
