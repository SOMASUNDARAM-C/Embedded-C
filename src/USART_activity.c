#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define BAUD 9600
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)  ///<Baudrate calculation

void USARTInit(void)
{
    ///Set baudrate
    UBRR0H |= (BAUDRATE >> 8);
    UBRR0L |= BAUDRATE;

    ///To set character size as 8 bits
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);

    ///Enable transmit and receive interrupts
    UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0) | (1 << TXCIE0);
}

char USARTReadChar(void)
{
    ///Wait to receive data
    while(!(UCSR0A & (1 << RXC0)));

    return UDR0;
}

void USARTWriteChar(char data)
{
    ///Wait to transmitt data
    while(!(UCSR0A & (1 << UDRE0)));

    UDR0 = data;
}

