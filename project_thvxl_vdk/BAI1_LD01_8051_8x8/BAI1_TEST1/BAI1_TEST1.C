/*
power by: le minh huu ktmt k19 - ictu - 9/2/2023
thuc hanh: hien thi led matrix 8x8
linh kien: 8051, matrix 8x8, 74hc164,74hc574, cong logic NOT.
che do: Quet theo hang
*/
#include <REGX51.H>

sbit in = P3^3;
sbit out = P3^4;
sbit syn = P3^5;
sbit dt = P1^7;

int i,j;

void main(){
	char x[8] ={0x00,0x6c,0x92,0x82,0x82,0x44,0x28,0x10};
		char temp;
		while(1){
			syn = 1;
			for(i = 0; i <8;i++){
				temp = x[i];
				for(j = 0; j < 8; j++){
					dt = temp%2;
					temp = temp/2;
					in = 1;
					in = 0;
				}
				out = 1;
				out = 0;
				syn = 0;
			}
		}
	
}


