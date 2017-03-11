void (*my_printf)(const char * fmt,...);
int (*my_getc)(void);//0x33f965f0  putc 0x33f965bc

#define GPBCON (*(volatile unsigned int *)0x56000010)
#define GPBDAT (*(volatile unsigned int *)0x56000014)

void LedInit(void)
{
	//GPBCON {17 16 15 14 13 12 11 10}
	//value    0  1  0  1  0  1  0  1
/*	GPBCON |=(0x01<<10);
	GPBCON |=(0x01<<12);
	GPBCON |=(0x01<<14);
	GPBCON |=(0x01<<16);*/
	GPBCON |=((0x01<<10)|(0x01<<12)|(0x01<<14)|(0x01<<16));//GPBCON |=0X15400;
	GPBCON &=((0x01<<11)|(0x01<<13)|(0x01<<15)|(0x01<<17));
	
//	GPBDAT |=((0x01<<5)|(0x01<<6)|(0x01<<7)|(0x01<<8));
	GPBDAT |=(0x0f<<5);
	/*
	GPBCON &=(0x01<<11);
	GPBCON &=(0x01<<13);
	GPBCON &=(0x01<<15);
	GPBCON &=(0x01<<17);*/
	//GPBDAT { 8 7 6 5}
	//value    1 1 1 1
	
	
}

void LedOn(int i)
{
	//GPB 8 7 6 5 
	//led 4 3 2 1 
	//    4 3 2 1
	GPBDAT &=~(0x01<<(i+4));
}

void LedOff(int i)
{
	GPBDAT |= (0x01<<(i+4));
}

int main()
{
	int num,flag,i;
	my_printf=(void *)0x33f963a8;
    my_getc=(void *)0x33f965f0;
    //初始化led灯的引脚
    
    LedInit();
    my_printf("0:led all on\n");
    my_printf("1-4:led 1-4 on\n");
    my_printf("5-8:led 5-8 off\n");
    my_printf("9:led All off\n");
    my_printf("Other :quit\n");
    
    flag = 1;
    while(flag)
    {
    	num=my_getc();
    	num-='0';
    	switch(num)
    	{
    		case 0:
    			for(i=1;i<5;i++)
    				LedOn(i);
    			break;
    			
    		case 1: 
    		case 2:
    		case 3:
    		case 4:
    			LedOn(num);
    			break;
    			
    		case 5:
    		case 6:	
    		case 7:
    		case 8:
    			LedOff(num-4);
    			break;
    			
    		case 9:
    			for(i=1;i<5;i++)
    				LedOff(i);	
    			break;
    		default:
    			flag=0;
    			break;
    	}
    }
	return 0;
}




















