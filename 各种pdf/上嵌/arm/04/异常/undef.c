int main()
{
	void (*my_printf)(const char * fmt,...);
	my_printf=(void *)0x33f963a8;
		
	my_printf("In %s:before undef\n",__func__);
	__asm__ __volatile__(
	".word 0x77777777\n"

	);

	my_printf("In %s:after undef\n",__func__);
	return 0;
}

void undef_handler(void)
{
	
	void (*my_printf)(const char * fmt,...);
	my_printf=(void *)0x33f963a8;

	my_printf("In %s:undefined exception.\n",__func__);
}
