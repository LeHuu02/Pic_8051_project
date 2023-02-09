/*
Le Minh Huu 31/12/2022
test code control 2 led: doc lap
*/
#include <regx51.h>
#include <REX51TNY.H>
#define INIT 0
#define LED1 1
#define LED2 2

#define on 1
#define off 0

sbit  led1 = P2^0;
sbit  led2 = P2^1;

unsigned int dem1 = 0;
unsigned int dem2 = 0;

//function start up
void Startup(void) _task_ INIT{
	led1 = led2 = 0;
	//11,0592 mhz 	//timer 0: ms
	TMOD = 0x01;	//timer 0
	TL0 = 0xFF;
	TH0 = 0xED;
	TR0 = 1;	//khoi dong timer 0
}

void Task_led1(void) _task_ LED1{
	while(1){
		os_wait2 (K_IVL,50);
		led1 = ~led1;
		
	}
}

void Task_led2(void) _task_ LED2{
	while(1){
		os_wait2 (K_IVL,50);
		led2 = ~led2;
		
	}
}




