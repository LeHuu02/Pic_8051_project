/*
test project  lmd01, control led matrix 8x8 88051.
Le Minh Huu 6/1/2023
/*
power by: le minh huu ktmt k19 - ictu - 9/2/2023
thuc hanh: hien thi led matrix 8x8
linh kien: 8051, matrix 8x8, 74hc164,74hc574, cong logic NOT.
che do: Quet theo Hang
*/
*/
#include <REGX51.H>

sbit in  = P3^3;
sbit out  = P3^4;
sbit syn  = P3^5;
sbit dt  = P1^7;

int i, j;

void main(){
	char x[8] = {0xc3,0xc3,0xc3,0xff,0xff,0xc3,0xc3,0xc3,};
	char temp;
		P1 = 0;
	while(1){
		syn = 1;
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
			syn = 0;
		}
	}
}