void (*my_printf)(const char * fmt,...);
int _start()
{
	my_printf=(void *)0x33f963a8;
	my_printf("hello u-boot.\n");
	return 0;
}

