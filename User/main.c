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
  * @brief  主循环
  * @param  None
  * @retval None
  */
int main(void)
{
    //初始化Systick
    RCC_Config();
    
    while (1)
    {
        
    }
}

/**
  * @brief  初始化时钟，主要为了初始化Systick
  * @param  None
  * @retval None
  */
void RCC_Config(void)
{
    //Systick时钟每1ms触发一次
  	if (SysTick_Config(SystemCoreClock / 1000))
  	{ 
    	//
   	 	while (1);
  	}  
}
/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
