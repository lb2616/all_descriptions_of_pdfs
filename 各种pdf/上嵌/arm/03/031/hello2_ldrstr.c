void (*my_printf)(const char * fmt,...);
int (*my_getc)(void);//0x33f965f0  putc 0x33f965bc
int _start()
{
	int a,ret;
	my_printf=(void *)0x33f963a8;
    my_getc=(void *)0x33f965f0;
    
    a=my_getc();
    my_printf("%c\n",a);
    a=a-'0';
    
    __asm__ __volatile__(
    	"ldr r0,=0x30008000\n"  //数据要存放的内存的位置
    	"mov r1,%1\n"
    	"str r1,[r0]\n"    // 把一个数据存到内存中的
    	"ldr r1,[r0]\n"    //
    	"mov %0,r1\n"
    	:"=r"(ret)
    	:"r"(a)
    	:"r0","r1"
    	
    	
    );//汇编代码 被c语言代码调用 :"r"(a) 传入值   :"=r"(ret) 将汇编的寄存器的值传到ret中
    
    my_printf("ret=%d\n",ret);
	return 0;
}

