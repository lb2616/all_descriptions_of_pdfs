int (*my_getc)(void);//0x33f965f0  putc 0x33f965bc
void (*my_printf)(const char * fmt,...);
int _start()
{
    my_getc=(void *)0x33f965f0;
	my_printf=(void *)0x33f963a8;
	my_printf(my_getc);
	return 0;
}

