/*
 * main.h
 *
 *  Created on: 20 jun. 2016
 *      Author: jorrit
 */

#ifndef MAIN_H_
#define MAIN_H_



#define F_CPU 16000000UL

extern bool sw(bool s);
extern void toggle( void );
extern bool Eeprom_rw( bool read_write );

enum{
	MODE_1_NIGHTRIDER,
	MODE_2_OM_EN_OM,

};

#endif /* MAIN_H_ */
