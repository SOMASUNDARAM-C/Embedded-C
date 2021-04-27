#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned SEAT_OCCUPANCY = 0;
volatile unsigned SWITCH_STATE = 0;

void ports(void)
{
    sei();
    DDRB |= (1 << PB1); //Set B0 bit in DDRB register(to make it as output)

    DDRD &= ~(1 << PD0); //Clear D0 bit in DDRD register(to make it as input)
    DDRC &= ~(1 << PC6); //Clear D4 bit in DDRD register(to make it as input)
    PORTD |= (1 << PD0); //Set D0 bit in PORTD register(initial value 1)
    PORTC |= (1 << PC6); //Set D4 bit in PORTD register(initial value 1)

    PCICR |= (1 << PCIE2) | (1 << PCIE1);
    PCMSK2 |= (1 << PCINT16);
    PCMSK1 |= (1 << PCINT14);

}

int LED_state(void)
{
    ports();
    uint16_t LED = 0;
    while(1)
    {
        if(SEAT_OCCUPANCY == 1 && SWITCH_STATE == 1)
        {
            PORTB |= (1 << PB1);
            LED = 1;
            continue;
        }
        else
        {
            PORTB &= ~(1 << PB1);
            LED = 0;
        }
    }


    return LED;
}

ISR(PCINT1_vect)
{
    if(!(PINC & (1 << PINC6)))
        SEAT_OCCUPANCY = 1;
    else
        SEAT_OCCUPANCY = 0;
}

ISR(PCINT2_vect)
{
    if(!(PIND & (1 << PIND0)))
        SWITCH_STATE = 1;
    else
        SWITCH_STATE = 0;
}