obj-m += buzzer.o
my_module=buzzer.ko
my_app=test_buzzer
all:
	make -C /home/xfliao/arm/linux-2.6.32.2/ M=$(PWD) modules
	arm-linux-gcc $(my_app).c -o $(my_app)
	cp $(my_module) $(my_app) /tftpboot/
clean:
	make -C /home/xfliao/arm/linux-2.6.32.2/ M=$(PWD) clean
	rm $(my_app) /tftpboot/$(my_module) /tftpboot/$(my_app)
