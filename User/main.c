#include "stm32f10x.h"
#include <stdio.h>

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void RCC_Config(void);
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  ��ѭ��
  * @param  None
  * @retval None
  */
int main(void)
{
    //��ʼ��Systick
    RCC_Config();
    
    while (1)
    {
        
    }
}

/**
  * @brief  ��ʼ��ʱ�ӣ���ҪΪ�˳�ʼ��Systick
  * @param  None
  * @retval None
  */
void RCC_Config(void)
{
    //Systickʱ��ÿ1ms����һ��
  	if (SysTick_Config(SystemCoreClock / 1000))
  	{ 
    	//
   	 	while (1);
  	}  
}
/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
