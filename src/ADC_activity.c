#include <avr/io.h>
#include <util/delay.h>

void InitADC(void)
{
    ADMUX |= (1 << REFS0);
    ADCSRA = (1 << ADEN);
    ADCSRA |= (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2);
    ADMUX &= 0xf8;
}

uint16_t Read_ADC(uint8_t ch)
{
    ch &= 0b00000111;
    ADMUX |= ch;
    ADCSRA |= (1 << ADSC);
    while(!(ADCSRA & (1 << ADIF)));
    ADCSRA |= (1 << ADIF);
    return ADC;
}