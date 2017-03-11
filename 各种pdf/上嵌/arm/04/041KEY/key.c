void (*my_printf)(const char * fmt,...);
int (*my_getc)(void);//0x33f965f0  putc 0x33f965bc

#define GPGCON (*(volatile unsigned int *)0x56000060)
#define GPGDAT (*(volatile unsigned int *)0x56000064)

keyInit(void)
{
	//key 1   2  3    4      5    6
	//GPG 0   3  5    6      7    11
	//bit 01  67 1011 1213  1415  2223
	//val 00 00 0 0  0 0   0 0   0 0
	GPGCON &=~((0x03<<0)|(0x03<<6)|(0x03<<10)|(0x03<<12)|(0x03<<14)|(0x03<<22));
}

void delay(int times)
{
	int i,j;
	for(i=0;i<times;i++)
		for(j=0;j<1000;j++)
			;
}

int keyUpDown(int i)
{
	//i  1    2    3    4      5      6
//GPGDAT 0    3    5    6      7      11
	switch(i)
	{
		case 1:
			if(GPGDAT &(0x01<<0))  //返回对应的比特位标识是否被按下 返回1 没有被按下
				return 1;
			break;
		case 2:
			if(GPGDAT &(0x01<<3))
				return 1;
			break;
		case 3:	
		case 4:			
		case 5:
			if(GPGDAT &(0x01<<(i+2)))
				return 1;
			break;
		case 6:
			if(GPGDAT &(0x01<<11))
				return 1;
			break;
		default:
			break;
	}
	return 0;
}

int main()
{
	int i;
	my_printf=(void *)0x33f963a8;
    	
	keyInit();
	while(1)
	{
		for(i=1;i<7;i++)
		{
			if(!keyUpDown(i))    //press :0 NOt press :1
			{
				my_printf("key %d is pressed.\n",i);
			}
			
		}
		delay(400);
	}

    return 0;
}



















