obj-m += hello.o
my_module=hello.ko
all:
	make -C /home/xuhuagen/arm/linux-2.6.32.2/ M=$(PWD) modules
	cp $(my_module) /tftpboot/
clean:
	make -C /home/xuhuagen/arm/linux-2.6.32.2/ M=$(PWD) clean
	rm /tftpboot/$(my_module)
