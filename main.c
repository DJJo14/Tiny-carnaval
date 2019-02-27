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

#define BAUD   9600
//:~/source/micronucleus/commandline$ sudo ./micronucleus --run ~/workspace/tiny_carnaval/Debug/tiny_carnaval.hex
//==========================================================================================
// Prototypes
//==========================================================================================

//==========================================================================================
// Global Values
//==========================================================================================
uint8_t mode = 3;
uint16_t EEMEM EE_Temperture_FS = 1024;
uint16_t EEMEM EE_Uout_FS = 1024;
uint16_t EEMEM EE_Iout_FS = 1024;
//==========================================================================================
// Interrupts
//==========================================================================================


//==========================================================================================
// Internal Functions
//==========================================================================================
static void init( void )
{
	DDRB = SYSTEM_DDR;
	PORTB = (1<<DDB4);
	Eeprom_rw(false);
	Smalltask_init();
	sei();	// __enable_interrupt();


}


//==========================================================================================
// Main
//==========================================================================================
int main(void)
{
	init();
//	Smalltask_rerun(TASK_button, 10);
	Smalltask_rerun(mode, 500);
//	Smalltask_rerun(TASK_Mode_2, 500);
//	Smalltask_rerun(TASK_Mode_3, 100);

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

void button( void )
{
	static uint8_t i = 0;

	if ( ~(PINB & (1<<DDB4)) )
	{
		PORTB |= (1<<PORTB1);
	}
	else
	{
		PORTB &= ~(1<<PORTB1);
	}


	if ( ~(PINB & (1<<DDB4)) && i == 0)
	{
		i++;


	}
	else if ( ~(PINB & (1<<DDB4)))
	{
		if ( i < 60)
		{
			i++;
//

		}
	}
	else if ( (PINB & (1<<DDB4)) && i > 50 )
	{

		if ( mode <= 3)
			mode++;
		else
			mode = 1;
		i = 49;
	}
	else if (i)
	{
		i--;
	}
	Smalltask_rerun(TASK_button, 10);
}

bool Eeprom_rw( bool n_read_write )
{
	if (n_read_write)
	{
//		eeprom_write_word( &EE_Uout_FS , Uout_FS);
//		eeprom_write_word( &EE_Iout_FS , Iout_FS);
//		eeprom_write_word( &EE_Temperture_FS , Temperture_FS);
		return true;

	}
	else
	{
//		Uout_FS = eeprom_read_word( &EE_Uout_FS );
//		Iout_FS = eeprom_read_word( &EE_Iout_FS );
//		Temperture_FS = eeprom_read_word( &EE_Temperture_FS );
		return false;
	}
	return false;
}
