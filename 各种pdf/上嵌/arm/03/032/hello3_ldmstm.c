void (*my_printf)(const char * fmt,...);
//int (*my_getc)(void);//0x33f965f0  putc 0x33f965bc
int _start()
{
	int a,b,c,d;
	my_printf=(void *)0x33f963a8;
   // my_getc=(void *)0x33f965f0;
    
   // a=my_getc();
    __asm__ __volatile__(
    	"ldr r0,=0x30000000\n"        //r0作为指针
    	"mov r1,#0x01\n"
    	"mov r2,#0x02\n"
    	"mov r3,#0x03\n"
    	"mov r4,#0x04\n"
    	"stmia r0!,{r1-r4}\n"    //将r1-r4 一次性存入内存中
    	"ldmdb r0!,{r1-r4}\n"    //一次性取出
    	"mov %0,r1\n"
    	"mov %1,r2\n"
    	"mov %2,r3\n"
    	"mov %3,r4\n"
    	:"=r"(a),"=r"(b),"=r"(c),"=r"(d)
    	:                  //没有输入只留:即可,没有输入也要冒号
    	:"r0","r1","r2","r3","r4"
    );//汇编代码 被c语言代码调用 :"r"(a) 传入值   :"=r"(ret) 将汇编的寄存器的值传到ret中
    
    my_printf("a,b,c,d=%d,%d,%d,%d\n",a,b,c,d);
	return 0;
}

