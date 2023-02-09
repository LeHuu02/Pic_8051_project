
/*
power by: le minh huu ktmt k19 - ictu - 9/2/2023
thuc hanh: hien thi led matrix 8x8
linh kien: 8051, matrix 8x8, 74hc164,74hc574, cong logic NOT.
che do: Quet theo cot
*/
#include <REGX51.H>

sbit in = P3^3;//tao xung dich vao bo dem ghi dich
sbit out = P3^4;//tao xung xuat ra dong thoi cua cac bo dem
sbit syn = P3^5;//tao xung dong bo hang dau tien, chan nay noi toi dau vao bo ghi
sbit dt = P1^7;

int i,j;

void main (void){
	//char x[8] = {0x00,0xfe,0xfe,0x06,0x06,0x06,0x00,0x00}; //chu L
	//char x[8] = {0x00,0x3f,0x7f,0xcc,0xcc,0x7f,0x3f,0x00};	//chu A
	//char x[8] = {0x00, 0xff,0xff,0xb3,0xb3,0xb3,0x53,0x0c}; //chu B
	//char x[8] = {0x00,0x7e,0xff,0xc3,0xc3,0xc3,0x66,0x00}; 	//chu C
	//char x[8] = {0x00,0xff,0xff,0xc3,0xc3,0x7e,0x3c,0x00};	//chu D
	//char x[8] = {0x3c,0x7e,0xc3,0xc3,0xcb,0x6f,0x2e,0x08}; 	//chu G
	//char x[8] = {0x00, 0xff,0xff,0x18,0x18,0x18,0xff,0xff}; //chu H
	//char x[8] = {0x00, 0xc3,0xc3,0xff,0xff,0xc3,0xc3,0x00}; //chu I
	//char x[8] = {0x00,0xff,0xff,0x30,0x78,0xcc,0xc6,0x03}; 	// chu K
	//char x[8] = {0x00,0xff,0xff,0x60,0x30,0x0c,0xff,0xff}; 	// chu N
	//char x[8] = {0xff,0xff,0x60,0x30,0x30,0x60, 0xff,0xff}; // chu M	
	//char x[8] = {0x00,0x3c,0x7e,0xc3,0xc3,0xc3,0x7e,0x3c}; 	// chu O
	//char x[8] = {0x00,0xff,0xff,0xcc,0xcc,0xcc,0x78,0x30}; 	// chu p
	//char x[8] = {0x3c,0x7e,0xc3,0xcb,0xcf,0x7e,0x3e,0x03}; 	// chu Q
	//char x[8] = {0x7e,0x7f,0x06,0x18,0x06,0x7f,0x7e,0x00}; 	// chu w
	//char x[8] = {0x00,0xff,0xff,0xd3,0xd3,0xd3,0xc3,0x00}; 	// chu E
	//char x[8] = {0x00,0xff,0xff,0xd8,0xd8,0xd8,0xc0,0xc0}; 	// chu F
	//char x[8] = {0xc3,0xc7,0xcf,0xdb,0xdb,0xe3,0xc3,0x00}; 	// chu Z
	//char x[8] = {0xc3,0x66,0x3c,0x18,0x3c,0x66,0xc3,0x00}; 	// chu X
	//char x[8] = {0xf8,0xfc,0x06,0x03,0x06,0xfc,0xf8,0x00}; 	// chu V
	//char x[8] = {0xc0,0x60,0x30,0x1F,0x1F,0X30,0x60,0xc0}; 	// chu Y
	//char x[8] = {0xfc,0xfe,0x03,0x03,0x03,0xfe,0xfc,0x00}; 	// chu U
	//char x[8] = {0x00,0xc0,0xc2,0xc3,0xff,0xfe,0xc0,0xc0}; 	// chu J
	//char x[8] = {0xc0,0xc0,0xc0,0xff,0xff,0xc0,0xc0,0xc0}; 	// chu T
	char x[8] = {0x00,0x66,0xf3,0xdb,0xdb,0xcf,0x66,0x00}; 	// chu S
	

	char temp;
	//P1 =  P3 = 1;
	while (1){
		syn = 1;
		for (i = 0; i <= 7; i++ ) {
			 temp = x[i];
			for (j=0; j<=7; j++) {
				dt = temp%2; //phat bit LSBTrungGian = TrungGian/2; //dich phai
				temp = temp/2;
				in = 1; //tao mot xung vuong kich vao bo dem ghi dich
				in = 0;
			}
			out = 1; //tao mot xung vuong de bo dem xuat ra dong thoi
			out = 0; //dich xung dong bo hang xuong hang tiep theo
			syn = 0; //tat xung dong bo o cac hang sau
		}
	}
}