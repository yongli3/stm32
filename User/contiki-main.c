/*
#include <stm32f10x_map.h>
#include <stm32f10x_dma.h>
#include <gpio.h>
#include <nvic.h>
*/

//Ìæ»»Í·ÎÄ¼þ
#include "stm32f10x.h"

#include <stdint.h>
#include <stdio.h>

#include <debug-uart.h>
#include <clock.h>

#include <sys/process.h>
#include <sys/procinit.h>
#include <etimer.h>
#include <sys/autostart.h>

unsigned int idle_count = 0;

void led_init();

PROCESS(blink_process, "Blink");
AUTOSTART_PROCESSES(&blink_process);
PROCESS_THREAD(blink_process, ev, data)
{
  
  PROCESS_BEGIN();
  while(1) 
  {
    static struct etimer et;
    etimer_set(&et, CLOCK_SECOND);
    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));
    
    //LED on
    GPIO_ResetBits(GPIOA,GPIO_Pin_8);
    GPIO_ResetBits(GPIOD,GPIO_Pin_2);
    printf("LED ON\r\n");
    
    etimer_set(&et, CLOCK_SECOND);
    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));
    
    //LED off
    GPIO_SetBits(GPIOA,GPIO_Pin_8);
    GPIO_SetBits(GPIOD,GPIO_Pin_2);
    printf("LED OFF\r\n");
    
  }
   PROCESS_END();
}


int main()
{
  dbg_setup_uart();
  led_init();
  printf("Initialising\r\n");
  
  clock_init();
  process_init();
  process_start(&etimer_process, NULL);
  autostart_start(autostart_processes);
  //process_start(&blink_process,NULL);
  printf("Processes running\r\n");
  while(1) {
    do 
    {
    } 
    while(process_run() > 0);
    idle_count++;
    /* Idle! */
    /* Stop processor clock */
    /* asm("wfi"::); */ 
  }
  return 0;
}

// LED0=PA8 LED1=PD2
void led_init()
{
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOD,ENABLE);

  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
}