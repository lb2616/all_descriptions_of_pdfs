int (*my_getc)(void);//0x33f965f0  putc 0x33f965bc
void (*my_printf)(const char * fmt,...);
void (*my_putc)(const char *s);
int _start()
{
	my_printf=(void *)0x33f963a8;
    my_getc=(void *)0x33f965f0;
    my_printf("Input 'q' to exit.\n");
    int ch;
    while(1)
    {
    	ch=my_getc();
    	my_printf("%c\n",ch);
    	if(ch=='q')
    		break;
    }
	return 0;
}

