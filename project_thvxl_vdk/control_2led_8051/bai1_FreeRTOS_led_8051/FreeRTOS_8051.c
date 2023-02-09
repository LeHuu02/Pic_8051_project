/*
Le Minh Huu 31/12/2022
test code control 2 led: doc lap
//copy ham tu ben thu vien rtx51.h sang thi khong bij loi os_creat_task
vao phan options tai target chon phan target -> opening system chon regx 51 tiny. de include thu vien.
*/
#include <regx51.h>
#include <rtx51tny.h>
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
	os_create_task (1);
	os_create_task (2);
	os_delete_task (0);
}

//1 tick = 10ms
void Task_led1(void) _task_ LED1{
	while(1){
		os_wait2 (K_IVL,3);	//3 tick --> 30ms
		led1 = on;	//sang trong 50ms
		os_wait2 (K_IVL,5);	//5 tick --> 50ms
		led1 = off;	//tat trong 30ms
	}
}

void Task_led2(void) _task_ LED2{
	while(1){
		os_wait2 (K_IVL,7);	//7 tick --> 70ms
		led2 = on;	//sang trong 30ms
		os_wait2 (K_IVL,3);	//3 tick --> 30ms
		led2 = off;	//tat trong 70ms		
	}
}

