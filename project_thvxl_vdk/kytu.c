#include <stdio.h>

int main(){
	int i;
	//char kt = 96;
	for(i  = 65; i < 90; i++){
		printf("%c	", i);
		if(i == 80)	printf("\n");
	}
	printf("\n");
	for(i =  48; i <  58; i++){
		printf("%c	", i);
	}
	return 0;
}
