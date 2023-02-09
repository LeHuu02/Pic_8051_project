/*
chuong trinh lmd01 quet led matrix 8x8 theo hang
Le Minh Huu 26/12/2022
*/
#include <REGX51.H>
sbit in = P3^3;
sbit out = P3^4;
sbit syn = P3^5;
sbit dt = P1^7;

unsigned int t = 1000;
int i, j;

void delay(){
	while(t--);
}

void main(){
	char temp;
	//char x[8] = {0x18, 0x3c, 0x66, 0x66, 0x7e, 0x7e, 0x66,0x66}; 	//chu A
	//char x[8] = {0x78, 0x66, 0x7c, 0x7e, 0x63, 0x63, 0x7e, 0x7e};	//chu B
	//char x[8] = {0xc3, 0xc3,0xc3, 0xff, 0xff, 0xc3, 0xc3,0xc3};	 //chu H
	//char x[8] = {0x3c, 0x78, 0xc0, 0xc0,0xc0,0xc0, 0x78, 0x3c}; 	// chu C
	//char x[8] = {0xc3,0xc3,0xc3,0xc3,0xc3,0xc3,0x7e,0x3c}; 	//chu U
	
	P1 = 0;
	while(1){
		syn = 0xff;
		for(i = 0; i < 8; i++){
			temp = x[i];
			for(j = 0; j < 8; j++){
				dt = temp %2;
				temp = temp/2;
				in = 1;
				in = 0;
			}
			out = 1; 
			out = 0;
				syn = 0x00;
		}
		//delay();
	}
}