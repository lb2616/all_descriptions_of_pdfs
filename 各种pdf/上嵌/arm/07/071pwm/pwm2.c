#define GPBCON    (*(unsigned int *)0x56000010)

#define TCFG0     (*(volatile unsigned int *)0x51000000)
#define TCFG1     (*(volatile unsigned int *)0x51000004)
#define TCON      (*(volatile unsigned int *)0x51000008)
#define TCNTB0    (*(volatile unsigned int *)0x5100000C)
#define TCMPB0    (*(volatile unsigned int *)0x51000010)


void  pwmInit()
{
	//先设置为输出模式GPBCON[1..0]=10  设置第0位为0,第一位为1
	GPBCON |=(0x01<<1);
	GPBCON &=~(0x01<<0);				

	//TCRG0 [7-0] for timer0
	TCFG0 &=~0xff;
	TCFG0 |=49;     //PCLK=50M HZ,output freq=PCLK/(49+1)
	//TCFG1 [3:0] for timer0,second prescaler freq.
	TCFG1 &= ~0x0f;
	TCFG1 &= 0x03;  //0011=1/16,now freq=62500

	TCNTB0=62500; // ONE second;总时间
	TCMPB0=20800; //2/3秒响,1/3s不响 低电平的时间就是不响的时间

	TCON &= ~0x0f;
	TCON |=0x01<<1; //manual update TCNT/TCMP
	TCON &= ~0x0f;
	TCON |= ((0x01<<0)|(0x01<<3));//bit 0:start timer,bit 3:auto load
}

int main()
{
	pwmInit();
	while(1)
		;
	return 0;
}
