/* 
 * File:   config.h
 * Author: Carlos H Tobar
 * Comments:
 * Revision history: v1.0
 */

#ifndef CONFIG
#define	CONFIG

// PIC16F877A Configuration Bit Settings

// CONFIG
// BEGIN CONFIG
#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF // Flash Program Memory Code Protection bit (Code protection off)
//END CONFIG

#define _XTAL_FREQ 4000000

#include <xc.h>
//#include <../include/proc/pic16f877a.h>
#include <stdint.h>     // uint8_t, uint16_t, ...
#include <stdio.h>      // sprintf(), printf(), scanf(), ...
#include "lcd.h"        // lcd header file
#include "teclado.h"

#endif	/* CONFIG */
