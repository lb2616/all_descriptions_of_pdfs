void (*my_printf)(const char* fmt,...);
int (*my_getc)(void);

#define GPBCON (*(volatile unsigned int*)0x56000010)
#define GPBDAT (*(volatile unsigned int*)0x56000014)

void LedInit(void){
//GPBCON [17 16 15 14 13 12 11 10]
//value    0  1  0  1  0  1  0  1
	GPBCON |=  ((0x01<<10)|(0x01<<12)|(0x01<<14)|(0x01<<16));
	GPBCON &= ~((0x01<<11)|(0x01<<13)|(0x01<<15)|(0x01<<17));

//GPBDAT [8 7 6 5]
//value   1 1 1 1
	//GPBDAT |=  ((0x01<<5)|(0x01<<6)|(0x01<<7)|(0x01<<8));
	GPBDAT |=  (0x0f<<5);	
}
void ledOn(int i){
	//GPB  8 7 6 5
	//led  4 3 2 1
	//i    4 3 2 1
	GPBDAT &= ~(0x01<<(i+4));
}
void ledOff(int i){
	GPBDAT |=   0x01<<(i+4);
}

int main(){
	int num,flag,i;
	my_printf=(void *)0x33f963a8;
	my_getc=(void *)0x33f965f0;

	LedInit();
	my_printf("0:Led All On.\n");
	my_printf("1-4:Led 1-4 On.\n");
	my_printf("5-8:Led 1-4 Off.\n");
	my_printf("9:Led All Off.\n");
	my_printf("Other:quit.\n");
	
	flag=1;
	while(flag){
		num=my_getc();
		num -= '0';
		
		switch (num){
			case 0:
				for(i=1;i<5;i++)
					ledOn(i);
				break;
			case 1:
			case 2:
			case 3:
			case 4:
				ledOn(num);
				break;
			case 5:
			case 6:
			case 7:
			case 8:
				ledOff(num-4);
				break;
			case 9:
				for(i=1;i<5;i++)
					ledOff(i);
				break;
			default:
				flag=0;
				break;
		}
	}

	return 0;
}







