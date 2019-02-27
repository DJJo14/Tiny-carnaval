/*
 * main.h
 *
 *  Created on: 20 jun. 2016
 *      Author: jorrit
 */

#ifndef MAIN_H_
#define MAIN_H_



#define F_CPU 16000000UL

extern void Mode_1( void );
extern void Mode_2( void );
extern void Mode_3( void );
extern void Mode_4( void );
extern void button( void );


enum{
	MODE_NONE,
	MODE_1_NIGHTRIDER,
	MODE_2_OM_EN_OM,
	MODE_3_BRANDWEER,
	MODE_4_DOBBELSTEEN,
	MODE_COUNT,

};

#endif /* MAIN_H_ */
