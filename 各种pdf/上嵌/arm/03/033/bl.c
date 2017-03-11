
//int (*my_getc)(void);//0x33f965f0  putc 0x33f965bc
int _start()
{
	int a,b,c,d;
	void (*my_printf)(const char * fmt,...);
	my_printf=(void *)0x33f963a8;
    my_printf("In %s:before bl.\n",__func__);
    __asm__ __volatile__(
    	"b here\n"                          //跳转到here处,将跳过mytest
    	"bl mytest\n"                           //函数调用用bl
    	"here:\n"
    	"bl mytest\n"
    );//汇编代码 被c语言代码调用 :"r"(a) 传入值   :"=r"(ret) 将汇编的寄存器的值传到ret中
    
    my_printf("In %s:after bl.\n",__func__);
	return 0;
}

void mytest(void)
{
	void (*my_printf)(const char * fmt,...);
	my_printf=(void *)0x33f963a8;
	my_printf("In %s:bl test.\n",__func__);
}
