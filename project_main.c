/**
 * @file project_main.c
 * @author Somasundaram.C 
 * @brief Project to control the seat temperature in an automobile
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#define F_CPU 16000000UL   ///Processor speed of 16MHz
#include <avr/io.h>
#include <util/delay.h>
#include "ADC_activity.h"
#include "LED_activity.h"
#include "PWM_activity.h"
#include "USART_activity.h"

int main()
{
	uint16_t temp = 0;
	int LED = 0;

    ///Calling initializing functions
	InitADC();
    USARTInit();
    ports_init();
    
    while(1)
    {
        ///Chck for switch statuses and turn on/off the LED
	    if(SEAT_OCCUPANCY == 1 && SWITCH_STATE == 1)
        {
            PORTB |= (1 << PB0);
            LED = 1;
        }
        else
        {
            PORTB &= ~(1 << PB0);
            LED = 0;
        }

        if(LED == 1)
        {
            temp = PWM_output(Read_ADC(0));  ///Read ADC input and generate appropriate PWM output
            USARTWriteChar(temp);  ///Write temperature value to serial monitor
            _delay_ms(200);
        }
        else
        {
            PWM_output(2000);   ///Function call to produce 0 PWM output
        }
    }
    return 0;
}
