/**
 * @file project_main.c
 * @author Somasundaram.C ()
 * @brief Project to control the seat temperature in an automobile
 * @version 0.1
 * @date 2021-04-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>
#include <util/delay.h>
#include <ADC_activity.h>
#include <LED_activity.h>

int main()
{
	uint16_t temp = 0;
	int LED = 0;
	InitADC();
    
    while(1)
	LED = LED_state();
    if(LED == 1)
    {
        temp = Read_ADC(0);
        _delay_ms(200);
    }
    return 0;
}
