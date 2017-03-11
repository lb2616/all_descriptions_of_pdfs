int (*my_getc)(void);//0x33f965f0  putc 0x33f965bc
void (*my_printf)(const char * fmt,...);
int _start()
{
	int a,b,cpsr;
	my_printf=(void *)0x33f963a8;
    my_getc=(void *)0x33f965f0;
    
    a=my_getc();
    my_printf("%c\n",a);
    a=a-'0';
    
    b=my_getc();
    my_printf("%c\n",b);
    b=b='0';
    
    __asm__ __volatile__(
    	"mov r0,%1\n"
    	"mov r1,%2\n"
    	"cmp r0,r1\n"
    	"mrs r2,cpsr\n"   //将cpsr的值放到r2中
    	"addhi r0,r0,#1\n"
    	"addls r1,r1,#1\n"
    	"mov %0,r0\n"
    	"mov %1,r1\n"
    	"mov %2,r2\n"
    	:"=r"(a),"=r"(b),"=r"(cpsr)
    	:"r"(a),"r"(b)
    	:"r0","r1","r2"
    );
    my_printf("a=%d,b=%d\n",a,b);
    my_printf("cpsr=0x%x\n",cpsr);
	return 0;
}

