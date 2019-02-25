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
	Eeprom_rw(false);
	Smalltask_init();
	sei();	// __enable_interrupt();


}


//==========================================================================================
// Main
//==========================================================================================
int main(void)
{
//	uint16_t c = 0;
	init();



	Smalltask_rerun(TASK_toggle, 500);
	PORTB |= (1<<PORTB0);
//	PORTB &= ~(1<<PORTB1);
	PORTB |= (1<<PORTB1);
//	sw(true);
	while(1)
	{

		Smalltask_dispatch();
//		_delay_ms(1000);
//		PORTB ^= (1<<PORTB1) | (1<<PORTB0) ;
	}
}


bool sw(bool s)
{
	if(s)
		PORTB |= (1<<PORTB1);
	else
		PORTB &= ~(1<<PORTB1);

	return s;
}

void toggle( void )
{
//	PORTB &= ~(1<<PORTB1);
	PORTB ^= (1<<PORTB1);
	Smalltask_rerun(TASK_toggle, 100);
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
