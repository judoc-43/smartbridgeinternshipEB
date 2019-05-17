/*
 * relaylcd.c
 *
 * Created: 14-05-2019 14:32:26
 * Author : nikhil
 */ 

#ifndef  F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#define E 5
#define RS 7

void send_a_command(unsigned char command);
void send_a_character(unsigned char character);
void send_a_string(char *string_of_characters);

int main(void)
{
	DDRC = 0xFF;
	DDRA = 0;
	DDRB = 0xFF;
	DDRD = 0xFF;
	_delay_ms(50);
	
	ADMUX |=(1<<REFS0)|(1<<REFS1);
	ADCSRA |=(1<<ADEN)|(1<<ADATE)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
	
	int16_t COUNTA = 0;
	char SHOWA [3];
	

	send_a_command(0x01);
	_delay_ms(50);
	send_a_command(0x38);
	_delay_ms(50);
	send_a_command(0x0F);
	_delay_ms(50);
	
	ADCSRA |=(1<<ADSC);
	while(1)
	{
		COUNTA = ADC/4;
		if(COUNTA>175)
		{
			
			PORTB=0x80;
			_delay_ms(800);
			send_a_string ("EVENING");
			send_a_command(0x80 + 0x40 + 0);
		}
		else if (COUNTA<120)
		{
			if(COUNTA>175)
			{
				
				PORTB=0x80;
				_delay_ms(800);
				send_a_string ("EVENING");
				send_a_command(0x80 + 0x40 + 0);
			}
			else
			{
				
		
			PORTB=0x00;
			_delay_ms(800);
			send_a_string ("Morning");
			send_a_command(0x80 + 0x40 + 0);
			}
			
		}
		else
		{
			send_a_string ("night");
			send_a_command(0x80 + 0x40 + 0);
			PORTB=0xFF;
			_delay_ms(800);
		}
	
		itoa(COUNTA,SHOWA,10);
		send_a_string(SHOWA);
		send_a_string ("      ");
		send_a_command(0x80 + 0);
		
	}
}

void send_a_command(unsigned char command)
{
	PORTC = command;
	PORTD &= ~ (1<<RS);
	PORTD |= 1<<E;
	_delay_ms(20);
	PORTD &= ~1<<E;
	PORTC = 0;
}

void send_a_character(unsigned char character)
{
	PORTC = character;
	PORTD |= 1<<RS;
	PORTD |= 1<<E;
	_delay_ms(20);
	PORTD &= ~1<<E;
	PORTC = 0;
}
void send_a_string(char *string_of_characters)
{
	while(*string_of_characters > 0)
	{
		send_a_character(*string_of_characters++);
	}
}
