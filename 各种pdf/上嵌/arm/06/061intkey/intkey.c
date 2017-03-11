//void (*my_printf)(const char * fmt,...);
#define GPGCON (*(volatile unsigned int *)0x56000060)
#define EXTINT1 (*(volatile unsigned int *)0x5600008c)
#define EXTINT2 (*(volatile unsigned int *)0x56000090)
#define EINTMASK (*(volatile unsigned int *)0x560000a4)
#define EINTPEND (*(volatile unsigned int *)0x560000a8)


#define SRCPND (*(volatile unsigned int *)0x4a000000)
#define INTMOD (*(volatile unsigned int *)0x4a000004)
#define INTMSK (*(volatile unsigned int *)0x4a000008)
#define INTPND (*(volatile unsigned int *)0x4a000010)
#define INTOFFSET (*(volatile unsigned int *)0x4a000014)

keyInit()
{
	//GPGCON [1:0 7:6 11:10 13:12 15:14 23:22]=10 EINT mode
	GPGCON &=~((0x01<<0)|(0x01<<6)|(0x01<<10)|(0x01<<12)|(0x01<<14)|(0x01<<22));//GPBCON |=0X15400;
	GPGCON &= ((0x01<<1)|(0x01<<7)|(0x01<<11)|(0x01<<13)|(0x01<<15)|(0x01<<23));
	//EXTINT1 [2:0 14:12 22:20 26:24 30:28]=000 LOW LEVEL
	//EXTINT2 [14:12]=000 low level ,key 6
	EXTINT1 &= ~((0x07<<0)|(0x07<<12)|(0x07<<20)|(0x07<<24)|(0x07<<28));
	EXTINT2 &= ~(0x07<<12);
   //EINTMASK [0 11 13 14 15 19]=0,enable EINT

	EINTMASK &= ~((0x01<<8)|(0x01<<11)|(0x01<<13)|(0x01<<14)|(0x01<<15)|(0x01<<19));
	//INTMOD [5]=0 irq mode
	INTMOD &= ~(0x01<<5);

	//INTMSK [5]=0 enable
	INTMSK &= ~(0x01<<5);
}

void delay(int times)
{
	int i,j;
	for(i=0;i<times;i++)
		for(j=0;j<1000;j++)
			;
}

int getPressedKey()
{
	//判断对应比特是否为1 EINTPEND [8 11 13 14 15 19]  1:pressed 0: not pressed
	if(EINTPEND &(0x01<<8))
		return 1;//key 1
	if(EINTPEND &(0x01<<11))
		return 2;//key 2
	if(EINTPEND &(0x01<<13))
		return 3;//key 3
	if(EINTPEND &(0x01<<14))
		return 4;//key 4
	if(EINTPEND &(0x01<<15))
		return 5;//key 5
	if(EINTPEND &(0x01<<19))
		return 6;//key 6
	return 0;
}
void irq_exit(int i)
{
	//clear corresponding bit 
	//EINTPEND [8 11 13 14 15 19]
	switch(i)
	{
		case 1:
			EINTPEND |= (0x01<<8);
			break;
		case 2:
			EINTPEND |=(0x01<<11);
			break;
		case 3:
		case 4:
		case 5:
			EINTPEND |=(0x01<<(i+10));
			break;
		case 6:
			EINTPEND |=(0x01<<19);
			break;
		default:
			break;
	}
	//clear SPCPND ,INTPND 5 bit
	SRCPND |=(0x01<<5);
	INTPND |=(0x01<<5);
}

void irq_handler(void)
{
	int int_no,key_id;
	void (*my_printf)(const char *fmt,...);
	my_printf=(void *)0x33f963a8;
	int_no=INTOFFSET;
	my_printf("Int NO:%d\n",int_no);
	if (int_no==5) //是5就是被按下的键的中断
	{
		key_id=getPressedKey();
		if(key_id!=0)
			my_printf("Key %d is pressed.\n",key_id);
		delay(400);
		irq_exit(key_id);//clear SRCPND,INTPND,EINTPEND
    }
}

int main()
{
	keyInit();
	while(1)
	{
		;
	}

	return 0;

}


