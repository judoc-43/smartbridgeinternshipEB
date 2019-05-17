/*
 * STEPPER MOTOR.c
 *
 * Created: 16-May-19 3:26:21 PM
 * Author : ROHITH
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	int period;
	DDRD = 0x0F;		/* Make PORTD lower pins as output */
	period = 2;		/* Set period in between two steps */
	while (1)
	{
		/* Rotate Stepper Motor clockwise with Half step sequence */
		for(int i=0;i<50;i++)
		{
			PORTD = 0x09;
			_delay_ms(period);
			PORTD = 0x08;
			_delay_ms(period);
			PORTD = 0x0C;
			_delay_ms(period);
			PORTD = 0x04;
			_delay_ms(period);
			PORTD = 0x06;
			_delay_ms(period);
			PORTD = 0x02;
			_delay_ms(period);
			PORTD = 0x03;
			_delay_ms(period);
			PORTD = 0x01;
			_delay_ms(period);
		}
		PORTD = 0x09;		/* Last step to initial position */
		_delay_ms(period);
		_delay_ms(1000);

		/* Rotate Stepper Motor Anticlockwise with Full step sequence */
		for(int i=0;i<50;i++)
		{
			PORTD = 0x09;
			_delay_ms(period);
			PORTD = 0x01;
			_delay_ms(period);
			PORTD = 0x03;
			_delay_ms(period);
			PORTD = 0x02;
			_delay_ms(period);
			PORTD = 0x06;
			_delay_ms(period);
			PORTD = 0x04;
			_delay_ms(period);
			PORTD = 0x0C;
			_delay_ms(period);
			PORTD = 0x08;
			_delay_ms(period);
		}
		PORTD = 0x09;
		_delay_ms(period);
		_delay_ms(1000);
	}
}

