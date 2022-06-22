#include "step.h"
#include "gpio.h"

void stepper_turn(int tim, float angle, float subdivide, uint8_t dir)
{
    int n,i;
    n = (int)(angle/(1.9/subdivide));
    if(dir == 'CW')
    {
        HAL_GPIO_WritePin(DIR_GPIO_Port,DIR_Pin,GPIO_PIN_SET);
    }
    else if(dir = 'CCW')
    {
        HAL_GPIO_WritePin(DIR_GPIO_Port,DIR_Pin,GPIO_PIN_RESET);
    }

    HAL_GPIO_WritePin(EN_GPIO_Port,EN_Pin,GPIO_PIN_RESET);

    for(i=0;i<n;i++)
    {
        HAL_GPIO_WritePin(STP_GPIO_Port,STP_Pin,GPIO_PIN_SET);
        HAL_Delay(tim/2);
        HAL_GPIO_WritePin(STP_GPIO_Port,STP_Pin,GPIO_PIN_RESET);
        HAL_Delay(tim/2);
    }
    HAL_GPIO_WritePin(EN_GPIO_Port,EN_Pin,GPIO_PIN_SET);
}