obj-m += workq.o
my_module=workq.ko
all:
	make -C /home/xfliao/arm/linux-2.6.32.2/ M=$(PWD) modules
	cp $(my_module) /tftpboot/
clean:
	make -C /home/xfliao/arm/linux-2.6.32.2/ M=$(PWD) clean
	rm /tftpboot/$(my_module) 
