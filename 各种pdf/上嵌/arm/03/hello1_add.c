void (*my_printf)(const char * fmt,...);
int (*my_getc)(void);//0x33f965f0  putc 0x33f965bc
int _start()
{
	int a,b,sum;
	my_printf=(void *)0x33f963a8;
    my_getc=(void *)0x33f965f0;
    
    a=my_getc();
    my_printf("%c\n",a);
    a=a-'0';
    
    b=my_getc();
    my_printf("%c\n",b);
    b=b-'0';
    
    __asm__ __volatile__(
    	"mov r0,%1\n"
    	"mov r1,%2\n"
    	"add r0,r0,r1\n"
    	"mov %0,r0\n"
    	:"=r"(sum)
    	:"r"(a),"r"(b)
    	:"r0","r1"
    );//汇编代码 被c语言代码调用 :"r"(a) 传入值   :"=r"(ret) 将汇编的寄存器的值传到ret中
    my_printf("%d+%d=%d\n",a,b,sum);
    
	return 0;
}

