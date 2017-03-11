obj-m += mymodule.o
mymodule-objs := hello.o test.o
all:
	make -C /home/xfliao/arm/linux-2.6.32.2/ M=$(PWD) modules
	cp mymodule.ko /tftpboot/
clean:
	make -C /home/xfliao/arm/linux-2.6.32.2/ M=$(PWD) clean
	rm /tftpboot/mymodule.ko
