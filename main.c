/*
 * main.c
 *
 *  Created on: 20 jun. 2016
 *      Author: jorrit
 */
//==========================================================================================
// Includes
//==========================================================================================
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/iotn85.h>
#include <inttypes.h>
#include <stdbool.h>
#include <util/delay.h>
#include <avr/eeprom.h>
#include "main.h"
#include "smalltask.h"
#include "hardware.h"

//==========================================================================================
// Definitions
//==========================================================================================
//#define F_CPU 8000000UL
#define TIME_LONG_HOLD_BUTTON 5000
#define TIME_HOLD_BUTTON 250
#define TIME_BUTTON 50
#define BAUD   9600
//:~/source/micronucleus/commandline$ sudo ./micronucleus --run ~/workspace/tiny_carnaval/Debug/tiny_carnaval.hex
//==========================================================================================
// Prototypes
//==========================================================================================

//==========================================================================================
// Global Values
//==========================================================================================
uint8_t mode = 1;
uint8_t EEMEM EE_mode = 1;
bool startup = true;
//==========================================================================================
// Interrupts
//==========================================================================================


//==========================================================================================
// Internal Functions
//==========================================================================================
static void init( void )
{
	DDRB = SYSTEM_DDR;
	PORTB = 0;//(1<<DDB5);
	mode = eeprom_read_byte( &EE_mode );
	if( mode > 0xF0 )
	{
		mode = 1;
	}
	Smalltask_init();
	sei();	// __enable_interrupt();


}


//==========================================================================================
// Main
//==========================================================================================
int main(void)
{
	init();

	Smalltask_rerun(mode, 50);
	if(startup && !(PINB & (1<<DDB5))  )
			Smalltask_rerun(TASK_button, TIME_BUTTON);


	while(1)
	{

		Smalltask_dispatch();

	}
}



void Mode_1( void )
{
	static uint8_t i = 0;
	switch(i++)
	{
	case 0:
		PORTB = (1<<PORTB0);
		break;
	case  1:
	case  2:
	case  3:
		PORTB = (PORTB<<1);
		break;
	case  4:
	case  5:
		PORTB = PORTB>>1;
		break;
	default:
		PORTB = (1<<PORTB0);
		i = 1;
	}
	Smalltask_rerun(mode, 500);
}

void Mode_2( void )
{
	static uint8_t i = 0;
	switch(i++)
	{
	case 0:
		PORTB = (1<<PORTB3) | (1<<PORTB1);
		break;
	default:
		PORTB = (1<<PORTB2) | (1<<PORTB0);
		i = 0;
	}
	Smalltask_rerun(mode, 500);
}

void Mode_3( void )
{
	static uint8_t i = 0;
	switch(i++)
	{
	case 0:
		PORTB ^=  (1<<PORTB2);
	case  1:
	case  2:
		PORTB ^=  (1<<PORTB3);
	case  3:
		PORTB ^=  (1<<PORTB0);
		break;
	case  4:
	case  5:
		PORTB ^=  (1<<PORTB3);
		break;
	case  6:
	case  7:
	case  8:
	case  9:
		PORTB ^= (1<<PORTB1);
		PORTB ^=  (1<<PORTB3);
		break;
//	case  10:
//	case  11:
//		break;
	default:
		PORTB &= ~((1<<PORTB0) |  (1<<PORTB1));

		i = 0;
		break;
	}
	Smalltask_rerun(mode, 100);
}

void Mode_4( void )
{
	static uint8_t i = 0;
	static uint8_t t = 0;
	if( !(PINB & (1<<DDB5) ) )
	{
		t = 6;
		if(i++ > 5)
			i = 0;
	}
	else if ( t )
	{
		t--;
		i++;
	}
	switch(i+1)
	{
	case 0:
		PORTB = 0x00;
		break;
	case  1:
		PORTB =  (1<<PORTB0);
		break;
	case  2:
		PORTB =  (1<<PORTB1);
		break;
	case  3:
		PORTB =  (1<<PORTB0) |  (1<<PORTB2);
		break;
	case  4:
		PORTB =  (1<<PORTB1) |  (1<<PORTB2);
		break;
	case  5:
		PORTB =  (1<<PORTB1) |  (1<<PORTB2) | (1<<PORTB0);
		break;
	case  6:
		PORTB =  (1<<PORTB1) |  (1<<PORTB2) | (1<<PORTB3);
		break;
	default:

		i = 0;
		break;
	}
	Smalltask_rerun(mode, 50+(5-t)*50);
}

void button( void )
{
	static uint8_t i = 0;

	if ( !(PINB & (1<<DDB5) ) && i == 0)
	{
		i++;
	}
	else if ( !(PINB & (1<<DDB5)))
	{
		if ( i < 250)
			i++;
	}
	else if ( (PINB & (1<<DDB5)) && i > (TIME_HOLD_BUTTON/TIME_BUTTON) )
	{
		if ( i < TIME_LONG_HOLD_BUTTON/TIME_BUTTON)
		{
			Smalltask_cancel_task( mode );
			if ( mode < MODE_COUNT-1 )
				mode++;
			else
				mode = 1;
			PORTB &= ~0x0F;
			PORTB |= mode & 0x0f;
		}
		else
		{
			PORTB |= 0x0f;
			eeprom_write_byte( &EE_mode , mode);
		}
		i = (TIME_HOLD_BUTTON/TIME_BUTTON)-1;
	}
	else if (i)
	{
		i--;
		if ( i == 0)
		{
			PORTB &= ~0x0F;
			Smalltask_rerun(mode, 50);
		}

	}
	Smalltask_rerun(TASK_button, TIME_BUTTON);
}
