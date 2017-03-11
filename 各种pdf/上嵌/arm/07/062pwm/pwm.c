//void(*my_printf)(const char* fmt,...);
//int (*my_getc)(void);
#define GPBCON    (*(unsigned int *)0x56000010)
#define GPBDAT    (*(unsigned int *)0x56000014)

#define SRCPND    (*(volatile unsigned int *)0x4a000000)
#define INTMOD    (*(volatile unsigned int *)0x4a000004)
#define INTMSK    (*(volatile unsigned int *)0x4a000008)
#define INTPND    (*(volatile unsigned int *)0x4a000010)
#define INTOFFSET (*(volatile unsigned int *)0x4a000014)

#define TCFG0     (*(volatile unsigned int *)0x51000000)
#define TCFG1     (*(volatile unsigned int *)0x51000004)
#define TCON      (*(volatile unsigned int *)0x51000008)
#define TCNTB0    (*(volatile unsigned int *)0x5100000C)
#define TCMPB0    (*(volatile unsigned int *)0x51000010)


void  pwmInit()
{
	//先设置为输出模式GPBCON[1..0]=01  设置第0位为1,第一位为0
	GPBCON |=(0x01<<0);
	GPBCON &=~(0x01<<1);				
	//buzzer off     GPBDAT[0]=0
	GPBDAT &=~(0x01<<0);

	//INTMOD [10]=0 irq mode
	INTMOD &= ~(0x01<<10);
	//INTMSK [10]=0 enable
	INTMSK &= ~(0x01<<10);

	//TCRG0 [7-0] for timer0
	TCFG0 &=~0xff;
	TCFG0 |=49;     //PCLK=50M HZ,output freq=PCLK/(49+1)
	//TCFG1 [3:0] for timer0,second prescaler freq.
	TCFG1 &= ~0x0f;
	TCFG1 &= 0x03;  //0011=1/16,now freq=62500

	TCNTB0=62500; // ONE second;
	TCMPB0=0;     //interrupt mode,triggier every 1s

	TCON &= ~0x0f;
	TCON |=0x01<<1; //manual update TCNT/TCMP
	TCON &= ~0x0f;
	TCON |= ((0x01<<0)|(0x01<<3));//bit 0:start timer,bit 3:auto load
}

void irq_exit()
{
	//clear SPCPND,INTPND 10 bit
	SRCPND |=(0x01<<10);
	INTPND |=(0x01<<10);
}
void irq_handler()
{
	int int_no;
	int *flag=(unsigned int *)0x30000000;
    void (*my_printf)(const char *fmt,...);
	my_printf=(void *)0x33f963a8;

	int_no=INTOFFSET;
	if(int_no==10)//10是TIMER0 
	{
		if(*flag==0)
		{
			my_printf("buzzer off.\n");
			GPBDAT &= ~(0x01<<0);
			*flag = 1;
		}
		else
		{
			my_printf("buzzer on.\n");
			GPBDAT |=0x01<<0;
			*flag = 0;
		}
		irq_exit();
	}
}


int main()
{
	pwmInit();
	while(1)
		;
	return 0;
}
