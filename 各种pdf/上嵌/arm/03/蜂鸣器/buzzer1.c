void (*my_printf)(const char * fmt,...);
int (*my_getc)(void);//0x33f965f0  putc 0x33f965bc
//定义两个变量指向两个地址
#define GPBCON (*(unsigned int *)0x56000010)
#define GPBDAT (*(unsigned int *)0x56000014)

void buzzerInit()
{
	//先设置为输出模式GPBCON[1..0]=01  设置第0位为1,第一位为0
	GPBCON |=(0x01<<0);
	GPBCON &=~(0x01<<1);
	
	//buzzer off     GPBDAT[0]=0
	GPBDAT &=~(0x01<<0);
}

int main()
{
	int ch;
	my_printf=(void *)0x33f963a8;
    my_getc=(void *)0x33f965f0;
    
    buzzerInit();
    my_printf("Press any key to stop/start buzzer,'q' to quit.\n");
    while(1)
    {
    	ch=my_getc();
    	if(ch=='q')
    		break;
    	//start buzzer
    	GPBDAT |=~(0x01<<0);
    	my_printf("%c\n",ch);
    	ch=my_getc();
    	my_printf("%c\n",ch);
    	if(ch=='q')
    		break;
    	//stop buzzer
    	GPBDAT &=~(0x01<<0);
    }
    //stop buzzer
    GPBDAT &=~(0x01<<0);
   // my_printf();
    
	return 0;
}

