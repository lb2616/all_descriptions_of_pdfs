obj-m += chrdev.o
my_module=chrdev.ko
my_app=test_chrdev
all:
	make -C /home/libo/arm/linux-2.6.32.2/ M=$(PWD) modules
	arm-linux-gcc $(my_app).c -o $(my_app)
	cp $(my_module) $(my_app) /tftpboot/
clean:	
	make -C /home/libo/arm/linux-2.6.32.2/ M=$(PWD) clean
	rm /tftpboot/$(my_module) /tftpboot/$(my_app)
