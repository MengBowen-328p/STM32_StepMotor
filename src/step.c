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
        HAL_GPIO_WritePin(STP3_GPIO_Port,STP3_Pin,GPIO_PIN_SET);
        HAL_Delay(1);
        HAL_GPIO_WritePin(STP3_GPIO_Port,STP3_Pin,GPIO_PIN_RESET);
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
        HAL_GPIO_WritePin(STP3_GPIO_Port,STP3_Pin,GPIO_PIN_SET);
        HAL_Delay(1);
        HAL_GPIO_WritePin(STP3_GPIO_Port,STP3_Pin,GPIO_PIN_RESET);
        HAL_Delay(1);
    }
}
