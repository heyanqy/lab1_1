// FILE:   Lab1_cpu02.c

#include "F28x_Project.h"     // Device Header File and Examples Include File

// Variables
Uint16 ToggleCount2 = 0;


void main(void)
{
// Initialize System Control
    InitSysCtrl();

// Initialize GPIO
    EALLOW;
 	GPIO_WritePin(34, 1);
    EDIS;

// Disable CPU interrupts and initialize PIE control registers
    DINT;
    InitPieCtrl();

// Disable CPU interrupts and clear all CPU interrupt flags
    IER = 0x0000;
    IFR = 0x0000;

// Initialize the PIE vector table
    InitPieVectTable();

// Enable global Interrupts and higher priority real-time debug events
    EINT;          // Enable Global interrupt INTM
    ERTM;          // Enable Global realtime interrupt DBGM

// Idle loop
    for(;;)
    {
    	GPIO_WritePin(34, 0);		// Turn on LD3
    	DELAY_US(1000 * 250);
    	GPIO_WritePin(34, 1);		// Turn off LD3
    	DELAY_US(2000 * 250);
    	ToggleCount2++;
    }
}

// end of file
