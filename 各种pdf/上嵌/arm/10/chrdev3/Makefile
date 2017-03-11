obj-m += chrdev3.o
my_module=chrdev3.ko
my_app=test_chrdev3
all:
	make -C /home/libo/arm/linux-2.6.32.2/ M=$(PWD) modules
	arm-linux-gcc $(my_app).c -o $(my_app)
	cp $(my_module) $(my_app) /tftpboot/
clean:	
	make -C /home/libo/arm/linux-2.6.32.2/ M=$(PWD) clean
	rm /tftpboot/$(my_module) /tftpboot/$(my_app)
