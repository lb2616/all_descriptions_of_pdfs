obj-m += buzzer.o
my_module=buzzer.ko
all:
	make -C /home/libo/arm/linux-2.6.32.2/ M=$(PWD) modules
	cp $(my_module) /tftpboot/
clean:	
	make -C /home/libo/arm/linux-2.6.32.2/ M=$(PWD) clean
	rm /tftpboot/$(my_module)
